//
// Created on 2020/7/20.
//

// 题目：https://leetcode-cn.com/problems/the-masseuse-lcci/

#include<vector>
using namespace std;
int massage(vector<int>& nums) {
    int len=nums.size();
    if(len==0) return 0;
    int f2=0,f1=nums[len-1];
    int temp=f1;
    for(int i=len-2;i>=0;--i){
        f1=max(nums[i]+f2,f1);
        f2=temp;temp=f1;
    }
    return max(f1,f2);
}