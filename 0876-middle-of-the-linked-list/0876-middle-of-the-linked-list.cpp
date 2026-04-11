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
    ListNode* middleNode(ListNode* head) {

        // 1st approach
        
        // int pos = 0;
        // ListNode* temp = head;
        // while(temp!=nullptr){
        //     pos++;
        //     temp = temp->next;
        // }
        // int mid = (0+pos)/2;
        // temp = head;
        // for(int i=0;i<mid;i++){
        //     temp = temp->next;
        // }
        // return temp;

        // 2nd approach

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }
};