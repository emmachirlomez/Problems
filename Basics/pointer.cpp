#include <bits/stdc++.h>
using namespace std;

/**
 * char = 1 bytes               -2^7 ... 2^7 - 1
 * short = 2 bytes              -2^15 ... 2^15 - 1
 * unsigned short = 2 bytes      0.... 2^16 - 1
 * int = 4 bytes                -2^31 .... 2^31 - 1
 */

// ocupa 36 de bytes
/**
 * [][][][] - x
 * [][][][] - v
 * [][][][]
 * [][][][]
 * [][][][]
 * [][][][]
 * [][][][]
 * [][][][]
 * [][][][]
 * [][][][]
 * [][][][]
 */
int x;
int v[9];

int main()
{
    int x;
    int *v = &x;
    void *p = v;
    cout << "v: " << v << '\n';
    cout << "v: " << v + 1 << '\n';
    cout << "p: " << p + 1 << '\n';
    cout << "long long p: " << ((long long *)p) + 1 << '\n';
    cout << "long long p: " << (long long *)(p + 1) << '\n';
}