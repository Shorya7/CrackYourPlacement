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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* t=head;
        ListNode* ans=new ListNode(0);
        ListNode* nt=ans;
        while(t){
            if(val!=t->val){
                nt->next=new ListNode(t->val);
                nt=nt->next;
            }
            t=t->next;
        }
        return ans->next;
    }
};