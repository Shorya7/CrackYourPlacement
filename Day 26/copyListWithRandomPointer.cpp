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