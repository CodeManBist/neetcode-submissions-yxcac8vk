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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 0;

        while(temp != nullptr) {
            len++;
            temp = temp -> next;
        }

        if(n == len) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int pos = len - n;
        temp = head;
        ListNode* rNode = nullptr;

        for(int i = 0; i < pos-1; i++) {
            temp = temp->next;
        }

        rNode = temp->next;
        temp->next = rNode->next;
        delete rNode;

        return head;
    }
};
