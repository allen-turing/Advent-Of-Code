#include <bits/stdc++.h>

using namespace std;

void findStartingAndEndingPoint(int &Sx, int &Sy, int &Ex, int &Ey, vector<string> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            if (v[i][j] == 'S')
            {
                Sx = i;
                Sy = j;
                v[i][j] = 'a';
            }
            if (v[i][j] == 'E')
            {
                Ex = i;
                Ey = j;
                v[i][j] = 'z';
            }
        }
    }
}

bool isValidCordinates(int x, int y, int R, int C)
{
    return x >= 0 && x < R && y >= 0 && y < C;
}

int main(int argc, char const *argv[])
{
    int count = 0;

    fstream file;

    string fileName = "in.txt";
    file.open(fileName.c_str());
    string inp;
    vector<string> v;
    while (file >> inp)
    {
        v.push_back(inp);
    }
    int R = v.size(), C = v[0].size();
    int Sx, Sy, Ex, Ey;
    findStartingAndEndingPoint(Sx, Sy, Ex, Ey, v);

    vector<vector<int>> distance(R, vector<int>(C, INT_MAX));

    queue<pair<int, int>> q;
    q.push({Sx, Sy});
    distance[Sx][Sy] = 0;

    int dirX[] = {-1, 0, 1, 0};
    int dirY[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x1 = x + dirX[i], y1 = y + dirY[i];
            if (isValidCordinates(x1, y1, R, C))
            {
                if (v[x1][y1] <= v[x][y] + 1)
                {
                    if (distance[x1][y1] > distance[x][y] + 1)
                    {
                        distance[x1][y1] = distance[x][y] + 1;
                        q.push({x1, y1});
                    }
                }
            }
        }
    }

    freopen("out.txt", "w", stdout);

    cout
        << "Result is : " << distance[Ex][Ey];

    return 0;
}
