/** 问题描述：
 *  返回一个无符号数的二进制中 1 的个数。
 */

#include <iostream>

using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        count++;
        n &= (n-1);
    }
    return count;
}

int main(int argc, char const *argv[])
{
    unsigned int num_ten = 43261596;
    bitset<sizeof(int)*8> a(num_ten);
    cout << a << endl;
    cout << hammingWeight(num_ten);
    return 0;
}
