/** 给定一个文件的绝对路径，简化它。
 *  举个例子：
 *  /home/ -> /home
 *  /a/./b/../../c/ -> /c
 *  /a/../../b/../c//.// -> /c
 *  /a//b////c/d//././/.. -> /a/b/c
 *  在 unix 文件系统下， . 代表当前目录，所以可以被忽略， .. 上移一个目录，所以无论前一个目录是什么都可以取消。
 *  /../ 应返回 / 。
 *  /home//foo/ 应返回 /home/foo 。
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string simplifyPath(string path)
{
    /*
        stringstream是另一种字符串型的串流，读取字符串进入输入，之后可以使用getline函数进行读取。
        getline可以将读取字符串以某个字符进行分割，存入新的字符，分割结束返回0。
    */

    string res, tmp;
    vector<string> res_temp;
    stringstream ss(path);
    while(getline(ss,tmp,'/'))//将路径字符串以‘/’符号分割开 /home//foo/被分割为 "" "home" "" "foo" 之后就退出while循环
    {
        if (tmp == "" or tmp == ".")//‘.’可以忽略
            continue;
        if (tmp == ".." && !res_temp.empty())//‘..’就弹出上一个目录，如果不为空的话
            res_temp.pop_back();
        else if (tmp != "..") //弹入当前目录
            res_temp.push_back(tmp);
    }
    for(auto str : res_temp) 
        res += "/"+str;
    return res.empty() ? "/" : res;
}

int main(int argc, char const *argv[])
{
    string path = "/home//foo/";
    cout << simplifyPath(path);
    return 0;
}