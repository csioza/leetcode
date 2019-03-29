#pragma once
#include <stdio.h>
#include <map>
#include <vector>
#include <stack>
#include <set>
using namespace std;
#include <time.h>
#include <sstream>
#include <algorithm>

//1. 两数之和
vector<int> twoSum1(vector<int>& nums, int target) {
    int len = nums.size();
    vector<int> rlt;
    for (int i = 0; i < len; i++)
    {
        for (int j = len - 1; j > i; j--)
        {
            int sum = nums[i] + nums[j];
            if (sum == target)
            {
                rlt.push_back(i);
                rlt.push_back(j);
                return rlt;
            }
        }
    }
    return rlt;
}
vector<int> twoSum2(vector<int>& nums, int target) {
    int len = nums.size();
    vector<int> rlt;
    map<int, int> keys;
    for (int i = 0; i < len; i++)
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
    return rlt;
}
//2. 两数相加
//Definition for singly - linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     ListNode* head = l1;
     ListNode* hight = l2;
     ListNode* hight2 = NULL;
     int jinwei = 0;
     while (l1)
     {
         if (l1->next == NULL)
         {
             if (l2 && l2->next)
             {
                 l1->next = l2->next;
                 l2->next = NULL;
             }
             else
             {
                 hight2 = l1;
             }
         }
         if (l1 && l2)
         {
             l1->val += (l2->val + jinwei);
             if (l1->val)
             {
                 jinwei = l1->val / 10;
                 l1->val %= 10;
             }
             else
             {
                 jinwei = 0;
             }
             l1 = l1->next;
             l2 = l2->next;
         }
         else if (l1)
         {
             if (jinwei > 0)
             {
                 l1->val += jinwei;
                 jinwei = l1->val / 10;
                 l1->val %= 10;
             }
             l1 = l1->next;
         }
     }
     if (jinwei > 0 && hight2)
     {
         hight->val = jinwei;
         hight->next = NULL;
         hight2->next = hight;
     }
     return head;
 }
ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
    ListNode* head = l1;
    ListNode* hight = l2;
    int jinwei = 0;
    while (l1)
    {
        if (l2)
        {
            l1->val += (l2->val + jinwei);
            l2 = l2->next;
            if (l1->next == NULL)
            {
                l1->next = l2;
                l2 = NULL;
            }
        }
        else
        {
            l1->val += jinwei;
        }
        if (l1->val >= 10)
        {
            jinwei = l1->val / 10;
            l1->val %= 10;
        }
        else
        {
            jinwei = 0;
        }
        if (l1->next == NULL)
        {
            break;
        }
        l1 = l1->next;
    }
    if (jinwei > 0)
    {
        hight->val = jinwei;
        hight->next = NULL;
        l1->next = hight;
    }
    return head;
}
int main2()
{
    ListNode * l1 = new ListNode(0);
    l1->next = NULL;
    ListNode * l2 = new ListNode(7);
    ListNode * node3 = new ListNode(3);
    l2->next = node3;
    node3->next = NULL;
    ListNode * rlt = addTwoNumbers(l1, l2);
    printf("%d,%d", rlt->val, rlt->next->val);
    getchar();
    return 0;
}
//3. 无重复字符的最长子串
int lengthOfLongestSubstring(string s) {//错误答案
    const char* str = s.c_str();
    int max = 1;
    int cnt = 1;
    int len = strlen(str);
    if (len <= 0)
    {
        return 0;
    }
    map<char, int> keys;
    keys[str[0]] = 0;
    int j = 0;
    for (int i = 0; i < len && j < len;)
    {
        if (j == 0)
        {
            j = i + 1;
        }
        for (; j < len; j++)
        {
            map<char, int>::iterator iter = keys.find(str[j]);
            if (iter != keys.end())
            {
                if (iter->second >= i)
                {
                    cnt = j - i;
                    i = iter->second + 1;
                    keys[str[j]] = j;
                    j++;
                    break;
                }
            }
            else
            {
                cnt++;
            }
            keys[str[j]] = j;
        }
        if (cnt > max)
        {
            max = cnt;
        }
    }
    return max;
}
int lengthOfLongestSubstring2(string s) {
    const char* str = s.c_str();
    int max = 1;
    int cnt = 1;
    int len = strlen(str);
    if (len <= 0)
    {
        return 0;
    }
    map<char, int> keys;
    keys[str[0]] = 0;
    for (int i = 0, j = i + 1; i < len && j < len; j++)
    {
        map<char, int>::iterator iter = keys.find(str[j]);
        if (iter != keys.end())
        {
            if (iter->second >= i)
            {
                i = iter->second + 1;
                cnt = j - i + 1;
            }
            else
            {
                cnt++;
            }
        }
        else
        {
            cnt++;
        }
        keys[str[j]] = j;
        if (cnt > max)
        {
            max = cnt;
        }
    }
    return max;
}
int main3()
{
    string s = "abcabcbb";
    int num = lengthOfLongestSubstring(s);
    printf("%d", num);
    getchar();
    return 0;
}
//4. 寻找两个有序数组的中位数
//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//
//}
//5. 最长回文子串
int main5()
{
    string s = "abcabcbb";
    int num = lengthOfLongestSubstring(s);
    printf("%d", num);
    getchar();
    return 0;
}
//6. Z 字形变换 
//只能找规律
string convert(string s, int numRows) 
{
    const char *str = s.c_str();
    int len = strlen(str);
    string rlt;
    int zhou = 2 * numRows - 2;
    if (zhou <= 0 || len <= 0)//差了个等号zhou <= 0
    {
        return s;
    }
    int numZhou = len / zhou + 1;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numZhou; j++)
        {
            int numnum = zhou * j + i;
            if (numnum < len)
            {
                rlt.push_back(str[numnum]);
            }
            else
            {
                break;
            }
            int gap = (numRows - i - 1) * 2;
            if (gap == 0 || gap == zhou)
            {
                continue;
            }
            numnum += gap;
            if (numnum < len)
            {
                rlt.push_back(str[numnum]);
            }
            else
            {
                break;
            }
        }
    }
    return rlt;
}
int main6()
{
    string s = "LEETCODEISHIRING";
    string s2 = convert(s,4);
    printf("%s", s2.c_str());
    getchar();
    return 0;
}
//7. 整数反转
int reverse(int x) 
{
    int f = 1;
    long long xx = x;
    if (xx < 0)
    {
        f = -1;
        xx = -xx;//这个都能不写，没谁了
    }
    long long rlt = 0;
    while (xx > 0)
    {
        int yu = xx % 10;
        rlt = rlt * 10 + yu;
        xx = xx / 10;
    }
    if (f < 0 && rlt > 2147483648)
    {
        return 0;
    }
    if (f > 0 && rlt > 2147483647)
    {
        return 0;
    }
    rlt *= f;
    return int(rlt);
}
int main7()
{
    int ss = reverse(-123);
    printf("%d", ss);
    getchar();
    return 0;
}
//8. 字符串转换整数 (atoi)
int myAtoi(string str) {
    const char * s = str.c_str();
    int len = strlen(s);
    int isFirst = true;
    int f = 1;
    long long num = 0;
    for (int i = 0; i < len; i++)
    {
        if (isFirst)
        {
            if (s[i] == ' ')
            {
            }
            else if (s[i] == '-')
            {
                f = -1;
                isFirst = false;
            }
            else if (s[i] == '+')
            {
                isFirst = false;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                num = s[i] - '0';
                isFirst = false;
            }
            else
            {
                return 0;
            }
            continue;
        }
        if (s[i] >= '0' && s[i] <= '9')
        {
            if (num > 0xffffffffffffff)
            {
                break;
            }
            num *= 10;
            num += s[i] - '0';
        }
        else
        {
            break;
        }
    }
    //
    if (f < 0 && num > 0x80000000)
    {
        return 0x80000000;
    }
    if (f > 0 && num > 0x7fffffff)
    {
        return 0x7fffffff;
    }
    num *= f;
    return int(num);
}
int main8()
{
    int ss = myAtoi("-91283472332");
    printf("%d", ss);
    getchar();
    return 0;
}
//9. 回文数
bool isPalindrome(int x) {
    if (x < 0)
    {
        return false;
    }
    else if (x == 0)
    {
        return true;
    }
    long long xx = x;
    long long xxx = x;
    long long rnum = 0;
    while (xx > 0)
    {
        if (rnum > 0xffffffffffffff)
        {
            break;
        }
        int yu = xx % 10;
        rnum = rnum * 10 + yu;
        xx = xx / 10;
    }
    if (xxx == rnum)
    {
        return true;
    }
    return false;
}
bool isPalindrome2(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0))
    {
        return false;
    }
    else if (x == 0)
    {
        return true;
    }
    long long xx = x;
    long long rnum = 0;
    while (xx > rnum)
    {
        if (rnum > 0xffffffffffffff)
        {
            break;
        }
        rnum = rnum * 10 + xx % 10;
        xx = xx / 10;
    }
    return (xx == rnum) || ((rnum / 10) == xx);
}
//10. 正则表达式匹配
bool isMatch(string s, string p) {//错误答案
    int slen = s.size();
    int plen = p.size();
    if (slen == 0 || plen == 0)
        return false;
    int charIndex = -1; 
    int i = 0, j = 0;
    for ( ; i < slen; i++)
    {
        if (j >= plen)
            return false;
        if (p[j] == '.')
            j++;
        else if (p[j] == '*')
        {
            if (i > 0 && s[i] == s[i - 1]) 
            {

            }
            else if (j > 0 && p[j - 1] == '.') {}
            else
            {
                for (j++; j < plen && (/*p[j] == '*' || p[j] == '.' ||*/p[j] == s[i - 1]); j++);
                i--;
            }
        }
        else if (s[i] == p[j])
            j++;
        else if (s[i] != p[j] && j + 1 < plen && p[j + 1] == '*')
        {
            i--;
            j+=2;
        }
    }
    if (j < plen)
    {
        for (; j < plen && p[j] == '*'; j++);
        if (j < plen)
            return false;
    }
    return true;
}
int main10()
{
    bool ss = isMatch("ab",".*c");
    if (ss)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    getchar();
    return 0;
}
//13. 罗马数字转整数
//int romanToInt(string s) {
//    
//}
//14. 最长公共前缀
string longestCommonPrefix(vector<string>& strs) 
{
    int strnum = strs.size();
    string rlt;
    if (strnum <= 0 || strs[0].size() <= 0)
    {
        return rlt;
    }
    int size0 = strs[0].size();
    for (int j = 0; size0 > j; ++j)
    {
        char tmp = strs[0][j];
        for (int i = 1; i < strnum; ++i)
        {
            if (j < strs[i].size())
            {
                if (tmp == strs[i][j])
                {

                }
                else
                {
                    return rlt;
                }
            }
            else
            {
                return rlt;
            }
        }
        rlt.push_back(tmp);
    }
    return rlt;
}
//20. 有效的括号
bool isValid(string s) {
    int slen = s.size();
    string stack;
    for (int i = 0; i < slen; ++i)
    {
        int k = stack.size();
        if (k > 0)
        {
            if (stack[k - 1] == '(' && s[i] == ')')
            {
                stack.erase(k - 1);
            }
            else if (stack[k - 1] == '{' && s[i] == '}')
            {
                stack.erase(k - 1);
            }
            else if (stack[k - 1] == '[' && s[i] == ']')
            {
                stack.erase(k - 1);
            }
            else
            {
                stack.push_back(s[i]);
            }
        }
        else
        {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                return false;
            }
            stack.push_back(s[i]);
        }
    }
    int m = stack.size();
    if (m > 0)
    {
        return false;
    }
    return true;
}
//21. 合并两个有序链表
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    ListNode *head = l1;
    ListNode *pre = NULL;
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            pre = l1;
            l1 = l1->next;
        }
        else
        {
            int tmp = l1->val;
            l1->val = l2->val;
            l2->val = tmp;
            //
            ListNode *l11 = l1->next;
            ListNode *l22 = l2->next;
            l1->next = l2;
            l2->next = l11;
            pre = l1;
            l1 = l1->next;
            l2 = l22;
        }
    }
    if (l1 == NULL && pre && l2)
    {
        pre->next = l2;
    }
    return head;
}
//26. 删除排序数组中的重复项
int removeDuplicates(vector<int>& nums) {
    int len = nums.size();
    if (len == 0 || len == 1)
    {
        return len;
    }
    int gap = 0;
    for (int i = 1; i < len; ++i)
    {
        if (nums[i] == nums[i - 1])
        {
            gap++;
        }
        else
        {
            nums[i - gap] = nums[i];
        }
    }
    return len - gap;
}
//27. 移除元素
int removeElement(vector<int>& nums, int val) {
    int len = nums.size();
    if (len == 0)
    {
        return len;
    }
    int gap = 0;
    for (int i = 0; i < len; ++i)
    {
        if (nums[i] == val)
        {
            gap++;
        }
        else
        {
            nums[i - gap] = nums[i];
        }
    }
    return len - gap;
}
//28. 实现strStr()
class Solution28 {
public:
    int strStr2(string haystack, string needle) {
        int hlen = haystack.size();
        int nlen = needle.size();
        if (nlen == 0)
        {
            return 0;
        }
        if (hlen == 0)
        {
            return -1;
        }
        for (int i = 0; i < hlen; i++)
        {
            int k = 0, j = i;
            for (; k < nlen && j < hlen && haystack[j] == needle[k]; j++, k++);
            if (k == nlen)
            {
                return i;
            }
        }
        return -1;
    }
    //
    vector<int> next(string str)
    {
        vector<int> v;
        v.push_back(-1);
        int i = 0, j = -1;
        while (i < str.size())
        {
            if (j == -1 || str[i] == str[j])
            {
                ++i;
                ++j;
                v.push_back(j);
            }
            else
                j = v[j];
        }
        return v;
    }
    int strStr(string haystack, string needle)//KMP
    {
        int i = 0, j = 0;
        int len1 = haystack.size();
        int len2 = needle.size();
        vector<int> nextptr;
        if (needle.empty())
            return 0;
        nextptr = next(needle);
        while ((i < len1) && (j < len2))
        {
            if ((j == -1) || (haystack[i] == needle[j]))
            {
                i++;
                j++;
            }
            else
                j = nextptr[j];
        };
        if (j == needle.size())
            return i - j;
        else
            return -1;
    }
};
int main28()
{
    Solution28 s;
    s.next("abcababc");
    return 0;
}
//35. 搜索插入位置
int searchInsert(vector<int>& nums, int target) {
    int max = nums.size() - 1;
    int min = 0;
    int mid = 0;
    for (; min < max;)
    {
        mid = min + (max - min) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    if (min > max)
        return min;
    if (nums[max] < target)
    {
        return max + 1;
    }
    return max;
}
int searchInsert2(vector<int>& nums, int target) {//错误答案
    int max = nums.size();//考虑不减一情况
    int min = 0;
    int mid = 0;
    for (; min < max;)
    {
        mid = min + (max - min) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    if (min == max)
    {
        return max;
    }
    if (nums[min] < target)
    {
        return min + 1;
    }
    return min;
}
//38. 报数
string countAndSay(int n) {
    string s;
    if (n <= 0)
    {
        return s;
    }
    s.push_back('1');
    for (int i = 2; i <= n; i++)
    {
        string t;
        int len = s.size();
        int cnt = 1;
        int j = 1;
        for (; j < len; j++)
        {
            if (s[j] == s[j - 1])
            {
                cnt++;
            }
            else
            {
                t.push_back('0' + cnt);
                t.push_back(s[j - 1]);
                cnt = 1;
            }
        }
        t.push_back('0' + cnt);
        t.push_back(s[j - 1]);
        s = t;
        printf("%s\n", s.c_str());
    }
    return s;
}
//53. 最大子序和
int maxSubArray(vector<int>& nums) {//我的答案，有点笨
    int len = nums.size();
    if (len <= 0)
    {
        return 0;
    }
    if (len == 1)
    {
        return nums[0];
    }
    vector<int> sums;
    sums.resize(len);
    sums[0] = nums[0];
    for (int i = 1; i < len; i++)
    {
        if (sums[i-1] > 0)
        {
            sums[i] = sums[i - 1] + nums[i];
        }
        else
        {
            sums[i] = nums[i];
        }
    }
    vector<int> sums2;
    sums2.resize(len);
    sums2[len - 1] = nums[len - 1];
    int max = sums[len - 1] + sums2[len - 1] - nums[len - 1];
    for (int j = len - 2; j >= 0; j--)
    {
        if (sums2[j + 1] > 0)
        {
            sums2[j] = sums2[j + 1] + nums[j];
        }
        else
        {
            sums2[j] = nums[j];
        }
        int max2 = sums[j] + sums2[j] - nums[j];
        if (max < max2)
        {
            max = max2;
        }
    }
    return max;
}
int maxSubArray2(vector<int>& nums) {//优秀答案
    int len = nums.size();
    if (len <= 0)
        return 0;
    int max = nums[0];
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (sum > 0)
        {
            sum = sum + nums[i];
        }
        else
        {
            sum = nums[i];
        }
        if (sum > max)
        {
            max = sum;
        }
    }
    return max;
}
int main53()
{
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    int ss = maxSubArray2(nums);
    printf("%d", ss);
    getchar();
    return 0;
}
//54. 螺旋矩阵
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> rlt;
    if (matrix.size() <= 0)
    {
        return rlt;
    }
    int up = 0; 
    int down = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;
    bool isL2R = true;
    bool isZheng = true;
    int i = 0, j = 0;
    while (up <= down && left <= right)
    {
        if (isL2R)
        {
            if (isZheng)
            {
                rlt.push_back(matrix[i][j]);
                if (j < right)
                {
                    j++;
                }
                else
                {
                    up++;
                    isL2R = false;
                    isZheng = true;
                    i = up;
                }
            }
            else
            {
                rlt.push_back(matrix[i][j]);
                if (j > left)
                {
                    j--;
                }
                else
                {
                    down--;
                    isL2R = false;
                    isZheng = false;
                    i = down;
                }
            }
        }
        else
        {
            if (isZheng)
            {
                rlt.push_back(matrix[i][j]);
                if (i < down)
                {
                    i++;
                }
                else
                {
                    right--;
                    isL2R = true;
                    isZheng = false;
                    j = right;
                }
            }
            else
            {
                rlt.push_back(matrix[i][j]);
                if (i > up)
                {
                    i--;
                }
                else
                {
                    left++;
                    isL2R = true;
                    isZheng = true;
                    j = left;
                }
            }
        }
    }
    return rlt;
}
//59. 螺旋矩阵 II
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {
        vector<int> nums;
        nums.resize(n);
        matrix.push_back(nums);
    }
    int up = 0;
    int down = n - 1;
    int left = 0;
    int right = n - 1;
    bool isL2R = true;
    bool isZheng = true;
    int i = 0, j = 0;
    int cnt = 1;
    while (up <= down && left <= right)
    {
        if (isL2R)
        {
            if (isZheng)
            {
                matrix[i][j] = cnt++;
                if (j < right)
                {
                    j++;
                }
                else
                {
                    up++;
                    isL2R = false;
                    isZheng = true;
                    i = up;
                }
            }
            else
            {
                matrix[i][j] = cnt++;
                if (j > left)
                {
                    j--;
                }
                else
                {
                    down--;
                    isL2R = false;
                    isZheng = false;
                    i = down;
                }
            }
        }
        else
        {
            if (isZheng)
            {
                matrix[i][j] = cnt++;
                if (i < down)
                {
                    i++;
                }
                else
                {
                    right--;
                    isL2R = true;
                    isZheng = false;
                    j = right;
                }
            }
            else
            {
                matrix[i][j] = cnt++;
                if (i > up)
                {
                    i--;
                }
                else
                {
                    left++;
                    isL2R = true;
                    isZheng = true;
                    j = left;
                }
            }
        }
    }
    return matrix;
}
int main54()
{
    vector<vector<int>> matrix;
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    vector<int> nums2;
    nums2.push_back(4);
    nums2.push_back(5);
    nums2.push_back(6);
    vector<int> nums3;
    nums3.push_back(7);
    nums3.push_back(8);
    nums3.push_back(9);
    matrix.push_back(nums1);
    matrix.push_back(nums2);
    matrix.push_back(nums3);

    vector<int> ss = spiralOrder(matrix);
    //printf("%d", ss);
    getchar();
    return 0;
}
//58. 最后一个单词的长度
int lengthOfLastWord(string s) {
    int len = s.size();
    int cnt = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            if (cnt == 0)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        else
        {
            cnt++;
        }
    }
    return cnt;
}
//60. 第k个排列
string getPermutation(int n, int k) {
    vector<int> nn;
    vector<int> n1;
    n1.resize(n);
    for (int i = 1; i <= n; i++)
    {
        nn.push_back(i);
    }
    int sum = 1;
    for (int j = 1; j <= n; j++)
    {
        sum *= j;
        n1[n - j] = sum;
    }
    for (int i = 0; i < n; i++)
    {
        if (k >= n1[i])
        {
            if (k = 1)
            {
                break;
            }
            if (i == 0)
            {
                int start = i;
                int end = n - 1;
                while (start < end)
                {
                    int tmp = nn[start];
                    nn[start] = nn[end];
                    nn[end] = tmp;
                    start++;
                    end--;
                }
                break;
            }
            int zheng = k / n1[i];
            int tmp = nn[i - 1];
            nn[i - 1] = nn[i - 1 + zheng];
            nn[i - 1 + zheng] = nn[i];
            nn[i] = tmp;
            int yu = k % n1[i];
            if (yu == 0)
            {
                int start = i + 1;
                int end = n - 1;
                while (start < end)
                {
                    int tmp = nn[start];
                    nn[start] = nn[end];
                    nn[end] = tmp;
                    start++;
                    end--;
                }
                break;
            }
            else if (yu == 1)
            {
                break;
            }
            else
            {
                k = yu;
            }
        }
    }
    string rlt;
    for (int i = 0; i < n; i++)
    {
        rlt.push_back('0' + nn[i]);
    }
    return rlt;
}
int main60()
{
    string ss = getPermutation(3,1);
    printf("%s",ss.c_str());
    getchar();
    return 0;
}
//67. 二进制求和
string addBinary(string a, string b) {//错误答案
    //a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101"
    //b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011"

    int aa = a.size();
    int bb = b.size();
    int cnt = 0;
    int num = 0;
    for (int i = aa - 1, j = bb - 1; i >= 0 || j >= 0; i--,j--,cnt++)
    {
        if (i >= 0)
        {
            int t = a[i] - '0';
            num += (t << cnt);
        }
        if (j >= 0)
        {
            int t = b[j] - '0';
            num += (t << cnt);
        }
    }
    
    if (num & (1<<cnt))//多加了个1 .cnt+1
    {
        cnt++;
    }
    string ss;
    for (int i = cnt - 1; i >= 0; i--)
    {
        if (num & (1 << i))
        {
            ss.push_back('1');
        }
        else
        {
            ss.push_back('0');
        }
    }
    return ss;
}
string addBinary2(string a, string b) {//我的正确答案
    int aa = a.size();
    int bb = b.size();
    string ss;
    int cnt = 0;
    int jin = 0;
    for (int i = aa - 1, j = bb - 1; i >= 0 || j >= 0; i--, j--, cnt++)
    {
        int num = jin;
        if (i >= 0)
        {
            int t = a[i] - '0';
            num += t;
        }
        if (j >= 0)
        {
            int t = b[j] - '0';
            num += t;
        }
        //
        if (num == 0)
        {
            jin = 0;
            ss.push_back('0');
        }
        else if (num == 1)
        {
            jin = 0;
            ss.push_back('1');
        }
        else if (num == 2)
        {
            jin = 1;
            ss.push_back('0');
        }
        else if (num == 3)
        {
            jin = 1;
            ss.push_back('1');
        }
    }
    if (jin > 0)
    {
        ss.push_back('1');//漏写了
    }
    cnt = ss.size();
    for (int i = 0,j = cnt - 1; i < j; i++,j--)
    {
        char tmp = ss[i];
        ss[i] = ss[j];
        ss[j] = tmp;
    }
    return ss;
}
int main67()
{
    string ss = addBinary2("11","1");
    printf("%s", ss.c_str());
    getchar();
    return 0;
}
//69. x 的平方根
int mySqrt(int x) {
    long long min = 0;
    long long max = x;
    while (min < max)
    {
        long long mid = min + (max - min) / 2;//边界问题确实恶心
        long long mm = mid * mid;//int老溢出 
        if (x > mm)
        {
            min = mid + 1;
        }
        else if (x < mm)
        {
            max = mid - 1;
        }
        else//x == mm
        {
            return mid;
        }
    }
    int rlt = min > max ? max : min;
    if (rlt * rlt > x)
    {
        rlt--;
    }
    return rlt;
}
int mySqrt2(int x) {//神奇的代码
    long long t = x;
    t = 0x5f3759df - (t >> 1);
    while (!(t*t <= x && (t + 1)*(t + 1) > x))
        t = (x / t + t) / 2;
    return (int)t;
}
int main69()
{
    int ss = mySqrt(8);
    printf("%d", ss);
    getchar();
    return 0;
}
//70. 爬楼梯
int climbStairs(int n) {
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    int f1 = 1;
    int f2 = 2;
    int sum = 0;
    for (int i = 3; i <= n; i++)
    {
        sum = f1 + f2;
        f1 = f2;
        f2 = sum;
    }
    return sum;
}
int main70()
{
    int ss = climbStairs(2);
    printf("%d", ss);
    getchar();
    return 0;
}
//83. 删除排序链表中的重复元素
/**
*Definition for singly - linked list.
* struct ListNode {
    *int val;
    *ListNode *next;
    *ListNode(int x) : val(x), next(NULL) {}
    *
};
*/
ListNode* deleteDuplicates(ListNode* head) {
    if (!head)
    {
        return head;
    }
    ListNode* pre = head;
    ListNode* p = head->next;
    while (p)
    {
        if (pre->val == p->val)
        {
            pre->next = p->next;
            p = p->next;
        }
        else
        {
            pre = pre->next;
            p = p->next;
        }
    }
    return head;
}
//88. 合并两个有序数组
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int len = m + n;
    for (int i = len - 1,k = m - 1,j = n - 1; i >= 0; i--)
    {
        if (k >= 0 && j >= 0)
        {
            if (nums1[k] > nums2[j])
            {
                nums1[i] = nums1[k];
                k--;
            }
            else
            {
                nums1[i] = nums2[j];
                j--;
            }
        }
        else if (k >= 0)
        {
            nums1[i] = nums1[k];
            k--;
        }
        else if (j >= 0)
        {
            nums1[i] = nums2[j];
            j--;
        }
    }
}
int main88()
{
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(0);
    nums1.push_back(0);
    nums1.push_back(0);
    vector<int> nums2;
    nums2.push_back(2);
    nums2.push_back(5);
    nums2.push_back(6);
    merge(nums1, 3,nums2,3);
    getchar();
    return 0;
}
//100. 相同的树
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL)
    {
        return true;
    }
    if (p == NULL || q == NULL)
    {
        return false;
    }
    if (p->val != q->val)
    {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
//101. 对称二叉树
bool isSymmetric(TreeNode* root) {//迭代方法
    if (root == NULL)
        return true;
    vector<TreeNode*> val;
    val.push_back(root);
    int i = 0;
    while (i < val.size())
    {
        int len = val.size();
        for (; i < len; i++)
        {
            if (val[i])
            {
                val.push_back(val[i]->left);
                val.push_back(val[i]->right);
            }
        }
        //检查一层是否镜像
        for (int j = i, k = val.size() - 1; j < k; j++,k--)
        {
            if (val[j] && val[k])
            {
                if (val[j]->val != val[k]->val)
                    return false;
            }
            else if (val[j] == NULL && val[k] == NULL)
            {
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
bool isSymmetric3(TreeNode* left, TreeNode* right)
{
    if (left == NULL && right ==NULL)
    {
        return true;
    }
    else if (left && right)
    {
        if (left->val == right->val)
        {
            return isSymmetric3(left->right, right->left) && isSymmetric3(left->left, right->right);
        }
        return false;
    }
    else
    {
        return false;
    }
}
bool isSymmetric2(TreeNode* root) {//递归方法
    if (root == NULL)
        return true;
    return isSymmetric3(root->left,root->right);
}
//104. 二叉树的最大深度
int maxDepth(TreeNode* root) {
    if (root == NULL)
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return (left > right ? left : right) + 1;
}
//107. 二叉树的层次遍历 II
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> rlt;
    vector<TreeNode*> treelist;
    if (root == NULL)
    {
        return rlt;
    }
    vector<int> tmp;
    tmp.push_back(root->val);
    rlt.push_back(tmp);
    treelist.push_back(root);
    int i = 0;
    while (true)
    {
        int len = treelist.size();
        for ( ; i < len; i++)
        {
            if (treelist[i]->left)
            {
                treelist.push_back(treelist[i]->left);
            }
            if (treelist[i]->right)
            {
                treelist.push_back(treelist[i]->right);
            }
        }
        len = treelist.size();
        if (i < len)
        {
            vector<int> tmp1;
            for (int j = i; j < len; j++)
            {
                tmp1.push_back(treelist[j]->val);
            }
            rlt.push_back(tmp1);
        }
        else
        {
            break;
        }
    }
    vector<vector<int>> rlt2;
    int rltLen = rlt.size();
    for (int m = rltLen - 1; m >= 0; m--)
    {
        rlt2.push_back(rlt[m]);
    }
    return rlt2;
}
//108. 将有序数组转换为二叉搜索树
TreeNode* sortedArrayToBST2(vector<int>& nums, int min, int max) {
    if (min > max)
        return NULL;
    int mid = min + (max - min) / 2;
    int val = nums[mid];
    TreeNode * node = new TreeNode(val);
    node->left = sortedArrayToBST2(nums, min, mid - 1);
    node->right = sortedArrayToBST2(nums, mid + 1, max);
    return node;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    int len = nums.size();
    if (len == 0)
        return NULL;
    return sortedArrayToBST2(nums,0,len-1);
}
int main108()
{
    vector<int> nums;
    nums.push_back(-10);
    nums.push_back(-3);
    nums.push_back(0);
    nums.push_back(5);
    nums.push_back(9);
    sortedArrayToBST(nums);
    getchar();
    return 0;
}
//110. 平衡二叉树
bool isisBalanced(TreeNode* root, int &num)
{
    if (root == NULL)
    {
        num = 0;
        return true;
    }
    int left = 0;
    bool bl = isisBalanced(root->left, left);
    int right = 0;
    bool br = isisBalanced(root->right, right);
    if (bl && br)
    {
        int max = left > right ? left : right;
        int min = left > right ? right : left;
        if (max - min >= 2)
        {
            return false;
        }
        else
        {
            num = max + 1;
        }
    }
    else
    {
        return false;
    }
    return true;
}
//111. 二叉树的最小深度
int minDepth(TreeNode* root) {
    if (root == NULL)
        return 0;
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    int min = 1;
    if (left == 0 && right == 0)
    {
    }
    else if (left != 0 && right != 0)
    {
        min += (left > right ? right : left);
    }
    else if (left > 0)
    {
        min += left;
    }
    else if (right > 0)
    {
        min += right;
    }
    return min;
}
bool isBalanced(TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }
    int num = 0;
    return isisBalanced(root, num);
}
//112. 路径总和
bool hasPathSum(TreeNode* root, int sum) {//错误答案，其实看怎么理解
    if (root == NULL)
    {
        if (sum == 0)
            return true;
        else
            return false;
    }
    if (root->val == sum/*&& root->left == NULL && root->right == NULL*/)
        return true;
    bool left = hasPathSum(root->left, sum - root->val);
    bool right = hasPathSum(root->right, sum - root->val);
    return left || right;
}
bool hasPathSum2(TreeNode* root, int sum) {//我的正确答案
    if (root == NULL)
        return false;
    if (root->val == sum && root->left == NULL && root->right == NULL)
        return true;
    bool left = false;
    bool right = false;
    if (root->left)
    {
        left = hasPathSum(root->left, sum - root->val);
    }
    if (root->right)
    {
        right = hasPathSum(root->right, sum - root->val);
    }
    return left || right;
}
//118. 杨辉三角
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> rlt;
    for (int i = 0; i < numRows; i++)
    {
        vector<int> tmp;
        tmp.resize(i + 1);
        tmp[0] = 1;
        tmp[i] = 1;
        if (i >= 2)
        {
            for (int j = 1;j < i; j++)
            {
                tmp[j] = rlt[i - 1][j - 1] + rlt[i - 1][j];
            }
        }
        rlt.push_back(tmp);
    }
    return rlt;
}
//119. 杨辉三角 II
vector<int> getRow(int rowIndex) {
    vector<int> rlt;
    for (int i = 0; i <= rowIndex; i++)
    {
        rlt.push_back(1);
        if (i >= 2)
        {
            int tmp = rlt[0];
            for (int j = 1; j < i; j++)
            {
                int tmp2 = rlt[j];//这块有点绕
                rlt[j] = rlt[j] + tmp;
                tmp = tmp2;//这块有点绕
            }
        }
    }
    return rlt;
}
//121. 买卖股票的最佳时机
int maxProfit(vector<int>& prices) {
    int len = prices.size();
    int minpos = 0;
    int maxsub = 0;
    for (int i = 1; i < len; i++)
    {
        if (prices[i] < prices[minpos])
        {
            minpos = i;
            continue;
        }
        int sub = prices[i] - prices[minpos];
        if (sub > maxsub)
        {
            maxsub = sub;
        }
    }
    return maxsub;
}
//122. 买卖股票的最佳时机 II
int maxProfit2(vector<int>& prices) {
    int len = prices.size();
    int minpos = 0;
    int maxsub = 0;
    for (int i = 1; i < len; i++)
    {
        if (prices[i] < prices[minpos])
        {
            minpos = i;
            continue;
        }
        int sub = prices[i] - prices[minpos];
        maxsub += sub;
        minpos = i;
    }
    return maxsub;
}
//123. 买卖股票的最佳时机 III
int maxProfit3(vector<int>& prices) {
    return 0;
}
//125. 验证回文串
bool isPalindrome(string s) {//错误答案
    int len = s.size();
    int i = 0;
    int j = len - 1;
    for (;i < j;)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
            continue;
        }
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            int sub = s[i] - s[j];
            if ((s[i] >= 'a' && sub == 32) || (s[i] <= 'Z' && sub == -32))
            {
                i++;
                j--;
            }
            else
            {
                if ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))
                {
                    return false;
                }
                else
                {
                    j--;
                }
            }
        }
        else
        {
            i++;
        }
        if ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))
        {
        }
        else
        {
            j--;
        }
    }
    return true;
}
bool isPalindrome2(string s) {//老老实实写各个case
    int len = s.size();
    int i = 0;
    int j = len - 1;
    for (; i < j;)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
            continue;
        }
        bool i09 = (s[i] >= '0' && s[i] <= '9');
        bool iaz = (s[i] >= 'a' && s[i] <= 'z');
        bool iAZ = (s[i] >= 'A' && s[i] <= 'Z');
        bool j09 = (s[j] >= '0' && s[j] <= '9');
        bool jaz = (s[j] >= 'a' && s[j] <= 'z');
        bool jAZ = (s[j] >= 'A' && s[j] <= 'Z');
        if (!i09 && !iaz && !iAZ)
        {
            i++;
            continue;
        }
        if (!j09 && !jaz && !jAZ)
        {
            j--;
            continue;
        }
        if (iaz && jAZ && s[i] - s[j] == 32)
        {
            i++;
            j--;
            continue;
        }
        if (iAZ && jaz && s[i] - s[j] == -32)
        {
            i++;
            j--;
            continue;
        }
        return false;
    }
    return true;
}
int main125()
{
    bool ss = isPalindrome("A man, a plan, a canal: Panama");
    printf("%d", ss);
    getchar();
    return 0;
}
//136. 只出现一次的数字
int singleNumber(vector<int>& nums) {
    int len = nums.size();
    if (len == 0)
    {
        return 0;
    }
    for (int i = 1; i < len; i++)
    {
        nums[0] ^= nums[i];
    }
    return nums[0];
}
//141. 环形链表
bool hasCycle(ListNode *head) {//错误答案
    if (head == NULL)
        return false;
    ListNode * p = head->next;
    ListNode * pp = head;
    while (true)
    {
        if (p->next == NULL || pp->next == NULL || pp->next->next == NULL)
            return false;
        if (p == pp)
            return true;
        p = p->next;//又忘写了
        pp = pp->next->next;//又忘写了
    }
    return false;
}
bool hasCycle2(ListNode *head) {//我的正确答案

    if (head == NULL)
        return false;
    ListNode * p = head/*->next*/;
    ListNode * pp = head;
    while (/*p && */pp)
    {
        if (pp->next == NULL || pp->next->next == NULL)
            return false;
        p = p->next;//又忘写了
        pp = pp->next->next;//又忘写了
        if (p == pp)
            return true;
    }
    return false;
}
//155. 最小栈
class MinStack {
public:
    /** initialize your data structure here. */
    int data[1024];
    int len;
    int min;
    MinStack() : len(0), min(0){
        memset(data, 0, sizeof(data));
    }
    void push(int x) {
        if (len < 1024)
        {
            data[len++] = x;
            if (x > min)
            {
                min = x;
            }
        }
    }
    void pop() {
        if (len > 0)
        {
            len--;
        }
    }
    int top() {

    }
    int getMin() {

    }
};
//160. 相交链表
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* ap = headA;
    ListNode* bp = headB;
    while (true)
    {
        if (ap == NULL || bp == NULL)
            return NULL;
        if (ap == bp)
            return ap;
        //
        if (ap->next == NULL)
        {
            ap = headB;
            headB = NULL;//没有写就过不了
        }
        else
            ap = ap->next;
        //
        if (bp->next == NULL)
        {
            bp = headA;
            headA = NULL;//没有写就过不了
        }
        else
            bp = bp->next;
    }
    return NULL;
}
//167. 两数之和 II - 输入有序数组
vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> rlt;
    int len = numbers.size();
    if (len <= 1)
    {
        return rlt;
    }
    for (int i = 0, j = len - 1; i < j; )
    {
        int sum = numbers[i] + numbers[j];
        if (sum > target)
        {
            j--;
        }
        else if (sum < target)
        {
            i++;
        }
        else
        {
            rlt.push_back(i + 1);
            rlt.push_back(j + 1);
            break;//忘写了
        }
    }
    return rlt;
}
//168. Excel表列名称
string convertToTitle(int n) {//难点在于没有0
    string s;
    while (n > 0)
    {
        int yu = n % 26;
        n /= 26;
        if (yu > 0)
        {
            s.push_back(yu + 64);
        }
        else
        {
            s.push_back('Z');
            n--;
        }
    }
    int slen = s.size();
    for (int i = 0, j = slen -1; i < j; i++,j--)
    {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
    return s;
}
//171. Excel表列序号
int titleToNumber(string s) {
    int len = s.size();
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        int num = s[i] - 64;
        sum = sum * 26 + num;
    }
    return sum;
}
//169. 求众数
int majorityElement(vector<int>& nums) {
    int len = nums.size();
    if (len == 0)
        return -1;
    int zhong = nums[0];
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        if (zhong == nums[i])
        {
            cnt++;
        }
        else
        {
            if (cnt <= 0)//***
            {
                zhong = nums[i];
                cnt = 0;//***
            }
            else
            {
                cnt--;//***
            }
        }
    }
    return zhong;
}
//172. 阶乘后的零
int trailingZeroes(int n) {//5,25,125,625...
    int sum = 0;
    while (n)
    {
        n /= 5;
        sum += n;
    }
    return sum;
}
//175. 组合两个表 MySQL
//select FirstName, LastName, City, State
//from
//Person left join Address
//on Person.PersonId = Address.PersonId;

