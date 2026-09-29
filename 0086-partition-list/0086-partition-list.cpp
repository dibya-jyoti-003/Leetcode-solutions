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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = nullptr, *prev = nullptr, *ptr = head;
        while (ptr){
            if (ptr->val < x){
                if (prev != left)prev->next = ptr->next;
                else {
                    prev = ptr;
                    left = ptr;
                    ptr = ptr->next;
                    continue;
                }
                if (left)ptr->next = left->next;
                else {
                    ptr->next = head;
                    head = ptr;
                }
                if (left)left->next = ptr;
                left = ptr;
                ptr = prev->next;
            }
            else {
                prev = ptr;
                ptr = ptr->next;
            }
        }
        return head;
    }
};