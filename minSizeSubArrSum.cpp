/*
Given an array of positive integers nums and a positive integer target, 
return the minimal length of a subarray
whose sum is greater than or equal to target. 
If there is no such subarray, return 0 instead.

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
*/

#include<iostream>
#include<vector>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums){

   vector<int> arr_sum;
    int len = nums.size();
    for(int i=0; i < len; i++){
        if(i>0){
            arr_sum.push_back(arr_sum[i-1] + nums[i]);
        } else {
            arr_sum.push_back(nums[i]);
        }
    }

    if(arr_sum[len-1] < target){
        return 0;
    }

    if(arr_sum[len-1] == target){
        return len;
    }

    int l=0;
    int r=1;

    int min=len;
    for(int i=0; i < len; i++){
        if(i == 0){
            if(arr_sum[i] >= target){
                min=1;
                break;
            }
        } else {
            if(arr_sum[i] >= target){
                for(int j=i-1; j>=0; j--){
                    
                    if(arr_sum[i] - arr_sum[j] >= target){
                        if(i - j < min){
                            min = i-j;
                        }
                        break;
                    }

                }
                if(arr_sum[i] >= target){
                    if (i + 1 < min){
                        min = i+1;
                    }
                }
            }
        }
    }

    return min; 
}

int main(){

    int n, target, item;
    vector<int> arr;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> item;
        arr.push_back(item);
    }
    cin >> target;

    int res = minSubArrayLen(target, arr);

    cout << "result: " << res << endl;

    return 0;
}