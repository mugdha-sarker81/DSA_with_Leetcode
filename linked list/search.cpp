//https://www.hackerrank.com/contests/assignment-02-a-basic-data-structures-a-batch-09/challenges/search-12/problem?isFullScreen=true

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
void find_x(node*head,int n,int &idx,bool &flag){
    node* tmp =head;
    while(tmp != NULL){
        if(tmp->val == n){
            flag=true; return;
        }
        tmp= tmp->next;
        idx++;
    }
}
int main() {
    int t; cin>>t; 
    while(t--){
    node* head=NULL;
    node* tail=NULL;
    bool flag=false;
    int x,n,idx=0;
    while (cin>>x) {
        if(x==-1) break;
            take_in(head,tail,x);
    }
    cin>>n;
    find_x(head,n,idx,flag);
    if(flag){
        cout<<idx<<endl;
    }else{
        cout<<"-1"<<endl;
    }}

    return 0;
}
