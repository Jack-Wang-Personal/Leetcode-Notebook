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
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        slow=slow->next;
        ListNode* pre=nullptr;
        ListNode* cur=slow;
        ListNode* aft=slow;
        while(aft!=nullptr){
            aft=aft->next;
            cur->next=pre;
            pre=cur;
            cur=aft;
        }
        while(pre!=nullptr){
            if(pre->val!=head->val){
                return false;
            }
            pre=pre->next;
            head=head->next;
        }
        return true;
    }
};