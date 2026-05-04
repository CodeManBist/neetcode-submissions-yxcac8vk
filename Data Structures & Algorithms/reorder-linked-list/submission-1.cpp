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
    void reorderList(ListNode* head) {
        vector<int> arr;

        ListNode* temp = head;

        while(temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> res;

        int i = 0, j = arr.size() - 1;

        while(i <= j) {
            if(i == j) {
                res.push_back(arr[i]);
            } else {
                res.push_back(arr[i]);
                res.push_back(arr[j]);
            }

            i++;
            j--;
        }

        temp = head;
        int k = 0;

        while(temp) {
            temp -> val = res[k];
            k++;
            temp = temp -> next;
        }
    }
};
