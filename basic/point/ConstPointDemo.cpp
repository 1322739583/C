using namespace std;
#include<iostream>
 

int main(int argc, char const *argv[])
{
    int a=10;
    int b=10;
    int c=20;
   // const int *p;
    // *p=20;
  //   p=&b;
  //   cout<<*p<<endl;
  //   p=&c;
  //   cout<<*p<<endl;

     //int* const p=&a;
    // p=&b;
   //  *p=30;

     const int* const p=&a;
    // p=&b;
    // *p=20;
    
    return 0;
}
