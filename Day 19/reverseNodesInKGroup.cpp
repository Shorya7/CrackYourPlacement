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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||!head->next||k==1)return head
        ListNode* t=head;
        int n=0;
        while(t){
            n++;
            t=t->next;
        }
        ListNode* d=new ListNode(0);
        d->next=head;
        ListNode* c=head,*pg=d;
        while(n>=k){
            ListNode* gs=c;
            ListNode* p= nullptr;
            int i=0;
            while(i<k){
            ListNode* f=c->next;
            c->next=p;
            p=c;
            c=f;
            i++;
            }
            pg->next=p;
            gs->next=c;
            pg=gs;
            n-=k;
        }
        return d->next;
    }
};