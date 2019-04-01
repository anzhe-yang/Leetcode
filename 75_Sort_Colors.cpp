/** 问题描述：
 *  给定一个具有红、白、蓝对象的数组，对它们进行排序，使颜色相同的对象相邻，顺序为红、白、蓝。
 *  0 1 2 分别为红、白、蓝。
 *  排序方法不允许使用额外的空间。
 */

#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums)
{
    /*
        one-pass解决方法。
        遍历数组，先保存当前值，并置当前位置为2。
        然后迭代是否等于1，则置为1，白位置加一。
        迭代是否等于0，则置为0，红位置加一。
        也就是说一个元素会置三次，判断两次。
        没有使用额外数组空间。
        没有使用交换和计数函数。
        将数组分为[0, red) [red, white) [white, blue)
    */

    int len = nums.size();
    int red = 0, white = 0;
    for (int blue = 0; blue < len; blue++)
    {
        int temp = nums[blue];
        nums[blue] = 2;
        if (temp < 2)
        {
            nums[white] = 1;
            white++;
        }
        if (temp == 0)
        {
            nums[red] = 0;
            red++;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> nums{2, 0, 2, 1, 1, 0};
    sortColors(nums);
    for (int s : nums)
        cout << s << " ";
    return 0;
}