//176. 第三高的薪水
//SELECT * FROM table LIMIT[offset, ] rows | rows OFFSET offset

//SELECT
//IFNULL(
//(SELECT DISTINCT Salary
//    FROM Employee
//    ORDER BY Salary DESC
//    LIMIT 1 OFFSET 2),
//    NULL) AS SecondHighestSalary;

//181. 超过经理收入的员工
//select A.Name as Employee
//from Employee as A left join Employee as B
//on A.ManagerId = B.Id
//where A.ManagerId = B.Id and A.Salary > B.Salary;//***A.ManagerId = B.Id

//select A.Name as Employee
//from Employee as A, Employee as B
//where A.ManagerId = B.Id and A.Salary > B.Salary;

//182. 查找重复的电子邮箱
//select Email
//from Person
//group by Email
//having count(Email) > 1;

//183. 从不订购的客户
//select Name as Customers
//from Customers
//where Id not in
//(select distinct CustomerId from Orders);

//select Name as Customers
//from Customers left join Orders
//on Customers.Id = Orders.CustomerId
//where Orders.CustomerId is null;

//189. 旋转数组
void rotate(vector<int>& nums, int k) {//错误答案
    int len = nums.size();
    k %= len;
    if (len <= 0 || k <= 0)
        return;
    if (len % k == 0)
    {
        for (int j = 0; j < k; j++)
        {
            int len2 = len / k;
            int tmp = nums[j];
            int ik = (j + k) % len;
            for (int i = 0; i < len2; i++)
            {
                int tmp2 = nums[ik];
                nums[ik] = tmp;
                tmp = tmp2;
                ik = (ik + k) % len;
            }
        }
    }
    else
    {
        int tmp = nums[0];
        int ik = k % len;
        for (int i = 0; i < len; i++)
        {
            int tmp2 = nums[ik];
            nums[ik] = tmp;
            tmp = tmp2;
            ik = (ik + k) % len;
        }
    }
}
//190. 颠倒二进制位
uint32_t reverseBits(uint32_t n) {
    uint32_t rlt = 0;
    for (int i = 0; i < 32; i++)
    {
        rlt <<= 1;
        rlt |= (n & 1);
        n >>= 1;// n = n >> i;//不应是i呀
    }
    return rlt;
}

int main190()
{
    reverseBits(43261596);
    return 0;
}

//191. 位1的个数
int hammingWeight(uint32_t n) {
    int cnt = 0;
    while (n > 0)
    {
        n = n&(n - 1);
        cnt++;
    }
    return cnt;
}

//196. 删除重复的电子邮箱
//delete p1 from Person p1, Person p2
//where p1.Email = p2.Email and p1.Id > p2.Id

//197. 上升的温度
//select w1.id
//from weather w1, weather w2
//where w1.Temperature > w2.Temperature and w2.RecordDate = DATE_SUB(w1.RecordDate, INTERVAL 1 DAY)

//202. 快乐数
bool isHappy(int n) {
    int limit = 1000;
    while (n != 1 && limit > 0)
    {
        int nn = 0;
        while (n > 0)
        {
            int y = n % 10;
            n /= 10;
            nn += (y*y);
        }
        n = nn;
        limit--;
    }
    if (limit == 0)
    {
        return false;
    }
    return true;
}

