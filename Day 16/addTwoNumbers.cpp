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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode* ans=new ListNode(0);
        ListNode* d=ans;
        while(l1||l2||c){
            int n1=0,n2=0;
            if(l1)n1=l1->val;
            if(l2)n2=l2->val;
            int n=n1+n2+c;
            c=n/10;
            n%=10;
            d->next=new ListNode(n);
            d=d->next;
            l1=(l1)?l1->next:NULL;
            l2=(l2)?l2->next:NULL;
        }
        return ans->next;
    }
};