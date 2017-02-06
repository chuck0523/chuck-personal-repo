// http://qiita.com/rinse_/items/09b67da4d16488ebea23

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <cstring>
#include <cstdlib>
#include <stdbool.h>

typedef struct tag_string
{
  char* c_str;
  size_t length;
  size_t capacity;
} string;

string create_string(const char* str, size_t capacity)
{
  string ret_val = {};
  ret_val.length = strlen(str);
  ret_val.capacity = capacity;
  if(ret_val.length > ret_val.capacity) {
    ret_val.capacity = ret_val.length;
  }
  // メモリを割り当て
  ret_val.c_str = (char*) malloc(sizeof(char) * ret_val.capacity + sizeof(char)); // 終端文字を考慮
  // メモリに値を設定
  memset(ret_val.c_str, 0, sizeof(char) * ret_val.capacity + sizeof(char));
  strncpy(ret_val.c_str, str, ret_val.length);
  return ret_val;
}

void destroy_string(string* p)
{
  if(p) {
    free(p->c_str);
    p->c_str = NULL;
    p->length = p->capacity = 0;
  }
}

char* begin_string(string* str)
{
  return str->c_str;
}
char* end_string(string* str)
{
  return str->c_str + str->length; // 終端文字を返す
}
const char* cbegin_string(const string* str)
{
  return str->c_str;
}
const char* cend_string(const string* str)
{
  return str->c_str + str->length; // 終端文字を返す
}

// compare
void copy_string(string* s1, const string* s2)
{
  if(s1->capacity >= s2->capacity) {
    strncpy(s1->c_str, s2->c_str, s2->length);
    s1->length = s2->length;
    memset(end_string(s1), 0, (s1->capacity - s1->length + 1));
    return;
  }
  // s1のバッファに入り切らない
  string ret_val = create_string(s2->c_str, s2->length);
  destroy_string(s1);
  *s1 = ret_val;
}

// equal
_Bool equal_string(const string* s1, const string* s2)
{
  return !strcmp(s1->c_str, s2->c_str);
}

int main(void)
{
  string str1 = create_string("abcdef", 6);
  string str2 = create_string("abcdefg", 0);
  string str3 = create_string("", 10);

  copy_string(&str2, &str1);
  copy_string(&str3, &str1);

  printf("string: %s\nlength: %lu\ncapacity:%lu\n",
    str2.c_str, str2.length, str2.capacity);
  printf("string: %s\nlength: %lu\ncapacity:%lu\n",
    str3.c_str, str3.length, str3.capacity);

  if (equal_string(&str1, &str2)) {
    printf("str1 == str2\n");
  }

  destroy_string(&str1);
  destroy_string(&str2);
  destroy_string(&str3);

  return 0;
}
