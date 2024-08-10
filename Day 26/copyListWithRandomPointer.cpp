// SOLUTION 1 (Using Hash Map)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* t=head;
        map<Node*,Node*>m;
        while(t){
            Node* n=new Node(t->val);
            m[t]=n;
            t=t->next;
        }
        t=head;
        while(t){
            Node* c=m[t];
            c->next=m[t->next];
            c->random=m[t->random];
            t=t->next;
        }
        return m[head];
    }
};


//---------------------------------------------------------------------------------------------------------------------------

// SOLUTION 2 (Optimized Approach)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* t=head;
        while(t){
            Node* c=new Node(t->val);
            c->next=t->next;
            t->next=c;
            t=t->next->next;
        }
        t=head;
        while(t){
            Node* c=t->next;
            if(t->random)
            c->random=t->random->next;
            else c->random=NULL;
            t=t->next->next;
        }
        Node* ans=new Node(0);
        Node* n=ans;
        t=head;
        while(t){
            n->next=t->next;
            t->next=t->next->next;
            n=n->next;
            t=t->next;
        }
        return ans->next;
    }
};