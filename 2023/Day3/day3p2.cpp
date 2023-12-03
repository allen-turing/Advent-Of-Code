// #include<bits/stdc++.h>
// using namespace std;

// bool isOnlyTwoNubers(vector<vector<char>> &v, int r, int c)
// {
//     int x[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
//     int y[] = { -1,  0,  1, -1, 1, -1, 0, 1 };
//     int count = 0;
//     vector<int> nums;
//     for (int i = 0; i < 8; i++)
//     {
//         for (int j = 0; j < 8; j++)
//         {
//             int rn = r + x[i];
//             int cn = c + y[j];
//             char ch = v[rn][cn];
//             if(isdigit(ch))
//             {
                
//             }
//         }
        
//     }
// }

// int main(int argc, char const *argv[])
// {
//     int total = 0;
//     fstream file;
//     string fileName = "in";
//     file.open(fileName.c_str());
//     string str;
//     vector<vector<char>> v;
//     while(file >> str)
//     {
//         vector<char> v1(str.begin(), str.end());
//         v.push_back(v1);
//     }

//     for (int i = 0; i < v.size();i++)
//     {
//         for (int j = 0; j < v[0].size(); j++)
//         {
//             if(v[i][j] == '*')
//             {
//                 bool isOnlyTwoNubers = isOnlyTwoNubers(v, i, j);
//             }
//         }
        
//     }

//         return 0;
// }
