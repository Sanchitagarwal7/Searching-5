#include<bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    if(n>m){
        return kthElement(arr2, arr1, m, n, k);
    }

    //i have the length of left half as k length

     //maybe k is greater than m, toh arr2  k saare elements ko lene k liye k-m elements ko arr1 se lena hi padega
    int low = max(0, k-m);
    int high = min(n, k); //for k less than n size,
    
    // int res = -1;

    while(low<=high){
        int mid1 = low+(high-low)/2;
        int mid2 = k-mid1;

        int left1 = (mid1-1<0) ? -1e9 : arr1[mid1-1];
        int right1 = (mid1==n) ? 1e9 : arr1[mid1]; 
        int left2 = (mid2-1<0) ? -1e9 : arr2[mid2-1];
        int right2 = (mid2==m) ? 1e9 : arr2[mid2];

        if(left1 <= right2 && left2 <= right1){
            //that means merged array is sorted
            //since left half is of k size, then the last element of that subarray will be the kth element
            return max(left1, left2);
        }else if(left1 > right2){
            //i took more elements from arr1
            high = mid1-1;
        }else if(left2 > right1){
            //i took more elements from arr2
            low = mid1+1;
        }
    }

    return 0;
}

int main(){
    vector<int> arr1 = {76, 94, 100};
    vector<int> arr2 = {5, 5, 9, 11, 31, 36, 68, 71, 75};
    int k = 12;

    cout << kthElement(arr1, arr2, k) << endl;

    return 0;
}