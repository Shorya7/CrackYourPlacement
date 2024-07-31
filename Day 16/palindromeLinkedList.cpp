// SOLUTION 1 (Using Stack)

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
    bool isPalindrome(ListNode* head) {
        stack<int>s;
        ListNode* t=head;
        while(t){
            s.push(t->val);
            t=t->next;
        }
        t=head;
        while(t&&t->val==s.top()){
            s.pop();
            t=t->next;
        }
        return t==NULL;
    }
    
};

//--------------------------------------------------------------------------------------------------------------------
// SOLUTION 2 (Using Two Pointers)

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
    ListNode* reverse(ListNode* t){
        ListNode *p=NULL,*c=t,*f;
        while(c){
            f=c->next;
            c->next=p;
            p=c;
            c=f;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *f=head, *s=head;
        while(f->next&&f->next->next){
            s=s->next;
            f=f->next->next;
        }
        ListNode* n=reverse(s->next);
        ListNode* t1=head,*t2=n;
        while(t2){
            if(t1->val!=t2->val)return false;
            t1=t1->next;
            t2=t2->next;
        }
        return true;
    }
};