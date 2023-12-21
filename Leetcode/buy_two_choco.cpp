#include<bits/stdc++.h>
using namespace std;

int buyChoco(vector<int>& prices, int money) {
    int min_1 = INT_MAX;
    int min_2 = INT_MAX;

    int min_1_counter = 0;

    for (auto i : prices)
        min_1 = min(min_1, i);
    
    for (auto i : prices) {
        if (i == min_1) {
            min_1_counter++;
            if (min_1_counter == 1)
                continue;
        }
        min_2 = min(min_2, i);
    }

    if (min_1 == INT_MAX || min_2 == INT_MAX || money - min_1 - min_2 < 0)
        return money;
    return money - min_1 - min_2;
}

int main() {
    return 0;
}