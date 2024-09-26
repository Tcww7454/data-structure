#ifndef Count_Sort
#define Count_Sort

//时间O(n+m),非自适应排序，空间O(n+m),非原地排序

#include<vector>
#include<algorithm>
//可排序对象，稳定排序
void countingSort(std::vector<int>&nums)
{
    // 1. 统计数组最大元素 m
    int m = 0;
    for (int num : nums) {
        m = std::max(m, num);
    }
    // 2. 统计各数字的出现次数
    // counter[num] 代表 num 的出现次数
    std::vector<int> counter(m + 1, 0);
    for (int num : nums) {
        counter[num]++;
    }
    // 3. 求 counter 的前缀和，将“出现次数”转换为“尾索引”
    // 即 counter[num]-1 是 num 在 res 中最后一次出现的索引
    for (int i = 0; i < m; i++) {
        counter[i + 1] += counter[i];
    }
    //执行这个循环前，count[i]的含义其实是每个i数字在待排序数组中的出现次数
    //执行这个循环后，count[i]的含义为排序后数组中所有小于等于i的所有元素的数量
    // 4. 倒序遍历 nums ，将各元素填入结果数组 res
    // 初始化数组 res 用于记录结果
    int n = nums.size();
    std::vector<int> res(n);
    /*
        这里排序使用倒序遍历的原因，这里的插入，是去查找前缀和数组中以该数字为索引的元素的值的
        而这个数组值是“排序后数组中所有小于等于i的所有元素的数量”，故插入时是会将该值插入到该段区间的最末的
        而我们如果是顺序遍历，最先出现的数字会被插入其对应的区间的最后，这个就打乱了原数组的顺序
        破坏了数组排序的稳定性，而这个稳定性是能够通过倒序遍历来实现的
        当我们遍历到一个元素时，其回去找到对应前缀和数组中目前的值，并插入该对应位置（最末）
        而这样就保证了最先访问到的位置插入到最后，而在现在的数组中最先访问到的数字是最后第几个出现的数字
        这就刚好保证了数组排序的稳定性
    */
    for (int i = n - 1; i >= 0; i--) {
        //千万注意这里的逻辑顺序
        /*
            这里是找到原数组中的最后一个元素，并查找该元素在最终的count[i]数组中的数值
            这里的就能找到在排序后的数组中对应的位置
            这里counter[num] - 1是因为排序数组的索引从0开始
            有一点可能能够增加对过程的理解，这目标数组的构建，其元素的插入是不连续的
        */
       /*
            假设我们有原数组 nums = [3, 1, 2, 1, 3, 2, 1]，counter 经过前缀和计算后为 [0, 3, 5, 7]。
            遍历到 nums[6] = 1，counter[1] = 3，所以 1 被放到 res[2] 位置，然后 counter[1]-- 变为 2。
            遍历到 nums[5] = 2，counter[2] = 5，所以 2 被放到 res[4] 位置，然后 counter[2]-- 变为 4。
            继续这个过程，最终结果数组 res 就是 [1, 1, 1, 2, 2, 3, 3]。
       */
        int num = nums[i];
        res[counter[num] - 1] = num; // 将 num 放置到对应索引处
        counter[num]--;              // 令前缀和自减 1 ，得到下次放置 num 的索引
    }
    // 使用结果数组 res 覆盖原数组 nums
    nums = res;

}

#endif