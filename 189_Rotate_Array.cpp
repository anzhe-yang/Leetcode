/** 问题描述：
 *  给定一个数组，将其向右移动 k 步。
 */

#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
    /*
        每次将前k个和后k个元素进行交换，这样后k个元素跑到前面之后位置就正确了。
        这时需要对除了交换后的前k个元素外，其余元素进行处理，按照上述方法。
        直到循环处理完所有元素。
    */
    int n = nums.size();
    for (int start = 0; k = k % n; start += k, n-= k) {
        for (int i = start; i < start+k; i++) {
            int temp = nums[i];
            nums[i] = nums[n - k + i];
            nums[n - k + i] = temp;
        }
        // for (int s : nums) {
        //     cout << s << " ";
        // }
        // cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> nums{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
    int k = 38;
    rotate(nums, k);
    for (int s : nums) {
        cout << s << " ";
    }
    return 0;
}
