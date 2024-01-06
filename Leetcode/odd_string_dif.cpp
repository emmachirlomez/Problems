#include<bits/stdc++.h>
using namespace std;

string oddString(vector<string>& words) {
       
    for (int i = 0; i < words.size() - 2; i++) {
        int diff0 = 0, diff1 = 0, diff2 = 0;
        for (int j = 0; j < words[i].size() - 1; j++) {
            diff0 = words[i][j + 1] - words[i][j];
            diff1 = words[i + 1][j + 1] - words[i + 1][j];
            diff2 = words[i + 2][j + 1] - words[i + 2][j];

            if (diff0 == diff1 && diff1 == diff2) continue;
            else if (diff0 == diff1) return words[i + 2];
            else if (diff0 == diff2) return words[i + 1];
            else return words[i];
        }
    }
    return "";
}

int main() {
    vector<string> words = {"mll","edd","jii","tss","fee","dcc","nmm","abb","utt","zyy","xww","tss","wvv","xww","utt"};
    cout << oddString(words) << endl;
    return 0;
}