//203. 移除链表元素
ListNode* removeElements(ListNode* head, int val) {
    ListNode*pre = head;
    ListNode*p = head;
    while (p)
    {
        if (p->val == val)
        {
            if (pre == head)//pre不对，应该改为p
            {
                head = pre->next;
                delete pre;
                p = head;
                pre = head;
            }
            else
            {
                pre->next = p->next;
                ListNode * q = p;
                p = p->next;
                delete q;
            }
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
    return head;
}

//204. 计数质数
int countPrimes(int n) {
    bool *isPrime = new bool[n];
    for (int i = 2; i < n; i++) {
        isPrime[i] = true;
    }
    for (int i = 2; i * i < n; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j < n; j += i) {
            isPrime[j] = false;
        }
    }
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) count++;
    }
    return count;
}
//206. 反转链表
ListNode* reverseList(ListNode* head) {
    if (head == NULL)
        return head;
    ListNode* p = head->next;
    head->next = NULL;//***
    while (p)
    {
        ListNode* q = p->next;//***
        p->next = head;
        head = p;
        p = q;
    }
    return head;
}

//217. 存在重复元素 快速排序 ==

//bool containsDuplicate(vector<int>& nums) {
//    vector<int> num(nums);
//    sort(num.begin(), num.end());
//    num.erase(unique(num.begin(), num.end()), num.end());  //排序后去除重复元素
//
//    return(num.size() < nums.size());
//}

void MySwap(int &a, int &b)//300亿次对比，比下面的快2.5%
{
    if (a != b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
}
void MySwap2(int &a, int &b)
{
    if (a != b)
    {
        int t = a;
        a     = b;
        b     = t;
    }
}
void MySwap3(int *arr, int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
void MySwap4(int *arr, int a, int b)
{
    //printf("\n arr[%d]=%d, arr[%d]=%d", a,arr[a], b,arr[b]);
    if (arr[a] != arr[b])
    {
        arr[a] = arr[a] ^ arr[b];
        arr[b] = arr[a] ^ arr[b];
        arr[a] = arr[a] ^ arr[b];
    }
    //printf(" ====> arr[%d]=%d, arr[%d]=%d", a, arr[a], b, arr[b]);
}
void QuickSort(int *arr, int p, int r)
{
    if (p <= r)
    {
        int j = p;
        for (int i = p + 1; i <= r; ++i)
        {
            if (arr[p] > arr[i])
            {
                MySwap(arr[i], arr[++j]);
                //MySwap3(arr,i,++j);
            }
        }
        MySwap(arr[p], arr[j]);
        //MySwap3(arr, p, j);
        //
        QuickSort(arr, p, j - 1);
        QuickSort(arr, j + 1, r);
    }
}
void QuickSortVec(vector<int>& arr, int p, int r)
{
    if (p <= r)
    {
        int j = p;
        for (int i = p + 1; i <= r; ++i)
        {
            if (arr[p] > arr[i])
                MySwap(arr[i], arr[++j]);
        }
        MySwap(arr[p], arr[j]);
        //
        QuickSortVec(arr, p, j - 1);
        QuickSortVec(arr, j + 1, r);
    }
}
int main217()
{
    long long N = 10000000000;
    printf("\n    交换1和2, %d亿次",N/100000000);
    {
        int m = 1, n = 2;
        clock_t start, ends;
        start = clock();
        for (long long i = 0; i < N; i++)
        {
            MySwap(m, n);
        }
        ends = clock();
        printf("\n    MySwap1:start[%6d],end[%6d],sub[%6d]", start, ends, ends - start);//191s,188s,189s
    }
    {
        int m = 1, n = 2;
        clock_t start, ends;
        start = clock();
        for (long long i = 0; i < N; i++)
        {
            MySwap2(m, n);
        }
        ends = clock();
        printf("\n    MySwap2:start[%6d],end[%6d],sub[%6d]", start, ends, ends - start);//191s,188s,189s
    }
    getchar();
    return 0;
}
//
int main2171()
{
    int m = 1, n = 2;
    time_t t1 = time(0);
    for (long long i = 0; i < 100000000000; i++)
    {
        if (i>0)
        {
        }
    }
    time_t t2 = time(0);
    printf("\nstart[%d],end[%d],sub[%d]", t1, t2, t2 - t1);//145,146

    m = 1, n = 2;
    int j = 0;
    t1 = time(0);
    for (long long i = 0; i < 100000000000; i++)
    {
        j = i + 3;
    }
    t2 = time(0);
    printf("\nstart[%d],end[%d],sub[%d]", t1, t2, t2 - t1);//195,192

    m = 1, n = 2;
    j = 0;
    t1 = time(0);
    for (long long i = 0; i < 100000000000; i++)
    {
        if (i > 0)
        {
            j = i + 3;
        }
    }
    t2 = time(0);
    printf("\nstart[%d],end[%d],sub[%d]", t1, t2, t2 - t1);//-,308
    getchar();
    return 0;
}
int main2172()
{
    int m = 1, n = 2;
    time_t t1 = time(0);
    for (long long i = 0; i < 10000000000; i++)
    {
        m << 10;//<<2 18s <<1 16s <<10 17s <<10 16s <<10 100000000000 162
        m >> 10;
    }
    time_t t2 = time(0);
    printf("\nstart[%d],end[%d],sub[%d]", t1, t2, t2 - t1);//145,146

    m = 1, n = 2;
    int j = 0;
    t1 = time(0);
    for (long long i = 0; i < 10000000000; i++)
    {
        m *= 1024;//  24s   24s   24s   24s 100000000000 231
        m >> 10;
    }
    t2 = time(0);
    printf("\nstart[%d],end[%d],sub[%d]", t1, t2, t2 - t1);//195,192
    getchar();
    return 0;
}
//226. 翻转二叉树
TreeNode* invertTree(TreeNode* root) {
    if (root == NULL)
        return root;
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
    return root;//别忘记写
}
//231. 2的幂
bool isPowerOfTwo(int n) {
    if (n <= 0)//漏写=号
        return false;
    n = n & (-n);
    if (n == 0)
        return true;
    return false;
}
//234. 回文链表
bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;
    ListNode*p = head->next;
    ListNode*p2 = p ? p->next : NULL;
    while (p2)
    {
        p  = p->next;
        p2 = p2->next ? p2->next->next : NULL;
    }
    //p中间偏后的节点 反转p后面的节点
    p2 = p->next;
    p->next = NULL;
    while (p2)
    {
        ListNode * tmp = p2->next;
        p2->next = p;
        p = p2;
        p2 = tmp;
    }
    p2 = p;
    while (p2)
    {
        if (head->val == p2->val)
        {
            head = head->next;
            p2 = p2->next;
        }
        else
        {
            return false;
        }
    }
    return true;
}
//235. 二叉搜索树的最近公共祖先
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {//通用
    if (root == NULL)
        return NULL;
    if (root == p)
        return p;
    if (root == q)
        return q;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    return root;
}
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {//BST
    if (root == NULL)
        return NULL;
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor2(root->left, p, q);
    if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor2(root->right, p, q);
    return root;
}
//237. 删除链表中的节点
void deleteNode(ListNode* node) {
    if (node == NULL || node->next == NULL)
        return;
    node->val = node->next->val;
    node->next = node->next->next;
}
//257. 二叉树的所有路径
void binaryTreePaths2(vector<string> &v,TreeNode* root,string ss) {//我的答案
    if (root == NULL)
        return;
    ss.append("->");
    std::stringstream s3s;
    s3s << root->val;
    ss.append(s3s.str());
    if (root->left == NULL && root->right == NULL)
    {
        v.push_back(ss);
        return;
    }
    if (root->left)
        binaryTreePaths2(v, root->left, ss);
    if (root->right)
        binaryTreePaths2(v, root->right, ss);
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> v;
    if (root == NULL)
    {
        return v;
    }
    std::stringstream s3s;
    s3s << root->val;
    string ss = s3s.str();
    if (root->left == NULL && root->right == NULL)
    {
        v.push_back(ss);
        return v;
    }
    binaryTreePaths2(v, root->left, ss);
    binaryTreePaths2(v, root->right, ss);
    return v;
}
//别人写的
void preOrder(TreeNode *root, vector<string> &res, string arr)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        arr += to_string(root->val);
        res.push_back(arr);
        return;
    }
    arr = arr + to_string(root->val) + "->";
    preOrder(root->left, res, arr);
    preOrder(root->right, res, arr);
}
//vector<string> binaryTreePaths(TreeNode *root)
//{
//    vector<string> res;
//    preOrder(root, res, "");
//    return res;
//}
//int main257()
//{
//    TreeNode*n1 = new TreeNode(1);
//    TreeNode*n2 = new TreeNode(2);
//    TreeNode*n3 = new TreeNode(3);
//    TreeNode*n4 = new TreeNode(5);
//    n1->left = n2;
//    n1->right = n3;
//    n2->right = n4;
//    n2->left = NULL;
//    n3->left = NULL;
//    n3->right = NULL;
//    vector<string> vv = binaryTreePaths(n1);
//    for (int i = 0; i < vv.size(); i++)
//    {
//        printf("\n%s", vv[i].c_str());
//    }
//    getchar();
//    return 0;
//}

//263. 丑数
bool isUgly(int num) {
    if (num < 0)
        return false;
    while (num != 1)
    {
        if (num % 2 == 0)
            num /= 2;
        else if (num % 3 == 0)
            num /= 3;
        else if (num % 5 == 0)
            num /= 5;
        else
            return false;
    }
    return true;
}
bool isUgly2(int num) {

    if (num <= 0) return false;
    while (num % 2 == 0)
        num /= 2;
    while (num % 3 == 0)
        num /= 3;
    while (num % 5 == 0)
        num /= 5;
    return num == 1;
}
//268. 缺失数字
int missingNumber(vector<int>& nums) {
    int len = nums.size();
    int nlen = len + 1;
    int s = 0;
    for (int i = 0; i < nlen; i++)
    {
        s ^= i;
        if (i < len)
            s ^= nums[i];
    }
    return s;
}
//
bool isBadVersion(int version) { return false; }
int firstBadVersion(int n) {
    int min = 1;
    int max = n;
    int mid = 0;
    while (min <= max)//得有等号
    {
        mid = min + (max - min) / 2;
        if (isBadVersion(mid))
        {
            if (mid >= 2)
            {
                if (isBadVersion(mid - 1))
                    max = mid - 1;
                else
                    return mid;
            }
            else
                return mid;
        }
        else
        {
            if (mid < n)
            {
                if (isBadVersion(mid + 1))
                    return mid + 1;
                else
                    min = mid + 1;
            }
            else
                return mid;
        }
    }
    return mid;
}
//283. 移动零
void moveZeroes(vector<int>& nums) {
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            cnt++;
        }
        else
        {
            if (cnt > 0)//忘写了
            {
                nums[i - cnt] = nums[i];
                nums[i] = 0;
            }
        }
    }
}
//292. Nim游戏
bool canWinNim(int n) {
    return n % 4 != 0;
}
//326. 3的幂
//342. 4的幂
bool isPowerOfThree(int n) {
    while (n > 1)
    {
        if (n % 3 != 0)
        {
            return false;
        }
        n /= 3;
    }
    if (n == 1)
        return true;
    return false;
}
//344. 反转字符串
void reverseString(vector<char>& s) {
    for (int i = 0, j = s.size() - 1; i < j; i++,j--)
    {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}
//345. 反转字符串中的元音字母
string reverseVowels(string s) {
    bool is_i = false;
    bool is_j = false;
    for (int i = 0, j = s.size() - 1; i < j; )
    {
        if (!is_i)
            is_i = s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
            || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U';
        if (!is_j)
            is_j = s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'
            || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U';
        if (is_i && is_j)
        {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
            is_i = false;
            is_j = false;
        }
        else if (is_i)
        {
            j--;
            is_j = false;
        }
        else if (is_j)
        {
            i++;
            is_i = false;
        }
        else
        {
            i++;
            j--;
            is_i = false;
            is_j = false;
        }
    }
    return s;
}
//367. 有效的完全平方数
bool isPerfectSquare(int num) {
    if (num <= 0)
        return false;
    unsigned long long min = 1;
    unsigned long long max = num;
    unsigned long long mid = 0;
    unsigned long long numl = num;
    while (min <= max)//少写了=号
    {
        mid = min + (max - min) / 2;
        unsigned long long mm = mid * mid;
        if (numl == mm)
            return true;
        else if (numl > mm)
            min = mid + 1;
        else
            max = mid - 1;
    }
    return false;
}
//371. 两整数之和
int getSum(int a, int b) {//-1 + 1 报错
    return b == 0 ? a : getSum(a^b, (a&b) << 1);
}
//
unsigned int getSum3(unsigned int a, unsigned int b) {
    return b == 0 ? a : getSum3(a^b, (a&b) << 1);
}
int getSum4(int a, int b) {
    unsigned int aa = (unsigned int)a;
    unsigned int bb = (unsigned int)b;
    return (int)getSum3(aa, bb);
}
//
int getSum2(int a, int b) {
    unsigned int aa = (unsigned int)a;
    unsigned int bb = (unsigned int)b;
    while (bb != 0)
    {
        unsigned int y = aa^bb;
        bb = (aa&bb) << 1;
        aa = y;
    }
    return (int)aa;
}
//374. 猜数字大小
int guess(int num) { return 0; }
int guessNumber(int n) {
    if (n <= 0)
        return 0;
    int min = 1;
    int max = n;
    int mid = 0;
    while (min <= max)
    {
        mid = min + (max - min) / 2;
        int rlt = guess(mid);
        switch (rlt)
        {
        case 0:
            return mid;
        case 1:
            min = mid + 1;
            break;//漏写了
        case -1:
            max = mid - 1;
            break;//漏写了
        }
    }
    return 0;
}
//383. 赎金信
bool canConstruct(string ransomNote, string magazine) {
    return false;
}
//389. 找不同
char findTheDifference(string s, string t) {
    char p = 0;
    int slen = s.size();
    int tlen = t.size();
    if (tlen <= slen)
        return 0;
    for (int i = 0; i < tlen; i++)
    {
        if (i < slen)
        {
            p ^= s[i];
        }
        p ^= t[i];
    }
    return p;
}
//404. 左叶子之和
int sumOfLeftLeaves(TreeNode* root) {
    if (root == NULL)
        return 0;
    int sum = 0;
    if (root->left)
    {
        if (root->left->left == NULL && root->left->right == NULL)
        {
            sum += root->left->val;
        }
        else 
        {
            sum += sumOfLeftLeaves(root->left);
        }
    }
    if (root->right)
    {
        sum += sumOfLeftLeaves(root->right);
    }
    return sum;
}
//405. 数字转换为十六进制数
string toHex(int num) {
    string s;
    unsigned int num2 = (unsigned int)num;
    while (num2 > 0)
    {
        unsigned int bit4 = num2 & 0xf;
        if (bit4 < 10)
            s.push_back(bit4 + '0');
        else
            s.push_back(bit4 - 10 + 'a');
        num2 >>= 4;//漏写=号
    }
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
    {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
    if (s.size() == 0)
        s.push_back('0');
    return s;
}
//409. 最长回文串 
//给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
int longestPalindrome(string s) {
    int sum = 0;
    int array['z' - 'A' + 1] = { 0 };
    for (char i : s)
        array[i - 'A']++;
    for (int i : array)
        sum += i&-2;
    return sum + (sum < s.size());
}
//412. Fizz Buzz
vector<string> fizzBuzz(int n) {
    vector<string> rlt;
    rlt.resize(n);
    for (int i = 1; i <= n; i++)
    {
        int i3 = (i % 3 == 0);
        int i5 = (i % 5 == 0);
        if (i3 && i5)
            rlt[i - 1] = "FizzBuzz";
        else if (i3)
            rlt[i - 1] = "Fizz";
        else if (i5)
            rlt[i - 1] = "Buzz";
        else
            rlt[i - 1] = to_string(i);
    }
    return rlt;
}
//434. 字符串中的单词数
int countSegments(string s) {
    int len = s.size();
    int cnt = 0;
    int i = 0;
    while (i < len)
    {
        for (;i < len && s[i] == ' ';i++)
        {
        }
        if (i < len)
        {
            cnt++;
        }
        for (; i < len && s[i] != ' '; i++)
        {
        }
    }
    return cnt;
}
//437. 路径总和 III
int pathSum3(TreeNode* root, int sum) {//我的错误答案，会少计，和pathSum2对比
    if (root == NULL)
        return 0;
    if (sum == root->val)
        return 1;
    return pathSum3(root->left, sum - root->val) + pathSum3(root->right,sum - root->val);
}
int pathSum2(TreeNode* root, int sum) {
    if (root == NULL)
        return 0;
    int rlt = 0;
    if (sum == root->val)
        rlt++;
    rlt += pathSum2(root->left, sum - root->val);
    rlt += pathSum2(root->right, sum - root->val);
    return rlt;
}
int pathSum(TreeNode* root, int sum) {
    if (root == NULL)
        return 0;
    int ret = pathSum2(root, sum);
    ret += pathSum(root->left, sum);
    ret += pathSum(root->right, sum);
    return ret;
}
//441. 排列硬币
int arrangeCoins(int n) {
    if (n == 0)
        return 0;
    int min = 1;
    int max = n;
    long long mid = 0;//int mid 会益处
    while (min <= max)
    {
        mid = min + (max - min) / 2;
        long long sum = mid*(1 + mid) / 2;//int sum 会益处
        if (n < sum)
            max = mid - 1;
        else if (n>sum)
            min = mid + 1;
        else 
            return mid;
    }
    return max;//***边界问题
}
//443. 压缩字符串
int compress(vector<char>& chars) {
    int len = chars.size();
    if (len <= 1)
        return len;
    int cnt = 0;
    int sub = 0;
    for (int i = 1; i <= len; i++)
    {
        if (i < len && chars[i] == chars[i-1])
            cnt++;
        else
        {
            if (cnt > 0)
            {
                cnt++;
                //计算位数
                int weishu = 0;
                for (int c = cnt; c > 0;) { weishu++; c /= 10; }
                //计算压缩量
                sub += (cnt - weishu - 1);
                chars[i - sub - weishu - 1] = chars[i - 1];
                for (int k = weishu; k >= 1; k--)
                {
                    if (k != 1)
                    {
                        int g = cnt / ((k - 1) * 10);
                        cnt %= ((k - 1) * 10);
                        chars[i - sub - k] = '0' + g;
                    }
                    else
                    {
                        chars[i - sub - k] = '0' + cnt;
                    }
                }
                cnt = 0;
            }
            else//漏写了
            {
                chars[i - sub - 1] = chars[i - 1];
            }
        }
    }
    return len - sub;
}
int main443()
{
    vector<char> chars;
    chars.push_back('a');
    chars.push_back('a');
    chars.push_back('a');
    chars.push_back('a');
    chars.push_back('b');
    chars.push_back('b');
    chars.push_back('b');
    chars.push_back('c');
    chars.push_back('c');
    chars.push_back('c');
    compress(chars);
    return 0;
}
//453. 最小移动次数使数组元素相等
int minMoves(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1)
        return 0;
    int sum = 0;
    int min = nums[0];
    for (int i = 0; i < len; i++)
    {
        if (min > nums[i])
        {
            int sub = min - nums[i];
            sum += (sub * i);
            min = nums[i];
        }
        else if (min < nums[i])
            sum += (nums[i] - min);
    }
    return sum;
}
//455. 分发饼干
int findContentChildren(vector<int>& g, vector<int>& s) {
    QuickSortVec(g, 0, g.size() - 1);
    QuickSortVec(s, 0, s.size() - 1);
    int i = 0;
    for (int j = 0; i < g.size() && j < s.size();)
    {
        if (s[j] >= g[i])
            i++;
        j++;
    }
    return i;
}
//461. 汉明距离
int hammingDistance(int x, int y) {
    x = x ^ y;
    y = 0;
    while (x)
    {
        y++;
        x = x&(x-1);
    }
    return y;
}
//463. 岛屿的周长
int islandPerimeter(vector<vector<int>>& grid) {
    int sum = 0;
    for (int i = 0; i < grid.size();i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                if (i-1 >= 0 && grid[i-1][j] == 0 || i - 1 < 0)//上
                    sum++;
                if (i + 1 < grid.size() && grid[i + 1][j] == 0 || i + 1 >= grid.size())//下
                    sum++;
                if (j - 1 >= 0 && grid[i][j-1] == 0 || j - 1 < 0)//left
                    sum++;
                if (j + 1 < grid[i].size() && grid[i][j+1] == 0 || j + 1 >= grid[i].size())//right
                    sum++;
            }
        }
    }
    return sum;
}
//19. 删除链表的倒数第N个节点
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* pre = head;
    ListNode* end = head;
    if (n <= 0)
        return head;
    int cnt = 0;
    while (end)
    {
        if (cnt > n)
            pre = pre->next;
        end = end->next;
        cnt++;
    }
    if (cnt < n)
        return head;
    else if (cnt == n)
    {
        ListNode *d = head;
        head = head->next;
        delete d;
        return head;
    }
    if (pre && pre->next)
    {
        ListNode *d = pre->next;
        pre->next = pre->next->next;
        delete d;
    }
    return head;
}
//24. 两两交换链表中的节点
ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *p = head;
    ListNode *q = head->next;
    ListNode *pre = head;
    while (q)
    {
        if (pre == head)
        {
            ListNode *t = q->next;
            q->next = pre;
            pre->next = t;
            head = q;
        }
        else
        {
            ListNode *t = q->next;
            q->next = pre->next;
            pre->next = q;
            p->next = t;
        }
        pre = p;
        p = p->next;
        if (p && p->next)
        {
            q = p->next;
        }
        else
            break;
    }
    return head;
}
//25. k个一组翻转链表
//ListNode* reverseKGroup2(ListNode* head, int k) {
//    if (head == NULL || head->next == NULL || k <= 1)
//        return NULL;
//    ListNode * p = head->next;
//    ListNode * q = p->next;
//    int i = 1;
//    for (; i <= k && p->next; i++, p = p->next);
//    if (i < k)
//        return NULL;
//    ListNode*end = p;
//    p = head->next;
//    ListNode*rlt = p;
//    p->next = end;
//    while (q && k > 1)
//    {
//        ListNode*t = q->next;
//        q->next = p;
//        p = q;
//        q = t;
//        k--;
//    }
//    head->next = p;
//    return rlt;
//}
//ListNode* reverseKGroup(ListNode* head, int k) {
//    ListNode*s = new ListNode(0);
//    s->next = head;
//    ListNode *t = reverseKGroup2(s, k);
//    while (t)
//        t = reverseKGroup2(t, k);
//    return s->next;
//}

