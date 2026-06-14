// Leetcode Question 206
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
};


// Leetcode Question 876
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


// Leetcode Question 141
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};


// Leetcode Question 142
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        bool isCycle=false;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                isCycle = true;
                break;
            }
        }
        if(!isCycle){
            return NULL;
        }
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};


// Leetcode Question 234
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int>v;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        int i=0;
        int j=v.size()-1;
        while(i<j){
            if(v[i]!=v[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};