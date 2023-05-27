#include <bits/stdc++.h>
using namespace std;
using intl = long long int;

bool branchAndBound(int row, int col, vector<string> &grid)
{
    int dupRow = row;
    int dupCol = col;

    while (col--)
    {
        if (grid[row][col] == 'Q')
            return false;
    }
    col = dupCol;
    while (row-- && col--)
    {
        if (grid[row][col] == 'Q')
            return false;
    }
    col = dupCol;
    row = dupRow;
    while (row < grid.size() && col >= 0)
    {
        if (grid[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}
void backTrack(int col, vector<string> &grid, vector<vector<string>> &ans)
{
    if (col == grid.size())
    {
        ans.push_back(grid);
        return;
    }

    for (int row = 0; row < grid.size(); row++)
    {

        if (branchAndBound(row, col, grid))
        {
            grid[row][col] = 'Q';
            backTrack(col + 1, grid, ans);
            grid[row][col] = '_';
        }
    }
}
int main()
{
    int n = 4;
    vector<string> grid(n);
    string s = "";
    for (int i = 0; i < n; i++)
    {
        s += '_';
    }
    for (int i = 0; i < n; i++)
    {
        grid[i] = s;
    }
    vector<vector<string>> ans;

    backTrack(0, grid, ans);

    for (auto &x : ans)
    {
        for (auto &y : x)
        {
            for (auto &z : y)
            {
                cout << z << "  ";
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }

    return 0;
}