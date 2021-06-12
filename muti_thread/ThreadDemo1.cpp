using namespace std;
#include<iostream>
#include<thread>

void myPrint(){
   cout<<"sub Thread start"<<endl;
   cout<<"sub Thread end"<<endl;
}

int main()
{

   //  std::thread th1(myPrint);
   //  cout << __GNUC__ << endl;
  //  cout << __cplusplus << endl;
   // th.join();
   int *p=(int *) 0x1100;
    cout<<*p<<endl;
  //  cout<<"main Thread end"<<endl;
    return 0;

    
    }
