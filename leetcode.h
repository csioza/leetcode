#pragma once
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int len = nums.size();
    vector<int> rlt;
    map<int, int> keys;
    for (int i = 0; i < len - 1; i++)
    {
        int sub = target - nums[i];
        map<int, int>::iterator iter = keys.find(sub);
        if (iter != keys.end())
        {
            rlt.push_back(iter->second);
            rlt.push_back(i);
            return rlt;
        }
        else
        {
            keys[nums[i]] = i;
        }
    }
    //for(int i = 0; i < len; i++)
    //{
    //    for(int j = len - 1; j > i; j--)
    //    {
    //        int sum = nums[i] + nums[j];
    //        if (sum == target)
    //        {
    //            rlt.push_back(i);
    //            rlt.push_back(j);
    //            return rlt;
    //        }
    //    }
    //}
    return rlt;
}

int main()
{

}