#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
// Here is the solution of Leetcode Biweekly Contest 115, Oct 14, I solved 2 questions out of 4
/* Last Visited Integers
Difficulty:Easy
Given a 0-indexed array of strings words where words[i] is either a positive integer represented as a string or the string "prev".

Start iterating from the beginning of the array; for every "prev" string seen in words, find the last visited integer in words which is defined as follows:

Let k be the number of consecutive "prev" strings seen so far (containing the current string). Let nums be the 0-indexed array of integers seen so far and nums_reverse be the reverse of nums, then the integer at (k - 1)th index of nums_reverse will be the last visited integer for this "prev".
If k is greater than the total visited integers, then the last visited integer will be -1.
Return an integer array containing the last visited integers.

 

Example 1:

Input: words = ["1","2","prev","prev","prev"]
Output: [2,1,-1]
Explanation: 
For "prev" at index = 2, last visited integer will be 2 as here the number of consecutive "prev" strings is 1, and in the array reverse_nums, 2 will be the first element.
For "prev" at index = 3, last visited integer will be 1 as there are a total of two consecutive "prev" strings including this "prev" which are visited, and 1 is the second last visited integer.
For "prev" at index = 4, last visited integer will be -1 as there are a total of three consecutive "prev" strings including this "prev" which are visited, but the total number of integers visited is two.*/

// keeping track of last visited in an array
class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int>lastVisited;
        vector<int>ans;
        int i=-1;
        for(const string& word : words) {
            if(word=="prev") {
                if(i<0) ans.push_back(-1);
                else {
                    ans.push_back(lastVisited[i]);
                    --i;
                }
            } else {
                int num = stoi(word);
                lastVisited.push_back(num);
                i=lastVisited.size()-1;
            }
        }
        return ans;
    }
};

/*
Longest Unequal Adjacent Groups Subsequence I
Difficulty:Medium
You are given an integer n, a 0-indexed string array words, and a 0-indexed binary array groups, both arrays having length n.

You need to select the longest subsequence from an array of indices [0, 1, ..., n - 1], such that for the subsequence denoted as [i0, i1, ..., ik - 1] having length k, groups[ij] != groups[ij + 1], for each j where 0 < j + 1 < k.

Return a string array containing the words corresponding to the indices (in order) in the selected subsequence. If there are multiple answers, return any of them.

A subsequence of an array is a new array that is formed from the original array by deleting some (possibly none) of the elements without disturbing the relative positions of the remaining elements.

Note: strings in words may be unequal in length.

 Input: n = 3, words = ["e","a","b"], groups = [0,0,1]
Output: ["e","b"]
Explanation: A subsequence that can be selected is [0,2] because groups[0] != groups[2].
So, a valid answer is [words[0],words[2]] = ["e","b"].
Another subsequence that can be selected is [1,2] because groups[1] != groups[2].
This results in [words[1],words[2]] = ["a","b"].
It is also a valid answer.
It can be shown that the length of the longest subsequence of indices that satisfies the condition is 2.*/

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        int count1=groups[0];
        int count0=!groups[0];
        int flag=groups[0];
        vector<string>ans;
        for(int i : groups) {
            if(flag && !i) {
                count0+=!i;
                flag=0;
            } else if({
                count1+=i;
                flag=1;
            }
        }
        int minCount=min(count1, count0);
        int length=2*minCount;
        if(count1==count0) {
            if(groups[0]) {
                flag=0;
                count1--;
            } else {
                flag=1;
                count0--;
            }
            ans.push_back(words[0]);
        }
        else if(minCount==count1) flag=0;
        else flag=1;
        for(int i=0; i<n; i++) {
            if(groups[i]==flag) {
                if(flag) {
                    flag=0;
                } else {
                    flag=1;
                }
                ans.push_back(words[i]);
                length--;
            }
        }
        return ans;
    }
};