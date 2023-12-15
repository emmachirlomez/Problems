#include<bits/stdc++.h>
using namespace std;

string destCity(vector<vector<string>>& paths) {
    unordered_set<string> cities;
    for (int i = 0; i < paths.size(); i++)
        cities.insert(paths[i][0]);
    for (int i = 0; i < paths.size(); i++)
        if (cities.find(paths[i][1]) == cities.end()) return paths[i][1];
    return "";
}

int main() {
    vector<vector<string>> paths = {{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
    string dest = destCity(paths);
    cout << dest << endl;
    return 0;
}