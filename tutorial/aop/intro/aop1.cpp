#include <iostream>

class dredd
{
  // ...
public:

  void dredd_say()
  {
    this->one();
    this->two();
    this->three();
    this->strike();
  }
  
private:
  
  void one()    {  std::cout<<"one, ";   }
  void two()    {  std::cout<<"two, ";   }
  void three()  {  std::cout<<"three, "; }
  void strike() {  std::cout<<"strike!"; }
};

int main()
{
  dredd d;
  std::cout << "Dredd: ";
  d.dredd_say();
  std::cout << std::endl;

  return 0;
}