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
        ListNode *l3 = new ListNode(0);
        ListNode *temp = l3;
        int carry = 0;
        while(l1!=NULL||l2!=NULL||carry!=0){
            int x = l1 != NULL ? l1->val : 0;
            int y = l2 != NULL ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            temp->next = new ListNode(sum%10);
            temp=temp->next;
            l1 = l1 != NULL ? l1->next : NULL;
            l2 = l2 != NULL ? l2->next : NULL;
        }
        ListNode *result = l3->next;
        delete l3;
        return result;
    }
};
