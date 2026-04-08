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
    ListNode* reverseList(ListNode* head) {
        ListNode* Prev=NULL;
        ListNode* Curr=head;
        ListNode* Next=NULL;

        while(Curr!=NULL){
            Next = Curr->next;

            Curr->next = Prev;
            Prev = Curr;
            Curr = Next;
        }

        return Prev;
    }
    /*
    Time Complexity - O(n) Traverse list once

    Space Complexity - O(1) No extra space used
    */
};