#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mystr {
  char *str;

  mystr(const char *s) {
    str = new char[strlen(s) + 1];
    strcpy(str, s);
  }
  ~mystr() {
    printf("~mystr: %s\n", str);
    delete[] str;
  }
  void printn() {
    printf("%s\n", str);
  }
  void operator+=(const char *s) {
    char *old = str;
    int len = strlen(str) + strlen(s);
    str = new char[len + 1];
    strcpy(str, old);
    strcat(str, s);
    delete[] old;
  }
};

int main()
{
  mystr s1 = "abc";
  s1 += "def";
  s1.printn();
}
