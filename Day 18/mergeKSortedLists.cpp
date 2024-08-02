// SOLUTION 1

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
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* n=new ListNode(0);
        ListNode* t=n;
        while(l1&&l2){
            if(l1->val>l2->val){
                t->next=l2;
                l2=l2->next;
            }
            else{
                t->next=l1;
                l1=l1->next;
            }
            t=t->next;
        }
        t->next=(l1)?l1:l2;
        return n->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        ListNode* head=lists[0];
        for(int i=1;i<lists.size();i++){
            head=merge(head,lists[i]);
        }
        return head;
    }
};

//------------------------------------------------------------------------------------------------------------------
// SOLUTION 2 (Min Heap)

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        ListNode* n=new ListNode(0);
        ListNode* t=n;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(auto i:lists){
            if(i)pq.push({i->val,i});
        }
        while(!pq.empty()){
            ListNode* m=pq.top().second;
            pq.pop();
            if(m->next)pq.push({m->next->val,m->next});
            t->next=m;
            t=m;
        }
        return n->next;
    }
};