#ifndef Qsort_H
#define Qsort_H

//哨兵划分的实质是将一个较长数组的排序问题简化为两个较短数组的排序问题
//取一个数为基准数，
//然后从右往左找第一个小于基准数的元素，从左往右找第一个大于基准数的元素
//找到这俩个数后进行交换，循环进行，当俩个指针重合时，交换该指针元素和基准数

/*
    没进行一次哨兵划分能使得最后得到的哨兵左右数组严格保证
    左数组元素<哨兵<右数组元素，在完成后在对左右数组进行递归操作
    知道子数组长度为1时能够保证数组有序
*/
#include<vector>

void swap(std::vector<int>&nums,int i,int j)
{
    int temp=nums[i];
    nums[i]=nums[j];
    nums[j]=temp;
}

int partition(std::vector<int>&nums,int left,int right)
{
    //以nums[left]为基准数
    int i=left,j=right;
    while(i<j)
    {
        while(i<j&&nums[j]>=nums[left])
            j--;//从右往左找个首个小于基准数的元素
            while(i<j&&nums[i]<=nums[left])
            i++;//从左往右找首个大于基准数的元素
            swap(nums,i,j);
    }
    swap(nums,i,left);
    return i;//返回基准数索引
}

int medianThree(std::vector<int>&nums,int left,int mid,int right)
{
    int l=nums[left],m=nums[mid],r=nums[right];
    if((l<=m&&m<=r)||(r<=m&&m<=l))
        return mid;   //m在l和r之间
    if ((m <= l && l <= r) || (r <= l && l <= m))
        return left; // l 在 m 和 r 之间
    return right;
}

void quickSort(std::vector<int>&nums,int left,int right)
{
    if(left>=right)return ;
    int pivot=partition(nums,left,right);
    quickSort(nums,left,pivot-1);
    quickSort(nums,pivot+1,right);
}

int partition_pro(std::vector<int> &nums, int left, int right) {
    // 选取三个候选元素的中位数
    int med = medianThree(nums, left, (left + right) / 2, right);
    // 将中位数交换至数组最左端
    swap(nums, left, med);
    // 以 nums[left] 为基准数
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] >= nums[left])
            j--; // 从右向左找首个小于基准数的元素
        while (i < j && nums[i] <= nums[left])
            i++;          // 从左向右找首个大于基准数的元素
        swap(nums, i, j); // 交换这两个元素
    }
    swap(nums, i, left); // 将基准数交换至两子数组的分界线
    return i;            // 返回基准数的索引
}

/* 快速排序（尾递归优化） */
void quickSort_pro(std::vector<int> &nums, int left, int right) {
    // 子数组长度为 1 时终止
    while (left < right) {
        // 哨兵划分操作
        int pivot = partition(nums, left, right);
        // 对两个子数组中较短的那个执行快速排序
        if (pivot - left < right - pivot) {
            quickSort(nums, left, pivot - 1); // 递归排序左子数组
            left = pivot + 1;                 // 剩余未排序区间为 [pivot + 1, right]
        } else {
            quickSort(nums, pivot + 1, right); // 递归排序右子数组
            right = pivot - 1;                 // 剩余未排序区间为 [left, pivot - 1]
        }
    }
}

#endif