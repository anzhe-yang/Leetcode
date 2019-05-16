/** 问题描述：
 *  给定一个非空整数数组，除了某个元素外其它元素都出现三次。
 *  找出那个出现一次的元素。
 */

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums)
{
    /*
        每个元素出现k次，只有一个元素出现p次。
        定义m个二进制计数器，2^m >= k，即在本题中m为2。
        假设元素只有0和1，当扫描到1时，计数器加1，扫描到0，计数器不变。
        如果已经为1，再扫描到1，应变为0，所以不能用x1|x2，应该为x1^x2。
        当计数器达到k时，即这个元素是普遍元素，不是要找的那个，这时要把计数器清零。
        定义一个mask变量，只有当x1和x2都为1时，即出现了三次，将mask变为0，这样将x1和x2做与操作，将其变为0。
        出现两次为普遍元素，即10时，mask为0，出现三次为普遍元素，即11时，mask为0。
        这样就将普遍的数都排除掉，如果最后x1或者x2某个不为0，即x1|x2就为要找的那个数字。
    */
   
    int x1 = 0, x2 = 0, mask = 0;
    for (int i : nums)
    {
        x2 ^= x1 & i;
        x1 ^= i;
        mask = ~(x1 & x2);
        x2 &= mask;
        x1 &= mask;
    }
    return x1 | x2;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{2, 2, 3, 2};
    cout << singleNumber(nums);
    return 0;
}
