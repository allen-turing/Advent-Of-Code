#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string str;
    vector<vector<int>> elf;
    int maxCalorie = 0;
    int sum = 0;
    vector<int> result;
    
    while(getline(cin, str))
    {
        if(str.empty())
        {
            maxCalorie = max(maxCalorie, sum);
            result.push_back(sum);
            sum = 0;
        }
        else
        {
            int num = stoi(str);
            sum += num;
        }        
    }

    sort(result.begin(), result.end(),greater<int>());
    cout <<"Top 3 are : "<< result[0]<<" "<<result[1] << " " << result[2] << "\n";
    int rsum = result[1] + result[2] + result[0];
    cout << "Top sum are : " <<rsum << "\n";
    cout << "Max is " << maxCalorie<<"\n";

    return 0;
}
