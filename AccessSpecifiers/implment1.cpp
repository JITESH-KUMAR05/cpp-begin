#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Base{
    public:
        int a=15;
    protected:
        int b;
    private:
        int c;
};
// int fact(int n){
//     if(n == 0){
//         return 1;
//     }
//     return n*fact(n-1);
// }
class derived: public Base{
    public:
        void fun(){
            // a = 10;
            b = 20;
            // c = 30; // This will give error as c is private member of class Base
        }
        void display(){
            cout << "Value of a is: " << a << endl;
            cout << "Value of b is: " << b << endl;
            // cout << "Value of c is: " << c << endl; // This will give error as c is private member of class Base
        }
};
int main(){
    Base obj;
    obj.a = 10;
    // obj.b = 20; // This will give error as b is protected member of class Base we can access it only in derived class
    // obj.c = 30; // This will give error as c is private member of class Base
    cout << "Value of a is: " << obj.a << endl;
    derived obj1;
    obj1.fun();
    obj1.display();
    // cout << "fact(5) is: " << fact(5) << endl;
    return 0;
}
// int fact(int n){
//     if(n == 0){
//         return 1;
//     }
//     return n*fact(n-1);
// }