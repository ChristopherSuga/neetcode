/*
    Given the head of a singly linked list, reverse list & return
    Ex. head = [1,2,3,4,5] -> [5,4,3,2,1], head = [1,2] -> [2,1]

    Maintain prev, curr, & next pointers, iterate thru & reverse

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
    ListNode* reverseList(ListNode* head) {
        //checks if the current head is null or if the next item in the linked list is null
        //if the linked list is empty or of size 1 returns the linked list
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr->next;
        //loops while the current head has a value
        while (curr != NULL) {
            //temporarily saves the address of the next value in the linked list
            next = curr->next;
            //flips the pointer of the current node to point to the previous node
            curr->next = prev;
            //sets the current node to the previous node
            prev = curr;
            //sets the next node as the current node
            curr = next;
        }

        return prev;
    }
};