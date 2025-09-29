#include <iostream>
using namespace std;
class student{
    private:
    int roll_no=100;
    
    public:
    string name;
    int age;
    
    student(string student_name , int student_age){
        this->name=student_name;
        this->age=student_age;
    }
    // setter function is used to set private members 
    void roll_no_setter(int r){
        this->roll_no=r;
    }
    // getter function will be used to get private members of a class
    int roll_no_getter(){
        return roll_no;
    }
};
int main()
{
    student s1("vijay",22);
    s1.roll_no_setter(12345);
    cout<<s1.roll_no_getter()<<endl;
    
    return 0;
}