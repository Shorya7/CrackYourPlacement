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
    ListNode* partition(ListNode* head, int x) {
        if(!head||!head->next)return head;
        ListNode* s=new ListNode(0), *g=new ListNode(0);
        ListNode* t1=s,*t2=g;
        while(head){
            if(head->val>=x){
                t2->next=head;
                t2=head;
            }
            else{
                t1->next=head;
                t1=head;
            }
            head=head->next;
        }
        t2->next=NULL;
        t1->next=g->next;
        return s->next;
    }
};