#include <bits/stdc++.h>

using namespace std;

int convertToNumber(string s)
{
    return stoi(s);
}

int main(int argc, char const *argv[])
{
    int count = 0;

    fstream file;

    string fileName = "in.txt";
    file.open(fileName.c_str());

    string user1;
    while (file >> user1)
    {
        int i = 0;
        string num1begin = "", num1end = "", num2begin = "", num2end = "";
        while (i < user1.size())
        {
            while (user1[i] != '-')
            {
                num1begin += user1[i++];
            }
            i++;
            while (user1[i] != ',')
            {
                num1end += user1[i++];
            }
            i++;
            while (user1[i] != '-')
            {
                num2begin += user1[i++];
            }
            i++;
            while (i < user1.size())
            {
                num2end += user1[i++];
            }
        }
        int n1b = stoi(num1begin), n1e = stoi(num1end), n2b = stoi(num2begin), n2e = stoi(num2end);

        if (n1b <= n2b && n1e >= n2e)
            count++;
        else if (n2b <= n1b && n2e >= n1e)
            count++;
        else if (n2b <= n1e && n2e >= n1e)
            count++;
        else if (n1b <= n2e && n1e >= n2b)
            count++;
    }

    cout << "Total Score is : " << count << "\n";
    return 0;
}
