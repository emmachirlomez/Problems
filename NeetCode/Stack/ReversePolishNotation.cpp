#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> my_stack;
    unordered_set<string> my_set = {"+", "-", "*", "/"};
    for (auto i : tokens) {
        int ans = 0;
        if (my_set.find(i) != my_set.end()) {
            int num_1 = my_stack.top();
            my_stack.pop();
 
            int num_2 = my_stack.top();
            my_stack.pop();

            switch (i[0]) {
                case '+':
                    ans = num_1 + num_2;
                    break;
                case '-':
                    ans = num_2 - num_1;
                    break;
                case '*':
                    ans = num_1 * num_2;
                    break;
                case '/':
                    ans = num_2 / num_1;
                    break;
            }

            my_stack.push((ans));

        }
        else
            my_stack.push(stoi(i));
    }

    return my_stack.top();
}

int main() {
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << evalRPN(tokens) << endl;
}