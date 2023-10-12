
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;
//https://leetcode.com/problems/find-in-mountain-array/
// approch : first get the peak of the mountain
// searh from 0 to peak and peak+1 to n-1
// return minimum index or -1(if target not found both side)

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak;
        int n = mountainArr.length();
        int low=0, high=n-1, mid;
        while(low<=high) {
            mid=low+(high-low)/2;
            if(mountainArr.get(mid)>mountainArr.get(mid+1)) {
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        peak = mid;
        int leftIdx=-1, rightIdx=-1;
        // 0 to peak
        low=0, high=peak;
        while(low<=high) {
            mid=low+(high-low)/2;
            if(mountainArr.get(mid)==target) {
                leftIdx=mid;
                high=mid-1;
            } else if(mountainArr.get(mid)>target) {
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        //peak+1 to n-1
        low=peak+1, high=n-1;
        while(low<=high) {
            mid=low+(high-low)/2;
            if(mountainArr.get(mid)==target) {
                rightIdx=mid;
                high=mid-1;
            } else if(mountainArr.get(mid)>target) {
                low=mid+1;
            } else {
                high=mid-1;
            }
        }
        if(rightIdx==-1 && leftIdx==-1) return -1;
        if(rightIdx==-1) return leftIdx;
        if(leftIdx==-1) return rightIdx;
        return min(leftIdx, rightIdx);
    }
};