#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    
    if(n>m){
        vector<int> temp = nums1;
        nums1 = nums2;
        nums2 = temp;

        n = nums1.size();
        m = nums2.size();
    }

    int mergedArrayLeftElements = (n+m+1)/2;

    //we are applying bs on the size of smaller array to pick out combinations of correct elements
    //since dono array sorted h isisliye jaha tk values pick krenge wo bhi sorted hoga
    int low = 0;
    int high = n;

    double median;

    while(low<=high)
    {
        int mid1 = low+(high-low)/2;
        int mid2 = mergedArrayLeftElements - mid1;

        //what if mid1 is 0? or mid1==n?
        int left1 = mid1-1<0 ? -1e9 : nums1[mid1-1]; //-1e9 isilye liya becoz ideally hum chahte h ki left1 chota ho right2 se
        int right1 = mid1==n ? 1e9: nums1[mid1];        //1e9 isilye liya becoz ideally hum chahte h ki left2 chota ho right1 se
        int left2 = mid2-1<0 ? -1e9 : nums2[mid2-1];   //same reason as above
        int right2 = mid2==m ? 1e9 : nums2[mid2];       //same reason as above

        // cout << left1 << " " << left2 << " " << right1 << " " << right2 << endl;

        if(left1 <= right2 && left2 <= right1){
            //1 hi unique formation banega
            if((n+m)%2==0){ //even length mein ye krenge becoz median would be formed of 2 elemnts 
                median = (double)(max(left1, left2)+min(right1, right2))/2.0;
            }else{
                median = max(left1, left2);
            }
            break; 
        }else if(left1 > right2){  //means humne nums1 k jayada elements le liye h
            high = mid1-1;  //toh kam krne h
        }else if(left2 > right1){  //nums2 k jayada le liya
            low = mid1+1;   //toh kam krne k liye mid1 ko badhana padega, thats why low=mid+1
        }
    }
    return median;
}

int main(){
    vector<int> arr1 = {1, 3 ,4, 7, 10, 12};
    vector<int> arr2 = {2, 3, 6, 15};

    cout << findMedianSortedArrays(arr1, arr2) << endl;
    return 0;
}