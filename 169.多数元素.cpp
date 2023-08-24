/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

#include <vector>
#include <unordered_map>
 
// 初步思路：哈希表无脑遍历，时间复杂度O(N)，空间复杂度O(N)
// 其他思路：先快速排序再指针遍历（直接[n/2]处，无需遍历），时间复杂度O(NlogN)，空间复杂度O(1)
// 方法3：选一个随机数并进行验证，选取期望次数（2次）的时间复杂度O(N)，空间复杂度O（1）
// 方法4：分治法，多数元素必须为左边部分或右半部分的众数，如果只为左（右）半部分的，则需要比较具体出现次数

// 报错：non-void function does not return a value in all control paths
// 原因：即使结果一定存在，也应在循环结束后返回未找到主要元素时返回的默认值

// unordered_map使用哈希表维护数据，map使用红黑树（一种平衡二叉树）维护数据
// 平均情况下unordered_map的插入、查找、删除性能更好（常数时间），但map可以进行有序的遍历

// 最佳解法：Boyer-Moore投票法，将候选多数元素记为+1，其他数记为-1
// 将所有元素加起来，显然和大于0；遍历数组进行+1-1，每次和归0后取下一数字为候选多数元素

using namespace std;

// @lc code=start
/***摩尔投票法***/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major;
        int count = 0;
        int siz = nums.size();
        
        for(int i=0; i<siz; i++){
            if(count==0){
                major = nums[i];
                count++;
            }
            else if(major == nums[i]){
                count++;
            }
            else{
                count--;
            }
        }

        return major;
    }
};

/***哈希表***/
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
        
//         int siz = nums.size()/2;
        
//         if(siz==0) return nums[0];

//         unordered_map<int,int> map;

//         for(const int &num : nums)
//         {
//             if(map.count(num)){
//                 map[num]++;
//                 if(map[num] > siz) return num;
//             }
//             else{
//                 map.insert({num,1});
//             }
//         }

//         return -1;
//     }
// };
// @lc code=end

