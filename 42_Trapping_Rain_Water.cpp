/** 问题描述：
 *  给定 n 个非负整数代表一个直方图，每个宽度都为 1 ，计算其中可以存储多少水。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height)
{
    /*
        从左，从右同时开始向内部循环。
        定义左边最大值和右边最大值。
        判断左边元素是否大于右边元素。
        之后让每个左边元素或者右边元素与左边最大值和右边最大值相比较。
        小于则说明可以存储水，大于则改变最大值。
    */

    int len = height.size();
    int left = 0, right = len-1;
    int sum = 0;
    int leftMax = 0, rightMax = 0;
    while (left < right)
    {
        // if (height[left] < height[right])
        // {
        //     if (height[left] >= leftMax)
        //         leftMax = height[left];
        //     else
        //         sum += leftMax - height[left];
            
        //     left++;
        // }
        // else
        // {
        //     if (height[right] >= rightMax)
        //         rightMax = height[right];
        //     else
        //         sum += rightMax - height[right];
            
        //     right--;
        // }
        leftMax = max(leftMax, height[left]);
        rightMax = max(rightMax, height[right]);

        if (height[left] < height[right])
        {
            sum += leftMax - height[left];
            left++;
        }
        else
        {
            sum += rightMax - height[right];
            right--;
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(height);
    return 0;
}
