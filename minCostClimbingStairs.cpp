//
// Created on 2020/7/19.
//
#include<vector>
using namespace std;

//题目：https://leetcode-cn.com/problems/min-cost-climbing-stairs/submissions/

int minCostClimbingStairs(vector<int>& cost) {
    int len=cost.size();
    vector<int> minCost(len+1,0);
    minCost[1]=cost[0];
    for(int i=1;i<len;++i){
        minCost[i+1]=min(minCost[i-1]+cost[i],minCost[i]+cost[i]);
    }
    return min(minCost[len-1],minCost[len]);
}
// 看完题解后的改进：
/*
int minCostClimbingStairs(vector<int>& cost) {
    int len=cost.size();
    int a=cost[len-2],b=cost[len-1];
    int t=a;
    for(int i=cost.size()-3;i>=0;--i){
        a=cost[i]+min(a,b);
        b=t;t=a;
    }
    return min(a,b);
}*/
