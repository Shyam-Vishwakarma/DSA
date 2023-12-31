//https://leetcode.com/problems/contiguous-array/

/*
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
*/
#include<bits/stdc++.h>
using namespace std;
/*Solution 1 O(n^2)*/ // TLE
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count1=0, count0=0;
        for(int i : nums) 
            i?count1++:count0++;
        int length = min(count1, count0)*2;
        //cout << length;
        if(length==2) {
            return length;
        }
        while(length>2) {
            int i=0, j=length-1;
            count1=0;
            count0=0;
            for(int k=0; k<=j; k++) 
                nums[k]?count1++:count0++;
            if(count1==count0) return length;
            // cout << j;
            for(j; j<nums.size()-1; j++) {
                nums[i]?count1--:count0--;
                nums[j+1]?count1++:count0++;
                //cout << count1 << count0;
                if(count1==count0) return length;
                i++;
            }
            length-=2;
        }
        if(length==2) {
            return length;
        }
        return 0;
    }
};

/*Solution 2 using unordered map O(n)*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> sumIndexMap;
        int maxLength = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sum += (nums[i] == 0) ? -1 : 1;

            if (sum == 0) {
                maxLength = max(maxLength, i + 1);
            } else if (sumIndexMap.find(sum) != sumIndexMap.end()) {
                maxLength = max(maxLength, i - sumIndexMap[sum]);
            } else {
                sumIndexMap[sum] = i;
            }
        }

        return maxLength;
    }
};
