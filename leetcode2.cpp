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
#include <functional>//��Ϊ����greater<int>()
using namespace std;

//2019.04.18

//703. �������еĵ�K��Ԫ��
class KthLargest {//����
public:
    //�������ǰ����
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