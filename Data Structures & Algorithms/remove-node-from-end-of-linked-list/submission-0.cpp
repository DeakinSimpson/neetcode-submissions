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
        ListNode* countHead { head };
        int counter { 0 };

        // get number of items in the linked list
        while (countHead)
        {
            countHead = countHead->next;
            ++counter;
        }

        // get position of the node we need to remove
        int pos { counter - n };
        if (pos == 0) { return head->next; }

        ListNode* curHead { head };
        // remove the node from the list at pos
        for (int i {0}; i < counter - 1; ++i)
        {
            if ((i + 1) == pos)
            {
                curHead->next = curHead->next->next;
                break;
            }
            curHead = curHead->next;
        }

        return head;
    }
};
