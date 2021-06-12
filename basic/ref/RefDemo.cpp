using namespace std;
#include <iostream>

int main()
{
    int a = 10;
    int a=20;
    int& b = a;
    cout << a << endl;
    cout << b << endl;
    b = 100;
    int& c=a;
    int& c=b;
    cout << a << endl;
    cout << b << endl;
    cout<<&a<<endl;
    cout<<&b<<endl;
  
    return 0;
}