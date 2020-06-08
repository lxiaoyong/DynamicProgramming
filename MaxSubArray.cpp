#include<vector>
using namespace std;
/*
 * 输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。
 * 求所有子数组的和的最大值。要求时间复杂度为O(n)。
 * */
int maxSubArray(vector<int>& nums) {
    int max_sum=nums[0],sum=0;
    for(int num : nums){
        sum+=num;
        max_sum=(sum>max_sum?sum:max_sum);
        sum=sum>0?sum:0;
    }
    return max_sum;
}