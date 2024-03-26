#include<bits/stdc++.h>
using namespace std;
void isPossible(vector<vector<int> > &A, int &count, int &n, int &mid){
    for(int i = 0; i<n; i++){
        count += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
    }
}

int findMedian(vector<vector<int> > &A) {
    int row = A.size();
    int col = A[0].size();
    
    // row*col will always be odd as mentioned in question

    int totElements = row*col;
    
    int k = (totElements+1)/2; //apply logic of 'kth element in matrix'
    
    int low = 1e9;
    int high = -1e9;
    
    for(int i = 0; i<row; i++){
        low = min(low, A[i][0]);
        high = max(high, A[i][col-1]);
    }
    
    int res = -1;
    
    while(low<=high){
        int mid = low+(high-low)/2;
        
        int count = 0;
        isPossible(A, count, row, mid);
        
        if(count < k){
            low = mid+1;
        }else{
            res = mid;
            high = mid-1;
        }
    }
    return res;
}

int main(){
    vector<vector<int>> mat = {   {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}   }

    cout << findMedian(mat) << endl;
    return 0;
}