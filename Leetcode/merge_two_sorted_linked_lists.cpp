#include<bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;
    
    if (list1->val <= list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

int main() {
    ListNode* list1_third = new ListNode(4);
    ListNode* list1_second = new ListNode(2, list1_third);
    ListNode* list1_first = new ListNode(1, list1_second);

    ListNode* list2_third = new ListNode(4);
    ListNode* list2_second = new ListNode(3, list2_third);
    ListNode* list2_first = new ListNode(1, list2_second);

    ListNode* ans = mergeTwoLists(list1_first, list2_first);
    while (ans != nullptr) {
        cout << ans->val << " ";
        ans = ans->next;
    }


    delete(list1_first);
    delete(list1_second);
    delete(list1_third);

    delete(list2_first);
    delete(list2_second);
    delete(list2_third);

    delete(ans);
    return 0;
}
        
