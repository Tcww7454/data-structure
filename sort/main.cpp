//注意：此中所有的排序都是将其排位从小到大的顺序
#include<iostream>
#include<vector>
#include<algorithm>
#include"qsort.h"
#include"countint_sort.h"
#include"radix_sort.h"

//选择排序
//时间O(n2),非自适应，空间O(1)，原地排序，非稳定排序
void selectionSort(std::vector<int>&nums);

//插入排序
//时间O(n2)
void insertionSort(std::vector<int>&nums);

int main()
{
    std::vector<int>nums={4,1,3,1,2,5};
    std::vector<int>nums_p={4,1,3,1,2,5,6,3,7,3,7,9,7,34,5};

    //selectionSort(nums);
    //insertionSort(nums);
    //quickSort(nums,0,nums.size()-1);
    //countingSort(nums_p);
    radixSort(nums_p);
    for(int num:nums_p)
        std::cout<<num<<"\t";
        std::cout<<std::endl;
    return 0;
}

void selectionSort(std::vector<int>&nums)
{
    int n=nums.size();
    //外循环：找到未排序区间，由于最后一个必定已排序，故不用对其进行处理
    for(int i=0;i<n-1;i++)
    {
        int k=i;//将最小值索引定义为区间起点
        for(int j=i+1;j<n;j++)
        {
            if(nums[j]<nums[k])
            k=j;//找到比当前最小值还小就更新
        }
        std::swap(nums[i],nums[k]);//把当前区间起点替换为未排序区间的最小值
        //每次使得一项元素达到对应位置
    }
}

void insertionSort(std::vector<int>&nums)
{
    //初始状态下将第一个元素视为已排序好的元素
    for(int i=1;i<nums.size();i++)
    {
        int base=nums[i],j=i-1;
        //注意：这里是将未排序的点取出，并从这个点出发，逐步往前遍历
        //直到找到合适的插入位置
        while(j>=0&&nums[j]>base)
        {
            nums[j+1]=nums[j];
            j--;
        }
        //退出意味着找到第一个小于它的元素或到头了
        //此时需要插到这个元素后面或者插入头中
        nums[j+1]=base;
    }
}