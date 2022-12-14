#include <bits/stdc++.h>

using namespace std;

int convertToNumber(string s)
{
    return stoi(s);
}

int main(int argc, char const *argv[])
{
    long long count = 1;

    // fstream file;

    // string fileName = "in.txt";
    // file.open(fileName.c_str());
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string inp;
    set<pair<int, int>> blocked;
    int MAX_Y = 0;
    while (getline(cin, inp))
    {
        istringstream input;
        input.str(inp);

        int X, Y;
        char coma;
        input >> X >> coma >> Y;
        string arrow;
        int x, y;
        while (input >> arrow >> x >> coma >> y)
        {
            int minX = min(X, x), maxX = max(X, x);
            int minY = min(Y, y), maxY = max(Y, y);
            MAX_Y = max(MAX_Y, maxY);
            for (int i = minX; i <= maxX; i++)
            {
                for (int j = minY; j <= maxY; j++)
                {
                    blocked.emplace(i, j);
                }
            }
            X = x;
            Y = y;
        }
    }

    MAX_Y += 2;
    unordered_set<int> air;
    air.emplace(500);
    for (int y = 1; y < MAX_Y; y++)
    {
        unordered_set<int> airNextRow;
        for (auto x : air)
        {
            if (blocked.count({x - 1, y}) == false)
                airNextRow.emplace(x - 1);
            if (blocked.count({x, y}) == false)
                airNextRow.emplace(x);
            if (blocked.count({x + 1, y}) == false)
                airNextRow.emplace(x + 1);
        }
        count += airNextRow.size();
        swap(air, airNextRow);
    }
    cout << "Result is : " << count;
    return 0;
}
