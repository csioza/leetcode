#pragma once
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;
#include <time.h>

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
int strStr(string haystack, string needle) {//TODO:KMP
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
void MySwap1(int &a, int &b)
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
        b     = a;
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
                //MySwap(arr[i], arr[++j]);
                MySwap3(arr,i,++j);
            }
        }
        //MySwap(arr[p], arr[j]);
        MySwap3(arr, p, j);
        //
        QuickSort(arr, p, j - 1);
        QuickSort(arr, j + 1, r);
    }
}
int main217()
{
    printf("交换1和2,100亿次");
    int m = 1, n = 2;
    time_t t1 = time(0);
    for (long long i = 0; i < 10000000000; i++)
    {
        MySwap1(m, n);
    }
    time_t t2 = time(0);
    printf("\nMySwap1:start[%d],end[%d],sub[%d]", t1, t2, t2 - t1);//191s,188s,189s

    m = 1, n = 2;
    t1 = time(0);
    for (long long i = 0; i < 10000000000; i++)
    {
        MySwap2(m, n);
    }
    t2 = time(0);
    printf("\nMySwap2:start[%d],end[%d],sub[%d]", t1, t2, t2 - t1);//172s,171s,172s
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