#include <algorithm>
#include<bits/stdc++.h>
#include <random>
using namespace std;

/**
 * Functia sorteaza v[0], v[1]..., v[len - 1]
 * Alegem un element random numit pivot
 * punem in stanga elementele < pivot 
 * punem in dreapta elementele >= pivot
 * sortam recursiv stanga si dreapta
 */
void QuickSort(int* v, int len) {
    if (len <= 1)
        return;

    // Alegem un pivot random si mutam la inceput.
    int pivot = v[rand() % len];
    int head = -1;

    // Iteram victor folosing 2 pointers si 
    // mutam elementele < cu v[pivot] in stanga pivotului.    
    for (int i = 0; i < len; i++) {
        if (v[i] < pivot) {
            head++;
            swap(v[i], v[head]);
        }
    }

    // Apelam recursiv functia cu vectorul din stanga lui pivot.
    QuickSort(v, head + 1);

    // Apelam recursiv functia cu vectorul din dreapta lui pivot.
    QuickSort(v + head + 1, len - head - 1);
}

void TestQuickSort() {
    vector<int> v(100);
    for (int i = 0; i < 100; i++)
        v[i] = i + 1;
    
    mt19937 rng(234);
    shuffle(v.begin(), v.end(), rng);

    QuickSort(v.data(), (int)v.size());
    assert(is_sorted(v.begin(), v.end()));
}

int main() {
    TestQuickSort();
}