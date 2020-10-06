//
// Created on 2020/10/7.
//
#include <string>
#include <algorithm>
using namespace std;
// https://leetcode-cn.com/problems/UlBDOe/
// 解释 https://leetcode-cn.com/problems/UlBDOe/solution/ulbdoe-by-ikaruga/
int minimumOperations(string leaves) {
    int r=0;
    int size = leaves.size();
    if(leaves[0]=='y') ++r;
    int ry = r+(leaves[1]=='r');
    int ryr = ry+(leaves[2] == 'y');
    for(int i=1;i<size;++i){
        if(i>1) ryr = min(ry,ryr)+(leaves[i]=='y');
        ry = min(r,ry)+(leaves[i]=='r');
        if(leaves[i]=='y') ++r;
    }
    return ryr;
}