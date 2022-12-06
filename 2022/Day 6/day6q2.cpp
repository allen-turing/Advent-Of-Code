#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    fstream file;

    string fileName = "in.txt";
    file.open(fileName.c_str());
    string inp;
    int count = 0;
    while (file >> inp)
    {
        count++;
        for (int i = 0; i < inp.size(); i++)
        {
            set<char> ss;

            for (int j = i; j < i + 14 && j < inp.size(); j++)
            {
                ss.insert(inp[j]);
            }
            if (ss.size() == 14)
            {
                cout << i + 14 << "\n";
                break;
            }
        }
    }
    return 0;
}
