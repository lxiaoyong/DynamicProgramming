//
// Created on 2020/10/14.
// https://leetcode-cn.com/problems/minimum-cost-for-tickets/

#include <vector>
using namespace std;
int mincostTickets(vector<int>& days, vector<int>& costs) {
    int dp_size = *(days.end()-1)+1;
    vector<int> dp(dp_size,0);
    int days_size = days.size();
    for(int i=0;i<days_size;++i) dp[days[i]]=1;
    for(int i=1;i<dp_size;++i){
        if(dp[i]==0){
            dp[i]=dp[i-1];continue;
        }
        dp[i]=dp[i-1]+costs[0];
        if(i>=7) dp[i]=min(dp[i],dp[i-7]+costs[1]);
        else dp[i]=min(dp[i],costs[1]);
        if(i>=30) dp[i]=min(dp[i],dp[i-30]+costs[2]);
        else dp[i]=min(dp[i],costs[2]);
    }
    return dp[dp_size-1];
}