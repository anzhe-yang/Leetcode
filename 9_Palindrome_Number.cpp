/** 问题描述：
 *  判断一个整数是否是回文数。整数是否是回文数看他正着读和反着读是否一样。
 */

#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int x)
{
    /*
        从中间反转，判断是否相等，前面判断双数，后面判断单数。
    */

    // if (x < 0 || (x % 10 == 0 && x != 0))
    //     return false;
    
    // int revertedNum = 0;
    // while (x > revertedNum)
    // {
    //     revertedNum = revertedNum * 10 + x % 10;
    //     x /= 10;
    // }
    // return (x == revertedNum || x == revertedNum/10);

    /*
        先反转，看与原来是否相等。
    */
   
    int revertedNum = 0, temp = x;//revertedNum 是 x 反转后的数字
    while (x > 0)
    {
        revertedNum = revertedNum * 10 + x % 10;
        x /= 10;
    }
    return (revertedNum == temp);
}

int main(int argc, char const *argv[])
{
    int x = 88888;
    cout << boolalpha << isPalindrome(x);
    return 0;
}
