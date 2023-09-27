//https://leetcode.com/problems/intersection-of-two-arrays/

class Solution1 { //O(n2)
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int flag;
        for(int i=0; i<nums1.size(); i++) {
            flag=0;
            for(int j=0; j<nums2.size(); j++) {
                if(nums1[i]==nums2[j]) {
                    nums2[j]=-1;
                    flag=1;
                }
            }
            if(flag) ans.push_back(nums1[i]);
        }
        return ans;
    }
};
class Solution2 { //O(nlogn)
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0, j=0, temp=-1;
        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i]==nums2[j]) {
                if(temp!=nums1[i])
                ans.push_back(nums1[i]);
                temp=nums1[i];
                i++;
                j++;
            }
            else if(nums1[i]>nums2[j]) {
                j++;
            }
            else {
                i++;
            }
        }
        return ans;
    }
};
class Solution { //O(n)
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mp;
        vector<int>ans;
        for(int i : nums1) {
            if(mp[i]==1) continue;
            mp[i]++; 
        }
        for(int i : nums2) {
            if(mp[i]) {
                mp[i]--;
                ans.push_back(i);
            }
        }
        return ans;
    }
};


