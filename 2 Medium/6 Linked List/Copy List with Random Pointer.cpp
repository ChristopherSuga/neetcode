class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mp;
        Node* ptr = head;
        //while loop that creates unlinked nodes with the same values as the original list
        while (ptr != NULL) {
            mp[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }
        //moves the ptr back the to the front of the linked list
        ptr = head;
        //
        while (ptr != NULL) {
            mp[ptr]->next = mp[ptr->next];
            mp[ptr]->random = mp[ptr->random];
            ptr = ptr->next;
        }
        return mp[head];
    }
};