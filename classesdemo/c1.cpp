#include<iostream>
#include<string>

using namespace std;
class demo{
    public:
    string name = "jitesh";
    int age = 19;
    void display(){
        cout << "Name is : " << name << " Age is : " << age ;
    }
};

int main(){
    demo d1 ;
    d1.display();
}