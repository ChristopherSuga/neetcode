/*
    Given 2 linked lists, digits stored in reverse order, add them
    Ex. l1 = [2,4,3] l2 = [5,6,4] -> [7,0,8] (342 + 465 = 807)

    Sum digit-by-digit + carry, handle if one list becomes null

    Time: O(max(m, n))
    Space: O(max(m, n))
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();

        ListNode* curr = dummy;
        int carry = 0;
        //adds the nodes as long as one is not null
        while (l1 != NULL || l2 != NULL) {
            //elvis operator if l1!=NULL then val == l1->val else val1 = 0
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;

            //basic math to add the two nodes
            int sum = val1 + val2 + carry;
            //carry is equal to the sum/10 ex. (15/10 = 1)
            carry = sum / 10;
            //adds a new node that equals the sum mod 10 ex. (15%10 = 5)
            curr->next = new ListNode(sum % 10);
            //shifts the new lists current pointer
            curr = curr->next;
            //shifts both lists as long as they are not null
            if (l1 != NULL) {
                l1 = l1->next;
            }
            if (l2 != NULL) {
                l2 = l2->next;
            }
        }
        //edge case to create a new listNode with the carry value in case the number addded is too long
        if (carry == 1) {
            curr->next = new ListNode(1);
        }

        return dummy->next;
    }
};