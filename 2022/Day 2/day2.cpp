#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    int count = 0;

    while(getline(cin,str))
    {
        stringstream s(str);

        string user1,user2;
        s >> user1;
        s >> user2;

        // checking against Rock
        if(user1=="A")
        {
            if(user2 == "X")
            {
                count += 3;
                count += 1;
            }
            else if(user2 == "Y")
            {
                count += 6;
                count += 2;
            }
            else
            {
                count += 0;
                count += 3;
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
                count += 6;
                count += 1;
            }
            else if (user2 == "Y")
            {
                count += 0;
                count += 2;
            }
            else
            {
                count += 3;
                count += 3;
            }
        }
    }
    cout << "Total Score is : " << count << "\n";
    return 0;
}
