/** 问题描述：
 *  给定一组非重叠的间隔数组集合，在整个集合中插入新的间隔数组。
 *  当和原集合有重叠部分时，合并重叠数组。
 *  假设集合是根据间隔数组的第一个数字排序好的。
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

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
    /*
        第一个while循环，解决完全小于（不重叠）new数组的原数组。
        第二个while循环，解决原数组中与new重叠的数组，同时也解决new数组。
        第三个while循环，解决剩下的完全大于（不重叠）new数组的原数组。
    */
   
    vector<Interval> res;
    int len = intervals.size();
    int sign = 0;
    while (sign < len && intervals[sign].end < newInterval.start)
        res.push_back(intervals[sign++]);
    
    while (sign < len && intervals[sign].start <= newInterval.end)
    {
        newInterval.start = min(intervals[sign].start, newInterval.start);
        newInterval.end = max(intervals[sign].end, newInterval.end);
        sign++;
    }
    res.push_back(newInterval);

    while (sign < len)
        res.push_back(intervals[sign++]);

    return res;
}

int main(int argc, char const *argv[])
{
    vector<Interval> intervals;
    Interval i1 = Interval(3, 5);
    Interval i2 = Interval(6, 7);
    Interval i3 = Interval(8, 10);
    intervals.push_back(i1);
    intervals.push_back(i2);
    intervals.push_back(i3);
    Interval newInterval = Interval(4, 8);
    vector<Interval> res = insert(intervals, newInterval);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i].start << " ";
        cout << res[i].end << endl;
    }
    return 0;
}