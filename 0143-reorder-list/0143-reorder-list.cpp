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
    // Brute Force Approach - In this Approach i am first finding final node and after that i am inserting it after current node
/*
    ListNode* returnFinalNode(ListNode* node){
        ListNode* Final = node;
        ListNode* preFinal = nullptr;
        while(Final->next!=nullptr){
            preFinal = Final;
            Final = Final->next;
        }
        preFinal->next = nullptr;
        return Final;
    }
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        while(temp!=nullptr && temp->next!=nullptr){
            ListNode* Final = returnFinalNode(temp);
            Final->next = temp->next;
            temp->next = Final;
            temp = temp->next->next;
        }
    }
*/
    /*
    Time Complexity - O(n^2)

    Space Complexity - O(1)
    */

    // Optimal Approach - In Optimal Approach We will Split question in 3 patterns
    /*
    1. Find Middle
    2. Reverse Second Half
    3. Merge both halves
    */
    void reorderList(ListNode* head) {
        // Find Middle - 
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=nullptr && fast->next->next !=nullptr){
            slow = slow->next;
            fast=fast->next->next;
        }
        // Split the list
        ListNode* mid = slow->next;
        slow->next = nullptr;

        // Reverse Second Half
        ListNode* prev=nullptr;
        ListNode* curr=mid;
        ListNode* next=nullptr;
        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
        }

        // Merger both halves 
        ListNode* first = head;
        ListNode* second = prev;
        while(second!=nullptr){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};