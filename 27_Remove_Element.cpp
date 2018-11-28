/** 问题描述：
 *  给定一个数组和一个数值，移除数组中所有等于该数值的元素，并返回新数组的长度。
 *  不允许开辟新的额外空间给另一个数组，必须通过处理该输入数组来达成目的，允许  O(1) 的额外空间。
 *  数组中元素的顺序可以发生变化，留下的元素相比于长度并不是最重要的。
 */

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val)
{
    /*
        .erase函数删除指定元素，并返回下一位置。
    */

    // int newLength = 0;
    // for (vector<int>::iterator it = nums.begin(); it != nums.end(); )
    // {
    //     if (*it == val)
    //     {
    //         it = nums.erase(it);
    //     }
    //     else
    //     {
    //         newLength++;
    //         it++;
    //     }
    // }
    // return newLength;

    /*
        设定另一个变量i为不等于val的位置。
        使用这种情况没有考虑如果最后一个数是val的情况。
        并且最后两个数会出现两次，同时val在最后也会出现一次。
    */
    int i = 0;
    for (int n : nums)
    {
        if (n != val)
        {
            nums[i++] = n; 
        }
    }
    return i;
}

int main(int argc, char const *argv[])
{
    int num[] = {0, 1, 2, 2, 3, 0, 4, 3};
    vector<int> nums(num, num+8);
    int val = 2;
    cout << removeElement(nums, val) << endl;
    for (int s : nums)
        cout << s << " ";
    return 0;
}
