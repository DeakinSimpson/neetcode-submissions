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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy { new ListNode() };
        ListNode* cur { dummy };
        int carry {};

        while(l1 || l2 || carry != 0 )
        {
            // get l1 and l2 if they dont = 0
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // add the two numbers together
            int v { (val1 + val2 + carry) % 10 };
            carry = (val1 + val2 + carry) / 10;

            // add new list node with v
            cur->next = new ListNode(v);

            // set cur to next node
            cur = cur->next;

            // get next l1 and l2, if nullptr keep nullptr
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        ListNode* result { dummy->next };
        delete dummy;
        return result;
    }
};
