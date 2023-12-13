#include<bits/stdc++.h>
using namespace std;

// Time Complexity O(n * m) and Space Complexity O(n + m)
int numSpecial(vector<vector<int>>& mat) {
    unordered_map<int, int> ones_in_row;
    unordered_map<int, int> ones_in_col;
    int special = 0;
    for (int i = 0; i < mat.size(); i++) 
        for (int j = 0; j < mat[i].size(); j++) 
            if (mat[i][j] == 1)
                ones_in_row[i]++, ones_in_col[j]++;

    for (auto i : ones_in_row) 
        for (auto j : ones_in_col)
            if (mat[i.first][j.first] == 1 && 
                i.second == 1 && 
                j.second == 1)
                special++;
    
    return special;
}

int main() {
    return 0;
}