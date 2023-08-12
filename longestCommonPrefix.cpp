#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int total = strs.size();

    if (total == 0)
        return "";

    int min_len = strs[0].size();
    for (int i = 0; i < total; i++)
    {
        if (strs[i].size() < min_len)
        {
            min_len = strs[i].size();
        }
    }

    bool stop = false;
    int prefix_len = 0;

    for (int i = 0; i < min_len; i++)
    {
        char ch = strs[0][i];

        for (int j = 1; j < total; j++)
        {
            if (strs[j][i] != ch)
            {
                stop = true;
                break;
            }
        }
        if (stop == true)
            break;
        else
        {
            prefix_len++;
        }
    }

    if (prefix_len == 0)
        return "";

    return strs[0].substr(0, prefix_len);
}

int main()
{

    vector<string> strs;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");

    string res = longestCommonPrefix(strs);
    cout << res << endl;
}