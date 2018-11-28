/** 问题描述：
 *  给定 n 个非负整数 a1, a2, a3, ...，每个整数表示坐标 (i, ai)。绘制 n 条垂直线，使得垂直线 i 的两个端点位于 (i, ai) (i, 0)。
 *  找到两条垂直线，使得它俩与 x 轴形成一个容器，使这个容易能够装下最多的水。
 *  容器不会被倾斜，且 n 至少为2。
 */

#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height)
{
    /*
        若只有两个点则直接返回。
        max为当前最大面积，left为左端点，right为右端点。
        找出左右端点代表得直线最短的那个作为高，宽度为相减，求面积。
    */
   
    int len = height.size();
    if (len == 2)
        return (min(height[0], height[1]));

    int max = 0;
    int left = 0;
    int right = len - 1;

    while (left != right)
    {
        if (min(height[left], height[right]) * (right-left) > max)
            max = min(height[left], height[right]) * (right-left);
        
        if (height[left] > height[right])
            right--;
        else
            left++;
    }
    return max;
}

int main(int argc, char const *argv[])
{
    int a[] = {2,3,4,5,18,17,6};
    vector<int> height(a, a+7);
    int area = maxArea(height);
    cout << area;
    return 0;
}
