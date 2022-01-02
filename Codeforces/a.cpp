#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fii;
vector<int> dist;

void DFS(int node)
{
    for (auto fiu : fii[node]) {
        dist[fiu] = dist[node] + 1;
        DFS(fiu);
    }

}

int main()
{
    int n;
    cin >> n;
    fii.resize(n + 1);
    vector<int> has_father(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        has_father[b] = 1;
        fii[a].push_back(b);
    }

    int root = -1;
    for (int i = 1; i < n + 1; i++) {
        if (has_father[i] == 0) {
            assert(root == -1);
            root = i;
        }
    }
    assert(root != -1);
    DFS(root);
}