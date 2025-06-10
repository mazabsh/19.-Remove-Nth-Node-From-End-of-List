#include<iostream> 
#include<vector> 

using namespace std; 

struct ListNode{
public: 
    int val; 
    ListNode* next; 
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution{
public: 
ListNode* removeNthFromEnd(ListNode* head, int n){
  ListNode dummy(0); 
  dummy.next = head; 
  ListNode* first = &dummy; 
  ListNode* second = &dummy; 

  for(int i=0; i<=n; ++i){
    first = first->next; 
  }
  while(first!=nullptr){
    first = first->next; 
    second = second->next; 
  }
  ListNode* toDelet = second -> next; 
  second -> next = second ->next -> next ; 
  delete toDelet; 
  return dummy.next; 
}
};
ListNode* createList(const vector<int>& vals) {
    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;
    for (int v : vals) {
        curr->next = new ListNode(v);
        curr = curr->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Test input
    vector<int> vals = {1, 2, 3, 4, 5};
    int n = 2;

    ListNode* head = createList(vals);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.removeNthFromEnd(head, n);

    cout << "After removing " << n << "-th node from end: ";
    printList(head);

    return 0;
}
