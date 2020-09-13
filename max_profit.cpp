//
// Created  on 2020/9/13.
// https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
#include <vector>
using namespace std;
int maxProfit(vector<int>& prices) {
    int len=prices.size(),max_profit=0,min_price=prices[0];
    for(int i=1;i<len;++i){
        max_profit=max(max_profit,prices[i]-min_price);
        min_price=min(min_price,prices[i]);
    }
    return max_profit;
}