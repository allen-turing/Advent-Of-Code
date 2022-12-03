#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int count = 0;

    fstream file;

    string fileName = "in.txt";
    file.open(fileName.c_str());

    string user1;
    int cc = 0;

    while (file >> user1)
    {
        unordered_set<char> s1, s2;
        for (int i = 0; i < user1.length() / 2; i++)
        {
            s1.insert(user1[i]);
        }

        for (int i = user1.length() / 2; i < user1.length(); i++)
        {
            s2.insert(user1[i]);
        }
        for (auto s1c : s1)
        {

            if (s2.count(s1c))
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

    cout << "Total Score is : " << count << "\n";
    return 0;
}
