#include<bits/stdc++.h>
using namespace std;


bool isBounddaryHasSymbol(int a, int b, string &prevRow,string &nextRow)
{
    for (int i = a - 1; i <= b + 1; i++)
    {
        if(prevRow[i]!='.' && !isdigit(prevRow[i])) // uperRow
        {
            //cout << "pat " << prevRow[i] << "\n";
            return true;
        }
        if(nextRow[i]!='.' && !isdigit(nextRow[i])) // dowRow
        {
            //cout << "pat " << nextRow[i] << "\n";
            return true;
        }
    }
    return false;
}

int main()
{
    /* code */
    int total = 0;
    fstream file;
    string fileName = "in";
    file.open(fileName.c_str());
    string str;
    file >> str;
    str = "." + str + ".";
    string previos = ".";
    for (int i = 0; i < str.size();i++)
    {
        previos += ".";
    }
    previos += ".";
    string next = "";
    file >> next;
    next = "." + next + ".";
    for (int i = 1; i < str.size()-1; i++)
    {
        if(isdigit(str[i]))
        {
            string number = "";
            int strartIndex = i;
            while(isdigit(str[i]))
            {
                number += str[i++];
            }
            int endIndex = i-1;
            if(str[strartIndex-1]!='.' || str[endIndex+1]!='.'  || isBounddaryHasSymbol(strartIndex,endIndex,previos,next))
            {
                //cout << "Number foud = " << number << " [" << strartIndex << "," << endIndex << "]\n";
                total += stoi(number);
            }
        }
    }
    previos = str;
    str = next;
    while (file >> next)
    {
        next = "." + next + ".";
        for (int i = 1; i < str.size()-1; i++)
        {
            if(isdigit(str[i]))
            {
                string number = "";
                int strartIndex = i;
                while(isdigit(str[i]))
                {
                    number += str[i++];
                }
                int endIndex = i-1;
                if(str[strartIndex-1]!='.' || str[endIndex+1]!='.' || isBounddaryHasSymbol(strartIndex,endIndex,previos,next))
                {
                    //cout << "Number foud = " << number << " [" << strartIndex << "," << endIndex << "]\n";
                    total += stoi(number);
                }
            }
        }
        previos = str;
        str = next;
    }
    next = "";
    for (int i = 0; i < str.size();i++)
    {
        next += ".";
    }
    next = "." + next + ".";
    for (int i = 1; i < str.size()-1; i++)
    {
        if(isdigit(str[i]))
        {
            string number = "";
            int strartIndex = i;
            while(isdigit(str[i]))
            {
                number += str[i++];
            }
            int endIndex = i-1;
            if(str[strartIndex-1]!='.' || str[endIndex+1]!='.' || isBounddaryHasSymbol(strartIndex,endIndex,previos,next))
            {
                //cout << "Number foud = " << number << " [" << strartIndex << "," << endIndex << "]\n";
                total += stoi(number);
            }
        }
    }
    cout << "Total " << total;
    return 0;
}