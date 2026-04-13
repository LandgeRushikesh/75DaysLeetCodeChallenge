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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* Fast = dummy;

        int i=0;
        while(i<n){
            Fast = Fast->next;
            i++;
        }

        while(Fast->next!=nullptr){
            slow = slow->next;
            Fast = Fast->next;
        }

        ListNode* toDelete = slow->next;
        slow->next = toDelete->next;
        delete toDelete;

        // return newHead
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }

    /*
    Time Complexity - O(n)

    Space Complexity - O(1)
    */
};