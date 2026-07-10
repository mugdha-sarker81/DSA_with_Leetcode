//https://www.hackerrank.com/contests/assignment-02-a-basic-data-structures-a-batch-09/challenges/same-to-same-1/problem?isFullScreen=true

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

void take_in(node*& head, node*& tail, int val) {
    node* newnode = new node(val);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

bool check_same(node* head1, node* head2) {

    while (head1 != NULL && head2 != NULL) {
        if (head1->val != head2->val) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return (head1 == NULL && head2 == NULL);
}

int main() {

    node* head1 = NULL;
    node* tail1 = NULL;
    int x;
    while (cin >> x) {
        if (x == -1) break;
        take_in(head1, tail1, x);
    }

    node* head2 = NULL;
    node* tail2 = NULL;
    int y;
    while (cin >> y) {
        if (y == -1) break;
        take_in(head2, tail2, y);
    }

    if (check_same(head1, head2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
