class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int remainder = 0;

        // Step 1: both lists
        while(temp1 && temp2) {
            int add = temp1->val + temp2->val + remainder;
            int currVal = add % 10;
            remainder = add / 10;

            tail->next = new ListNode(currVal);
            tail = tail->next;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // Step 2: remaining temp1
        while(temp1) {
            int add = temp1->val + remainder;
            int currVal = add % 10;
            remainder = add / 10;

            tail->next = new ListNode(currVal);
            tail = tail->next;

            temp1 = temp1->next;
        }

        // Step 3: remaining temp2
        while(temp2) {
            int add = temp2->val + remainder;
            int currVal = add % 10;
            remainder = add / 10;

            tail->next = new ListNode(currVal);
            tail = tail->next;

            temp2 = temp2->next;
        }

        // Step 4: final carry
        if(remainder != 0) {
            tail->next = new ListNode(remainder);
        }

        return dummy->next;
    }
};