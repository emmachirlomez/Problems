#include <bits/stdc++.h>
using namespace std;

void LeftRightTopDown(int N, int M)
{
    for (int i = 0; i < N * M; i++)
        cout << i << ": " << "(" << i / M << "," << i % M << ")" << '\n';

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int poz = i * M + j;
            cout << poz << " ";
        }
        cout << '\n';
    }
}

void DownTopRightLeft(int N, int M)
{
    for (int i = 0; i < N * M; i++)
    {
        int poz_row = N - 1 - i % N;
        int poz_col = N - 1 - i / N;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int poz = M * N - 1 - j * N - i;
            cout << poz << " ";
        }
        cout << '\n';
    }
}

void RightLeftTopDown(int N, int M)
{
    for (int i = 0; i < N * M; i++)
    {
        int poz_row = i / M;
        int poz_col = M - 1 - i % M;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int poz = i * M + (M - 1 - j);
            cout << poz << " ";
        }
        cout << '\n';
    }
}

void MainDiagonals(int N, int M)
{
    for (int sum = 0; sum < N + M - 1; sum++)
    {
        for (int i = max(0, sum - M + 1); i < N && i <= sum; i++)
            cout << i << " " << sum - i << '\n';
    }
}

void ZigZag(int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << i << " " << (i % 2 == 0 ? j : M - 1 - j) << '\n';
        }
    }
}

void Circular(int N)
{
    int v_min = 0, v_max = N - 1;
    while (v_min < v_max)
    {
        for (int i = v_min; i < v_max; i++)
            cout << v_min << " " << i << '\n';
        for (int i = v_min; i < v_max; i++)
            cout << i << " " << v_max << '\n';
        for (int i = v_max; i > v_min; i--)
            cout << i << " " << v_max << '\n';
        for (int i = v_max; i > v_min; i--)
            cout << i << " " << v_min << '\n';

        v_min++, v_max--;
    }
}

void CircularTwo(int N, int M)
{
    pair<int, int> delta[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>> viz(N, vector<int>(M));
    function<bool(int, int)> isValid = [&](int i, int j)
    {
        if (i < 0 || i >= N)
            return false;
        if (j < 0 || j >= M)
            return false;
        return viz[i][j] == 0;
    };

    int state = 0;
    int x = 0, y = 0;
    while (true)
    {
        if (!isValid(x, y))
            break;
        cout << x << " " << y << '\n';
        viz[x][y] = 1;
        int next_x = x + delta[state].first;
        int next_y = y + delta[state].second;
        if (isValid(next_x, next_y))
        {
            x = next_x, y = next_y;
            continue;
        }
        state = (state + 1) % 4;
        x += delta[state].first;
        y += delta[state].second;
    }
}

int main()
{
    int N = 3, M = 6;
    CircularTwo(N, M);
}