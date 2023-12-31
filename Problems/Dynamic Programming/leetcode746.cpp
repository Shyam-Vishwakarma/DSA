//https://leetcode.com/problems/min-cost-climbing-stairs/description/

/*Problem : 
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.*/

/*Approach
Using dp can easily solve this problem.
We will find out the cost from the top.
In the dp array the index i will represent the minimum cost to go to the top from that particular index.

hence in the last we have the minmum cost from index 0 and index 1 and our answer will be min(dp[0], dp[1])
steps to solve :

Create a dp array of size = n+1 (n=cost.size())

Assign dp[n]=0 (we reached to the top)

Assign dp[n-1]=cost[n-1] (as it is the min cost from the last index)

Now traverse from n-2 to 0 and keep assigning the min cost at dp[i] as:
dp[i]=cost[i]+min(dp[i+1], dp[i+2])

Answer will be min(dp[0], dp[1])

Complexity
Time complexity: O(n)

Space complexity: O(n)*/

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;

//Code :
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1);
        dp[n]=0;
        dp[n-1]=cost[n-1];
        cout << dp[n];
        for(int i = n-2; i>=0; --i) {
            dp[i]=cost[i]+min(dp[i+1], dp[i+2]);
        }
        return min(dp[0], dp[1]);
    }
};