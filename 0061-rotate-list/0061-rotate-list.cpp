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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int n = 1;
        ListNode* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
            n++;
        }
        if(k%n==0) return head;
        int i = n-(k%n);
        ListNode* st = head;
        while(i>1){
            st = st->next;
            i--;
        }
        // cout<<n;
        ListNode* ans = st->next;
        st->next = NULL;
        temp->next = head;
        return ans;
    }
};