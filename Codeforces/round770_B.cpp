#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        long long n, d, y;
        cin >> n >> d >> y;
        long long sum = 0;
        while (n--) {
            long long a;
            cin >> a;
            sum += a;
        }
        if (1LL * (sum + d + y) % 2 == 0)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    
    }
    return 0;
}