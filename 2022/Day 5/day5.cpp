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
    vector<stack<char>> cargo;
    stack<char> item1;

    item1.push('B');
    item1.push('W');
    item1.push('N');

    stack<char> item2;
    item2.push('L');
    item2.push('Z');
    item2.push('S');
    item2.push('P');
    item2.push('T');
    item2.push('D');
    item2.push('M');
    item2.push('B');

    stack<char> item3;
    item3.push('Q');
    item3.push('H');
    item3.push('Z');
    item3.push('W');
    item3.push('R');

    stack<char> item4;
    item4.push('W');
    item4.push('D');
    item4.push('V');
    item4.push('J');
    item4.push('Z');
    item4.push('R');

    stack<char> item5;
    item5.push('S');
    item5.push('H');
    item5.push('M');
    item5.push('B');

    stack<char> item6;
    item6.push('L');
    item6.push('G');
    item6.push('N');
    item6.push('J');
    item6.push('H');
    item6.push('V');
    item6.push('P');
    item6.push('B');

    stack<char> item7;
    item7.push('J');
    item7.push('Q');
    item7.push('Z');
    item7.push('F');
    item7.push('H');
    item7.push('D');
    item7.push('L');
    item7.push('S');

    stack<char> item8;
    item8.push('W');
    item8.push('S');
    item8.push('F');
    item8.push('J');
    item8.push('G');
    item8.push('Q');
    item8.push('B');

    stack<char> item9;
    item9.push('Z');
    item9.push('W');
    item9.push('M');
    item9.push('S');
    item9.push('C');
    item9.push('D');
    item9.push('J');

    stack<char> emptyItem;

    cargo.push_back(emptyItem);
    cargo.push_back(item1);
    cargo.push_back(item2);
    cargo.push_back(item3);
    cargo.push_back(item4);
    cargo.push_back(item5);
    cargo.push_back(item6);
    cargo.push_back(item7);
    cargo.push_back(item8);
    cargo.push_back(item9);

    string mv = "",
           cargoItem = "", from = "", to = "";
    int cc = 0;
    while (file >> mv >> cargoItem >> mv >> from >> mv >> to)
    {
        int crgI = stoi(cargoItem);
        int fromI = stoi(from);
        int toI = stoi(to);
        while (crgI--)
        {
            char cargItem = cargo[fromI].top();
            cargo[toI].push(cargItem);
            cargo[fromI].pop();
        }
    }

    cout << "Result is : ";
    for (int i = 1; i < cargo.size(); i++)
    {
        cout << cargo[i].top();
    }
    return 0;
}
