//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int  profit=0;
        int cheaperPrice=prices[0];
        for(int i=1; i<prices.size(); i++) {
            if(prices[i]<cheaperPrice) {
                cheaperPrice=prices[i];
            } else if(prices[i]>cheaperPrice) {
                if(prices[i]-cheaperPrice>profit) profit=prices[i]-cheaperPrice;
            }
        }
        return profit;
    }
};