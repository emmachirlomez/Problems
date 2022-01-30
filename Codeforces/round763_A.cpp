#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m, r_b, c_b, r_d, c_d;
        cin >> n >> m >> r_b >> c_b >> r_d >> c_d;
        int time_x = 0;
        int time_y = 0;
        if (r_b <= r_d)
            time_x = r_d - r_b;
        else
            time_x = 2 * n - r_b - r_d;
        if (c_b <= c_d)
            time_y = c_d - c_b;
        else
            time_y = 2 * m - c_d - c_b;
        cout << min(time_x, time_y) << '\n';
    }
}