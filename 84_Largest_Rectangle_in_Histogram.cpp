/** 问题描述：
 *  给定 n 个非负整数，代表了直方图中每个区域的权重，找到直方图的最大区域面积。
 */

#include <iostream>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    // int len = heights.size();
    // if (len == 1)
    //     return heights[0];
    // int left = 0, right = len-1;
    // int sum = 0;
    // while (left <= right)
    // {
    //     int dis = right - left + 1;
    //     vector<int>::iterator curMin = min_element(heights.begin()+left, heights.begin()+right+1);
    //     int tmp = *curMin * dis;
    //     sum = max(sum, tmp);
    //     if (heights[left] < heights[right])
    //         left++;
    //     else
    //         right--;
    // }
    // return sum;

    /*
        通过一个while循环判断，在前i个柱状图内，求最大面积。
        之后通过一个for循环求整个直方图。
        当通过对当前高度判断，得出前一个高度目前最高，则进入while循环。
        在while循环中，找出前几个直方图的最大面积。
        首先找出当前最高高度curMaxWeight，然后弹出这个位置，计算之前的位置当作左边界，则当前范围为i-1到左边界，得出当前面积。
        如果再前一个还大于第i个高度，则继续计算当前面积。
        如果index里没有位置了，则计算一个块的面积。
        通过在heights的最后加一个0，可以计算整体最大面积，否则的话到直方图最高的那个位置就停止了。
    */

    int curMax = 0;
    heights.push_back(0);
    vector<int> index;
    int len = heights.size();
    for (int i = 0; i < len; i++)
    {
        while (index.size() > 0 && heights[index.back()] >= heights[i])
        {
            int curMaxWeight = heights[index.back()];
            index.pop_back();
            int leftSide = index.size() > 0 ? index.back() : -1;
            curMax = max(curMax, curMaxWeight*(i-1-leftSide));
        }
        index.push_back(i);
    }
    return curMax;
}

int main(int argc, char const *argv[])
{
    vector<int> heights{2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(heights);
    return 0;
}
