#include <bits/stdc++.h>
using namespace std;

// We are given N, we want to print all permutations 0...N-1.

int perm[100];
int frq[100];

/**
 * This function N length of permutation and poz the position we need to set.
 * if poz == N it means all pozitions are set so we just check.
 * poz < N => positions perm[0], perm[1]...perm[poz-1] are already set.
 */
void AllPermutations(int poz, int N)
{
    // we want to see we are at the end.
    if (poz == N)
    {
        for (int i = 0; i < N; i++)
            cout << perm[i] << " ";
        cout << '\n';
        return;
    }

    // we try every single possible value for perm[poz].
    for (int i = 0; i < N; i++)
    {
        if (!frq[i])
        {
            perm[poz] = i;
            frq[i]++;
            AllPermutations(poz + 1, N);
            frq[i]--;
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    AllPermutations(0, N);
}
