/** 问题描述：
 *  给定 n 个点在 2D 平面上，找到能连成同一直线的最多点的数目。
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

int maxPoints(vector<vector<int>>& points)
{
    /*
        用二重遍历。
        如果x和y值都一样，说明是一个位置的节点。
        如果x值一样，说明是一个直线上，即180度的点，斜率为无穷大。
        剩下的情况就要计算两个点的斜率，保存在map变量中。
        每次循环，统计以第i个点为基准，当前连成直线最多点的数目。
        最后找出最大的。
    */
   
    int res = 0;
    for (int i = 0; i < points.size(); i++)
    {
        int samePoint = 1;
        int overSlope = 0;
        int curMax = 0;
        // unordered_map<double, int> map;
        unordered_map<string, int> map;
        for (int j = i+1; j < points.size(); j++)
        {
            if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
                samePoint++;
            else if (points[i][0] == points[j][0])
                overSlope++;
                // map[INT_MAX]++;
            else
            {
                // double slope = double(points[i][1] - points[j][1]) / double(points[i][0] - points[j][0]);
                // map[slope]++;
                int slope_x = points[i][0] - points[j][0];
                int slope_y = points[i][1] - points[j][1];
                // int g = __gcd(slope_x, slope_y);
                int g = __algo_gcd(slope_x, slope_y);
                slope_x /= g;
                slope_y /= g;
                if (slope_y < 0)
                {
                    slope_x = -slope_x;
                    slope_y = -slope_y;
                }
                stringstream s;
                s << slope_y << "," << slope_x;
                map[s.str()]++;
                curMax = max(curMax, map[s.str()]);
            }
            curMax = max(curMax, overSlope);
        }
        // int curMax = 0;
        // for (auto it = map.begin(); it != map.end(); it++)
        // {
        //     curMax = max(curMax, it->second);
        // }
        curMax += samePoint;
        res = max(res, curMax);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> points{
        {0, 0},
        {0, 1}
    };
    cout << maxPoints(points);
    return 0;
}
