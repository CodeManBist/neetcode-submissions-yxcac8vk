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
        if(head == nullptr) {
            return nullptr;
        }
        vector<int> list;
        ListNode* temp = head;

        while(temp != nullptr) {
            list.push_back(temp->val);
            temp = temp->next;
        }

        reverse(list.begin(), list.end());

        ListNode* newHead = new ListNode(list[0]);
        ListNode* curr = newHead;

        for(int i = 1; i < list.size(); i++) {
            curr->next = new ListNode(list[i]);
            curr = curr->next;
        }
        return newHead;
    }
};
