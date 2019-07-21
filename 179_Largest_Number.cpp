/** 问题描述：
 *  给定一些非负整数，排列它们使其成为最大的数字。
 *  返回整数的字符串形式。
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string largestNumber(vector<int>& nums)
{
    /*
        先将每个数字转为字符串，并保存到数组里。
        之后对这个数组进行排序，排序规则是 s1+s2 > s2+s1，重点在这里。
        举个例子：3，30这两个字符串，3应该在前面，30在后面，那么330>303，所以就这么排好序。
        这样就把字符串排序成题目想要的样子。
        之后把每个字符串按顺序压入res。
        如果首字符为0，则直接返回0。
    */
    vector<string> num2str;
    for(int num : nums)
    {
        num2str.push_back(to_string(num));
    }
    sort(begin(num2str), end(num2str), [](string &s1, string &s2){ return s1+s2>s2+s1; });
    string res;
    for(string s : num2str)
    {
        res += s;
    }
    return res[0]=='0' ? "0" : res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{0, 0};
    cout << largestNumber(nums);
    return 0;
}
