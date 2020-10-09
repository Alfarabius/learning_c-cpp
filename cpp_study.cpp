#include <iostream>
#include <vector>
using namespace std;


void print (string var) // перегрузка 
{
  cout << var;
}


void print (int var) // перегрузка
{
  cout << var << endl;
}


uint64_t multiply(int &a, uint16_t &b)
{
  return a * b;
}


int changeVar(int &a)
{
  a = a * 10;
  return a;
}

int main() 
{
  int zz = 10;
  uint8_t a = 252;
  uint16_t two = 2;
  uint16_t &_ref = two;
  int num = 333;
  double num_2 = 22.22;
  int ch = 'q';

  char let = 'w';
  char str[] = "Hello World!";// C style
  string _str = "Goodbye World!";// std::string 
  
  vector <int> vect (10); // можно удлинять
  int arr[] = {1, 33, 44, 1, 0, 8}; // нельзя удлинять

  vect.insert(vect.begin(), arr, arr + 6);
  cout << "element 3 of vect: " << vect.at(2) << endl; // 44
  vect.push_back(42);
  cout << "last element of vect: " << vect.back() << endl;
  cout << "first element of vect: " << vect.front() << endl;
  std::cout << "Hello World!\n";
  cout << "Hello World!" << endl;
  cout << _str << " " << str << endl;
  cout << "a + ch = " << a + ch << endl << "int ch = 'q' =  " << ch << endl;
  cout << endl;

  print("12 is: ");
  print(12);

  print(multiply(num, two));
  print(multiply(num, _ref));
    
  print(changeVar(zz));
  // changeVar(zz);
  print(changeVar(zz));
  // changeVar(zz);
  print(changeVar(zz));
}