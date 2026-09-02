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
 #define node ListNode
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        node* head=NULL,*curr =NULL;
        int carry =0,sum=0;
        while (l1 or l2 or carry){
            node* temp = new node();
            if (l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            sum = sum%10;
            temp->val = sum;
            temp->next =NULL;
            if (!head){head = temp;curr=temp;}
            else {
                curr->next = temp;
                curr = temp;
            }
            sum =0;
        }
        return head;
    }
};