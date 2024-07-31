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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head||left==right)return head;
        ListNode* n=new ListNode(0);
        n->next=head;
        ListNode* p=n;
        int d=right-left;
        while(left-->1){
            p=p->next;
        }
        ListNode* t=p->next,*f;
        while(d--){
            f=t->next;
            t->next=f->next;
            f->next=p->next;
            p->next=f;
        }
        return n->next;
    }
};