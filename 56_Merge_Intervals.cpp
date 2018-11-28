/** 问题描述：
 *  给定一组具有间隔的数字集合，合并所有有重叠间隔的集合。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compar(const Interval& temp1, const Interval& temp2)
{
    return temp1.start < temp2.start;
}

vector<Interval> merge(vector<Interval>& intervals)
{
    /*
        先按照每个数组的start元素进行排序。
        先把第一组数字压入。
        比较res最后那一组的end元素和当前数组的start元素。
        如果小于，则代表没有重合，压入当前数组。
        否则，大于等于，则代表有重合，res最后数组的end元素变换为它和当前数组end元素中大的那一个。
    */

    vector<Interval> res;
    int len = intervals.size();
    if (intervals.empty())
        return res;
    sort(intervals.begin(), intervals.end(), compar);
    // sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {return a.start < b.start;});
    res.push_back(intervals[0]);
    for (int i = 1; i < len; i++)
    {
        if (res.back().end < intervals[i].start)
            res.push_back(intervals[i]);
        else
            res.back().end = max(res.back().end, intervals[i].end);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<Interval> intervals;
    Interval i1 = Interval(1, 4);
    Interval i2 = Interval(0, 0);
    intervals.push_back(i1);
    intervals.push_back(i2);
    vector<Interval> res = merge(intervals);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i].start << " ";
        cout << res[i].end << endl;
    }
    return 0;
}
