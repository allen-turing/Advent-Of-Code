#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string str;
    int res = 0;
    fstream file;

    string fileName = "in.txt";
    file.open(fileName.c_str());
    while (file >> str)
    {
        int length = str.size();
        int i = 0,j = length;

        string num = "";
        
        while(i < length)
        {
            if(isdigit(str[i]))
            {
                num += str[i];
                break;
            }
            i++;
        }
        while(j>= 0)
        {
            if(isdigit(str[j]))
            {
                num += str[j];
                break;
            }
            j--;
        }
        res += stoi(num);
        num = "";
    }
    cout << res<<"\n";
}
