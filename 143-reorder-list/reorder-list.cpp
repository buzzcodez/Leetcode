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
    void reorderList(ListNode* head) {
        if(head==nullptr) return;
        //middle node dhondo
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=nullptr && fast->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        //list ke sec half ko reverse karo
        ListNode* second=slow->next;
        slow->next=nullptr;
        ListNode* prev=nullptr;
        while(second!=nullptr){
            ListNode*temp=second->next;
            second->next=prev;
            prev=second;
            second=temp;
        }
        //dono halves ko alternate tarike se merge karo
        ListNode* first=head;
        second=prev;
        while(second!=nullptr){
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }

        
    }
};