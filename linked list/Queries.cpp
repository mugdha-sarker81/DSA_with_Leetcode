//https://www.hackerrank.com/contests/assignment-02-a-basic-data-structures-a-batch-09/challenges/queries-6-1/problem?isFullScreen=true

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
void take_in_head(node*& head, node*& tail, int val){
    node* newnode = new node(val);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next= head;
    head= newnode;
}
void del_in_any_pos(node* &head, node* &tail, int idx) {
    if (idx == 0) {
        node* delnode = head;
        head = head->next;
        delete delnode;
    }else{
        node* tmp = head;
        for (int i = 1; i < idx; i++) {
            tmp = tmp->next;
        }
        node* delnode = tmp->next;
        tmp->next = tmp->next->next;
        delete delnode;
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

    int t; cin>>t;
    int size=0;
    while(t--){
        int x,val; cin>>x>>val;
        if(x==1){
            take_in_tail(head,tail,val); size++;
            print_list(head);
        }else if(x==0){
            take_in_head(head,tail,val); size++;
            print_list(head);
        }else{
            if(val<size+1){
                del_in_any_pos(head,tail,val); size--;
            }
            print_list(head);
        }
    }

    return 0;
}
