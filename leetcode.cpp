#pragma once
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;

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
    int min = 0;
    int max = x;
    while (min < max)
    {
        int mid = min + (max - min) / 2;//边界问题确实恶心
        int mm = mid * mid;
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
    return min > max ? max : min;
}
int main()
{
    int ss = mySqrt(50);
    printf("%d", ss);
    getchar();
    return 0;
}