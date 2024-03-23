#include<bits/stdc++.h>
using namespace std;

void isPossible(int mat[MAX][MAX], int &n, int &k, int &count,int &mid){
    for(int i = 0; i<n; i++){
        count += (upper_bound(mat[i], mat[i]+n, mid) - mat[i]);
    }
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int low = mat[0][0];
    int high = mat[n-1][n-1];
    
    int res = -1;
    
    while(low<=high){
        int mid = low+(high-low)/2;
        
        int numbersLessThanMid = 0;
        isPossible(mat, n, k, numbersLessThanMid, mid);
        if(numbersLessThanMid < k){
            low = mid+1;
        }else{
            res = mid;
            high = mid-1;
        }
    }
    
    return res;
}

int main(){
    int mat[4][4] = {{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }};
    int k = 3;

    cout << kthSmallest(mat, 4, k);
    return 0;
}