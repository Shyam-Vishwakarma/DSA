//https://leetcode.com/problems/monotonic-array/
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

int isMonoIncreasing(vector<int>&nums) {
    for(int i=0; i<nums.size()-1; i++) {
        if(nums[i]>nums[i+1]) return 0;
    }
    return 1;
}
int isMonoDecreasing(vector<int>&nums) {
    for(int i=0; i<nums.size()-1; i++) {
        if(nums[i]<nums[i+1]) return 0;
    }
    return 1;
}
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int i=0;
        while(i<nums.size()-1 && nums[i]==nums[i+1]) {
            i++;
        }
        if(i == nums.size()-1) return true;
        if(nums[i]>nums[i+1]) {
            return isMonoDecreasing(nums);
        }
        else return isMonoIncreasing(nums);
    }
};
