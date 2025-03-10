#include<iostream>
using namespace std;
class Ball{
    public:
        float radius;
        float area(){
            return 3.14*radius*radius;
        }
};

int main(){
    Ball obj;
    obj.radius=10;
    cout << "Area of circle is: " << obj.area() << endl;
    return 0;
}