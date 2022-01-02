#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if (n % 2 == 0)
            cout << n - 3 << " " << 2 << " " << 1 << '\n';
        else { 
            int x = n -1;
            if (x / 2 % 2 == 0) 
                cout << x / 2 - 1 << " " << x / 2 + 1 << " " << 1 << '\n';
            else
                cout << x / 2 - 2 << " " << x / 2 + 2 << " " << 1 << '\n';
        }
            
        
    }
}