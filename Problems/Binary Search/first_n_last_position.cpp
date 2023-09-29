// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1, mid;
        int firstPosition=-1, lastPosition=-1;
        // first position
        while(low<=high) {
            mid=low+(high-low)/2;
            if(nums[mid]==target) {
                firstPosition=mid;
                high=mid-1;
            } else if(nums[mid]>target) {
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        // last position
        low=0, high=nums.size()-1;
        while(low<=high) {
            mid=low+(high-low)/2;
            if(nums[mid]==target) {
                lastPosition=mid;
                low=mid+1;
            } else if(nums[mid]>target) {
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return {firstPosition, lastPosition};
    }
};