#ifndef Merge_h
#define Merge_h

#include<vector>
//时间O(nlogn),非自适应排序，空间O(n),原地排序

//合并过程
void merge(std::vector<int>&nums,int left,int mid,int right)
{
    //左子数组区间为[left,mid],右子树组区间为[mid+1,right]
    //创建一个临时数组tmp,用于存放合并的结果
    std::vector<int>tmp(right-left+1);
    //初始化左子数组和右子数组的起始索引
    int i=left,j=mid+1,k=0;
    // 当左右子数组都还有元素时，进行比较并将较小的元素复制到临时数组中
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j])
            tmp[k++] = nums[i++];
        else
            tmp[k++] = nums[j++];
    }
    // 将左子数组和右子数组的剩余元素复制到临时数组中
    while (i <= mid) {
        tmp[k++] = nums[i++];
    }
    while (j <= right) {
        tmp[k++] = nums[j++];
    }
    // 将临时数组 tmp 中的元素复制回原数组 nums 的对应区间
    for (k = 0; k < tmp.size(); k++) {
        nums[left + k] = tmp[k];
    }
}

/* 归并排序 */
void mergeSort(std::vector<int> &nums, int left, int right) {
    // 终止条件
    if (left >= right)
        return; // 当子数组长度为 1 时终止递归
    // 划分阶段
    int mid = left + (right - left) / 2;    // 计算中点
    mergeSort(nums, left, mid);      // 递归左子数组
    mergeSort(nums, mid + 1, right); // 递归右子数组
    // 合并阶段
    merge(nums, left, mid, right);
}

#endif