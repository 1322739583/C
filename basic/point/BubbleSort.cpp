using namespace std;
#include<iostream>

void sort(int* arr,int len){//和int arr[]是一样的
      for (int i = 0; i <len; i++)
      {
          for (int j = 0; j < len-i-1; j++)
          {
             if (arr[j]>arr[j+1])
             {
                 int temp=arr[j];
                 arr[j]=arr[j+1];
                 arr[j+1]=temp;
             }
             
          }
      }
      
}

 

int main(int argc, char const *argv[])
{
     int arr[]={5,2,7,15,1,6,9};
     int len=sizeof(arr)/sizeof(arr[0]);
     sort(arr,len);
     for (int i = 0; i < len; i++)
     {
        cout<<arr[i]<<endl;
     }
     return 0;
}