ListNode* reverseKGroup2(ListNode* &head, int k) {//我的正确答案
    if (head == NULL || head->next == NULL || k <= 1)
        return NULL;
    ListNode * p = head;
    int i = 0;
    for (; i < k && p; i++, p = p->next);
    if (i < k)
        return NULL;
    ListNode* endNext = p;
    //
    p = head;
    ListNode *q = p->next;
    ListNode* end = p;
    p->next = endNext;
    while (q && k > 1)
    {
        ListNode*t = q->next;
        q->next = p;
        p = q;
        q = t;
        k--;
    }
    head = p;
    return end;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *end = reverseKGroup2(head, k);
    while (end)
        end = reverseKGroup2(end->next, k);
    return head;
}
int main25()
{
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    reverseKGroup(n1,2);
    return 0;
}
//61. 旋转链表
ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k <= 0)
        return head;
    ListNode *p = head;
    int cnt = 1;
    while (p->next) {
        cnt++;
        p = p->next;
    }
    p->next = head;
    k %= cnt;
    for (int i = 0; i < cnt - k; i++)
    {
        p = p->next;
    }
    head = p->next;
    p->next = NULL;
    return head;
}
//82. 删除排序链表中的重复元素 II
ListNode* deleteDuplicates2(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    //节点数>=2
    ListNode*pre = head;
    ListNode*p = head;
    ListNode*q = head->next;
    //
    while (true)
    {
        if (q && p->val == q->val)
            q = q->next;
        else
        {
            if (p->next == q)
            {
                if (!q)
                    break;
                pre = p;
                p = p->next;
                q = q->next;
            }
            else
            {
                if (pre == p)//p => head是不对的
                {
                    head = q;
                    pre = head;
                    p = head;
                }
                else
                {
                    pre->next = q;
                    p = q;
                }
                //
                if (q)
                    q = q->next;
                else
                    break;
            }
        }
    }
    return head;
}
int main82()
{
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(2);
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    deleteDuplicates2(n1);
    return 0;
}
//86. 分隔链表
ListNode* partition(ListNode* head, int x) {//无头节点
    if (head == NULL || head->next == NULL)
        return head;
    //大于1个节点
    ListNode *max = NULL;
    ListNode *maxend = NULL;
    ListNode *pre = head;
    ListNode *p = head;
    while (p)
    {
        if (p->val < x)
        {
            pre = p;
            p = p->next;
        }
        else
        {
            if (max == NULL)
            {
                max = p;
                maxend = p;
            }
            else
                maxend->next = p;
            //
            ListNode *t = p->next;
            if (pre == p)//就是头结点
            {
                pre = t;
                head = t;
            }
            else
                pre->next = p->next;
            if (maxend != p)
                maxend = maxend->next;
            maxend->next = NULL;
            p = t;
        }
    }
    if (pre)
        pre->next = max;
    else
        head = max;
    return head;
}
ListNode* partition2(ListNode* head, int x) {//构件头结点
    if (head == NULL || head->next == NULL)
        return head;
    //大于1个节点
    ListNode *min = new ListNode(0);
    min->next = NULL;
    ListNode *max = new ListNode(0);
    max->next = NULL;
    ListNode *minend = min;
    ListNode *maxend = max;
    while (head)
    {
        ListNode *t = head->next;
        if (head->val < x)
        {
            minend->next = head;
            minend = head;
        }
        else
        {
            maxend->next = head;
            maxend = head;
        }
        head->next = NULL;
        head = t;
    }
    minend->next = max->next;
    return min->next;
}
//92. 反转链表 II
ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (head == NULL || head->next == NULL || m <= 0 || m >= n)
        return head;
    ListNode* h = new ListNode(0);
    h->next = head;
    ListNode*pre = h;
    int i = 1;
    for ( ; i < m && pre; i++)
        pre = pre->next;
    if (pre == NULL || i < m)
        return h->next;
    head = pre->next;
    ListNode *rend = pre->next;
    for ( ; i < n && head; i++)
    {
        ListNode*t = head->next;
        ListNode*t2 = pre->next;
        pre->next = head;
        head->next = t2;
        head = t;
    }
    rend->next = head;
    return h->next;
}
//109. 有序链表转换二叉搜索树
TreeNode* sortedListToBST(ListNode* head) {
    if (head == NULL)
        return NULL;
    //if (head->next == NULL)//***1***
    //{
    //    TreeNode *node = new TreeNode(head->val);
    //    node->left = NULL;
    //    node->right = NULL;
    //    return node;
    //}
    ListNode*p = head;
    ListNode*q = head;
    ListNode*pre = head;
    while (q && q->next)
    {
        pre = p;
        p = p->next;
        q = q->next;
        if (q == NULL)
            break;
        q = q->next;
    }
    pre->next = NULL;
    TreeNode *node = new TreeNode(p->val);
    if (p != head)//***1***
        node->left = sortedListToBST(head);
    node->right = sortedListToBST(p->next);
    return node;
}
int main109()
{
    ListNode *n1 = new ListNode(-10);
    ListNode *n2 = new ListNode(-3);
    ListNode *n3 = new ListNode(0);
    ListNode *n4 = new ListNode(5);
    ListNode *n5 = new ListNode(9);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    sortedListToBST(n1);
    return 0;
}
//876. 链表的中间结点
ListNode* middleNode(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *p = head;
    ListNode *q = head;
    while (q && q->next)
    {
        p = p->next;
        q = q->next;
        if (q == NULL)
            break;
        q = q->next;
    }
    return p;
}
//138. 复制带随机指针的链表
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
Node* copyRandomList(Node* head) {
    if (head == NULL)
        return head;
    Node *newHead = new Node(head->val,NULL,NULL);
    //至少一个节点
    Node *p = head->next;
    Node *newPre = newHead;
    Node *pre = head;
    while (p)
    {
        Node *n = new Node(p->val,NULL,NULL);
        newPre->next = n;
        newPre = n;
        pre = p;
        p = p->next;
    }
    newPre->next = newHead;
    pre->next = head;
    p = head;
    Node *newP = newHead;
    do 
    {
        Node *n1 = p;
        Node *n2 = newP;
        while (true)
        {
            if (p->random == NULL)
            {
                newP->random = NULL;
                break;
            }
            if (n1 == p->random)
            {
                newP->random = n2;
                break;
            }
            n1 = n1->next;
            n2 = n2->next;
        }
        p = p->next;
        newP = newP->next;
    } while (p != head);
    newPre->next = NULL;
    pre->next = NULL;
    return newHead;
}
int main138()
{
    Node *n1 = new Node;
    n1->val = 1;
    n1->next = NULL;
    n1->random = n1;
    //Node *n2 = new Node;
    //n2->val = 2;
    //n1->next = n2;
    //n1->random = n2;
    //n2->next = NULL;
    //n2->random = n2;
    Node*n = copyRandomList(n1);
    return 0;
}
//142. 环形链表 II
ListNode *detectCycle(ListNode *head) {
    if (head == NULL)
        return NULL;
    ListNode*p = head;
    ListNode*q = head;
    do 
    {
        p = p->next;
        q = q->next;
        if (!q)
            return NULL;
        q = q->next;
    } while (p == q);
    return p;
}
ListNode *detectCycle2(ListNode *head) {
    if (head == NULL)
        return NULL;
    ListNode*p = head;
    ListNode*q = head;
    while (q)
    {
        p = p->next;
        q = q->next;
        if (!q)
            return NULL;
        q = q->next;
        if (p == q)
            break;
    }
    q = head;
    while (p && p != q)
    {
        p = p->next;
        q = q->next;
    }
    return p;
}
//143. 重排链表
void reorderList(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return;
    ListNode*pre = head;
    ListNode*p = head;
    ListNode*q = head;
    while (q)
    {
        pre = p;
        p = p->next;
        q = q->next;
        if (!q)
            break;
        q = q->next;
    }
    pre->next = NULL;
    ListNode*head2 = p;
    p = head2->next;
    head2->next = NULL;
    while (p)
    {
        ListNode *t = p->next;
        p->next = head2;
        head2 = p;
        p = t;
    }
    p = head;
    q = head2;
    while (q)
    {
        ListNode*t = p->next;
        ListNode*t2 = q->next;
        p->next = q;
        q->next = t;
        q = t2;
        p = t;
    }
}
//147. 对链表进行 插入排序
ListNode* insertionSortList(ListNode* head) {
    if (head == NULL)
        return head;
    ListNode*p = head->next;
    head->next = NULL;
    while (p)
    {
        ListNode *pp = head;
        ListNode *ppre = head;
        ListNode *t = p->next;
        while (pp)
        {
            if (pp->val > p->val)
            {
                if (pp == ppre)
                {
                    p->next = pp;
                    pp = p;
                    ppre = p;
                    head = pp;//忘记写了
                    break;
                }
                else
                {
                    ppre->next = p;
                    p->next = pp;
                    break;
                }
            }
            ppre = pp;
            pp = pp->next;
            if (!pp)
            {
                ppre->next = p;
                p->next = NULL;
            }
        }
        p = t;
    }
    return head;
}
//148. 归并排序 链表
ListNode* sortList(ListNode* head) {
    return NULL;
}
//快速排序 链表
ListNode* sortList2(ListNode* &head) {
    if (head == NULL)
        return head;
    if (head->next == NULL)
        return head;
    ListNode *lend = NULL;
    ListNode *mid  = head;
    ListNode *p    = head->next;
    mid->next      = NULL;
    while (p)
    {
        ListNode *t = p->next;
        if (p->val > mid->val)
        {
            p->next = mid->next;
            mid->next = p;
        }
        else
        {
            p->next = head;
            head = p;
            if (!lend)
                lend = head;
        }
        p = t;
    }
    if (lend)
        lend->next = NULL;
    ListNode *leftend = NULL;
    if (head == mid)
        return sortList2(mid->next);
    leftend = sortList2(head);
    if (leftend)
        leftend->next = mid;
    ListNode *rightend = sortList2(mid->next);
    return rightend ? rightend : mid;
}
int main148()
{
    ListNode*n1 = new ListNode(4);
    ListNode*n2 = new ListNode(2);
    ListNode*n3 = new ListNode(1);
    ListNode*n4 = new ListNode(3);
    n1->next = n2;
    n2->next = NULL;
    n3->next = n4;
    n4->next = NULL;
    ListNode*t = sortList2(n1);
    return 0;
}
//328. 奇偶链表
ListNode* oddEvenList(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *p = head;
    ListNode *q = head->next;
    ListNode *head2 = q;
    ListNode *pre = head;
    while (p && q)
    {
        p->next = q->next;
        pre = p;
        p = q->next;
        if (!p)
            break;
        else
            pre = p;
        q->next = p->next;
        q = p->next;
    }
    pre->next = head2;
    return head;
}
//445. 两数相加 II
ListNode* addTwoNumbers3(ListNode* l1, ListNode* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    ListNode*p1 = l1;
    ListNode*p2 = l2;
    while (p1 && p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    ListNode *longHead = NULL;
    ListNode *longEnd = NULL;
    ListNode *shortHead = NULL;
    if (p1)
    {
        longHead = l1;
        longEnd = l1;
        while (p1->next)
        {
            p1 = p1->next;
            longEnd = longEnd->next;
        }
        p1 = longEnd->next;
        shortHead = l2;
        p2 = l2;
    }
    else if (p2)
    {
        longHead = l2;
        longEnd = l2;
        while (p2->next)
        {
            p2 = p2->next;
            longEnd = longEnd->next;
        }
        p2 = longEnd->next;
        shortHead = l1;
        p1 = l1;
    }
    else
    {
        p1 = l1;
        p2 = l2;
    }
    ListNode *newHead = new ListNode(0);
    newHead->next = NULL;
    ListNode *newEnd = NULL;
    while (p1 && p2)
    {
        ListNode *node = new ListNode(p1->val + p2->val);
        if (!newEnd)
            newEnd = node;
        node->next = newHead->next;
        newHead->next = node;
        p1 = p1->next;
        p2 = p2->next;
    }
    if (longHead && newEnd)
    {
        p1 = longHead;
        while (p1 != longEnd->next)
        {
            ListNode *node = new ListNode(p1->val);
            node->next = newEnd->next;
            newEnd->next = node;
            p1 = p1->next;
        }
    }
    p1 = newHead->next;
    newHead->next = NULL;
    int carry = 0;
    while (p1)
    {
        p1->val += carry;
        carry = 0;
        if (p1->val >= 10)
        {
            carry = 1;
            p1->val %= 10;
        }
        ListNode*t = p1->next;
        p1->next = newHead->next;
        newHead->next = p1;
        p1 = t;
    }
    if (carry > 0)
    {
        newHead->val = carry;
        return newHead;
    }
    return newHead->next;
}
int main445()
{
    ListNode*l1 = new ListNode(9);
    ListNode*n2 = new ListNode(9);
    ListNode*n3 = new ListNode(9);
    ListNode*n4 = new ListNode(9);
    ListNode*n5 = new ListNode(9);
    l1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    ListNode*l2 = new ListNode(1);
    l2->next = NULL;
    ListNode * rlt = addTwoNumbers3(l1,l2);
    return 0;
}
//725. 分隔链表
vector<ListNode*> splitListToParts(ListNode* root, int k) {
    vector<ListNode*> head;
    vector<ListNode*> end;
    head.resize(k);
    end.resize(k);
    for (int i = 0; i < k; i++)
    {
        head[i] = NULL;
        end[i] = NULL;
    }
    if (root == NULL || k <= 0)
        return head;
    ListNode *p = root;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    int duan = len / k;
    int yu   = len % k;
    p = root;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < duan; j++)
        {
            end[i] = p;
            p = p->next;
        }
        if (i < yu)
        {
            end[i] = p;
            p = p->next;
        }
    }
    head[0] = root;
    for (int i = 1; i < k; i++)
    {
        if (end[i - 1])
        {
            head[i] = end[i - 1]->next;
            end[i - 1]->next = NULL;
        }
    }
    return head;
}
int main725()
{
    ListNode*l1 = new ListNode(1);
    ListNode*n2 = new ListNode(2);
    ListNode*n3 = new ListNode(3);
    ListNode*n4 = new ListNode(4);
    l1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;
    splitListToParts(l1,5);
    return 0;
}
//707. 设计链表
class MyLinkedList {//错误答案
    ListNode*head;
    ListNode*end;
    int cnt;
public:
    /** Initialize your data structure here. */
    MyLinkedList() : head(NULL),end(NULL),cnt(0){

    }
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (cnt <= index)
            return -1;
        ListNode*p = head;
        while (p && index > 0)
        {
            index--;
            p = p->next;
        }
        if (p)
            return p->val;
        return -1;
    }
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode*t = new ListNode(val);
        if (head == NULL)
            end = t;
        t->next = head;
        head = t;
        cnt++;
    }
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode*t = new ListNode(val);
        t->next = NULL;
        if (end == NULL)
            head = t;
        else
            end->next = t;
        end = t;
        cnt++;
    }
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > cnt)
            return;
        ListNode*p = head;
        ListNode*t = new ListNode(val);
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        if (index == cnt)
        {
            addAtTail(val);
            return;
        }
        while (p && index > 1)
        {
            index--;
            p = p->next;
        }
        if (p)
        {
            t->next = p->next;
            p->next = t;
            cnt++;
        }
    }
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= cnt)
            return;
        if (index == 0)
        {
            head = head->next;
            cnt--;
            return;
        }
        ListNode*p = head;
        while (p && index > 1)
        {
            index--;
            p = p->next;
        }
        if (p && p->next)
        {
            p->next = p->next->next;
            cnt--;
        }
    }
};
int main707()
{
    MyLinkedList* linkedList = new MyLinkedList;
    linkedList->addAtHead(1);
    linkedList->addAtTail(3);
    linkedList->addAtIndex(1, 2);   //链表变为1-> 2-> 3
    linkedList->get(1);            //返回2
    linkedList->deleteAtIndex(1);  //现在链表是1-> 3
    linkedList->get(1);            //返回3
    return 0;
}
//94. 二叉树的中序遍历
vector<int> inorderTraversal(TreeNode* root) {//经过参考inorderTraversal2，修改我原来的答案得出我的正确答案
    vector<int> rlt;
    stack<TreeNode*> s;
    if (root == NULL)
        return rlt;
    s.push(root);
    while (!s.empty())
    {
        TreeNode*t = s.top();
        if (t->left)
            s.push(t->left);
        else
        {
            rlt.push_back(t->val);
            s.pop();
            if (t->right)
                s.push(t->right);
            else
            {
                while (!s.empty())
                {
                    t = s.top();
                    s.pop();
                    rlt.push_back(t->val);
                    if (t->right != NULL)
                    {
                        s.push(t->right);
                        break;
                    }
                }
            }
        }
    }
    return rlt;
}
vector<int> inorderTraversal2(TreeNode* root) {//巧妙，网上找的
    vector<int> rlt;
    stack<TreeNode*> s;
    while (root || !s.empty())
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
        if (!s.empty())
        {
            root = s.top();
            s.pop();
            rlt.push_back(root->val);
            root = root->right;
        }
    }
    return rlt;
}
vector<int> inorderTraversal3(TreeNode* root) {//参考inorderTraversal2写的
    vector<int> rlt;
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty())
    {
        root = s.top();
        if (root)
        {
            while (root = root->left)
                s.push(root);
        }
        else
            s.pop();
        if (!s.empty())
        {
            root = s.top();
            s.pop();
            rlt.push_back(root->val);
            s.push(root->right);
        }
    }
    return rlt;
}
int main94()
{
    TreeNode*root = new TreeNode(3);
    TreeNode*n2 = new TreeNode(1);
    TreeNode*n3 = new TreeNode(2);
    root->left = n2;
    root->right = n3;
    vector<int> rlt = inorderTraversal(root);
    return 0;
}
//144. 二叉树的前序遍历
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> rlt;
    stack<TreeNode*> s;
    if (root == NULL)
        return rlt;
    s.push(root);
    while (!s.empty())
    {
        TreeNode*t = s.top();
        s.pop();
        rlt.push_back(t->val);
        if (t->right)
            s.push(t->right);
        if (t->left)
            s.push(t->left);
    }
    return rlt;
}
int main144()
{
    TreeNode*root = new TreeNode(1);
    TreeNode*n2 = new TreeNode(2);
    TreeNode*n3 = new TreeNode(3);
    root->left = NULL;
    root->right = n2;
    n2->left = n3;
    n2->right = NULL;
    vector<int> rlt = preorderTraversal(root);
    return 0;
}
//145. 二叉树的后序遍历
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> rlt;
    stack<TreeNode*> s;
    if (root == NULL)
        return rlt;
    s.push(root);
    TreeNode*lastPop = NULL;
    while (!s.empty())
    {
        TreeNode*t = s.top();
        if (lastPop && t->right == lastPop)
        {
            rlt.push_back(t->val);
            lastPop = t;
            s.pop();
        }
        else
        {
            if (!(lastPop && t->left == lastPop))
            {
                while (t->left)
                {
                    s.push(t->left);
                    t = t->left;
                }
            }
            if (t->right)
                s.push(t->right);
            else
            {
                rlt.push_back(t->val);
                lastPop = t;
                s.pop();
            }
        }
    }
    return rlt;
}
//5. 最长回文子串https://leetcode-cn.com/problems/longest-palindromic-substring/
string longestPalindrome2(string s)//网上找的
{
    if (s.empty()) return "";
    int len = s.size();
    if (len == 1)return s;
    int longest = 1;
    int start = 0;
    vector<vector<int> > dp(len, vector<int>(len));
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        if (i < len - 1)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                start = i;
                longest = 2;
            }
        }
    }
    for (int l = 3; l <= len; l++)//子串长度
    {
        for (int i = 0; i + l - 1 < len; i++)//枚举子串的起始点
        {
            int j = l + i - 1;//终点
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
            {
                dp[i][j] = 1;
                start = i;
                longest = l;
            }
        }
    }
    return s.substr(start, longest);
}
//62. 不同路径
int uniquePaths(int m, int n) {
    if (m <= 0 || n <= 0)
        return 0;
    //vector<vector<int> > dp(n, vector<int>(m));
    int* *dp = new int*[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[m];
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i > 0 && j > 0)
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            else if (i > 0)
                dp[i][j] = dp[i - 1][j];
            else if (j > 0)
                dp[i][j] = dp[i][j - 1];
        }
    }
    int res = dp[n-1][m-1];
    delete[] dp;
    return res;
}
int main62()
{
    int r = uniquePaths(3,2);
    return 0;
}
//63. 不同路径 II
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    if (n <= 0)
        return 0;
    int m = obstacleGrid[0].size();
    if (m <= 0)
        return 0;
    long long **dp = new long long*[n];
    for (int i = 0; i < n; i++)
        dp[i] = new long long[m];
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (obstacleGrid[i][j])
            {
                dp[i][j] = 0;
                continue;
            }
            if (i > 0 && j > 0)
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            else if (i > 0)
                dp[i][j] = dp[i - 1][j];
            else if (j > 0)
                dp[i][j] = dp[i][j - 1];
        }
    }
    int res = dp[n - 1][m - 1];
    delete[] dp;
    return res;
}
//64. 最小路径和
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n <= 0)
        return 0;
    int m = grid[0].size();
    if (m <= 0)
        return 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i > 0 && j > 0)
            {
                if (grid[i][j - 1] > grid[i - 1][j])
                    grid[i][j] = grid[i][j] + grid[i - 1][j];
                else
                    grid[i][j] = grid[i][j] + grid[i][j - 1];
            }
            else if (i > 0)
                grid[i][j] = grid[i][j] + grid[i - 1][j];
            else if (j > 0)
                grid[i][j] = grid[i][j] + grid[i][j - 1];
        }
    }
    return grid[n-1][m-1];
}
//91. 解码方法
int numDecodings(string s) {//我的正确答案
    int len = s.size();
    if (len == 0 || s[0] == '0') 
        return 0;
    if (len == 1)
        return 1;
    int *res = new int[len];
    res[0] = 1;
    for (int i = 1; i < len; i++)
    {
        if (s[i] == '0')
        {
            if (s[i - 1] != '1' && s[i - 1] != '2')
                return 0;
            else
            {
                if (i > 1)
                    res[i] = res[i-2];
                else
                    res[i] = 1;
            }
        }
        else
        {
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
            {
                if (i > 1)
                    res[i] = res[i - 2] + res[i - 1];
                else
                    res[i] = 2;
            }
            else
                res[i] = res[i - 1];
        }
    }
    return res[len - 1];
}
int numDecodings2(string s) {//网上找的
    int cnt = 0;
    if (s.size() == 0 || (s.size() == 1 && s[0] == '0')) return 0;
    if (s.size() == 1) return 1;
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < s.size(); ++i) {
        dp[i + 1] = s[i] == '0' ? 0 : dp[i];
        if (i > 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
            dp[i + 1] += dp[i - 1];
        }
    }
    return dp.back();
}
int main91()
{
    int s = numDecodings("10");
    return 0;
}
//120. 三角形最小路径和
int minimumTotal(vector<vector<int>>& triangle) {
    int h = triangle.size();
    if (h <= 0)
        return 0;
    int w = triangle[h-1].size();
    if (w <= 0)
        return 0;
    vector<int> dp(w, 0);
    //int *dp = new int[w];
    //memset(dp, 0, sizeof(dp));
    int min = -1;
    for (int i = 0; i < h; i++)
    {
        int len = triangle[i].size();
        for (int j = len - 1; j >= 0; j--)
        {
            if (j > 0 && j < len - 1)
            {
                if (dp[j] > dp[j - 1])
                    dp[j] = dp[j - 1] + triangle[i][j];
                else
                    dp[j] = dp[j] + triangle[i][j];
            }
            else if (j == 0)
                dp[j] = dp[j] + triangle[i][j];
            else
                dp[j] = dp[j - 1] + triangle[i][j];
            //
            if (j == len - 1)
                min = dp[j];
            else if (min > dp[j])
                min = dp[j];
        }
    }
    return min;
}
int main120()
{
    vector<vector<int>> triangle;
    vector<int> h1;
    h1.push_back(2);
    vector<int> h2;
    h2.push_back(3);
    h2.push_back(4);
    vector<int> h3;
    h3.push_back(6);
    h3.push_back(5);
    h3.push_back(7);
    vector<int> h4;
    h4.push_back(4);
    h4.push_back(1);
    h4.push_back(8);
    h4.push_back(3);
    triangle.push_back(h1);
    triangle.push_back(h2);
    triangle.push_back(h3);
    triangle.push_back(h4);
    int s = minimumTotal(triangle);
    return 0;
}
//95. 不同的二叉搜索树 II
vector<TreeNode*> numTrees2(vector<int> n, int left, int right) {
    vector<TreeNode*> rlt;
    if (left > right)
    {
        rlt.push_back(NULL);
        return rlt;
    }
    for (int i = left; i <= right; i++)
    {
        vector<TreeNode*> vleft = numTrees2(n, left, i - 1);
        vector<TreeNode*> vright = numTrees2(n, i + 1, right);
        for (int m = 0; m < vleft.size(); m++)
        {
            for (int k = 0; k < vright.size(); k++)
            {
                TreeNode*node = new TreeNode(n[i]);
                node->left = vleft[m];
                node->right = vright[k];
                rlt.push_back(node);
            }
        }
    }
    return rlt;
}
vector<TreeNode*> generateTrees(int n) {
    if (n <= 0)
    {
        vector<TreeNode*> r;
        return r;
    }
    vector<int> nums;
    for (int i = 1; i <= n; i++)
        nums.push_back(i);
    return numTrees2(nums, 0, n - 1);
}
//746. 使用最小花费爬楼梯
int minCostClimbingStairs(vector<int>& cost) {
    int len = cost.size();
    if (len == 0)
        return 0;
    if (len == 1)
        return cost[0];
    int min = cost[0] > cost[1] ? cost[1] : cost[0];
    if (len == 2)
        return min;
    vector<int> dp(len+1,0);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= len; i++)
    {
        int i2 = dp[i - 2] + cost[i - 2];
        int i1 = dp[i - 1] + cost[i - 1];
        dp[i] = i2 > i1 ? i1 : i2;
    }
    return dp[len];
}
//139. 单词拆分
#include <unordered_set>
bool wordBreak(string s, vector<string>& wordDict) {//错误答案"aaaaaaa" ["aaaa", "aaa"]
    unordered_set<string> m(wordDict.begin(), wordDict.end());
    //获取最长字符串长度
    int maxWordLength = 0;
    for (int i = 0; i < wordDict.size(); ++i) {
        int len = wordDict[i].size();
        if (maxWordLength == 0 || maxWordLength < len)
            maxWordLength = len;
    }
    for (int i = 0; i < s.size(); ) {
        int j = 1;
        for (; j <= maxWordLength; ++j) {
            if (m.find(s.substr(i, j)) != m.end()) {
                i += j;
                break;
            }
        }
        if (j > maxWordLength)
            return false;
    }
    return true;
}
bool wordBreak2(string s, vector<string>& wordDict) {//我的正确答案
    vector<bool> dp(s.size(), false);
    unordered_set<string> m(wordDict.begin(), wordDict.end());
    //获取最长字符串长度
    int maxWordLength = 0;
    for (int i = 0; i < wordDict.size(); ++i) {
        int len = wordDict[i].size();
        if (maxWordLength == 0 || maxWordLength < len)
            maxWordLength = len;
    }
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 1; j <= maxWordLength && i+j-1 < s.size(); ++j) {
            if ((i == 0 || dp[i-1]) && m.find(s.substr(i, j)) != m.end()) {
                dp[i+j-1] = true;
            }
        }
    }
    return dp[s.size()-1];
}
//bool wordBreak3(string s, vector<string>& wordDict) {//网上找的
//    vector<bool> dp(s.size() + 1, false);
//    unordered_set<string> m(wordDict.begin(), wordDict.end());
//    dp[0] = true;
//    //获取最长字符串长度
//    int maxWordLength = 0;
//    for (int i = 0; i < wordDict.size(); ++i) {
//        if (maxWordLength < wordDict[i].size())
//            maxWordLength = wordDict[i].size();
//    }
//    for (int i = 1; i <= s.size(); ++i) {
//        for (int j = std::max(i - maxWordLength, 0); j < i; ++j) {
//            if (dp[j] && m.find(s.substr(j, i - j)) != m.end()) {
//                dp[i] = true;
//                break;
//            }
//        }
//    }
//    return dp[s.size()];
//}
int main139()
{
    vector<string> wordDict;
    wordDict.push_back("aaaa");
    wordDict.push_back("aaa");
    bool t = wordBreak2("aaaaaaa", wordDict);
    return 0;
}
//152. 乘积最大子序列
int maxProduct(vector<int>& nums) {//网上找的
    int len = nums.size();
    if (len == 0)
        return 0;
    if (len == 1)
        return nums[0];
    int max  = nums[0];
    int imax = nums[0];
    int imin = nums[0];
    for (int i = 1; i < len; i++)
    {
        if (nums[i] < 0)
        {
            int t = imin;
            imin = imax;
            imax = t;
        }
        int x = imax * nums[i];
        int y = imin * nums[i];
        imax = x > nums[i] ? x : nums[i];
        imin = y < nums[i] ? y : nums[i];

        if (imax > max)
        {
            max = imax;
        }
    }
    return max;
} 

