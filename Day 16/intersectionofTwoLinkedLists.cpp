//Solution 1

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *temp;
		while(headA != NULL){
			temp = headB;
			while(temp != NULL){
				if(headA == temp){
					return headA;
				}
				temp = temp -> next;
			}
			headA = headA -> next;
		}
		return NULL;
	}
};
//--------------------------------------------------------------------------------------------------------------------

//Solution 2

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* solve(ListNode *s, ListNode *l,int k){
        while(k--){
            l=l->next;
        }
        while(s!=l){
            if(!s||!l)return NULL;
            s=s->next;
            l=l->next;
        }
        return s;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1=0,n2=0;
        ListNode* tA=headA;
        ListNode* tB=headB;
        while(tA){
            n1++;
            tA=tA->next;
        }
        while(tB){
            n2++;
            tB=tB->next;
        }
        if(n1>n2)return solve(headB,headA,n1-n2);
        return solve(headA,headB,n2-n1);
    }
};

//--------------------------------------------------------------------------------------------------------------------

//Solution 3

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tA=headA;
        ListNode* tB=headB;
        while(tA!=tB){
            tA=tA->next;
            tB=tB->next;
            if(tA==tB)return tA;
            if(tA==NULL)tA=headB;
            if(!tB)tB=headA;
        }
        return tA;
    }
};