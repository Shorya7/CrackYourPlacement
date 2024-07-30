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
    ListNode* add(ListNode* l1,ListNode* l2){
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
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        return ans->next;
    }
    ListNode* rev(ListNode* l){
        ListNode* p=NULL;
        ListNode* t=l;
        ListNode* f;
        while(t){
            f=t->next;
            t->next=p;
            p=t;
            t=f;
        }
        return p;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=rev(l1);
        l2=rev(l2);
        ListNode* ans=add(l1,l2);
        return rev(ans);
    }
};