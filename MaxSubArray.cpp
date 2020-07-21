#include<vector>
using namespace std;
/* 题目：https://leetcode-cn.com/problems/contiguous-sequence-lcci/submissions/
 * 输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。
 * 求所有子数组的和的最大值。要求时间复杂度为O(n)。
 * */

int maxSubArray(vector<int>& nums) {
    int len=nums.size();
    if(len==0) return 0;
    vector<int> subSum(len, 0);
    subSum[0]=nums[0];
    int maxSum=nums[0];
    for(int i=1;i<len;++i){
        subSum[i]=max(nums[i], subSum[i - 1] + nums[i]);
        maxSum=max(maxSum, subSum[i]);
    }
    return maxSum;
}
/*
// 分治法
int maxSubArray(vector<int>& nums)
{
    if(nums.size() == 0) return INT_MIN;
    return divide(nums,0,nums.size()-1);
}
int divide(vector<int>& nums, int left, int right)
{
    if(left == right) return nums[left];
    int mid = (left + right) / 2;
    // 1. 最大数列和在左边
    int sumLeft = divide(nums,left,mid);
    // 2. 最大数列和在右边
    int sumRight = divide(nums,mid+1,right);
    // 3. 最大数列和在中间
    // 先求左边的最大和
    int leftSum = 0,leftMaxSum = INT_MIN;
    for(int i = mid; i >= left; i--)
    {
        leftSum += nums[i];
        leftMaxSum = max(leftMaxSum,leftSum);
    }
    // 求右边的最大和
    int rightSum = 0,rightMaxSum = INT_MIN;
    for(int i = mid + 1; i <= right; i++)
    {
        rightSum += nums[i];
        rightMaxSum = max(rightMaxSum,rightSum);
    }
    return max(max(sumLeft,sumRight),leftMaxSum+rightMaxSum);
}

作者：yang-zi-ju-2
链接：https://leetcode-cn.com/problems/contiguous-sequence-lcci/solution/fen-zhi-he-dong-tai-gui-hua-liang-chong-jie-fa-by-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/
