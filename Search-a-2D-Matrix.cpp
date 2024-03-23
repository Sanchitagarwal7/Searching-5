#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(int *arr, int target) {
    int n = 3;
    int m = 4;

    //1-d array assume krke chlo toh ss 0-m*n-1 hogi

    int low = 0;
    int high = m*n-1;

    while(low<=high){

        int mid = low+(high-low)/2;
        //ab agr midth element nikaalna h assumed 1d array mein toh ye formula banega
        int cell = matrix[mid/m][mid%m];    

        if(cell == target) return true;
        else if(cell < target){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return false;
}

int main(){
    int arr[3][4] = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;

    cout << searchMatrix(arr, target) << endl;
    return 0;
}