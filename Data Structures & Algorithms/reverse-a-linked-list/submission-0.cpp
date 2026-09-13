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
        ListNode* prevListNode { nullptr };                
        ListNode* curListNode { head };
        
        // while the current node isnt nullptr
        while (curListNode)
        {
            // create a temp of the next list node
            ListNode* next { curListNode->next };
            curListNode->next = prevListNode;
            prevListNode = curListNode;
            curListNode = next;
        }

        return prevListNode;
    }
};
