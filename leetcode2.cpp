#pragma once
#include <stdio.h>
#include <map>
#include <vector>
#include <stack>
#include <set>
#include <iostream>
#include <list>
#include <queue>
#include <time.h>
#include <sstream>
#include <algorithm>
#include <functional>//因为用了greater<int>()
using namespace std;

//2019.04.18

//703. 数据流中的第K大元素
class KthLargest {//网上
public:
    //定义放在前面了
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
    KthLargest(int k, vector<int> nums) {
        size = k;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if (pq.size() > k) pq.pop();
        }
    }
    int add(int val) {
        pq.push(val);
        if (pq.size() > size) pq.pop();
        return pq.top();
    }
};
//2019.04.19

//347. 前K个高频元素
class Solution347 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // pair<count, val>
        // top k, min heap(小根堆)
        using E = pair<int, int>;
        priority_queue<E, vector<E>, greater<E>> minHeap;
        map<int, int> counter;
        for (auto e : nums) {
            ++counter[e];
        }
        for (auto& x : counter) {
            auto pair = make_pair(x.second, x.first);
            if (minHeap.size() == k) {
                if (pair < minHeap.top()) continue;
                minHeap.pop();
            }
            minHeap.push(move(pair));
        }
        vector<int> res(minHeap.size());
        k = res.size();
        while (!minHeap.empty()) {
            res[--k] = minHeap.top().second;
            minHeap.pop();
        }
        return res;
    }
};
//2019.04.20

//