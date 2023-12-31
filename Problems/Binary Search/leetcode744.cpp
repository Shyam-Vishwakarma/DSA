#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low=0, high = letters.size()-1, mid;
        int index=0, difference=INT_MAX;
        while(low<=high) {
            mid=low+(high-low)/2;
            if(letters[mid]-target<=0) {
                low=mid+1;
            } else {
                if(letters[mid]-target<difference) {
                    difference = letters[mid]-target;
                    index=mid;
                }
                high=mid-1;
            }
        }
        return letters[index];
    }
};