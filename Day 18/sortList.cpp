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
    ListNode* mid(ListNode* head){
        ListNode* s=head, *f=head->next;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode d(0);
        ListNode* t=&d;
        while(l1&&l2){
            if(l1->val>l2->val){
                t->next=l2;
                l2=l2->next;
            }
            else{
                t->next=l1;
                l1=l1->next;
            }
            t=t->next;
        }
        t->next=l1?l1:l2;
        return d.next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* m=mid(head);
        ListNode* l=head, *r=m->next;
        m->next=NULL;
        l=sortList(l);
        r=sortList(r);
        return merge(l,r);
    }
};