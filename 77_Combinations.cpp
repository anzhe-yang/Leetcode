/** 问题描述：
 *  给定两个整数 n 和 k ，返回 1...n 中所有可能的 k 个数的组合。
 *  从 1 到 n 中挑选出 k 个数，返回所有不同的组合。
 */

#include <iostream>
#include <vector>

using namespace std;

// vector< vector<int> > combine(int n, int k)
// {
//     /*
//         定义一个临时数组temp，为满足规则的一个组合。
//         定义位置元素i，从1开始，如果元素大于n了，则位置退后一位。
//         如果临时数组元素达到k个数，则此组合满足规则，压入结果数组res。
//         剩下的情况就是不满足规则，就将位置加一，将此位置元素复制给下一个位置，下一个循环就将下一个位置元素再加一，直到等于n为止。
//     */

//     vector< vector<int> > res;
//     vector<int> temp(k, 0);
//     int i = 0;
//     while (i >= 0)
//     {
//         temp[i]++;
//         if (temp[i] > n)
//             i--;
//         else if (i == k-1)
//             res.push_back(temp);
//         else
//         {
//             i++;
//             temp[i] = temp[i-1];
//         }
//     }
//     return res;
// }

void combineHelper(vector< vector<int> >& result, vector<int>& oneCombo, int n, int k, int startNum)
{
    if(oneCombo.size() == k) {
        result.push_back(oneCombo);
        return;
    }
    for(int i = startNum; i<=n; ++i){
        oneCombo.push_back(i);
        combineHelper(result,oneCombo,n,k,i+1);
        oneCombo.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) 
{
    /*
        回溯法。
    */

    vector<vector<int> > result;
    vector<int> oneCombo;
    combineHelper(result,oneCombo,n,k,1);
    return result;
}

int main(int argc, char const *argv[])
{
    int n = 4, k = 2;
    vector< vector<int> > res = combine(n, k);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
