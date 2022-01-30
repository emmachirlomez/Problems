#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t ;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> array(n + 1);
        vector<int> frq(n + 1);
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            array[i] = a;
            frq[a]++;
        }
        int q;
        cin >> q;
        while(q--) {
            int x, k;
            cin >> x >> k;
            int act = 0;
            while(true) {
                if (array == frq)
                    break;
                if (act == k)
                    break;
                for (int i = 1; i <= n; i++)
                    array[i] = frq[array[i]];   
                for (int i = 1; i <= n; i++)
                    frq[i] = 0;
                for (int i = 1; i <= n; i++)
                    frq[array[i]]++;
                act++;
            }
            cout << array[x] << '\n';
        }
    }
    // NOT DONE
}