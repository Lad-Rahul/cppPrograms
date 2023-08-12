#include <iostream>
#include <map>
using namespace std;

/*
M - 1000
D - 500
C - 100
L - 50
X - 10
V - 5
I - 1

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.

III - 3
LVIII - 58
MCMXCIV - 1994
*/

int romanToInt(string roman)
{
    int number = 0;
    map<char, int> valueMap;

    valueMap['I'] = 1;
    valueMap['V'] = 5;
    valueMap['X'] = 10;
    valueMap['L'] = 50;
    valueMap['C'] = 100;
    valueMap['D'] = 500;
    valueMap['M'] = 1000;

    int len = roman.size();

    for (int i = 0; i < len; i++)
    {
        if ((i < (len - 1)) && (valueMap[roman[i]] < valueMap[roman[i + 1]]))
        {
            number -= valueMap[roman[i]];
        }
        else
        {
            number += valueMap[roman[i]];
        }
    }

    return number;
}

int main()
{

    string roman;
    cin >> roman;
    int number = romanToInt(roman);
    cout << number << endl;
}