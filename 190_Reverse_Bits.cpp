/** 问题描述：
 *  反转一个 32bit 的无符号整数。
 */

#include <iostream>
#include <bitset>

using namespace std;

uint32_t reverseBits(uint32_t n) {
    /*
        32位数字，每次对半反转，反转5次即可。
        对1进行与操作，保留原数字，然后进行左移和右移，完成反转操作，之后在合并起来（或操作）。
    */

    n = (n >> 16) | (n << 16); //abcd efgh -> efgh abcd
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8); //efgh abcd -> ghef cdab
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4); //ghef cdab -> hgfe dcba
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2); //g:abcd -> g:cdab
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1); //g:cdab -> g:dcba ✅
    return n;
}

int main(int argc, char const *argv[])
{
    // uint32_t a = 00000010100101000001111010011100;
    unsigned int num_ten = 43261596;
    bitset<sizeof(int)*8> a(num_ten);
    cout << a << endl;
    // cout << reverseBits(num_ten);
    bitset<sizeof(int)*8> b(reverseBits(num_ten));
    cout << b;
    return 0;
}
