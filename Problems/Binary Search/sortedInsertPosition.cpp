//https://www.interviewbit.com/problems/sorted-insert-position/

//https://www.interviewbit.com/problems/sorted-insert-position/

#include<iostream>
#include<vector>
using namespace std;

//using binary search :
int searchInsert(vector<int> &A, int B) {
    int low=0, high=A.size()-1;
    while(low<=high) {
        int mid=low+(high-low)/2;
        if(A[mid]==B) {
            return mid;
        }
        else if(A[mid]>B) {
            high=mid-1;
        } else {
            low=mid+1;
        }
    }
    return low;
}
