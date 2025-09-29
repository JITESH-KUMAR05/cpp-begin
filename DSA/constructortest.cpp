#include<bits/stdc++.h>
using namespace std;

class calc{

    int a,b;
    calc(){
        cout << "Constructor is called" << endl;
    }

    calc(int a,int b){
        this->a = a;
        this->b = b;
        cout << "Constructor with params" << endl;
    }
}

int main(){
    
    return 0;
}