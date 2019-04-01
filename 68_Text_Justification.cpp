/** 问题描述：
 *  给定一组单词数组和一个最大宽度数值，将文字整理为每行占满最大宽度（左和右）。
 *  在每一行中尽可能放更多的单词，每个单词之间至少有一个空格，剩下的位置被空格占据，让每一行都能达到最大宽度数值。
 *  每个单词之间额外的空格要尽可能均匀，如果没法完全均匀，左边的空格要比右边的多。
 *  对于最后一行文字，靠左，不需要额外的空格。
 *  假设单词不包含任何空格，长度都大于零且小于等于最大宽度，数组最少包含一个单词。
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth)
{
    /*
        先计算每一行最多能保存多少个单词，不包含空格数。
        加上空格数之后能保存多少个单词。
        除了最后一个外，在每个单词后面加一个空格。
        从左到右循环填满空格。
        最后一行单独处理。
    */

    // int len = words.size();
    // vector<string> res;
    // int index = 0;//单词索引，该第几个单词
    // int l = len;//保存单词个数
    // while (len > 0)//单词为0就停止
    // {
    //     int cur_width = 0;//某行的当前宽度，每行都初始化为0
    //     string temp = "";//保存当前行单词字符串
    //     int k = 0;//当前行保存单词的数量，每行都初始化为0

    //     while (cur_width <= maxWidth && index+k < l)//计算当前行最多能保存多少个单词，不包含单词之间的空格
    //     {
    //         cur_width += words[index+k].length();//加上当前单词的长度
    //         k++;//当前行单词数加一
    //     }
    //     while (cur_width + k - 1 > maxWidth)//有n个单词，就至少有n-1个空格，所以加上空格数后必须小于等于最大宽度
    //     {
    //         cur_width -= words[index+k-1].length();//减去多的最后那个单词长度
    //         k--;//单词数减少
    //     }
    //     cur_width += k-1;//加上空格数
    //     len = len - k;//单词总数减少k个
    //     for (int i = 0; i < k-1; i++)
    //     {
    //         words[index+i] += " ";//为当前行除了最后一个单词外，每个单词都加一个空格
    //     }

    //     int cir = 0;//一个循环变量
    //     if (cur_width < maxWidth && len > 0)//如果当前行宽度小于最大宽度，等于就退出
    //     {
    //         int remain = maxWidth - cur_width;//remain表示剩余的宽度，也就是要加空格的个数
    //         while (remain > 0)
    //         {
    //             if (k == 1)
    //             {
    //                 words[index] += " ";
    //                 remain--;
    //             }
    //             else
    //             {
    //                 if (cir == k-1)
    //                     cir = 0;//如果循环到最后一个单词，则置0，重新开始
    //                 if (cir < k-1)//每行中如果有一个单词以上，最后一个单词靠右，后面不加任何空格
    //                 {
    //                     words[index+cir] += " ";//除最后一个单词之外，从左到右循环在每个单词后面加空格
    //                     remain--;//加一个空格，剩余宽度-1
    //                 }
    //                 cir++;//循环位置+1
    //             }
    //         }
    //     }

    //     if (cur_width < maxWidth && len == 0)//处理最后一行情况，只在最后一个单词后面填满空格
    //     {
    //         int remain = maxWidth - cur_width;
    //         while (remain > 0)
    //         {
    //             words[index+k-1] += " ";
    //             remain--;
    //         }
    //     }

    //     int fin_index = index + k - 1;//当前行保存k个单词，单词最后一个索引是fin_index
    //     while (index <= fin_index)
    //     {
    //         temp += words[index];//把当前行单词（加空格之后）保存在temp字符串里
    //         index++;
    //     }
    //     res.push_back(temp);//temp保存在结果里，一行单词执行完毕
    // }
    // return res;

    /*
        关键之处在于(maxWidth - l) / (k - 1) + (j < (maxWidth - l) % (k - 1))。
        (maxWidth - l) / (k - 1)解析：n个单词，要在n-1个位置处加空格，平均每个加多少，不考虑余数。
        (maxWidth - l) % (k - 1)解析：计算余数。
        (j < (maxWidth - l) % (k - 1))解析：因为是从左往右加，所以只在前j个位置把余数填满。
        解决了每行中每个单词后面该加几个空格的问题。
    */

    vector<string> res;
    for(int i = 0, k, l; i < words.size(); i += k) {
        for(k = l = 0; i + k < words.size() and l + words[i+k].size() <= maxWidth - k; k++) {
            l += words[i+k].size();
        }
        string tmp = words[i];
        for(int j = 0; j < k - 1; j++) {
            if(i + k >= words.size()) tmp += " ";//除最后一个单词外，每个单词后面先加一个空格
            else tmp += string((maxWidth - l) / (k - 1) + (j < (maxWidth - l) % (k - 1)), ' ');//在每个单词后面加合适数量的空格
            tmp += words[i+j+1];
        }
        tmp += string(maxWidth - tmp.size(), ' ');//处理最后一行的问题
        res.push_back(tmp);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<string> words{"Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"};
    int maxWidth = 20;
    vector<string> res = fullJustify(words, maxWidth);
    for (string s : res)
    {
        cout << s << endl;
        cout << s.length() << endl;
    }
    return 0;
}