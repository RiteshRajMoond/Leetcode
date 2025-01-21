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
        Node* cur = head;
        
        while(cur) {
            Node* temp = new Node(cur->val);
            temp->next = cur->next;
            cur->next = temp;
            cur = temp->next;
        }

        cur = head;
        while(cur) {
            if(cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        Node* x = new Node(-1);
        cur = head;
        Node* temp = x;

        while(cur) {
            temp->next = cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
            temp = temp->next;
        }

        return x->next;
    }
};