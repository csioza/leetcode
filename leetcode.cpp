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
int romanToInt(string s) {
    
}
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


int main()
{
    string ss = longestCommonPrefix("ab", ".*c");
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