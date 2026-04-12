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
};