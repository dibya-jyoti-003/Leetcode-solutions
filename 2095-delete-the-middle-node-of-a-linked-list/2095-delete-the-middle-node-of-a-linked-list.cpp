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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *fast = head, *slow = head, *prev = nullptr;
        if (!head->next)return nullptr;
        while (fast){
            fast = fast->next;
            if (!fast)break;
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (prev)prev->next = slow->next;
        slow->next = nullptr;
        return head;
    }
};