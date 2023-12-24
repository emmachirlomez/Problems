#include<bits/stdc++.h>
#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> my_stack;
    stack<int> min_stack;
    MinStack() {
        
    }
    
    void push(int val) {
        my_stack.push(val);
        if (min_stack.empty() || val <= min_stack.top())
            min_stack.push(val);
    }
    
    void pop() {
        if (my_stack.top() == min_stack.top())
            min_stack.pop();
        my_stack.pop();
    }
    
    int top() {
        return my_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

int main() {
    return 0;
}