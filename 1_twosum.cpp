/******************************************************************************************
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
******************************************************************************************/
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> save;
    for(int i = 0; i < nums.size(); ++i){
        for(int j = i+1; j < nums.size(); ++j){
            if(nums[i] + nums[j] == target){
                save.push_back(i);
                save.push_back(j);
            }
        }
    }
    return save;
}
/******************************************************************************************
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> save;
        vector<int> save_num;
        vector<int> result;
        int flag = 0;
        for(int i = 0; i < nums.size(); ++i){
            for(int n = 2; n <= nums.size(); ++n){
                save.clear();
                save_num.clear();
                for(int j = i; j < nums.size(); ++j){
                    save.push_back(j);
                    save_num.push_back(nums[j]);
                    if(save.size() == n){
                        int sum = accumulate(save_num.begin(), save_num.end(), 0);
                        if(sum == target){
                            if(flag == 0){
                                flag = 1;
                                result = save;
                            }
                            if(result.size() > save.size())
                                result = save;
                        }
                        save.pop_back();
                        save_num.pop_back();
                    }
                }
            }
        }
        return result;
    }
};
******************************************************************************************/
int main()
{
    int n[4] = {2, 7, 11, 15};
    vector<int> nums(n, n+4);
    int target = 9;
    vector<int> r = twoSum(nums, target);
    for(int i = 0; i < r.size(); ++i)
        cout << r[i] << " ";
    cout << endl;
}