#include<iostream>

using namespace std;

int main () {
    int n;
    cin>>n;

    int arr[n];
    int target;
    int res[2];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cin>>target;

    sort(arr, arr+n);

    int l,r;
    l=0;
    r=n-1;

    while(l < r){
        if(arr[l] + arr[r] == target){
            res[0]=l;
            res[1]=r;
            break;
        } else if( arr[l] + arr[r] > target){
            r--;
        } else if( arr[l] + arr[r] < target){
            l++;
        }
    }
    
    cout<<"result : "<<res[0]<<" "<<res[1]<<endl;

    return 0;
}