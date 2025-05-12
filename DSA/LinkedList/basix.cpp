#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node*next;
    Node(int insert_val){
        val = insert_val;
        next = nullptr;
    }
};

int main(){

    Node* head;
    head = new Node(4);
    cout << head->val << endl;
    // insert values to this list
    head->next = new Node(8);
    cout << head->next->val;
    cout << endl;
    head->next->next = new Node(12);
    cout << head->next->val;
    cout << endl;
    Node * temp = head;
    while(temp != nullptr){
        cout  << temp->val;
        temp=temp->next;
    }
    cout << endl;
    int target = 8;
    temp = head;
    while(temp != nullptr){
        if(temp->next->val == target){
            cout << "Deleted" << endl;
            temp->next = temp->next->next;
            break;
        }
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        cout  << temp->val;
        temp=temp->next;
    }
    cout << endl;

    return 0;
}