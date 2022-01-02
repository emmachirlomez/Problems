#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        string S, T;
        cin >> S >> T;
        sort(S.begin(), S.end());
        if (T == "abc" && find(S.begin(), S.end(), 'a') != S.end()) {
            for (auto i : S) 
                if (i == 'a')
                    cout << i;
            for (auto i : S) 
                if (i == 'c')
                    cout << i;
            for (auto i : S) 
                if (i == 'b')
                    cout << i;
            for (auto i : S) 
                if (i - 'a' > 2)
                    cout << i;
        }
        else 
            cout << S;
        cout << '\n';
    }
}