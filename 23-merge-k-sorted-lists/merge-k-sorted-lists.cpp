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
        if(lists.size() == 0) return nullptr;
        if(lists.size() == 1) return lists[0];

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < lists.size(); i++) {
            ListNode* cur = lists[i];
            while(cur) {
                pq.push(cur->val);
                cur = cur->next;
            }
            delete lists[i];
        }

        ListNode* root = new ListNode(-1);
        ListNode* cur = root;
        while(!pq.empty()) {
            cur->next = new ListNode(pq.top());
            cur = cur->next;
            pq.pop();
        }

        return root->next;

    }
};