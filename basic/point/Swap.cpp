using namespace std;
#include<iostream>

void swap(int a,int b){
     int temp=a;
     a=b;
     b=temp;
}

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(int argc, char const *argv[])
{
    int a=10;
    int b=20;
   // swap(a,b);
    swap(&a,&b);
    cout<<a<<endl;
    cout<<b<<endl;
    
    return 0;
}
