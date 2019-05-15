/** 问题描述：
 *  有 N 个孩子站在一条线上，每个孩子被赋予一个 rank 值。
 *  你将按照一下规则给每个孩子发糖果：
 *  每个孩子至少有一个糖果。
 *  更高 rank 值的孩子会得到比周围邻近孩子更多的糖果。
 *  返回你所需要的最少糖果数目。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int candy(vector<int>& ratings)
{
    /*
        首先定义一个全是1的数组，因为每个孩子至少有一个糖果。
        之后利用两个循环，分别从左到右，从右到左进行变化。
        从左到右遍历时，比较当前与前一个值的大小，更改当前值。
        从右到左遍历时，比较前一个与当前值的大小，更改前一值。
        循环的过程中，更改“后一个”要循环的值，去比较“前一个”要循环的值，这样才能完美实现。
    */
   
    int len = ratings.size();
    if (len < 2)
        return len;
    
    vector<int> c(len, 1);
    for (int i = 1; i < len; i++)
    {
        if (ratings[i] > ratings[i-1])
        {
            c[i] = c[i-1] + 1;
        }
    }
    for (int j = len-1; j > 0; j--)
    {
        if (ratings[j-1] > ratings[j])
        {
            c[j-1] = max(c[j]+1, c[j-1]);
        }
    }
    int res = 0;
    for (int i = 0; i < len; i++)
    {
        res += c[i];
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> ratings{1, 0, 2};
    cout << candy(ratings);
    return 0;
}
