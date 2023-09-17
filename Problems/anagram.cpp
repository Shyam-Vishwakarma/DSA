// https://practice.geeksforgeeks.org/problems/anagram-1587115620/1?page=1&difficulty[]=0&company[]=Adobe&sortBy=submissions
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string a, string b){
        
        // Your code here
        unordered_map<char,int> freq;
        for(int i=0;i<a.size();i++){
            if(freq.find(a[i])==freq.end())freq[a[i]]=1;
            else freq[a[i]]++;
        }
        for(int i=0;i<b.size();i++){
            if(freq.find(b[i])==freq.end())return 0;
            else freq[b[i]]--;
        }
        for(auto it:freq){
            if(it.second!=0)return 0;
        }
        
        return 1;
        
        
    }


