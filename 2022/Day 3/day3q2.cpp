#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int count = 0;

    fstream file;

    string fileName = "in2.txt";
    file.open(fileName.c_str());

    string group1;
    string group2;
    string group3;

    while (file >> group1 >> group2 >> group3)
    {
        unordered_set<char> s1, s2, s3;
        for (int i = 0; i < group1.length(); i++)
        {
            s1.insert(group1[i]);
        }

        for (int i = 0; i < group2.length(); i++)
        {
            s2.insert(group2[i]);
        }

        for (int i = 0; i < group3.length(); i++)
        {
            s3.insert(group3[i]);
        }

        for (auto s1c : s1)
        {
            if (s2.count(s1c))
            {
                if (s3.count(s1c))
                {
                    if (s1c >= 97 && s1c <= 122)
                    {
                        count += s1c - 'a' + 1;
                    }
                    else
                    {
                        count += s1c - 'A' + 27;
                    }
                }
            }
        }
    }

    cout << "Total Score is : " << count << "\n";
    return 0;
}