//2019.03.09

//198. 打家劫舍
int rob(vector<int>& nums) {
    int len = nums.size();
    if (len == 0)
        return 0;
    if (len == 1)
        return nums[0];
    vector<int> dp(len,0);
    dp[0] = nums[0];
    dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    for (int i = 2; i < len; i++)
    {
        int max = dp[i - 2] + nums[i];
        dp[i] = max > dp[i - 1] ? max : dp[i - 1];
    }
    return dp[len-1];
}
//213. 打家劫舍 II
int rob2(vector<int>& nums) {
    int len = nums.size();
    if (len == 0)
        return 0;
    if (len == 1)
        return nums[0];
    if (len == 2)
        return nums[0] > nums[1] ? nums[0] : nums[1];
    vector<int> num1;
    vector<int> num2;
    for (int i = 0; i < len; i++)
    {
        if (i < len - 1)
            num1.push_back(nums[i]);
        if (i > 0)
            num2.push_back(nums[i]);
    }
    int max1 = rob(num1);
    int max2 = rob(num2);
    return max1 > max2 ? max1 : max2;
}
//337. 打家劫舍 III
int rob4(TreeNode* root,int &fmax) {//fmax不打劫root的最大值，返回打劫root的最大值
    if (root == NULL)
    {
        fmax = 0;
        return 0;
    }
    int fmaxL = 0;
    int fmaxR = 0;
    fmax = rob4(root->left, fmaxL) + rob4(root->right,fmaxR);
    int max = root->val + fmaxL + fmaxR;
    max = max > fmax ? max : fmax;
    return max;
}
int rob3(TreeNode* root) {//自己做出来的
    int fmax = 0;
    int max = rob4(root, fmax);
    return max;
}
//221. 最大正方形
int maximalSquare(vector<vector<char>>& matrix) {//网上找的
    if (matrix.empty() || matrix[0].empty()) return 0;
    int m = matrix.size(), n = matrix[0].size(), res = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 || j == 0) dp[i][j] = matrix[i][j] - '0';
            else if (matrix[i][j] == '1') {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            }
            res = max(res, dp[i][j]);
        }
    }
    return res * res;
}
int maximalSquare2(vector<vector<char>>& matrix) {//网上找的
    if (matrix.empty() || matrix[0].empty()) return 0;
    int m = matrix.size(), n = matrix[0].size(), res = 0, pre = 0;
    vector<int> dp(m + 1, 0);
    for (int j = 0; j < n; ++j) {
        for (int i = 1; i <= m; ++i) {
            int t = dp[i];
            if (matrix[i - 1][j] == '1') {
                dp[i] = min(dp[i], min(dp[i - 1], pre)) + 1;
                res = max(res, dp[i]);
            }
            else {
                dp[i] = 0;
            }
            pre = t;
        }
    }
    return res * res;
}
//264. 丑数 II
int nthUglyNumber(int n) {//我的正确答案
    if (n <= 0 || n > 1690)
        return 0;
    vector<int> dp(n,0);
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (; i2 < i; i2++)
        {
            int max = 2 * dp[i2];
            if (max > dp[i - 1])
            {
                dp[i] = max;
                break;
            }
        }
        for (; i3 < i; i3++)
        {
            int max = 3 * dp[i3];
            if (max > dp[i - 1])
            {
                dp[i] = min(max, dp[i]);
                break;
            }
        }
        for (; i5 < i; i5++)
        {
            int max = 5 * dp[i5];
            if (max > dp[i - 1])
            {
                dp[i] = min(max, dp[i]);
                break;
            }
        }
    }
    return dp[n-1];
}
int nthUglyNumber2(int n) {//网上找的
    vector<int> ugly(n, 1), idx(3, 0);
    for (int i = 1; i < n; ++i) {
        int a = ugly[idx[0]] * 2, b = ugly[idx[1]] * 3, c = ugly[idx[2]] * 5;
        int next = std::min(a, std::min(b, c));
        if (next == a) {
            ++idx[0];
        }
        if (next == b) {
            ++idx[1];
        }
        if (next == c) {
            ++idx[2];
        }
        ugly[i] = next;
    }
    return ugly.back();
}
//279. 完全平方数
int numSquares(int n) {//网上找的
    vector<int> dp(n + 1, INT_MAX);
    for (int i = 1; i * i <= n; i++)
        dp[i * i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j * j < i; j++)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    return dp[n];
}
//300. 最长上升子序列
int lengthOfLIS(vector<int>& nums) {//网上找的
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        auto iter = std::lower_bound(res.begin(), res.end(), nums[i]);
        if (iter == res.end()) {
            res.push_back(nums[i]);
        }
        else {
            *iter = nums[i]; // update
        }
    }
    return res.size();
}
//303. 区域和检索 - 数组不可变
class NumArray {
public:
    vector<int> dp;
    NumArray(vector<int> nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            dp.push_back(sum);
        }
    }
    int sumRange(int i, int j) {
        if (i > j || i < 0 || j > dp.size() - 1)
            return 0;
        if (i > 0)
            return dp[j] - dp[i - 1];
        else
            return dp[j];
    }
};

//2019.03.10

//304. 二维区域和检索 - 矩阵不可变
class NumMatrix {
public:
    vector<vector<int>> dp;
    int mm;
    int nn;
    NumMatrix(vector<vector<int>> matrix) {
        nn = matrix.size();
        if (nn > 0)
        {
            mm = matrix[0].size();
            for (int i = 0; i < nn; i++)
            {
                vector<int> t(mm,0);
                int sum = 0;
                for (int j = 0; j < mm; j++)
                {
                    sum += matrix[i][j];
                    t[j] = sum;
                    if (i > 0)
                        t[j] += dp[i - 1][j];
                }
                dp.push_back(t);
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 <= row2 && col1 <= col2 
            && row1 >= 0 && col1 >= 0
            && row2 < nn && col2 < mm)
        {
            if (row1 == 0 && col1 == 0)
                return dp[row2][col2];
            else if (row1 == 0)
                return dp[row2][col2] - dp[row2][col1-1];
            else if (col1 == 0)
                return dp[row2][col2] - dp[row1-1][col2];
            else
                return dp[row2][col2] + dp[row1-1][col1-1] - dp[row1-1][col2] - dp[row2][col1-1];
        }
        return 0;
    }
};
//309. 最佳买卖股票时机含冷冻期
int maxProfit100(vector<int>& prices) {//网上找的
    int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;
    for (int price : prices) {
        pre_buy = buy;
        buy = max(pre_sell - price, pre_buy);
        pre_sell = sell;
        sell = max(pre_buy + price, pre_sell);
    }
    return sell;
}
//98. 验证二叉搜索树
bool isValidBST2(TreeNode* root, int &min, int &max) {
    if (root == NULL)
        return true;
    int lmin, lmax;
    if (root->left && root->right)
    {
        if (root->val > root->right->val || root->val < root->left->val)
            return false;
        bool l = isValidBST2(root->left, lmin, lmax);
        if (!l || root->val <= lmax)
            return false;
        min = lmin;
        bool r = isValidBST2(root->right, lmin, lmax);
        if (!r || root->val >= lmin)
            return false;
        max = lmax;
    }
    else if (root->left)
    {
        if (root->val < root->left->val)
            return false;
        bool l = isValidBST2(root->left, lmin, lmax);
        if (!l || root->val <= lmax)
            return false;
        min = lmin;
        max = root->val;
    }
    else if (root->right)
    {
        if (root->val > root->right->val)
            return false;
        bool r = isValidBST2(root->right, lmin, lmax);
        if (!r || root->val >= lmin)
            return false;
        max = lmax;
        min = root->val;
    }
    else
    {
        min = root->val;
        max = root->val;
    }
    return true;
}
bool isValidBST3(TreeNode* root) {
    int lmin, lmax;
    return isValidBST2(root, lmin, lmax);
}
int last = INT_MIN;
bool isValidBST(TreeNode* root) {//网上找的，通不过测试，但是提供了一种思想
    if (root == NULL) {
        return true;
    }
    if (isValidBST(root->left)) {
        if (last < root->val) {
            last = root->val;
            return isValidBST(root->right);
        }
    }
    return false;
}
//102. 二叉树的层次遍历
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> rlt;
    vector<TreeNode*> rr;
    if (root == NULL)
        return rlt;
    vector<int> t;
    t.push_back(root->val);
    rlt.push_back(t);
    rr.push_back(root);
    for (int i = 0; i < rr.size(); /*++i*/)
    {
        vector<int> row;
        int len = rr.size();
        for (; i < len; ++i)
        {
            if (rr[i]->left)
            {
                rr.push_back(rr[i]->left);
                row.push_back(rr[i]->left->val);
            }
            if (rr[i]->right)
            {
                rr.push_back(rr[i]->right);
                row.push_back(rr[i]->right->val);
            }
        }
        if (row.size() > 0)
        {
            rlt.push_back(row);
        }
    }
    return rlt;
}
//103. 二叉树的锯齿形层次遍历
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> rlt;
    vector<TreeNode*> rr;
    if (root == NULL)
        return rlt;
    vector<int> t;
    t.push_back(root->val);
    rlt.push_back(t);
    rr.push_back(root);
    for (int i = 0; i < rr.size(); /*++i*/)
    {
        int s = rlt.size();
        vector<int> row;
        int len = rr.size();
        for (; i < len; ++i)
        {
            if (rr[i]->left)
            {
                rr.push_back(rr[i]->left);
                row.push_back(rr[i]->left->val);
            }
            if (rr[i]->right)
            {
                rr.push_back(rr[i]->right);
                row.push_back(rr[i]->right->val);
            }
        }
        if (s % 2 == 1)
        {
            for (int m = 0, n = row.size() - 1; m < n; ++m, --n)
                MySwap(row[m], row[n]);
        }
        if (row.size() > 0)
            rlt.push_back(row);
    }
    return rlt;
}
//105. 从前序与中序遍历序列构造二叉树
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() != inorder.size() || preorder.size() == 0)
        return NULL;
    TreeNode*root = new TreeNode(preorder[0]);
    if (preorder.size() == 1)
        return root;
    vector<int> preorder1, preorder2;
    vector<int> inorder1, inorder2;
    bool isFind = false;
    for (int i = 0,j = 1; i < inorder.size();++i,++j)
    {
        if (root->val == inorder[i])
        {
            isFind = true;
            ++i;
        }
        if (!isFind)
        {
            preorder1.push_back(preorder[j]);
            inorder1.push_back(inorder[i]);
        }
        else
        {
            if (i < inorder.size())
            {
                preorder2.push_back(preorder[j]);
                inorder2.push_back(inorder[i]);
            }
        }
    }
    root->left = buildTree(preorder1, inorder1);
    root->right = buildTree(preorder2, inorder2);
    return root;
}
//106. 从中序与后序遍历序列构造二叉树
TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder) {
    if (postorder.size() != inorder.size() || inorder.size() == 0)
        return NULL;
    int len = postorder.size();
    TreeNode*root = new TreeNode(postorder[len-1]);
    if (len == 1)
        return root;
    vector<int> postorder1, postorder2;
    vector<int> inorder1, inorder2;
    bool isFind = false;
    for (int i = 0, j = 0; i < inorder.size(); ++i, ++j)
    {
        if (root->val == inorder[i])
        {
            isFind = true;
            ++i;
        }
        if (!isFind)
        {
            postorder1.push_back(postorder[j]);
            inorder1.push_back(inorder[i]);
        }
        else
        {
            if (i < inorder.size())
            {
                postorder2.push_back(postorder[j]);
                inorder2.push_back(inorder[i]);
            }
        }
    }
    root->left = buildTree2(inorder1, postorder1);
    root->right = buildTree2(inorder2, postorder2);
    return root;
}

//2019.03.11

//113. 路径总和 II
vector<vector<int>> pathSum5(TreeNode* root, int sum) {
    vector<vector<int>> rlt;
    if (root == NULL)
        return rlt;
    if (root->left == NULL && root->right == NULL)
    {
        if (root->val == sum)
        {
            vector<int> a(1, root->val);
            rlt.push_back(a);
        }
        return rlt;
    }
    vector<vector<int>> rltLeft = pathSum5(root->left, sum - root->val);
    vector<vector<int>> rltRight = pathSum5(root->right, sum - root->val);
    for (int i = 0; i < rltLeft.size(); ++i)
    {
        vector<int>::iterator iter = rltLeft[i].begin();
        rltLeft[i].insert(iter,root->val);
        rlt.push_back(rltLeft[i]);
    }
    for (int i = 0; i < rltRight.size(); ++i)
    {
        vector<int>::iterator iter = rltRight[i].begin();
        rltRight[i].insert(iter, root->val);
        rlt.push_back(rltRight[i]);
    }
    return rlt;
}
//114. 二叉树展开为链表
ListNode* flatten2(ListNode* &head, TreeNode* root) {//题意理解错了
    if (root == NULL)
        return NULL;
    ListNode* node = new ListNode(root->val);
    head->next = node;
    ListNode* left = flatten2(node, root->left);
    if (left)
    {
        ListNode* right = flatten2(left, root->right);
        if (right)
            return right;
        else
            return left;
    }
    else
    {
        ListNode* right = flatten2(node, root->right);
        if (right)
            return right;
        else
            return node;
    }
}
ListNode* flatten(TreeNode* root) {//题意理解错了
    if (root == NULL)
        return NULL;
    ListNode* node = new ListNode(root->val);
    flatten2(node,root);
    return node;
}

