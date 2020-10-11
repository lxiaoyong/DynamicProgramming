//
// Created on 2020/10/11.
// https://leetcode-cn.com/problems/partition-equal-subset-sum/

#include<vector>
using namespace std;
bool canPartition(vector<int>& nums) {
    int size=nums.size();
    if(size<2) return false;
    int all_sum=0,max_num=nums[0];
    for(int n:nums){
        all_sum+=n;
        max_num=max(max_num,n);
    }
    if(all_sum%2) return false;
    int average = all_sum/2;
    if(max_num>average) return false;

    vector<bool> dp(average+1,false);
    dp[0]=true;
    dp[nums[0]]=true;
    for(int i=1;i<size;++i){
        int num_i=nums[i];
        for(int j=average;j!=0;--j){
            if(j>=num_i) dp[j]=(dp[j] || dp[j-nums[i]]);
            else dp[j]=dp[j];
        }
    }
    return dp[average];
}