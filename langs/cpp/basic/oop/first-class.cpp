#include <iostream>
#include <string>

using namespace std;

class Neko {
  private:
    string name;
  public:
    Neko(string s) {
      name = s;
    }
    void naku() {
      cout << "Meow. I'm " << name << "." << endl;
    }
};

int main()
{
  Neko dora("Boss");
  dora.naku();
}
