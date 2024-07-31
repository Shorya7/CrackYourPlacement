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
ListNode* rev(ListNode* t){
    ListNode* p=NULL,*f;
    while(t){
        f=t->next;
        t->next=p;
        p=t;
        t=f;
    }
    return p;
}
    void reorderList(ListNode* head) {
        ListNode *s=head, *f=head;
        while(f->next&&f->next->next){
            s=s->next;
            f=f->next->next;
        }
        ListNode* n=rev(s->next);
        s->next=NULL;
        ListNode* ans=new ListNode(0);
        ListNode* t=ans,*t1=head;
        while(n){
            t->next=t1;
            t1=t1->next;
            t=t->next;
            t->next=n;
            n=n->next;
            t=t->next;
        }
        t->next=t1;
        head=ans->next;
    }
};