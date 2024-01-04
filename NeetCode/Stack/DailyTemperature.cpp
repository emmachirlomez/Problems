#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<pair<int, int>> temps;
    vector<int> ans(temperatures.size());

    for (int i = 0; i < temperatures.size(); i++) {
        int currentDay = i;
        int currentTemp = temperatures[i];

        while(!temps.empty() && temps.top().second < currentTemp)  {
            int prevDay = temps.top().first;
            int prevTemp = temps.top().second;
            temps.pop();
            ans[prevDay] = currentDay - prevDay;
        }

        temps.push({currentDay, currentTemp});
    }
    return ans;

}

int main() {
    return 0;
}