#include <bits/stdc++.h>

using namespace std;

void print(vector<string> v)
{
    for (auto vi : v)
    {
        cout << vi << "\n";
    }
}

vector<string> SplitThePacksts(string &packet)
{
    vector<string> result;
    string current;
    int bracketCount = 0;

    for (int i = 1; i < packet.size() - 1; i++)
    {
        if (packet[i] == '[')
            bracketCount++;
        if (packet[i] == ']')
            bracketCount--;
        if (!bracketCount && packet[i] == ',')
        {
            result.push_back(current);
            current.clear();
        }
        else
        {
            current += packet[i];
        }
    }
    if (!current.empty())
        result.push_back(current);
    return result;
}

int VerifyPackets(string &packet1, string &packet2)
{
    if (packet1.empty())
        return -1;
    if (packet2.empty())
        return 1;
    bool bracketsPacket1 = 0, bracketsPacket2 = 0;
    if (packet1[0] == '[' && packet1.back() == ']')
        bracketsPacket1 = true;
    if (packet2[0] == '[' && packet2.back() == ']')
        bracketsPacket2 = true;
    if (bracketsPacket1 || bracketsPacket2)
    {
        if (bracketsPacket1 == false)
        {
            packet1 = "[" + packet1 + "]";
        }
        if (bracketsPacket2 == false)
        {
            packet2 = "[" + packet2 + "]";
        }

        vector<string> packet1Remains = SplitThePacksts(packet1);
        vector<string> packet2Remains = SplitThePacksts(packet2);
        // print(packet1Remains);
        // print(packet2Remains);

        int minSizePacket = min(packet1Remains.size(), packet2Remains.size());

        for (int i = 0; i < minSizePacket; i++)
        {
            int result = VerifyPackets(packet1Remains[i], packet2Remains[i]);
            if (result)
                return result;
        }
        if (packet1Remains.size() < packet2Remains.size())
            return -1;
        if (packet1Remains.size() > packet2Remains.size())
            return 1;
        return 0;
    }
    else
    {
        if (stoi(packet1) < stoi(packet2))
            return -1;
        if (stoi(packet1) > stoi(packet2))
            return 1;
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    int total = 0, index = 1;

    fstream file;

    string fileName = "in.txt";
    freopen("out.txt", "w", stdout);

    file.open(fileName.c_str());
    string packet1, packet2, emptyLine;

    while (file >> packet1 >> packet2)
    {
        int result = VerifyPackets(packet1, packet2);
        // cout << "Result each " << result << "\n";
        if (result <= 0)
            total += index;
        index++;
    }

    cout << "Result is : " << total << "\n";
    return 0;
}
