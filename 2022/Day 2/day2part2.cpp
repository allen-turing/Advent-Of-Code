#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int count = 0;

    fstream file;

    string fileName = "day2Input2.txt";
    file.open(fileName.c_str());

    string user1, user2;
    while (file >> user1 >> user2)
    {
        // checking against Rock
        if (user1 == "A")
        {
            if (user2 == "X")
            {
                count += 0;
                count += 3;
            }
            else if (user2 == "Y")
            {
                count += 3;
                count += 1;
            }
            else
            {
                count += 6;
                count += 2;
            }
        }
        // checking against paper
        else if (user1 == "B")
        {
            if (user2 == "X")
            {
                count += 0;
                count += 1;
            }
            else if (user2 == "Y")
            {
                count += 3;
                count += 2;
            }
            else
            {
                count += 6;
                count += 3;
            }
        }
        // check against scissor
        if (user1 == "C")
        {
            if (user2 == "X")
            {
                count += 0;
                count += 2;
            }
            else if (user2 == "Y")
            {
                count += 3;
                count += 3;
            }
            else
            {
                count += 6;
                count += 1;
            }
        }
    }
    cout << "Total Score is : " << count << "\n";
    return 0;
}
