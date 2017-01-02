#include <iostream>
#include <string>

using namespace std;

class Neko
{
  string name;
public:
    Neko(string s);
    void naku() const;
};

Neko::Neko(string s) : name(s){}

void Neko::naku() const {
  cout << "Meow. I'm " << name << "." << endl;
}

int main()
{
  Neko dora("Boss");
  dora.naku();
}
