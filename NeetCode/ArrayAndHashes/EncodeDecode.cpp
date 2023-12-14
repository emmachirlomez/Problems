#include<bits/stdc++.h>
#include <string>
using namespace std;

string encode(vector<string> &strs) {
        string encode = "";
        for (int i = 0; i < strs.size(); i++) {
            encode += to_string(strs[i].size()) + "|" + strs[i];
        }
        return encode;
}

vector<string> decode(string &str) {
    vector<string> ans;
    int string_size = str.size();
    int i = 0;
    while (i < str.size()) {
        int j = i;
        while (str[j] != '|')
            j++;
        int len = stoi(str.substr(i, j - i));
        ans.push_back(str.substr(j + 1, len));
        i = j + 1 + len;
    }
    return ans;
}

int main() {
    vector<string> input = {"lint","|","love","you"};
    vector<string> input2 = {"test", "test", "test", "test"};
    string encoded = encode(input2);
    vector<string> output = decode(encoded);
    for (auto i : output)
        cout << i << " ";
        cout << '\n';
    return 0;
}