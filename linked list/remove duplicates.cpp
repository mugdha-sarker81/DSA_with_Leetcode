//https://www.hackerrank.com/contests/assignment-02-a-basic-data-structures-a-batch-09/challenges/remove-duplicate-9-1/submissions/code/1410796922

#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int val;
    node* next;
    node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void take_in_tail(node*& head, node*& tail, int val) {
    node* newnode = new node(val);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void find_x(node*head,int x,bool &flag){
    node* tmp =head;
    while(tmp != NULL){
        if(tmp->val == x){
            flag=true; return;
        }
        tmp= tmp->next;
    }
}

void print_list(node*head){
    node*tmp= head;
    while(tmp != NULL){
        cout<<tmp->val<<" ";
        tmp= tmp->next;
    }
    cout<<endl;
}
int main() {

    node* head = NULL;
    node* tail = NULL;
    int x; 
    while(cin>>x){
        if(x==-1) break;
        bool flag=false;
        find_x(head,x,flag);
        if(flag==false){
            take_in_tail(head,tail,x);
        }
    }
    print_list(head);
    return 0;
}
