/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reverse_copy(ListNode*&newhead,ListNode*&newtail,ListNode* tmp){
        if(tmp==NULL){
            return;
        }
        reverse_copy(newhead,newtail,tmp->next);
        ListNode *newNode= new ListNode(tmp->val);
        if(newhead==NULL){
            newhead= newNode;
            newtail= newNode;
        }
        newtail->next= newNode;
        newtail= newNode;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL) return true;
        ListNode* newhead= NULL;
        ListNode* newtail= NULL;
        reverse_copy(newhead,newtail,head);
        ListNode *tmp1=head;
        ListNode *tmp2=newhead;
        bool flag=true;
        while(tmp1->next!= NULL){
            if(tmp1->val!= tmp2->val){
                flag= false; break;
            }else{
                tmp1= tmp1->next;
                tmp2= tmp2->next;
            }
        }
        return flag;
    }
};
