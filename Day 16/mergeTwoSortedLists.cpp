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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1=list1;
        ListNode* t2=list2;
        ListNode* dum=new ListNode(0);
        ListNode* d=dum;
        while(t1&&t2){
            if(t1->val>t2->val){
                d->next=t2;
                // d=t2;
                t2=t2->next;
            }
            else{
                d->next=t1;
                // d=t1;
                t1=t1->next;
            }
            d=d->next;
        }
        if(t1)d->next=t1;
        else d->next=t2;
        return dum->next;
    }
};