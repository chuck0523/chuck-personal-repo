#include <stdio.h>
#include <time.h>
#include <string>

class mystr {
  char *str;
  size_t len;
  size_t buflen;
  int *refcount;

public:
  const char *c_str() const { return str; }
  size_t length() const { return len; }

  mystr() {
    str = NULL;
    *this = "";
  }
  mystr(const char *s) {
    str = NULL;
    *this = s;
  }
  mystr(const mystr &s) {
    str = NULL;
    *this = s.str;
  }
  ~mystr() {
    unset(str);
  }
  void printn() const {
    printf("%s\n", str);
  }
private:
  void set(const char *s, size_t newlen) {
    char *old = str;
    len = newlen;
    if(!old || buflen < len) {
      if(!old) {
        buflen = 16;
      }
      while(buflen < len) {
        buflen += buflen;
      }
      str = new char[buflen + 1];
    } else if(*refcount > 1) {
      str = new char[buflen + 1];
    }
    if(str != s) {
      strcpy(str, s);
    }
    if(old != str) {
      unset(old);
      refcount = new int(1);
    }
  }
  void unset(char *str) {
    if(str && --*refcount == 0) {
      delete refcount;
      delete[] str;
    }
  }
public:
  mystr operator+=(const char *s) {
    int oldlen = len;
    set(str, len + strlen(s));
    strcat(&str[oldlen], s);
    return *this;
  }
  mystr &operator+=(const mystr &s) {
    int oldlen = len;
    set(str, len + s.len);
    strcpy(&str[oldlen], s.str);
    return *this;
  }
  mystr &operator=(const char *s) {
    set(s, strlen(s));
    return *this;
  }
  mystr &operator=(const mystr &s) {
    unset(str);
    str = s.str;
    len = s.len;
    buflen = s.buflen;
    ++*(refcount = s.refcount);
    return *this;
  }
  mystr substr(int start, int len) const {
    mystr ret;
    ret.set("", len);
    strncpy(ret.str, &str[start], len);
    ret.str[len] = 0;
    return ret;
  }
};

mystr operator+(const mystr &s1, const mystr &s2) {
    mystr ret = s1;
    ret += s2;
    return ret;
}

int main() {
  mystr s = "abc";
  printf("[%lu]%s\n", s.length(), s.c_str());
}
