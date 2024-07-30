//SOLUTION 1 (Iterative)

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
    ListNode* reverseList(ListNode* head) {
        ListNode* p=NULL; 
        ListNode* t=head;
        ListNode* f;
        while(t){
            f=t->next;
            t->next=p;
            p=t;
            t=f;
        }
        return p;
    }
};

//--------------------------------------------------------------------------------------------------------------------
//SOLUTION 2 (Recursive)

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
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* n=reverseList(head->next);
        ListNode* f=head->next;
        f->next=head;
        head->next=NULL;
        return n;
    }
};