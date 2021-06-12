using namespace std;
#include <iostream>

struct Student
{
    int age;
    string name;
};

int main(int argc, char const *argv[])
{

    Student students[]{
        {10, "tom"},
        {20, "jack"},
        {22, "mike"}};
    cout << students[2].name << endl;


    Student students2[2];
    students2[0].age = 10;
    students2[0].name = "tom";
    students2[1].age = 20;
    students2[1].name = "jack";

    cout << students2[1].name << endl;
   

    return 0;
}
