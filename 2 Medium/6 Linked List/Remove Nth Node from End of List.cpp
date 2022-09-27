/*
    Given head of a linked list, remove nth node from end of list
    Ex. head = [1,2,3,4,5], n = 2 -> [1,2,3,5]

    Create 2 pointers "n" apart, iterate until end, will be at nth

    Time: O(n)
    Space: O(1)
*/

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
        if (head->next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        //while loop to set the fast node n nodes ahead
        while (n > 0) {
            fast = fast->next;
            n--;
        }

        if (fast == NULL) {
            return head->next;
        }
        //keeps moving both pointers along until the end of the list is reached
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        //when the end is reached changes the slow pointer to skip over one node
        slow->next = slow->next->next;
        return head;
    }
};