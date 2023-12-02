#include <bits/stdc++.h>
using namespace std;

void insertIntoSet(unordered_map<string,string> &u)
{
    u["one"]="1";
    u["two"]="2";
    u["three"]="3";
    u["four"]="4";
    u["five"]="5";
    u["six"]="6";
    u["seven"]="7";
    u["eight"]="8";
    u["nine"]="9";
}

int main(int argc, char const *argv[])
{
    string str;
    int res = 0;
    unordered_map<string,string> u;

    insertIntoSet(u);

    fstream file;
    string fileName = "in";
    file.open(fileName.c_str());

    int lineNo = 1;

    while (file >> str)
    {
        int length = str.size();

        string num = "";
        int isfoundStart = 0, isfoundEnd = 0;
        for (int index = 0; index < length; index++)
        {
            if (isdigit(str[index]))
            {
                num += str[index];
                break;
            }
            for (int id = 1; id <= length; id++)
            {
                string subs = str.substr(index, id);
                if(u.count(subs))
                {
                    num += u[subs];
                    isfoundStart = 1;
                    break;
                }
            }
            if(isfoundStart)
                break;
        }
        for (int index = length-1; index > -1; index--)
        {
            if (isdigit(str[index]))
            {
                num += str[index];
                break;
            }
            for (int id = index; id > -1; id--)
            {
                int len = index - id+1;
                string subs = str.substr(id, len);
                if(u.count(subs))
                {
                    num += u[subs];
                    isfoundEnd = 1;
                    break;
                }
            }
            if(isfoundEnd)
                break;
        }
        res += stoi(num);
        str.clear();
    }
    cout<< res<<"\n";
}
