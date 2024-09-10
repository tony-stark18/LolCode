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
    int gcd(int a, int b) {
        while (a != b) {
            if (a > b)
                a = a - b;
            else
                b = b - a;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp1 = head->next;
        // if(temp1->next==nullptr) return head;
        ListNode* temp2 = head;
        while(temp1!=nullptr){
            int gcdd = gcd(temp1->val,temp2->val);
            ListNode* newNode = new ListNode(gcdd,temp1);
            temp2->next = newNode;
            temp2 = temp1;
            temp1 = temp1->next;
        }
        return head;
    }
};