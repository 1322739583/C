using namespace std;
#include <iostream>

struct Teacher
{
    int id;
    int age;
    string name;
};


struct Student
{
    int age;
    string name;
    Teacher teacher;
};



int main(int argc, char const *argv[])
{
    //方式1
    Teacher teacher={1,33,"jack"};
    Student stu={12,"tom",teacher};
    

    cout<<stu.teacher.name<<endl;
    return 0;
}