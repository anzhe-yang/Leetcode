/** 问题描述：
 *  给定一个排好序的数组，删除其中的重复项，使得每个元素只出现一次，并返回新的数组长度。
 *  不要为另一个数组分配额外的空间，必须使用 O(1) 额外内存来修改输入的数组，从而实现此目的。
 */

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    /*
        从第二个位置开始找，设定一个重复值temp。
        如果这个元素不等于重复值，说明是下一轮，将temp进行更新，将nums的新位置进行更新，长度加一。
    */
   
    int len = nums.size();
    if (len == 0)
        return 0;
    int temp = nums[0];
    int newLength = 1;

    for (int i = 1; i < len; i++)
    {
        if (nums[i] != temp)
        {
            temp = nums[i];
            nums[newLength] = nums[i];
            newLength++;
        }
    }
    return newLength;
}

int main(int argc, char const *argv[])
{
    int num[] = {1, 1, 2};
    vector<int> nums(num, num+3);
    cout << removeDuplicates(nums);
    return 0;
}
