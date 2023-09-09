#include <bits/stdc++.h>

using namespace std;

/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
 

Follow up: Can you come up with an algorithm that runs in O(m + n) time?

easy approach: add 2nd array items in 1st and then sort array. O(nlogn)

*/

void merge(vector <int>& nums1, int m, vector <int>& nums2, int n) {


    int ptr_m = m-1;
    int ptr_n = n-1;
    int ptr_m_n = m+n-1;
    
    while(ptr_n >= 0){
        if(ptr_m >= 0 && nums1[ptr_m] > nums2[ptr_n]){
            nums1[ptr_m_n] = nums1[ptr_m];
            ptr_m--;
        }else {
            nums1[ptr_m_n] = nums2[ptr_n];
            ptr_n--;
        }
        ptr_m_n--;
    }

}


int main(){

    int m,n,v;

    cout<<"\nEnter m: ";
    cin>>m;

    cout<<"\nEnter n: ";
    cin>>n;

    vector<int> nums1;
    vector<int> nums2;

    cout<<"\nEnter "<<m<<" items: ";
    for(int i=0; i<m; i++){
        cin>>v;
        nums1.push_back(v);
    }

    cout<<"\nEnter "<<n<<" items: ";
    for(int i=0; i<n; i++){
        cin>>v;
        nums2.push_back(v);
        nums1.push_back(0);
    }

    merge(nums1, m, nums2, n);

    cout<<"\nResult: ";
    for(int i=0; i<m+n; i++){
        cout<<nums1[i]<<" ";
    };

    return 0;
}