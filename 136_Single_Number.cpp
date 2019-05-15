/** 问题描述：
 *  给定一个非空整数数组，除了某个元素外其它元素都出现两次。
 *  找出那个出现一次的元素。
 */

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums)
{
    /*
        初始化res为0。
        依次将它与每个元素进行异或操作。
        相同的数，即出现两次的数会抵消。
        剩下的就是出现一次的元素。
    */
   
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        res = res ^ nums[i];
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{2, 2, 1};
    cout << singleNumber(nums);
    return 0;
}
