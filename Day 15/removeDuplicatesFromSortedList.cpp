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
        if(!head)return head;
        ListNode* s=head;
        int l=head->val;
        ListNode* f=head->next;
        while(f){
            if(l==f->val){
                if(!f->next){
                    s->next=NULL;
                    break;
                }
                f=f->next;
                s->next=f;
            }
            else{
                s=f;
                l=s->val;
                f=f->next;
            }
        }
        return head;
    }
};