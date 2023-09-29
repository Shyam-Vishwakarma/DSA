// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=0; j<nums.size(); j++) {
            if(nums[j]!=nums[i]) {
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};