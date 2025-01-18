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
    ListNode* sortList(ListNode* head) { return merge_sort(head); }

private:
    ListNode* merge_sort(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* mid = middle(head);

        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr;

        left = merge_sort(left);
        right = merge_sort(right);

        ListNode* merged = merge(left, right);
        return merged;
    }

    ListNode* middle(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        return prev ? prev : head; 
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while (t1 && t2) {
            if (t1->val < t2->val) {
                temp->next = t1;
                t1 = t1->next;
            } else {
                temp->next = t2;
                t2 = t2->next;
            }
            temp = temp->next;
        }

        if (t1)
            temp->next = t1;
        else if (t2)
            temp->next = t2;

        return ans->next;
    }
};