TreeNode* flatten3(TreeNode* root) {//我的正确答案
    if (root == NULL)
        return NULL;
    if (root->left && root->right)
    {
        TreeNode* right = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode* leftEnd = flatten3(root->right);
        if (leftEnd)
        {
            leftEnd->right = right;
            TreeNode* rightEnd = flatten3(right);
            return rightEnd ? rightEnd : right;
        }
        return root->right;
    }
    else if (root->left)
    {
        root->right = root->left;
        root->left = NULL;
        return flatten3(root->right);
    }
    return root->right ? flatten3(root->right) : root;
}
TreeNode* flatten5(TreeNode* root) {//我的错误答案
    if (root == NULL)
        return NULL;
    TreeNode* leftEnd = flatten3(root->left);
    if (leftEnd)
    {
        if (root->right)
        {
            TreeNode* right = root->right;
            root->right = root->left;
            root->left = NULL;
            leftEnd->right = right;
            TreeNode* rightEnd = flatten3(right);
            return rightEnd ? rightEnd : right;
        }
        return leftEnd;
    }
    if (root->right)
    {
        TreeNode* rightEnd = flatten3(root->right);
        if (rightEnd)
            return rightEnd;
    }
    return root;
}
void flatten4(TreeNode* root) {
    flatten3(root);
}
//501. 二叉搜索树中的众数
void findMode3(TreeNode* root, vector<int> &res) {//这个思路有点笨,过了
    if (root == NULL)
        return;
    findMode3(root->left, res);
    int len = res.size();
    if (len == 0)
    {
        res.push_back(root->val);
        res.push_back(1);
    }
    else
    {
        if (root->val == res[len-2])
        {
            res[len - 1]++;
            if (len > 3)
            {
                if (res[len-3] == res[len-1])
                {
                    if (len > 5)
                    {
                        res[len - 5] = res[len - 4];
                        res[len - 4] = res[len - 3];
                        res[len - 3] = res[len - 2];
                        res[len - 2] = res[len - 1];
                        res.pop_back();
                    }
                }
                else if (res[len - 3] < res[len - 1])
                {
                    int max = res[len-1];
                    res.clear();
                    res.push_back(root->val);
                    res.push_back(max);
                }
            }
        }
        else
        {
            if (len > 3)
            {
                if (res[len-1] == res[len-3])
                {
                    res[len - 3] = res[len - 2];
                    res[len - 2] = res[len - 1];
                    res[len - 1] = root->val;
                    res.push_back(1);
                }
                else
                {
                    res[len - 2] = root->val;
                    res[len - 1] = 1;
                }
            }
            else
            {
                res.push_back(root->val);
                res.push_back(1);
            }
        }
    }
    findMode3(root->right, res);
}
vector<int> findMode(TreeNode* root) {
    vector<int> res;
    findMode3(root,res);
    int len = res.size();
    if (len == 0)
    {
    }
    else if (len == 2)
    {
        res.pop_back();
    }
    else 
    {
        if (res[len - 1] == res[len - 3])
        {
            res[len - 3] = res[len - 2];
            res.pop_back();
            res.pop_back();
        }
        else
        {
            res.pop_back();
            res.pop_back();
            res.pop_back();
        }
    }
    return res;
}
//116. 填充每个节点的下一个右侧节点指针
//class Node {
//public:
//    int val;
//    Node* left;
//    Node* right;
//    Node* next;
//    Node() {}
//
//    Node(int _val, Node* _left, Node* _right, Node* _next) {
//        val = _val;
//        left = _left;
//        right = _right;
//        next = _next;
//    }
//};
//Node* connect(Node* root) {
//    if (root == NULL)
//        return NULL;
//    Node* head = root;
//    head->next = NULL;
//    while (head)
//    {
//        Node* p = head;
//        head = NULL;
//        Node* newP = NULL;
//        while (p)
//        {
//            if (p->left && p->right)
//            {
//                if (!newP)
//                {
//                    head = p->left;
//                    newP = p->left;
//                }
//                else
//                {
//                    newP->next = p->left;
//                    newP = newP->next;
//                }
//                newP->next = p->right;
//                newP = newP->next;
//            }
//            else
//                return root;
//            p = p->next;
//        }
//        newP->next = NULL;
//    }
//    return root;
//}
//117. 填充每个节点的下一个右侧节点指针 II
//Node* connect2(Node* root) {
//    if (root == NULL)
//        return NULL;
//    Node* head = root;
//    head->next = NULL;
//    while (head)
//    {
//        Node* p = head;
//        head = NULL;
//        Node* newP = NULL;
//        while (p)
//        {
//            if (p->left)
//            {
//                if (!newP)
//                {
//                    head = p->left;
//                    newP = p->left;
//                }
//                else
//                {
//                    newP->next = p->left;
//                    newP = newP->next;
//                }
//            }
//            if (p->right)
//            {
//                if (!newP)
//                {
//                    head = p->right;
//                    newP = p->right;
//                }
//                else
//                {
//                    newP->next = p->right;
//                    newP = newP->next;
//                }
//            }
//            p = p->next;
//        }
//        if (newP && newP->next)
//            newP->next = NULL;
//    }
//    return root;
//}

//2019.03.12-13

//52. N皇后 II

//int len = 0;
//int **queen;
//int totalNQueensHelp(int n/*, vector<vector<int>> &queen*/)
//{
//    int num = 0;
//    if (n <= 0)
//        return 1;
//    int index = len - n;
//    if (index > 0)
//    {
//        //memset(queen[index], 0, sizeof(queen[index]));
//        for (int i = 0; i < len; ++i)
//        {
//            if (queen[index - 1][i] & 0x2)
//                queen[index][i] |= 0x2;
//            if (i > 0 && (queen[index - 1][i] & 0x4))
//                queen[index][i - 1] |= 0x4;
//            if (i < len - 1 && (queen[index - 1][i] & 0x1))
//                queen[index][i + 1] |= 0x1;
//        }
//    }
//    for (int i = 0; i < len; ++i)
//    {
//        if (queen[index][i] > 0)
//            continue;
//        queen[index][i] = 7;
//        num += totalNQueensHelp(n - 1);
//        queen[index][i] = 0;
//    }
//    return num;
//}
//int totalNQueens2(int n) {
//    if (n <= 0)
//        return 0;
//    len = n;
//    queen = new int*[n];
//    for (int i = 0; i < n; ++i)
//    {
//        queen[i] = new int[n];
//        memset(queen[i], 0, sizeof(queen[i]));
//    }
//    //vector<vector<int>> queen(n, vector<int>(n,0));
//    return totalNQueensHelp(n);
//}

//////////////////////////////////////////////////////////////////////////
int **queen16;
int len16;
int lenmem16;
int totalNQueensHelp16(int n)
{
    int num = 0;
    if (n <= 0)
        return 1;
    int index = len16 - n;
    if (index > 0)
    {
        memset(queen16[index], 0, lenmem16);
        for (int i = 0; i < len16; ++i)
        {
            //if (queen16[index - 1][i] <= 0)
            //    continue;
            if (queen16[index - 1][i] & 0x2)
                queen16[index][i] |= 0x2;
            if (i > 0 && (queen16[index - 1][i] & 0x4))
                queen16[index][i - 1] |= 0x4;
            if (i < len16 - 1 && (queen16[index - 1][i] & 0x1))
                queen16[index][i + 1] |= 0x1;
        }
    }
    for (int i = 0; i < len16; ++i)
    {
        if (queen16[index][i] > 0)
            continue;
        queen16[index][i] = 7;
        num += totalNQueensHelp16(n - 1);
        queen16[index][i] = 0;
    }
    return num;
}
int totalNQueens16(int n) {
    if (n <= 0)
        return 0;
    len16 = n;
    queen16 = new int *[n];
    lenmem16 = sizeof(int)*len16;
    for (int i = 0; i < n; i++)
    {
        queen16[i] = new int[n];
        memset(queen16[i], 0, lenmem16);
    }
    return totalNQueensHelp16(n);
}
//////////////////////////////////////////////////////////////////////////
int totalNQueensHelp2(int n, vector<vector<int>> &queen)
{
    int num = 0;
    if (n <= 0)
        return 1;
    int len = queen.size();
    int index = len - n;
    if (index > 0)
    {
        for (int i = 0; i < len; ++i)
            queen[index][i] = 0;
        for (int i = 0; i < len; ++i)
        {
            if (queen[index - 1][i] & 0x2)
                queen[index][i] |= 0x2;
            if (i > 0 && (queen[index - 1][i] & 0x4))
                queen[index][i - 1] |= 0x4;
            if (i < len - 1 && (queen[index - 1][i] & 0x1))
                queen[index][i + 1] |= 0x1;
        }
    }
    for (int i = 0; i < len; ++i)
    {
        if (queen[index][i] > 0)
            continue;
        queen[index][i] = 7;
        num += totalNQueensHelp2(n - 1, queen);
        queen[index][i] = 0;
    }
    return num;
}
int totalNQueens3(int n) {
    if (n <= 0)
        return 0;
    vector<vector<int>> queen(n, vector<int>(n, 0));
    return totalNQueensHelp2(n, queen);
}

int totalNQueensHelp(int n, vector<vector<int>> &queen)
{
    int num = 0;
    if (n <= 0)
        return 1;
    int len = queen.size();
    int index = len - n;
    if (index < len - 1)//预处理index+1层
    {
        for (int i = 0; i < len; ++i)
            queen[index + 1][i] = 0;
        bool isT = true;
        for (int i = 0; i < len; ++i)
        {
            if (queen[index][i] <= 0)
                isT = false;
            if (queen[index][i] & 0x2)
                queen[index + 1][i] |= 0x2;
            if (i > 0 && (queen[index][i] & 0x4))
                queen[index + 1][i - 1] |= 0x4;
            if (i < len - 1 && (queen[index][i] & 0x1))
                queen[index + 1][i + 1] |= 0x1;
        }
        if (isT)
            return 0;
    }
    for (int i = 0; i < len; ++i)
    {
        if (queen[index][i] > 0)
            continue;
        int left = -1;
        int zhong = -1;
        int right = -1;
        if (index < len - 1)
        {
            zhong = queen[index + 1][i];
            queen[index + 1][i] |= 0x2;
            if (i > 0)
            {
                left = queen[index + 1][i - 1];
                queen[index + 1][i - 1] |= 0x4;
            }
            if (i < len - 1)
            {
                right = queen[index + 1][i + 1];
                queen[index + 1][i + 1] |= 0x1;
            }
        }
        num += totalNQueensHelp(n - 1, queen);
        if (left >= 0)
            queen[index + 1][i - 1] = left;
        if (zhong >= 0)
            queen[index + 1][i] = zhong;
        if (right >= 0)
            queen[index + 1][i + 1] = right;
    }
    return num;
}
int totalNQueens2(int n) {
    if (n <= 0)
        return 0;
    vector<vector<int>> queen(n, vector<int>(n, 0));
    return totalNQueensHelp(n, queen);
}

int totalNQueensHelp3(int n, vector<int> queen)
{
    int num = 0;
    int len = queen.size();
    vector<int> queen2(len, 0);
    if (n <= 0)
        return 1;
    int index = len - n;
    for (int i = 0; i < len; ++i)
    {
        if (queen[i] > 0 )
        {
            if (queen[i] & 0x2)
                queen2[i] |= 0x2;
            if (i > 0 && (queen[i] & 0x4))
                queen2[i - 1] |= 0x4;
            if (i < len - 1 && (queen[i] & 0x1))
                queen2[i + 1] |= 0x1;
        }
    }
    for (int i = 0; i < len; ++i)
    {
        if (queen2[i] > 0)
            continue;
        queen2[i] = 0x7;
        num += totalNQueensHelp3(n - 1, queen2);
        queen2[i] = 0;
    }
    return num;
}
int totalNQueens(int n) {
    if (n <= 0)
        return 0;
    vector<int> queen(n,0);
    return totalNQueensHelp3(n, queen);
}
//////////////////////////////////////////////////////////////////////////

int queenLen = 0;
int totalNQueensHelp15(int n, int *queen)
{
    int num = 0;
    int *queen2 = new int[queenLen];
    memset(queen2, 0, sizeof(queen2));
    if (n <= 0)
        return 1;
    int index = queenLen - n;
    for (int i = 0; i < queenLen; ++i)
    {
        if (queen[i] & 0x2)
            queen2[i] |= 0x2;
        if (i > 0 && (queen[i] & 0x4))
            queen2[i - 1] |= 0x4;
        if (i < queenLen - 1 && (queen[i] & 0x1))
            queen2[i + 1] |= 0x1;
    }
    for (int i = 0; i < queenLen; ++i)
    {
        if (queen2[i] > 0)
            continue;
        queen2[i] = 0x7;
        num += totalNQueensHelp15(n - 1, queen2);
        queen2[i] = 0;
    }
    return num;
}
int totalNQueens15(int n) {
    if (n <= 0)
        return 0;
    queenLen = n;
    int *queen = new int[queenLen];
    memset(queen,0,sizeof(queen));
    return totalNQueensHelp15(n, queen);
}
//////////////////////////////////////////////////////////////////////////
int *indexs;
int num = 0;
bool CheckCan(int k, int target)
{
    for (int i = k - 1; i >= 0; i--)
        if (indexs[i] == target
            || indexs[i] - (k - i) == target
            || indexs[i] + (k - i) == target)
            return false;
    return true;
}
bool CheckCan2(int k, int target)
{
    for (int i = 0; i < k; ++i)
        if (indexs[i] == target
            || indexs[i] - (k - i) == target
            || indexs[i] + (k - i) == target)
            return false;
    return true;
}
void Check(int k, int n)
{
    for (int i = 0; i < n; i++)
    {
        //bool result = false;               //这样反而会变慢
        //for (int j = k - 1; j >= 0; j--)
        //    if (indexs[j] == i
        //        || indexs[j] - (k - j) == i
        //        || indexs[j] + (k - j) == i)
        //        result = true;
        //if (!result)
        if (CheckCan(k, i))
        {
            indexs[k] = i;
            if (k == n - 1)
                num++;
            else
                Check(k + 1, n);
        }
    }
}
int totalNQueens4(int n)//别人的代码
{
    indexs = new int[n];
    Check(0, n);
    return num;
}

int *indexs11;
bool isCanPut11(int k, int putId)
{
    for (int j = 0; j < k; ++j)
    {
        if (indexs11[j] == putId
            || indexs11[j] - k + j == putId
            || indexs11[j] + k - j == putId)
            return false;
    }
    return true;
}
int totalNQueensHelp11(int k, int n) {
    for (int i = 0; i < n; ++i)
    {
        if (isCanPut11(k, i))
        {
            indexs11[k] = i;
            if (k == n - 1)
                num++;
            else
                totalNQueensHelp11(k + 1,n);
        }
    }
    return 0;
}
int totalNQueens11(int n) {
    if (n <= 0)
        return 0;
    indexs11 = new int[n];
    totalNQueensHelp11(0, n);
    return num;
}

vector<int> queen;
bool isCanPut13(int k, int putId)
{
    for (int j = 0; j < k; ++j)
    {
        if (queen[j] == putId
            || queen[j] - k + j == putId
            || queen[j] + k - j == putId)
            return false;
    }
    return true;
}
int totalNQueensHelp13(int k) {
    int len = queen.size();
    for (int i = 0; i < len; ++i)
    {
        if (isCanPut13(k, i))
        {
            queen[k] = i;
            if (k == len - 1)
                num++;
            else
                totalNQueensHelp13(k + 1);
        }
    }
    return 0;
}
int totalNQueens13(int n) {
    if (n <= 0)
        return 0;
    for (int i = 0; i < n; i++)
    {
        queen.push_back(0);
    }
    totalNQueensHelp13(0);
    return num;
}

bool isCanPut12(int k, vector<int> queen, int putId)
{
    for (int j = 0; j < k; ++j)
    {
        if (queen[j] == putId
            || queen[j] - k + j == putId
            || queen[j] + k - j == putId)
            return false;
    }
    return true;
}
int totalNQueensHelp12(int k, vector<int> queen) {
    int len = queen.size();
    for (int i = 0; i < len; ++i)
    {
        if (isCanPut12(k, queen, i))
        {
            queen[k] = i;
            if (k == len - 1)
                num++;
            else
                totalNQueensHelp12(k + 1, queen);
        }
    }
    return 0;
}
int totalNQueens12(int n) {
    if (n <= 0)
        return 0;
    vector<int> queen(n, 0);
    totalNQueensHelp12(0, queen);
    return num;
}

bool isCanPut10(int k, vector<int> &queen, int putId)
{
    for (int j = 0; j < k; ++j)
    {
        if (queen[j] == putId
            || queen[j] - k + j == putId
            || queen[j] + k - j == putId)
            return false;
    }
    return true;
}
int totalNQueensHelp10(int k, vector<int> &queen) {
    int len = queen.size();
    for (int i = 0; i < len; ++i)
    {
        if (isCanPut10(k, queen, i))
        {
            queen[k] = i;
            if (k == len - 1)
                num++;
            else
                totalNQueensHelp10(k + 1, queen);
        }
    }
    return 0;
}
int totalNQueens10(int n) {
    if (n <= 0)
        return 0;
    vector<int> queen(n, 0);
    totalNQueensHelp10(0, queen);
    return num;
}

bool isCanPut9(int k, vector<int> &queen, int putId)
{
    for (int j = 0; j < k; ++j)
    {
        if (queen[j] == putId
            || queen[j] - k + j == putId
            || queen[j] + k - j == putId)
            return false;
    }
    return true;
}
int totalNQueensHelp9(int k, vector<int> &queen) {
    int num = 0;
    int len = queen.size();
    if (k == len)
        return 1;
    for (int i = 0; i < len; ++i)
    {
        if (isCanPut9(k, queen, i))
        {
            queen[k] = i;
            num += totalNQueensHelp9(k + 1, queen);
        }
    }
    return num;
}
int totalNQueens9(int n) {
    if (n <= 0)
        return 0;
    vector<int> queen(n, 0);
    return totalNQueensHelp9(0, queen);
}

int count1;
int max1;
int*  lines;
int dx, dy, ii, jj;
bool av;
bool avalid(int x, int y, int x2, int y2)
{
    if (y == y2)
        return false;
    dx = x - x2;
    dy = y - y2;
    if (dx == dy || dx == -dy)
        return false;
    return true;
}
int findnext(int x, int starty)
{
    if (x == max1)
    {
        count1++;
        return -1;
    }
    for (ii = starty; ii < max1; ii++)
    {
        av = true;
        for (jj = 0; jj < x; jj++)
        {
            if (!avalid(jj, lines[jj], x, ii))
            {
                av = false;
                break;
            }
        }
        if (av)
            return ii;
    }
    return -1;
}
void gonext(int currentx, int nextstarty)
{
    int next = -1;
    while (true)
    {
    gotonextline: currentx++;
        next = findnext(currentx, 0);
    panduan:  if (next >= 0)
        {
            //向下继续;
            lines[currentx] = next;
            goto gotonextline;
        }
        else
        {
            //向上返回;
            if (currentx == 1)
                break;
            currentx--;
            next = findnext(currentx, lines[currentx] + 1);
            goto panduan;
        }
    }
}
int totalNQueens8(int n)
{
    if (n == 1)
    {
        return 1;
    }
    count1 = 0;
    max1 = n;
    lines = new int[n];
    int cishu = n / 2;
    if (n % 2 == 0)
    {
        for (int i = 0; i < cishu; i++)
        {
            lines[0] = i;
            gonext(0, 0);
        }
        count1 = count1 * 2;
    }
    else
    {
        lines[0] = cishu;
        gonext(0, 0);
        int temp = count1;
        count1 = 0;
        for (int i = 0; i < cishu; i++)
        {
            lines[0] = i;
            gonext(0, 0);
        }
        count1 = count1 * 2;
        count1 = count1 + temp;
    }
    return count1;
}

