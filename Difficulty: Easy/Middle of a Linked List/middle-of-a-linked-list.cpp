/* Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        // code here
        if(!head->next) return head->data;
        else if(!head->next->next) return head->next->data;
        
        Node* slow = head, *fast = head;
        
        while(true) {
            fast = fast->next->next;
            slow = slow->next;
            if(!fast->next) return slow->data;
            else if(!fast->next->next) return slow->next->data;
        }
    }
};
