#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* removeElements(ListNode* head, int val) {
    for (auto i = head; i != nullptr; i = i->next) {
        while (i->next != nullptr && i->next->val == val)
            i->next = i->next->next;
    }
    if (head == nullptr)
        return nullptr;
    if (head->val == val)
        return head->next;
    return head;
}

int main() {
    return 0;
}
