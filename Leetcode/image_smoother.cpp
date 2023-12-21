#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    vector<vector<int>> ans(img.size(), vector<int>(img[0].size(),1));;

    for (int i = 0; i < (int)img.size(); i++) {
        for (int j = 0; j < (int)img[i].size(); j++) {
            int sum = 0;
            int num = 0;
            for (int a = -1; a <= 1; a++) {
                for (int b = -1; b <= 1; b++) {
                    int row = i + a;
                    int col = j + b;
                    if ((row < 0 || row >= (int)img.size())
                        || (col < 0 || col >= (int)img[0].size())) continue;
                    sum += img[row][col];
                    num++;
                }
            }
            ans[i][j] = floor(sum / num);
        }
    }   
    return ans;
} 

int main() {
    vector<vector<int>> img = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> img_dif = {{100,200,100},{200,50,200},{100,200,100}};
    vector<vector<int>> ans = imageSmoother(img_dif);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
