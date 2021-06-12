using namespace std;
#include <iostream>

struct Student
{
    int age;
    string name;
}s3;

int main(int argc, char const *argv[])
{
    //方式1
    Student s1;
    s1.age = 10;
    s1.name = "tom";
    cout << s1.age << endl;
    cout << s1.name << endl;

    //方式2
    Student s2 = {20, "jack"};
    cout << s2.age << endl;
    cout << s2.name << endl;

    //方式3
    s3.age=22;
    s3.name="mike";
    cout << s3.age << endl;
    cout << s3.name << endl;

    return 0;
}
