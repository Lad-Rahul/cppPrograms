#include <bits/stdc++.h>

using namespace std;

/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
The order of the elements may be changed.
Then return the number of elements in nums which are not equal to val.

Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).

*/

int removeElement(vector<int> &nums, int val)
{

    int final_index = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[final_index] = nums[i];
            final_index++;
        }
    }

    return final_index;
}

int main()
{
    int n, val, v;

    cout << "\nEnter n: ";
    cin >> n;

    vector<int> nums;

    cout << "\nEnter " << n << " Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        nums.push_back(v);
    }

    cout << "\nEnter value to remove: ";
    cin >> val;

    int result = removeElement(nums, val);

    cout << "\nResult: " << result << endl;

    return 0;
}