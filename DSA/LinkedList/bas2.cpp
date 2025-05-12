#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int val;
    Node* next;
    Node(int inserted_val){
        val = inserted_val;
        next = nullptr;
    }
};
int main(){
    // int arr[5] = {1,2,3,4,5};
    Node* head = new Node(0);
    for(int i=1;i<55;i++){
        Node *tem;
        tem = new Node(i);
        if(head->next == nullptr){
            head->next = tem;
        }else{
            Node *temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = tem;
        }
    }
    Node *temp = head;
    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
    // cout << temp->val << " ";

    return 0;
}