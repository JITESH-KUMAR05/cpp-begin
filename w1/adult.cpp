#include<bits/stdc++.h>

int main(){
    int x;
    std::cin >> x;
    if(x>=18){
        std::cout << "The person is adult and the age is " << x;
    }
    else{
        std::cout<< "The person is not an adult and the age is " << x;
    }
}