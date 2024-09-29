#include <iostream>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    for (int mask = 0; mask < (1 << N); mask++)
    {
        printf("Mask = %d: ", mask);
        for (int bit = 0; bit < N; bit++)
        {
            int new_number = (1 << bit);
            if (new_number & mask)
                printf("%d ", bit);
        }
        printf("\n");
    }
}