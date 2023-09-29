// https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int firstBadVersion(int n) {
        int low=1, high=n, mid;
        int firstBad;
        while(low<=high) {
            mid=low+(high-low)/2;
            if(isBadVersion(mid)) {
                firstBad=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
    }
        return firstBad;
    }
};