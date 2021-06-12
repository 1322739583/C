using namespace std;
#include <iostream>

struct Student
{
    int age;
    string name;
};

void printStrudent1(const Student stu){
    //stu.age=22;
    cout<<stu.age<<endl;
}


void printStrudent2(const Student* stu){
    //stu->age=22;
    cout<<stu->age<<endl;
}
int main(int argc, char const *argv[])
{
    //方式1
    Student stu={12,"tom"};
    printStrudent1(stu);
    printStrudent2(&stu);
    cout<<stu.age<<endl;
   

    return 0;
}
