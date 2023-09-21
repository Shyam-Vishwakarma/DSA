//https://www.hackerrank.com/challenges/jim-and-the-jokes/problem

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int convertToDecimal(vector<int> v){
    int number = v[1];
    int base = v[0];
    int ans = 0,i=0;
    while(number > 0){
        int d = number % 10;
        number/=10;
        if(d>=base)return -1;
        ans = ans + (pow(base,i)*d);
        i++;
    }
    return ans;
}


int solveBruteForce(vector<vector<int>> dates) {
    vector<int> decimals(dates.size());
    for(int i=0;i<dates.size();i++){
        decimals[i]= convertToDecimal(dates[i]);
    }
    int ans =0 ;
    for(int i=0;i<dates.size();i++){
        for(int j=i+1;j<dates.size();j++){
            if(decimals[i]!=-1 && decimals[j]!=-1 && decimals[i]==decimals[j] )ans++;
        }    
    }
    return ans;
}


int solveOptimized(vector<vector<int>> dates) {
    vector<long> decimals(dates.size());
    unordered_map<int,int> deciFreq;
    for(int i=0;i<dates.size();i++){
        decimals[i]= convertToDecimal(dates[i]);
    }
    int ans =0 ;
    for(int i=0;i<dates.size();i++){
            if(decimals[i]==-1) continue;
            if( deciFreq.find(decimals[i])==deciFreq.end())deciFreq[decimals[i]]=1;
            else{
                ans+=deciFreq[decimals[i]];
                deciFreq[decimals[i]]++;
            }
    }
    return ans;
}
