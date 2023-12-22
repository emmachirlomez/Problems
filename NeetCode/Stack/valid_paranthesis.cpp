#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> stack;
    for (auto i : s) {
        if (i == '(' || i == '[' || i == '{')
            stack.push(i);
        if (i == ')' || i == ']' || i == '}') {
            if (stack.empty())
                return false;
            else if ((stack.top() == '(' && i == ')') ||
                    (stack.top() == '[' && i == ']') || 
                    (stack.top() == '{' && i == '}')) {
                stack.pop();
            }
            else
                return false;
        }
    }
    return stack.empty();
}

bool isValidSecond(string s) {
    stack<char> stack;
    unordered_map<char, char> paran = {{')', '('}, {']', '['}, {'}', '{'}};
    for (auto i : s) {
        if (paran.find(i) == paran.end())
            stack.push(i);
        else {
            if (stack.empty())
                return false;
            else if (stack.top() == paran[i])
                stack.pop();
            else return false;
        }
    }
    return stack.empty();
}

int main() {
    string s = "(]";
    cout << isValid(s) << endl;
    return 0;
}