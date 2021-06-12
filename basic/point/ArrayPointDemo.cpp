using namespace std;
#include<iostream>
 

int main(int argc, char const *argv[])
{
    
    int arr[]={11,22,33,44,5};
    
    for(int i = 0; i <sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout<<arr[i]<<endl;
    }

    int* p=arr;

     for(int i = 0; i <sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout<<*p++<<endl;
    }
        
    return 0;
}