int nn;
void FindNQueen(int k, int l, int r)
{
    if (k == nn)
    {
        num++;
        return;
    }
    int z = nn & (~(k | l | r));  //能走的位置， 和nn取并可以去掉前面多余的1
    while (z != 0)
    {
        int index = z & (~z + 1);   //最右边的一个1， 即要放皇后的位置。
        z -= index;   //去掉这个位置。
        FindNQueen(k | index, (l | index) << 1, (r | index) >> 1);   //查找下一个。
    }
}
int main52()
{
    int nn = 12;
    {
        int old = clock();
        int numnum = totalNQueens4(nn);//11 //速度:totalNQueens > totalNQueens3 > totalNQueens2
        printf("%d, %d\n", numnum, clock() - old);
    }
    {
        int old = clock();
        int numnum = totalNQueens16(nn);//11 //速度:totalNQueens > totalNQueens3 > totalNQueens2
        printf("%d, %d\n", numnum, clock() - old);
    }
    {
        int old = clock();
        int numnum = totalNQueens8(nn);//11 //速度:totalNQueens > totalNQueens3 > totalNQueens2
        printf("%d, %d\n", numnum, clock() - old);
    }
    getchar();
    return 0;
}
//129. 求根到叶子节点数字之和
int sumNumbers(TreeNode* root, int pre) {
    if (root == NULL)
        return 0;
    pre += root->val;
    if (!root->left && !root->right)
        return pre;
    pre *= 10;
    int num = sumNumbers(root->left, pre) + sumNumbers(root->right, pre);
    return num;
}
int sumNumbers(TreeNode* root) {
    return sumNumbers(root, 0);
}
//199. 二叉树的右视图
class Solution199 {
public:
    void rightSideView2(TreeNode* root, vector<int> &res, int curDeep) {
        if (root == NULL)
            return;
        if (curDeep > res.size())
            res.push_back(root->val);
        if (root->right)
            rightSideView2(root->right, res, curDeep + 1);
        if (root->left)
            rightSideView2(root->left, res, curDeep + 1);
    }
    vector<int> rightSideView2(TreeNode* root) {
        vector<int> res;
        rightSideView2(root, res, 1);
        return res;
    }
};
//222. 完全二叉树的节点个数
class Solution222 {
public:
    int leaf;
    bool isFind;
    int maxDeep;
    void countNodes(TreeNode* root, int curDeep) {
        if (root == NULL)
            return;
        if (curDeep > maxDeep)
            maxDeep = curDeep;
        if (!root->left && !root->right)
        {
            if (curDeep < maxDeep)
            {
                isFind = true;
                return;
            }
            leaf++;
        }
        countNodes(root->left, curDeep + 1);
        countNodes(root->right, curDeep + 1);
    }
    int countNodes(TreeNode* root) {
        leaf = 0;
        isFind = false;
        if (root == NULL)
            return 0;
        countNodes(root, 1);
        int sum = 0;
        for (int i = 0; i < maxDeep - 1; ++i)
            sum |= (1<<i);
        return sum+leaf;
    }
};
//230. 二叉搜索树中第K小的元素
class Solution230 {
public:
    int cnt = 0;
    int val = 0;
    void kthSmallest2(TreeNode* root, int k) {
        if (root == NULL)
            return;
        kthSmallest2(root->left, k);
        cnt++;
        if (cnt == k)
        {
            val = root->val;
            return;
        }
        kthSmallest2(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL)
            return 0;
        kthSmallest2(root, k);
        return val;
    }
};
//236. 二叉树的最近公共祖先
class Solution236 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        if (root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (!left)
            return right;
        if (!right)
            return left;
        return root;
    }
};
//173. 二叉搜索树迭代器
class BSTIterator {
public:
    vector<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        while (root)
        {
            st.push_back(root);
            root = root->left;
        }
    }
    /** @return the next smallest number */
    int next() {
        int len = st.size();
        if (len > 0)
        {
            int res = st[len - 1]->val;
            TreeNode* root = st[len - 1]->right;
            st.pop_back();
            while (root)
            {
                st.push_back(root);
                root = root->left;
            }
            return res;
        }
        return 0;
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        int len = st.size();
        if (len > 0) return true;
        return false;
    }
};
//449. 序列化和反序列化二叉搜索树
class Codec449 {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        if (root == NULL)
            return s;
        int val = root->val;
        if (val == 0)
            s.push_back('0');
        else
        {
            if (val < 0)
            {
                s.push_back('-');
                val = -val;
            }
            while (val > 0)
            {
                int y = val % 10;
                char tmp = '0' + y;
                s.push_back(tmp);
                //s.push_back('0' + val);
                val /= 10;
            }
        }
        s.push_back(',');
        if (root->left)
            s.append(serialize(root->left));
        if (root->right)
            s.append(serialize(root->right));
        //s.pop_back();
        return s;
    }
    TreeNode* bstFromPreorder(int* preorder, int left, int right) {
        if (left > right)
            return NULL;
        TreeNode* node = new TreeNode(preorder[left]);
        int i = left + 1;
        for (; i <= right && preorder[i] < node->val; ++i);
        node->left = bstFromPreorder(preorder, left + 1, i - 1);
        node->right = bstFromPreorder(preorder, i, right);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return NULL;
        int *p = new int[data.size() / 2 + 1];
        int cnt = 0;
        for (int i = 0; i < data.size(); ++i)
        {
            int num = 0;
            int x = 1;
            int f = 1;
            if (data[i] == '-')
                f = -1;
            while (data[i] != ',')
            {
                num += (data[i] - '0') * x;
                x *= 10;
                ++i;
            }
            p[cnt++] = num*f;
        }
        return bstFromPreorder(p,0,cnt-1);
    }
};
int main449()
{
    Codec449 code;
    TreeNode*n1 = new TreeNode(2);
    TreeNode*n2 = new TreeNode(1);
    TreeNode*n3 = new TreeNode(3);
    n1->left = n2;
    n1->right = n3;
    string s = code.serialize(n1);
    TreeNode*p = code.deserialize(s);
    getchar();
    return 0;
}
//1008. 先序遍历构造二叉树
class Solution1008 {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder, int left, int right) {
        int len = preorder.size();
        if (len == 0 || left > right || len <= right || left < 0)
            return NULL;
        TreeNode* node = new TreeNode(preorder[left]);
        int i = left + 1;
        for (; i <= right && preorder[i] < node->val; ++i);
        node->left = bstFromPreorder(preorder, left + 1, i - 1);
        node->right = bstFromPreorder(preorder, i, right);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int len = preorder.size();
        return bstFromPreorder(preorder, 0, len - 1);
    }
};

//2019.03.16

//450. 删除二叉搜索树中的节点
class Solution450 {
public:
    TreeNode** next = NULL;
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        if (root->val == key)
        {
            TreeNode* pre = root;
            TreeNode* p = root->right;
            if (p)
            {
                while (p->left)
                {
                    pre = p;
                    p = p->left;
                }
                p->left = root->left;
                if (pre->left == p)
                {
                    //if (p->right)
                        pre->left = p->right;
                    p->right = root->right;
                }
                if (next)
                    *next = p;
                else
                    return p;
            }
            else
            {
                if (next)
                    *next = root->left;
                else
                    return root->left;
            }
        }
        else if (root->val > key)
        {
            next = &root->left;
            deleteNode(root->left, key);
        }
        else
        {
            next = &root->right;
            deleteNode(root->right, key);
        }
        return root;
    }    
    TreeNode* deleteNode2(TreeNode* root, int key) //网上找的
    {
        if (!root) return NULL;
        if (root->val == key) {
            if (!root->right) return root->left;
            else {
                TreeNode *cur = root->right;
                while (cur->left) cur = cur->left;
                swap(root->val, cur->val);
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};
int main450()
{
    Solution450 de;
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n7 = new TreeNode(7);
    n5->left = n3;
    n5->right = n6;
    n3->left = n2;
    n3->right = n4;
    n6->right = n7;

    de.deleteNode(n5,3);
    getchar();
    return 0;
}
//508. 出现次数最多的子树元素和
class Solution508 {
public:
    map<int,int> res;
    int maxCnt = 0;
    int findSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        int sum = root->val + findSum(root->left) + findSum(root->right);
        map<int, int>::iterator iter = res.find(sum);
        if (iter == res.end())
        {
            res[sum] = 1;
            if (maxCnt == 0)
                maxCnt = 1;
        }
        else
        {
            iter->second++;
            if (iter->second > maxCnt)
                maxCnt = iter->second;
        }
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        findSum(root);
        vector<int> ret;
        map<int, int>::iterator iter = res.begin();
        for (; iter != res.end();iter++)
        {
            if (maxCnt == iter->second)
            {
                ret.push_back(iter->first);
            }
        }
        return ret;
    }
};
//513. 找树左下角的值
class Solution513 {
public:
    int maxDeep = 0;
    int val = 0;
    void findBottomLeftValue2(TreeNode* root,int deep) {
        if (root)
        {
            if (deep > maxDeep)
            {
                maxDeep++;
                val = root->val;
            }
            findBottomLeftValue2(root->left, deep + 1);
            findBottomLeftValue2(root->right, deep + 1);
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        if (root == NULL)
            return 0;
        findBottomLeftValue2(root, 1);
        return val;
    }
};
//515. 在每个树行中找最大值
class Solution515 {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;
        vector<TreeNode*> s;
        s.push_back(root);
        res.push_back(root->val);
        for (int i = 0; i < s.size();)
        {
            int len = s.size();
            int max = INT_MIN;
            for ( ; i < len; ++i)
            {
                if (s[i]->left)
                {
                    s.push_back(s[i]->left);
                    if (s[i]->left->val > max)
                        max = s[i]->left->val;
                }
                if (s[i]->right)
                {
                    s.push_back(s[i]->right);
                    if (s[i]->right->val > max)
                        max = s[i]->right->val;
                }
            }
            if (i < s.size())
            {
                res.push_back(max);
            }
        }
        return res;
    }
};
//538. 把二叉搜索树转换为累加树
class Solution538 {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL)
            return root;
        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
        return root;
    }
};
//543. 二叉树的直径
class Solution543 {
public:
    int maxDeep = 0;
    int diameterOfBinaryTree2(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = diameterOfBinaryTree2(root->left);
        int right = diameterOfBinaryTree2(root->right);
        int maxcnt = left + right;
        if (maxcnt > maxDeep)
            maxDeep = maxcnt;
        return max(left,right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        diameterOfBinaryTree2(root);
        //int left = diameterOfBinaryTree2(root->left);
        //int right = diameterOfBinaryTree2(root->right);
        //int maxcnt = left + right;
        //if (maxcnt > maxDeep)
        //    maxDeep = maxcnt;
        return maxDeep;
    }
};
//563. 二叉树的坡度
class Solution563 {
public:
    int p = 0;
    int findTilt2(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }
        int left = findTilt2(root->left);
        int right = findTilt2(root->right);
        p += left > right ? left - right : right - left;
        return left + right + root->val;
    }
    int findTilt(TreeNode* root) {
        findTilt2(root);
        return p;
    }
};
//572. 另一个树的子树
class Solution572 {
public:
    bool isMatch(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL)
            return true;
        if (s && t && s->val == t->val)
            return isMatch(s->left, t->left) && isMatch(s->right, t->right);
        return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s)
            return false;
        bool res = false;
        if (t && s->val == t->val)
            res = isMatch(s, t);
        if (res || isSubtree(s->left,t) || isSubtree(s->right,t))
            return true;
        return false;
    }
};

//2019.03.17

//606. 根据二叉树创建字符串
class Solution606 {
public:
    string tree2str(TreeNode* t) {
        string s;
        if (t == NULL)
            return s;
        s.append(to_string(t->val));
        if (t->left)
        {
            s.push_back('(');
            s.append(tree2str(t->left));
            s.push_back(')');
        }
        if (t->right)
        {
            if (!t->left)
                s.append("()");
            s.push_back('(');
            s.append(tree2str(t->right));
            s.push_back(')');
        }
        return s;
    }
};
//617. 合并二叉树
class Solution617 {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 && t2)
        {
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
            delete t2;//要想到删除的节点 delete掉
            return t1;
        }
        else if (t1)
            return t1;
        else if (t2)
            return t2;
        return NULL;
    }
};
//623. 在二叉树中增加一行
class Solution623 {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (root == NULL || d <= 0)
            return root;
        if (d == 1)
        {
            TreeNode *n = new TreeNode(v);
            n->left = root;
            return n;
        }
        vector<TreeNode*> s;
        s.push_back(root);
        for (int i = 0, j = 1; i < s.size() && j < d; ++j)
        {
            int len = s.size();
            for (; i < len; ++i)
            {
                if (j == d - 1)
                {
                    TreeNode* node = new TreeNode(v);
                    TreeNode* tmp = s[i]->left;
                    s[i]->left = node;
                    node->left = tmp;
                    TreeNode* node2 = new TreeNode(v);
                    TreeNode* tmp2 = s[i]->right;
                    s[i]->right = node2;
                    node2->right = tmp2;
                }
                else 
                {
                    if (s[i]->left)
                        s.push_back(s[i]->left);
                    if (s[i]->right)
                        s.push_back(s[i]->right);
                }
            }
        }
        return root;
    }
};
//637. 二叉树的层平均值
class Solution637 {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> r;
        if (!root)
            return r;
        vector<TreeNode*> s;
        s.push_back(root);
        r.push_back(root->val);
        for (int i = 0; i < s.size(); )
        {
            long long sum = 0;
            int cnt = 0;
            int len = s.size();
            for (; i < len; ++i)
            {
                if (s[i]->left)
                {
                    sum += s[i]->left->val;
                    cnt++;
                    s.push_back(s[i]->left);
                }
                if (s[i]->right)
                {
                    sum += s[i]->right->val;
                    cnt++;
                    s.push_back(s[i]->right);
                }
            }
            if (cnt > 0)
                r.push_back(double(sum) / cnt);
        }
        return r;
    }
};
//652. 寻找重复的子树
class Solution652 {//错误答案
public:
    map<int, vector<TreeNode*>> s;
    void find(TreeNode* root) {
        if (!root)
            return;
        map<int, vector<TreeNode*>>::iterator iter = s.find(root->val);
        if (iter != s.end())
            iter->second.push_back(root);
        else
            s[root->val] = vector<TreeNode*>(1, root);
        find(root->left);
        find(root->right);
    }
    bool isMatch(TreeNode* t1, TreeNode* t2) {
        if (t1 && t2)
        {
            return t1->val == t2->val 
                && isMatch(t1->left, t2->left) 
                && isMatch(t1->right,t2->right);
        }
        else if (!t1 && !t2)
            return true;
        return false;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        find(root);
        vector<TreeNode*> res;
        map<int, vector<TreeNode*>>::iterator iter = s.begin();
        for (; iter != s.end(); ++iter)
        {
            for (int i = 0; i < iter->second.size(); ++i)
            {
                for (int j = i + 1; j < iter->second.size(); ++j)
                {
                    if (isMatch(iter->second[i], iter->second[j]))
                    {
                        res.push_back(iter->second[i]);
                    }
                }
            }
        }
        return res;
    }
};
//653. 两数之和 IV - 输入 BST
class Solution653 {
public:
    bool isTarget(TreeNode* root, TreeNode* n, int k) {
        if (root == NULL)
            return false;
        if (root != n && root->val == k)
            return true;
        if (root->val > k)
            return isTarget(root->left, n, k);
        return isTarget(root->right, n, k);
    }
    bool findTarget2(TreeNode* root, TreeNode* curNode, int k) {
        if (!curNode)
            return false;
        return isTarget(root, curNode, k - curNode->val)
            || findTarget2(root, curNode->left, k)
            || findTarget2(root, curNode->right, k);
    }
    bool findTarget3(TreeNode* root, int k) {
        return findTarget2(root, root, k);
    }
    TreeNode*r = NULL;
    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;
        if (!r)
            r = root;
        return isTarget(r, root, k - root->val)
            || findTarget(root->left, k)
            || findTarget(root->right, k);
    }
};
//654. 最大二叉树
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int left, int right) {
        if (left > right)
            return NULL;
        int maxNum = nums[left];
        int pos = left;
        for (int i = left + 1; i <= right; ++i)
        {
            if (maxNum < nums[i])
            {
                maxNum = nums[i];
                pos = i;
            }
        }
        TreeNode* n = new TreeNode(maxNum);
        n->left = constructMaximumBinaryTree(nums, left, pos - 1);
        n->right = constructMaximumBinaryTree(nums, pos + 1, right);
        return n;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return NULL;
        return constructMaximumBinaryTree(nums, 0, len - 1);
    }
};
//662. 二叉树最大宽度
class Solution662 {
public:
    int widthOfBinaryTree2(TreeNode* root) {//107/108 超出内存限制
        int maxW = 0;
        if (root == NULL)
            return maxW;
        vector<TreeNode*> s;
        s.push_back(root);
        maxW = 1;
        for (int i = 0; i < s.size();)
        {
            int len = s.size();
            int st = -1;
            int ed = 0;
            for (int j = 0; i < len; ++i,j+=2)
            {
                if (s[i])
                {
                    if (s[i]->left)
                    {
                        if (st == -1)
                            st = j;
                        ed = j;
                    }
                    if (s[i]->right)
                    {
                        if (st == -1)
                            st = j+1;
                        ed = j+1;
                    }
                    s.push_back(s[i]->left);
                    s.push_back(s[i]->right);
                }
                else
                {
                    s.push_back(NULL);
                    s.push_back(NULL);
                }
            }
            if (st >= 0)
            {
                int cur = ed - st + 1;
                if (cur > maxW)
                    maxW = cur;
            }
            else
                break;
        }
        return maxW;
    }
    int widthOfBinaryTree4(TreeNode* root) {//107/108 超出内存限制
        int maxW = 0;
        if (root == NULL)
            return maxW;
        TreeNode* s[1024];
        int slen = 0;
        memset(s, 0, sizeof(s));
        TreeNode* s2[1024];
        s[0] = root;
        slen = 1;
        maxW = 1;
        while (slen > 0)
        {
            int st = -1;
            int ed = 0;
            memset(s2, 0, sizeof(s2));
            int slen2 = 0;
            for (int i = 0,j = 0; i < slen; ++i, j += 2)
            {
                if (s[i])
                {
                    if (s[i]->left)
                    {
                        if (st == -1)
                            st = j;
                        ed = j;
                    }
                    if (s[i]->right)
                    {
                        if (st == -1)
                            st = j + 1;
                        ed = j + 1;
                    }
                    s2[slen2++] = s[i]->left;
                    s2[slen2++] = s[i]->right;
                }
                else
                {
                    s2[slen2++] = NULL;
                    s2[slen2++] = NULL;
                }
            }
            if (st >= 0)
            {
                int cur = ed - st + 1;
                if (cur > maxW)
                    maxW = cur;
            }
            else
                break;
            memcpy(s, s2, sizeof(s));
            slen = slen2;
        }
        return maxW;
    }
    int maxNum = 0;
    vector<int> d;
    void widthOfBinaryTree3(TreeNode* root,int deep) {
        if (root == NULL)
            return;
        if (d.size() > deep)
            d[deep]++;
        else
            d.push_back(1);
        if (maxNum < d[deep])
            maxNum = d[deep];
        widthOfBinaryTree3(root->left, deep + 1);
        widthOfBinaryTree3(root->right, deep + 1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        widthOfBinaryTree3(root, 1);
        return maxNum;
    }
};
//669. 修剪二叉搜索树
class Solution669 {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root == NULL || L > R)
            return root;
        if (root->val > R)
            return trimBST(root->left, L, R);
        if (root->val < L)
            return trimBST(root->right, L, R);
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};

//2019.03.18

//671. 二叉树中第二小的节点
class Solution671 {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL)
            return -1;
        int sec = -1;
        if (root->left && root->left->val != root->val)
            sec = root->left->val;
        if (root->right && root->right->val != root->val)
        {
            if (sec > 0)
                sec = std::min(root->right->val, sec);
            else
                sec = root->right->val;
        }
        int lsec = findSecondMinimumValue(root->left);
        if (lsec > 0)
        {
            if (sec > 0)
                sec = std::min(lsec, sec);
            else
                sec = lsec;
        }
        int rsec = findSecondMinimumValue(root->right);
        if (rsec > 0)
        {
            if (sec > 0)
                sec = std::min(rsec, sec);
            else
                sec = rsec;
        }
        return sec;
    }
};
//687. 最长同值路径
class Solution687 {
public:
    int maxNum = 0;
    int longestUnivaluePath2(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = longestUnivaluePath2(root->left);
        if (root->left && root->left->val == root->val)
            left++;
        else
            left = 0;
        int right = longestUnivaluePath2(root->right);
        if (root->right && root->right->val == root->val)
            right++;
        else
            right = 0;
        int lr = left + right;
        if (lr > maxNum)
            maxNum = lr;
        return std::max(left,right);
    }
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL)
            return 0;
        longestUnivaluePath2(root);
        return maxNum;
    }
};
int main687()
{
    Solution687 s;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(4);
    TreeNode* n3 = new TreeNode(5);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(4);
    TreeNode* n6 = new TreeNode(5);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    int i = s.longestUnivaluePath(n1);
    getchar();
    return 0;
}
//429. N叉树的层序遍历
// Definition for a Node.
class NNode {
public:
    int val;
    vector<NNode*> children;
    NNode() {}
    NNode(int _val, vector<NNode*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution492 {
public:
    vector<vector<int>> levelOrder(NNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        vector<int> t;
        t.push_back(root->val);
        res.push_back(t);
        vector<NNode*> s;
        s.push_back(root);
        while (s.size() > 0)
        {
            vector<int> tmp;
            vector<NNode*> st;
            for (int i = 0; i < s.size(); ++i)
            {
                for (int j = 0; j < s[i]->children.size(); ++j)
                {
                    if (s[i]->children[j])
                    {
                        st.push_back(s[i]->children[j]);
                        tmp.push_back(s[i]->children[j]->val);
                    }
                }
            }
            if (tmp.size() > 0)
            {
                res.push_back(tmp);
                s = st;
            }
            else
            {
                break;
            }
        }
        return res;
    }
};
//559. N叉树的最大深度
class Solution559 {
public:
    int maxDepth(NNode* root) {
        if (root == NULL)
            return 0;
        int maxNum = 0;
        for (int i = 0; i < root->children.size(); ++i)
            maxNum = std::max(maxDepth(root->children[i]),maxNum);
        return maxNum + 1;
    }
};
//589. N叉树的前序遍历
class Solution589 {
public:
    vector<int> preorder(NNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;
        res.push_back(root->val);
        for (int i = 0; i < root->children.size(); ++i)
        {
            vector<int> r = preorder(root->children[i]);
            res.insert(res.end(), r.begin(), r.end());
        }
        return res;
    }
};

//2019.03.19

//590. N叉树的后序遍历
class Solution590 {
public:
    vector<int> postorder(NNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;
        for (int i = 0; i < root->children.size(); ++i)
        {
            vector<int> r = postorder(root->children[i]);
            res.insert(res.end(), r.begin(), r.end());
        }
        res.push_back(root->val);
        return res;
    }
};
//700. 二叉搜索树中的搜索
class Solution700 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL)
            return root;
        if (root->val == val)
            return root;
        else if (root->val > val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};
//701. 二叉搜索树中的插入操作
class Solution701 {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL)
            return root;
        if (root->val == val)
        {
        }
        else if (root->val > val)
        {
            if (root->left)
                insertIntoBST(root->left, val);
            else
            {
                root->left = new TreeNode(val);
            }
        }
        else
        {
            if (root->right)
                insertIntoBST(root->right, val);
            else
                root->right = new TreeNode(val);
        }
        return root;
    }
};
//814. 二叉树剪枝
class Solution814 {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL)
            return root;
        TreeNode* left = pruneTree(root->left);
        TreeNode* right = pruneTree(root->right);
        if (!left)
            root->left = NULL;
        if (!right)
            root->right = NULL;
        return root->val != 0 || left || right ? root : NULL;
    }
};
//863. 二叉树中所有距离为 K 的结点
class Solution863 {
public:
    vector<int> res;
    void disK(TreeNode* root, int K) {
        if (root == NULL || K < 0)
            return;
        if (K == 0)
        {
            res.push_back(root->val);
            return;
        }
        disK(root->left, K - 1);
        disK(root->right, K - 1);
    }
    int disFindK(TreeNode* root, TreeNode* target, int K) {
        if (root == NULL || K < 0)
            return K;
        if (target == root)
            return K - 1;
        int left = disFindK(root->left, target, K);
        int right = disFindK(root->right, target, K);
        if (left < 0 || right < 0)
            return -1;
        if (left == 0 || right == 0)
        {
            res.push_back(root->val);
            return -1;
        }
        if (left < K)
        {
            disK(root->right, left - 1);
            return left - 1;
        }
        if (right < K)
        {
            disK(root->left, right - 1);
            return right - 1;
        }
        return K;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (K < 0 || target == NULL)
            return res;
        if (K == 0)
        {
            res.push_back(target->val);
            return res;
        }
        disK(target, K);
        disFindK(root,target,K);
        return res;
    }
};

