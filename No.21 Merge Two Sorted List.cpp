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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        ListNode* res;

        if(l1->val<=l2->val){
            res=l1;
            l1=l1->next;
        }else{
            res=l2;
            l2=l2->next;
        }
        ListNode* pointer=res;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val<=l2->val){
                pointer->next=l1;
                pointer=pointer->next;
                l1=l1->next;
            }else{
                pointer->next=l2;
                pointer=pointer->next;
                l2=l2->next;
            }
        }
        if(l1==nullptr){
            pointer->next=l2;
        }else{
            pointer->next=l1;
        }
        return res;
    }
};