// http://qiita.com/rinse_/items/09b67da4d16488ebea23
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

class string {
  char* _c_str;
  size_t _length;
  size_t _capacity;

public:
  string(const char* str, size_t capacity)
  : _c_str(nullptr), _length(0), _capacity(0)
  {
    _length = strlen(str);
    _capacity = capacity;
    if(_length > _capacity) {
      _capacity = _length;
    }
    _c_str = reinterpret_cast< char* >(malloc(sizeof(char) * _capacity + sizeof(char))); // 終端文字を考慮
    memset(_c_str, 0, sizeof(char) * _capacity + sizeof(char));
    strncpy(_c_str, str, _length);
  }

  ~string() {
    free(_c_str);
    _c_str = nullptr;
    _length = _capacity = 0;
  }

  const char* c_str() const noexept { return _c_str; }
  size_t length() const noexept { return _length; }
  size_t capacity() const noexept { return _capacity; }
};

int main(void)
{
  string str("abcdef", 6);
  printf("string:%s\nlength:%d\ncapacity:%d\n",
    str.c_str(), str.length(), str.capacity());
  return 0;
}
