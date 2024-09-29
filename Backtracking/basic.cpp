#include <bits/stdc++.h>
using namespace std;

struct Sudoku
{
    int tabla[9][9];

    Sudoku()
    {
        for (int i = 0; i < 9; i++)
            fill(tabla[i], tabla[i] + 9, 0);
    }

    bool isValid()
    {
        vector<vector<int>> frq_rows(9, vector<int>(9));
        auto frq_columns = frq_rows;
        vector<vector<vector<int>>> frq_squares(3, vector<vector<int>>(3, vector<int>(9)));

        for (int x = 0; x < 9; x++)
        {
            for (int y = 0; y < 9; y++)
            {
                // verify if table[x][y] is already repeated.
                int val = tabla[x][y];
                if (!val)
                    continue;
                val--;
                if (frq_rows[x][val])
                    return false;
                frq_rows[x][val] = 1;

                if (frq_columns[y][val])
                    return false;
                frq_columns[y][val] = 1;

                if (frq_squares[x / 3][y / 3][val])
                    return false;
                frq_squares[x / 3][y / 3][val] = 1;
            }
        }
        return true;
    }
};

bool solveSudoku(Sudoku &s, int x, int y)
{
    if (!s.isValid())
        return false;
    // if x = 9 we have finished.
    if (x == 9)
    {
        return true;
    }

    int next_x = x;
    int next_y = y + 1;
    if (next_y == 9)
        next_x = x + 1, next_y = 0;

    // If s[x][y] is already filled, we do nothing.
    if (s.tabla[x][y])
        return solveSudoku(s, next_x, next_y);

    // We try to solve this cell.
    for (int i = 1; i <= 9; i++)
    {
        s.tabla[x][y] = i;
        // puttnig an i there works
        if (solveSudoku(s, next_x, next_y))
            return true;
    }
    s.tabla[x][y] = 0;
    return false;
}

int main()
{
}