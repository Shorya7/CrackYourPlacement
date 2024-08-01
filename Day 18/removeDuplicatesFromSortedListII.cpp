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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* n=new ListNode(0);
        n->next=head;
        ListNode* p=n, *t=head;
        while(t){
            while(t->next&&t->val==t->next->val)t=t->next;
            if(p->next!=t)p->next=t->next;
            else p=p->next;
            t=t->next;
        }
        return n->next;
    }
};