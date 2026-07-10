//https://www.hackerrank.com/contests/assignment-02-a-basic-data-structures-a-batch-09/challenges/get-difference/problem?isFullScreen=true

#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int val ;
    node* next;
    node(int val){
        this->val= val;
        this->next=NULL;
    }

};

void take_in(node*&head,node*&tail,int val){
    node*newnode = new node(val); 
    if(head==NULL){
        head= newnode; tail= newnode; return;
    }
    tail->next= newnode;
    tail= newnode;
}
void find_max(node*head,int &max,int &min){
    node* tmp =head;
    while(tmp != NULL){
        if(tmp->val > max){
            max= tmp->val;
        }
        if(tmp->val<min){
            min= tmp->val;
        }
        tmp= tmp->next;
    }
}
int main() {

    node* head=NULL;
    node* tail=NULL;

    int x,max=INT_MIN,min=INT_MAX;
    while (cin>>x && x!=-1) {
            take_in(head,tail,x);
    }
    find_max(head,max,min);
    cout << (max - min) << endl;

    return 0;
}
