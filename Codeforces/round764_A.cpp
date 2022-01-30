#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int minimum = 1e9 + 10;
        int maximum = 0;
        while (n--) {
            int a;
            cin >> a;
            minimum = min(minimum, a);
            maximum = max(maximum, a);
        }
        cout << maximum - minimum << '\n';
    }
}