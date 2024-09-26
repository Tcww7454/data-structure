#ifndef Radix_H
#define Radix_H
#include<vector>
#include<algorithm>

/* 获取元素 num 的第 k 位，其中 exp = 10^(k-1) */
int digit(int num, int exp) {
    // 传入 exp 而非 k 可以避免在此重复执行昂贵的次方计算
    return (num / exp) % 10;
}

//与之前的计数排序完全相同，不过这里排序的对象变成了每个数字的每位数字
//由于逆序循环的计数排序是原地排序，故不会打乱原有的数字顺序
/* 计数排序（根据 nums 第 k 位排序） */
void countingSortDigit(std::vector<int> &nums, int exp) {
    // 十进制的位范围为 0~9 ，因此需要长度为 10 的桶数组
    std::vector<int> counter(10, 0);
    int n = nums.size();
    // 统计 0~9 各数字的出现次数
    for (int i = 0; i < n; i++) {
        int d = digit(nums[i], exp); // 获取 nums[i] 第 k 位，记为 d
        counter[d]++;                // 统计数字 d 的出现次数
    }
    // 求前缀和，将“出现个数”转换为“数组索引”
    for (int i = 1; i < 10; i++) {
        counter[i] += counter[i - 1];
    }
    // 倒序遍历，根据桶内统计结果，将各元素填入 res
    std::vector<int> res(n, 0);
    /*
        需要注意，直到这里，对原数组中的元素仍没有进行任何修改，使用的知识没个元素对应的元素
        这里使用了一点映射的原理吧，
        这里先对每一位上的数字进行一次计数排序的前缀和计算，然后根据这个数组对原数组进行排序
        每次调用能够实现没一位上的数字的从小到大排序
        而当所有的数字位都从小到大排序后，原数组自然也就从小到大排序了
    */
    for (int i = n - 1; i >= 0; i--) {
        int d = digit(nums[i], exp);
        int j = counter[d] - 1; // 获取 d 在数组中的索引 j
        res[j] = nums[i];       // 将当前元素填入索引 j
        counter[d]--;           // 将 d 的数量减 1
    }
    // 使用结果覆盖原数组 nums
    for (int i = 0; i < n; i++)
        nums[i] = res[i];
}

/* 基数排序 */
void radixSort(std::vector<int> &nums) {
    // 获取数组的最大元素，用于判断最大位数
    int m = *std::max_element(nums.begin(), nums.end());
    // 按照从低位到高位的顺序遍历
    for (int exp = 1; exp <= m; exp *= 10)
        // 对数组元素的第 k 位执行计数排序
        // k = 1 -> exp = 1
        // k = 2 -> exp = 10
        // 即 exp = 10^(k-1)
        countingSortDigit(nums, exp);
}

#endif