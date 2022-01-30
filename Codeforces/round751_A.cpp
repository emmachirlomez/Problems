#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string a, b;
        char min = '~'; 
        int poz;
        for (int i = 0; i < (int)s.size(); i++)
            if (s[i] - 'a' <= min - 'a')
                min = s[i], poz = i;
        a = min;
        for (int i = 0; i < (int)s.size(); i++)
            if (i != poz)
                b.push_back(s[i]);
        cout << a << " "<< b << '\n';
    }
}