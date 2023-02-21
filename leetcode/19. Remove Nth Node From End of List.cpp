//https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/902356954/




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
        // Step 1: Determine the length of the linked list
        int length = 0;
        ListNode* node = head;
        while (node != nullptr) {
            length++;
            node = node->next;
        }

        // Step 2: Calculate the index of the node to remove
        int index = length - n;

        // If the node to remove is the first one, return the second node
        if (index == 0) {
            return head->next;
        }

        // Step 3: Traverse the list and remove the node at the calculated index
        node = head;
        for (int i = 0; i < index - 1; i++) {
            node = node->next;
        }
        node->next = node->next->next;

        // Step 4: Return the modified linked list
        return head;
    }
};
