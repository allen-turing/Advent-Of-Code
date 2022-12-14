#include <bits/stdc++.h>

using namespace std;

int convertToNumber(string s)
{
    return stoi(s);
}

int main(int argc, char const *argv[])
{
    long long count = 0;

    // fstream file;

    // string fileName = "in.txt";
    // file.open(fileName.c_str());
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string inp;
    set<pair<int, int>> blocked;
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
    int X, Y;
    while (true)
    {
        X = 500;
        Y = 0;
        while (Y < 600)
        {
            if (blocked.count({X, Y + 1}) == false)
            {
                Y++;
            }
            else if (blocked.count({X - 1, Y + 1}) == false)
            {
                X--;
                Y++;
            }
            else if (blocked.count({X + 1, Y + 1}) == false)
            {
                X++;
                Y++;
            }
            else
            {
                break;
            }
        }
        if (Y >= 600)
            break;
        count++;
        blocked.emplace(X, Y);
    }

    cout << "Result is : " << count;
    return 0;
}
