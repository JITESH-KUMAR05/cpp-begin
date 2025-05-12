#include<bits/stdc++.h>
using namespace std;
int i=0;
void print(){
    if(i>5) return;
    cout << "Hello " << i;
    cout << endl;
    i++;
    print();
}
int main(){

    print();
    return 0;
}