//2019.03.20

//865. 具有所有最深结点的最小子树
class Solution865 {
public:
    int deep(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        int left = deep(root->left);
        int right = deep(root->right);
        return max(left,right) + 1;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return root;
        int left = deep(root->left);
        int right = deep(root->right);
        if (left == right)
            return root;
        if (left > right)
            return subtreeWithAllDeepest(root->left);
        return subtreeWithAllDeepest(root->right);
    }
};
//872. 叶子相似的树
class Solution872 {
public:
    void bianli(TreeNode* root,vector<int> &s) {
        if (root == NULL)
            return;
        if (!root->left && !root->right)
            s.push_back(root->val);
        bianli(root->left,s);
        bianli(root->right,s);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> s1;
        vector<int> s2;
        bianli(root1, s1);
        bianli(root2, s2);
        if (s1.size() == s2.size())
        {
            for (int i = 0; i < s1.size(); ++i)
            {
                if (s1[i] != s2[i])
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
        return true;
    }
};

//2019.03.21

//897. 递增顺序查找树
class Solution897 {
public:
    TreeNode* increasingBST2(TreeNode* root, TreeNode* &end) {
        if (root == NULL)
            return NULL;
        TreeNode* rend = NULL;
        TreeNode* rstr = NULL;
        rstr = increasingBST2(root->right, rend);
        TreeNode* lend = NULL;
        TreeNode* lstr = NULL;
        lstr = increasingBST2(root->left, lend);
        //
        root->left = NULL;
        root->right = rstr;
        if (rend)
            end = rend;
        else
            end = root;
        if (lend)
        {
            lend->right = root;
        }
        if (lstr)
        {
            return lstr;
        }
        return root;
    }
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL)
            return NULL;
        TreeNode* end = NULL;
        return increasingBST2(root, end);
    }
};
int main897()
{
    Solution897 s;
    TreeNode*n1 = new TreeNode(1);
    TreeNode*n2 = new TreeNode(2);
    TreeNode*n3 = new TreeNode(3);
    TreeNode*n4 = new TreeNode(4);
    TreeNode*n5 = new TreeNode(5);
    TreeNode*n6 = new TreeNode(6);
    TreeNode*n7 = new TreeNode(7);
    TreeNode*n8 = new TreeNode(8);
    TreeNode*n9 = new TreeNode(9);
    n5->left = n3;
    n5->right = n6;
    n3->left = n2;
    n3->right = n4;
    n6->right = n8;
    n2->left = n1;
    n8->left = n7;
    n8->right = n9;
    TreeNode * r = s.increasingBST(n5);
    getchar();
    return 0;
}
//889. 根据前序和后序遍历构造二叉树
class Solution889 {
public:
    TreeNode* constructFromPrePost(
        vector<int>& pre, int xl, int xr,
        vector<int>& post, int hl, int hr ) {
        if (xl > xr || xr - xl != hr - hl)
            return NULL;
        TreeNode *node = new TreeNode(pre[xl]);
        if (xr - xl == 0)
            return node;
        xl++;
        int i = 0;
        for (; i + hl <= hr && post[i + hl] != pre[xl]; i++);
        node->left = constructFromPrePost(pre, xl, xl + i, post, hl, hl + i);
        node->right = constructFromPrePost(pre, xl + 1 + i, xr, post, hl + i + 1, hr-1);
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int xlen = pre.size();
        int hlen = post.size();
        if (xlen != hlen || xlen == 0)
            return NULL;
        return constructFromPrePost(pre,0,xlen-1,post,0,hlen-1);
    }
};
//894. 所有可能的满二叉树
class Solution894 {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        if (N % 2 == 0)
            return res;
        if (N == 1)
        {
            TreeNode* head = new TreeNode(0);
            res.push_back(head);
        }
        for (int i = 1; i < N; ++i)
        {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(N-i-1);
            for (int j = 0; j < left.size(); ++j)
            {
                for (int k = 0; k < right.size(); ++k)
                {
                    TreeNode* head = new TreeNode(0);
                    head->left = left[j];
                    head->right = right[k];
                    res.push_back(head);
                }
            }
        }
        return res;
    }
};
//993. 二叉树的堂兄弟节点
class Solution993 {
public:
    int xDeep = 0;
    int yDeep = 0;
    int isB = false;
    void isCousins3(TreeNode* root, int x, int y, int curDeep) {
        if (root == NULL)
            return;
        if (root->val == x)
            xDeep = curDeep;
        else if (root->val == y)
            yDeep = curDeep;
        if (root->left && root->right && 
            ((root->left->val == x && root->right->val == y)
             || (root->left->val == y && root->right->val == x)))
        {
            isB = true;
        }
        isCousins3(root->left, x, y, curDeep + 1);
        isCousins3(root->right, x, y, curDeep + 1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL)
            return false;
        isCousins3(root,x,y,0);
        return !isB && (xDeep > 0 && yDeep > 0 && xDeep == yDeep);
    }
};
//951. 翻转等价二叉树
class Solution951 {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 && root2)
        {
            if (root1->val == root2->val)
            {
                return (flipEquiv(root1->left, root2->left)
                        && flipEquiv(root1->right, root2->right))
                    || (flipEquiv(root1->left, root2->right) 
                        && flipEquiv(root1->right, root2->left));
            }
        }
        else if (!root1 && !root2)
        {
            return true;
        }
        return false;
    }
};
//958. 二叉树的完全性检验
class Solution958 {
public:
    int maxDeep = 0;
    int scdDeep = 0;
    bool isCompleteTree2(TreeNode* root,int deep) {
        if (!root)
        {
            if (deep < maxDeep - 1)
            {
                return false;
            }
            if (deep == maxDeep)
            {
                scdDeep = deep - 1;
            }
            return true;
        }
        if (deep > maxDeep)
        {
            maxDeep = deep;
        }
        if (!root->left && !root->right)
        {
            if (deep < maxDeep - 1)
            {
                return false;
            }
            else if (deep < maxDeep)
            {
                scdDeep = deep;
            }
            if (scdDeep > 0 && deep > scdDeep)
            {
                return false;
            }
        }
        return isCompleteTree2(root->left,deep+1) && isCompleteTree2(root->right, deep + 1);
    }
    bool isCompleteTree22(TreeNode* root) {//错误答案
        return isCompleteTree2(root, 1) && (scdDeep == 0 || scdDeep > 0 && scdDeep >= maxDeep - 1);
    }
    int isCompleteTree3(TreeNode* root) {//错误答案
        if (root == NULL)
            return 0;
        int left = isCompleteTree3(root->left);
        int right = isCompleteTree3(root->right);
        if (left < 0 && right < 0)
        {
            return INT_MIN;
        }
        if (left > 0 && right > 0)
        {
            if (right > left)
            {
                return INT_MIN;
            }
            if (left - 1 > right)
            {
                return INT_MIN;
            }
            return left + 1;
        }
        if (left > 0 && right < 0 && left == -right)
        {
            return right - 1;
        }
        if (left < 0 && right > 0 && -left == right - 1)
        {
            return left;
        }
        return INT_MIN;
    }
    bool isCompleteTree(TreeNode* root) {//终于过啦
        if (root == NULL)
            return true;
        vector<TreeNode*> s;
        s.push_back(root);
        int j = 1;
        for (int i = 0; i < s.size();j*=2)
        {
            int len = s.size();
            bool last = true;
            int cnt = 0;
            int cnt2 = 0;
            for (; i < len; ++i)
            {
                if (s[i])
                {
                    if (s[i]->left)
                    {
                        s.push_back(s[i]->left);
                        cnt2++;
                        if (last)
                            cnt++;
                    }
                    else
                        last = false;
                    if (s[i]->right)
                    {
                        s.push_back(s[i]->right);
                        cnt2++;
                        if (last)
                            cnt++;
                    }
                    else
                        last = false;
                }
            }
            if (cnt2 < j*2)
            {
                if (cnt < cnt2)
                    return false;
                for (; i < s.size(); ++i)
                {
                    if (s[i]->left || s[i]->right)
                        return false;
                }
            }
        }
        return true;
    }
};
//965. 单值二叉树
class Solution965 {
public:
    bool isUnivalTree(TreeNode* root) {
        if (root == NULL)
            return true;
        if (root->left && root->left->val != root->val)
            return false;
        if (root->right && root->right->val != root->val)
            return false;
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};

//2019.03.24

//968. 监控二叉树
class Solution968 {
public:
    int minCameraCover2(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (!root->left && !root->right)
        {
            return 0x10000;
        }
        int left = minCameraCover2(root->left);
        int right = minCameraCover2(root->right);
        int res = (left & 0xffff) + (right & 0xffff);
        if ((left & 0x10000) || (right & 0x10000))
        {
            res |= 0x20000;
            res++;
            return res;
        }
        if ((left & 0x20000) || (right & 0x20000))
        {
            return res;
        }
        return res | 0x10000;
    }
    int minCameraCover(TreeNode* root) {
        if (root == NULL)
            return 0;
        int res = minCameraCover2(root);
        if (res & 0x10000)
        {
            res++;
        }
        return res & 0xffff;
    }
};
//971. 翻转二叉树以匹配先序遍历
class Solution971 {
public:
    int index = 0;
    vector<int> res;
    bool flipMatchVoyage2(TreeNode* root, vector<int>& voyage) {
        if (root == NULL)
            return true;
        if (voyage.size() <= index
            || root->val != voyage[index])
        {
            return false;
        }
        index++;
        if (flipMatchVoyage2(root->left, voyage))
        {
            return flipMatchVoyage2(root->right, voyage);
        }
        else
        {
            if (flipMatchVoyage2(root->right, voyage))
            {
                res.push_back(root->val);
                return flipMatchVoyage2(root->left, voyage);
            }
        }
        return false;
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if (root == NULL)
        {
            return res;
        }
        if (!flipMatchVoyage2(root,voyage))
        {
            res.clear();
            res.push_back(-1);
        }
        return res;
    }
};
//979. 在二叉树中分配硬币
class Solution979 {
public:
    int cnt = 0;
    int distributeCoins2(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }
        int left = distributeCoins2(root->left);
        int right = distributeCoins2(root->right);
        cnt += left >= 0 ? left : -left;
        cnt += right >= 0 ? right : -right;
        int r = root->val - 1;
        return left + right + r;
    }
    int distributeCoins(TreeNode* root) {
        if (root == NULL)
            return 0;
        distributeCoins2(root);
        return cnt;
    }
};

//2019.03.25

//987. 二叉树的垂序遍历
class Solution987 {
public:
    struct record
    {
        int _x;
        int _y;
        int _val;
        record(int x, int y, int v):_x(x),_y(y),_val(v){}
        bool operator < (const record &r) const
        {
            if (this->_x < r._x)
                return true;
            else if (this->_x == r._x)
            {
                if (this->_y > r._y)
                    return true;
                else if (this->_y == r._y && this->_val < r._val)
                    return true;
            }
            return false;
        }
    };
    set<record> res;
    void verticalTraversal2(TreeNode* root,int x,int y) {
        if (root == NULL)
            return;
        record r(x,y,root->val);
        res.insert(r);
        verticalTraversal2(root->left, x - 1, y - 1);
        verticalTraversal2(root->right, x + 1, y - 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        verticalTraversal2(root,0,0);
        int x = INT_MIN;
        vector<int> r;
        vector<vector<int>> rr;
        set<record>::iterator iter = res.begin();
        for (; iter != res.end(); ++iter)
        {
            if (x != iter->_x)
            {
                x = iter->_x;
                if (r.size() > 0)
                {
                    rr.push_back(r);
                    r.clear();
                }
            }
            r.push_back(iter->_val);
        }
        if (r.size()>0)
        {
            rr.push_back(r);
            r.clear();
        }
        return rr;
    }
};
int main987()
{
    TreeNode*n1 = new TreeNode(3);
    TreeNode*n2 = new TreeNode(9);
    TreeNode*n3 = new TreeNode(20);
    TreeNode*n4 = new TreeNode(15);
    TreeNode*n5 = new TreeNode(7);
    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;
    Solution987 s;
    vector<vector<int>> rr = s.verticalTraversal(n1);
    return 0;
}
//988. 从叶结点开始的最小字符串
class Solution988 {//错误答案
public:
    bool less(string a,string b)
    {
        int alen = a.size();
        int blen = b.size();
        bool is = true;
        for (int i = 0; i < alen && i < blen; ++i)
        {
            if (a[i] > b[i])
                return false;
            if (a[i] == b[i])
            {
            }
            else
            {
                is = false;
            }
        }
        if (is)
        {
            return alen <= blen;
        }
        return true;
    }
    string smallestFromLeaf(TreeNode* root) {
        string rr;
        if (root == NULL)
            return rr;
        string l = smallestFromLeaf(root->left);
        string r = smallestFromLeaf(root->right);
        l.push_back(root->val + 'a');
        r.push_back(root->val + 'a');
        if (l.size() == 1)
            return r;
        if (r.size() == 1)
            return l;
        if (less(l,r))
            return l;
        return r;
    }
};
//78. 子集
class Solution78 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> rr;
        res.push_back(rr);
        int len = nums.size();
        if (len == 0)
        {
            return res;
        }
        int max = 1 << len;
        for (int i = 1; i < max; ++i)
        {
            vector<int> rrr;
            int h = i;
            int j = 0;
            while (h > 0)
            {
                if (h & 1)
                    rrr.push_back(nums[j]);
                h >>= 1;
                j++;
            }
            res.push_back(rrr);
        }
        return res;
    }
};

//2019.03.26

//187. 重复的DNA序列
class Solution187 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<int,int> r;
        int len = s.size();
        vector<string> rr;
        if (len < 10)
            return rr;
        int t = 0;
        for (int i = 0; i < 10; ++i)
        {
            t <<= 2;
            switch (s[i])
            {
            case 'A':
                break;
            case 'C':
                t |= 1;
                break;
            case 'G':
                t |= 2;
                break;
            case 'T':
                t |= 3;
                break;
            default:
                break;
            }
            t &= 0xfffff;
        }
        r[t] = 1;
        for (int i = 10; i < len; ++i)
        {
            t <<= 2;
            switch (s[i])
            {
            case 'A':
                break;
            case 'C':
                t |= 1;
                break;
            case 'G':
                t |= 2;
                break;
            case 'T':
                t |= 3;
                break;
            default:
                break;
            }
            t &= 0xfffff;
            map<int, int>::iterator iter = r.find(t);
            if (iter != r.end())
            {
                iter->second++;
                if (iter->second == 2)
                    rr.push_back(s.substr(i - 9, 10));
            }
            else
            {
                r[t] = 1;
            }
        }
        return rr;
    }
};
int main187()
{
    Solution187 s;
    s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    return 0;
}
//201. 数字范围按位与
class Solution201 {
public:
    int rangeBitwiseAnd(int m, int n) {//	超出时间限制
        if (m>n)
        {
            return 0;
        }
        int s = m;
        for (int i = m+1; i <= n; ++i)
        {
            s &= i;
        }
        return s;
    }
    int rangeBitwiseAnd2(int m, int n) {//my
        if (m > n || m == 0)
            return 0;
        int t = n;
        int w = 0;
        while (t > 0)
        {
            w++;
            t >>= 1;
        }
        int max2 = 1 << (w-1);
        if (max2 > m)
        {
            return 0;
        }
        else if (max2 == m)
        {
            return max2;
        }
        return max2 | rangeBitwiseAnd2(m - max2, n - max2);
    }
    int rangeBitwiseAnd3(int m, int n) {//网上找的
        while (n > m)
        {
            n &= (n-1);
        }
        return n;
    }
};
//260. 只出现一次的数字 III
class Solution260 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int yh = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            yh ^= nums[i];
        }
        yh &= (-yh);
        int a = 0;
        int b = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if ((nums[i] & yh) > 0)
            {
                a ^= nums[i];
            }
            else
            {
                b ^= nums[i];
            }
        }
        vector<int> r;
        r.push_back(a);
        r.push_back(b);
        return r;
    }
};
//338. 比特位计数
class Solution338 {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1,0);
        int j = 1;
        for (int i = 1; i <= num; ++i)
        {
            if (i >= j)
            {
                j <<= 1;
            }
            dp[i] = 1 + dp[i-(j>>1)];
        }
        return dp;
    }
    vector<int> countBits2(int num) {//网上找的
        vector<int> dp(num + 1, 0);
        for (int i = 0; i <= num; ++i)
        {
            dp[i] = dp[i&(i - 1)] + 1;
        }
        return dp;
    }
};
//397. 整数替换
class Solution397 {
public:
    int integerReplacement(int n) {
        int cnt = 0;
        long long m = n;
        while (m != 1)
        {
            if (m == 3)
            {
                return cnt+2;
            }
            if (m & 1)
            {
                if (m & 2)
                {
                    m += 1;
                }
                else
                {
                    m -= 1;
                }
            }
            else
            {
                m >>= 1;
            }
            cnt++;
        }
        return cnt;
    }
};
//476. 数字的补数
class Solution476 {
public:
    int findComplement(int num) {
        long long i = 1;
        while (i <= num)
        {
            i <<= 1;
        }
        i--;
        return i ^ num;
    }
};
//693. 交替位二进制数
class Solution693 {
public:
    bool hasAlternatingBits(int n) {
        int n1 = n;
        n1 <<= 1;
        n1 ^= n;
        n1 >>= 1;
        n1++;
        return (n1 & (n1-1)) == 0;
    }
};

//2019.03.27

//784. 字母大小写全排列
class Solution784 {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        int len = S.size();
        if (len <= 0)
        {
            res.push_back(S);
            return res;
        }
        int cnt = 0;
        for (int i = 0; i < len; ++i)
        {
            if (S[i] < '0' || S[i] > '9')
                cnt++;
            if (S[i] >= 'A' && S[i] <= 'Z')
                S[i] = S[i] - 'A' + 'a';
        }
        if (cnt == 0)
        {
            res.push_back(S);
            return res;
        }
        int maxNum = 1 << cnt;
        for (int i = 0; i < maxNum; ++i)
        {
            string s = S;
            for (int j = 0,k = 0; j < s.size() && k < cnt; ++j)
            {
                if (s[j] >= 'a' && s[j] <= 'z')
                {
                    if (i & (1 << k))
                        s[j] = s[j] - 'a' + 'A';
                    k++;
                }
            }
            res.push_back(s);
        }
        return res;
    }
};

//2019.03.28

//762. 二进制表示中质数个计算置位
class Solution762 {
public:
    bool isZhishu(int num)
    {
        switch (num)
        {
        //case 1:
        case 2:
        case 3:
        case 5:
        case 7:
        case 11:
        case 13:
        case 17:
        case 19:
        case 23:
        case 29:
        case 31:
            return true;
        default:
            break;
        }
        return false;
    }
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for (int i = L; i <= R; ++i)
        {
            int num = i;
            int cnt = 0;
            while (num > 0)
            {
                cnt++;
                num &= (num-1);
            }
            if (isZhishu(cnt))
            {
                res++;
            }
        }
        return res;
    }
};
//477. 汉明距离总和
class Solution477 {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> num0(32, 0);
        vector<int> num1(32, 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int n = nums[i];
            unsigned int probe = 1;
            for (int j = 0; j < 32; ++j, probe <<= 1)
            {
                if (n & probe)//1
                {
                    num1[j]++;
                    sum += num0[j];
                }
                else //0
                {
                    num0[j]++;
                    sum += num1[j];
                }
            }
        }
        return sum;
    }
};
//470. 用 Rand7() 实现 Rand10()
class Solution470 {
public:
    int rand7()
    {
        return 0;
    }
    int rand10() {//网上找的 2.56次
        int small = rand7();
        while (small == 7)
            small = rand7();
        int tmpn = rand7();
        while (tmpn > 5)
            tmpn = rand7();
        if (small < 4)
            return tmpn;
        else
            return tmpn + 5;
    }
    int rand102() {
        int res = 40;
        while (res >= 40) {//网上找的 2.4
            res = 7 * (rand7() - 1) + (rand7() - 1); //rand10可以通过对10取余+1得到。rand7()-1产生0~6,7*(rand7()-1)产生[0,7,14,21,28,35,42],再加rand7()-1得到0~49,舍去大于等于40的部分即可
        }
        return res % 10 + 1;
    }
};

//2019.03.29

//318. 最大单词长度乘积
class Solution318 {
public:
    int maxProduct(vector<string>& words) {//参考答案写的
        int len = words.size();
        if (len == 0)
            return 0;
        int* res = new int[len];//没初始化
        memset(res, 0, sizeof(int)*len);//*******
        //vector<int> res(len,0);
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < words[i].size(); ++j)
            {
                res[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        int max = 0;
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                if (i != j && !(res[i] & res[j]))
                {
                    int num = words[i].size() * words[j].size();
                    if (num > max)
                        max = num;
                }
            }
        }
        return max;
    }
};