/*
    Given head of a linked list, determine if it has a cycle in it

    Slow/fast pointers, if they ever intersect then there's a cycle

    Time: O(n)
    Space: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        //base case for if the list is empty
        if (head == NULL) {
            return false;
        }
        //creates the slow and fast pointers. Both start at the front of the linked list 
        ListNode* slow = head;
        ListNode* fast = head;
        //walks through the linked list. checks if the next 2 nodes in front of the fast pointer is not null
        while (fast->next != NULL && fast->next->next != NULL) {
            //point slow to the next node in the list
            slow = slow->next;
            //points fast two nodes down the list
            fast = fast->next->next;
            //if slow and fast point to the same node then return true
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};