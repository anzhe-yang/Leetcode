/** 问题描述：
 *  给定一个无序数组，找到排序后数组中连续元素间的最大差值。
 *  如果数组个数少于 2 则返回 0 。
 *  假设所有元素为非负数。
 *  时间和空间复杂度为线性。
 */

#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int>& nums, int left, int right)
{
    if (left < right)
    {
        int target = nums[left];
        int i = left, j = right;
        while (i < j)
        {
            while (i < j && nums[j] > target)
            {
                j--;
            }
            if (i < j)
            {
                nums[i++] = nums[j];
            }
            while (i < j && nums[i] < target)
            {
                i++;
            }
            if (i < j)
            {
                nums[j] = nums[i];
            }
        }
        nums[i] = target;
        sort(nums, left, i-1);
        sort(nums, i+1, right);   
    }
}

int maximumGap(vector<int>& nums)
{
    /*
        先用快速排序算法进行排序。
        然后找相邻的最大间隔。
    */

    // int len = nums.size();
    // if (len < 2)
    //     return 0;
    // if (len == 2)
    //     return abs(nums[0]-nums[1]);
    
    // sort(nums, 0, len-1);
    // int res = 0;
    // for (int i = 1; i < len; i++)
    // {
    //     if (nums[i] - nums[i-1] > res)
    //     {
    //         res = nums[i] - nums[i-1];
    //     }
    // }
    // return res;

    /*
        桶排序算法。
        每个桶容量是(max-min)/(len-1)，然后计算每个桶最大存储元素个数为(max-min)/桶容量+1。
        建立两个数组变量，一个保存每个桶内的最大值，一个保存每个桶内的最小值。
        遍历每个元素，将每个元素安排到对应的桶中，并计算当前桶的最大最小值。
        之后以桶为单位去比较。
        如果当前桶最小值为INT_MAX，说明此桶没有元素。
        否则求得相邻桶中最小元素与前一个最大元素的间隔，找到其最大间隔就为结果。
    */
   
    int len = nums.size();
    int maxV, minV;
    int bucket_size, bucket_num, bucket_id;
    int maxGap = INT_MIN;
    int lastMax;

    if (len > 1)
    {
        maxV = minV = nums[0];
        for (int i = 1; i < len; i++)
        {
            if (minV > nums[i])
                minV = nums[i];
            else if (maxV < nums[i])
                maxV = nums[i];
        }
        bucket_size = max(1, (maxV-minV)/(len-1));
        bucket_num = (maxV-minV) / bucket_size + 1;

        if (bucket_num <= 1)
            return maxV - minV;
        vector<int> bucket_max(bucket_num, INT_MIN);
        vector<int> bucket_min(bucket_num, INT_MAX);

        for (int i = 0; i < len; i++)
        {
            bucket_id = (nums[i] - minV) / bucket_size;
            bucket_min[bucket_id] = bucket_min[bucket_id] > nums[i] ? nums[i] : bucket_min[bucket_id];
            bucket_max[bucket_id] = bucket_max[bucket_id] < nums[i] ? nums[i] : bucket_max[bucket_id];
        }

        lastMax = minV;
        for (int i = 0; i < bucket_num; i++)
        {
            if (bucket_min[i] == INT_MAX)
            {
                continue;
            }
            maxGap = max(maxGap, bucket_min[i] - lastMax);
            lastMax = bucket_max[i];
        }
        return maxGap;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{3, 6, 9, 1};
    cout << maximumGap(nums);
    return 0;
}
