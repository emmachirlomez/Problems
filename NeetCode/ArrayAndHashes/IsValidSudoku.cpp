#include<bits/stdc++.h>
using namespace std;

// O(cnt^2) for both memory and time
bool isValidSudoku(vector<vector<char>>& board) {
    const int cnt = 9;
    bool row[cnt][cnt] = {false};
    bool col[cnt][cnt] = {false};
    bool box[cnt][cnt] = {false};

    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt; j++) {
            if (board[i][j] == '.')
                continue;
            int area = (i / 3) * 3 + j / 3;
            int val = board[i][j] - '0' - 1;

            if (row[i][val] || col[j][val] || box[area][val])
                return false;

            row[i][val] = true;
            col[j][val] = true;
            box[area][val] = true;

        }
    }

    return true;
}

int main() {
    return 0;
}