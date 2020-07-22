//
// Created on 2020/7/22.
//
/* 题目：https://leetcode-cn.com/problems/unique-binary-search-trees/
 *假设n个节点存在二叉排序树的个数是G(n)，1为根节点，2为根节点，...，n为根节点，
 * 当1为根节点时，其左子树节点个数为0，右子树节点个数为n-1，
 * 同理当2为根节点时，其左子树节点个数为1，右子树节点为n-2，
 * 所以可得G(n) = G(0)*G(n-1)+G(1)*(n-2)+...+G(n-1)*G(0)
 * */
#include <vector>
using namespace std;
int numTrees(int n) {
    vector<int> nums(n+1,0);
    nums[0]=1;
    nums[1]=1;
    for(int i=2;i<=n;++i){
        for(int j=0;j<i;++j){
            nums[i]+=nums[j]*nums[i-j-1];
        }
    }
    return nums[n];
}