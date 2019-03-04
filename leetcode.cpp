#pragma once
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;
#include <time.h>
#include <sstream>

//1. ����֮��
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
//2. �������
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
//3. ���ظ��ַ�����Ӵ�
int lengthOfLongestSubstring(string s) {//�����
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
//4. Ѱ�����������������λ��
//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//
//}
//5. ������Ӵ�
int main5()
{
    string s = "abcabcbb";
    int num = lengthOfLongestSubstring(s);
    printf("%d", num);
    getchar();
    return 0;
}
//6. Z ���α任 
//ֻ���ҹ���
string convert(string s, int numRows) 
{
    const char *str = s.c_str();
    int len = strlen(str);
    string rlt;
    int zhou = 2 * numRows - 2;
    if (zhou <= 0 || len <= 0)//���˸��Ⱥ�zhou <= 0
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
//7. ������ת
int reverse(int x) 
{
    int f = 1;
    long long xx = x;
    if (xx < 0)
    {
        f = -1;
        xx = -xx;//������ܲ�д��û˭��
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
//8. �ַ���ת������ (atoi)
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
//9. ������
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
//10. ������ʽƥ��
bool isMatch(string s, string p) {//�����
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
//13. ��������ת����
//int romanToInt(string s) {
//    
//}
//14. �����ǰ׺
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
//20. ��Ч������
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
//21. �ϲ�������������
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
//26. ɾ�����������е��ظ���
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
//27. �Ƴ�Ԫ��
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
//28. ʵ��strStr()
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
//35. ��������λ��
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
int searchInsert2(vector<int>& nums, int target) {//�����
    int max = nums.size();//���ǲ���һ���
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
//38. ����
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
//53. ��������
int maxSubArray(vector<int>& nums) {//�ҵĴ𰸣��е㱿
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
int maxSubArray2(vector<int>& nums) {//�����
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
//54. ��������
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
//59. �������� II
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
//58. ���һ�����ʵĳ���
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
//60. ��k������
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
//67. ���������
string addBinary(string a, string b) {//�����
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
    
    if (num & (1<<cnt))//����˸�1 .cnt+1
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
string addBinary2(string a, string b) {//�ҵ���ȷ��
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
        ss.push_back('1');//©д��
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
//69. x ��ƽ����
int mySqrt(int x) {
    long long min = 0;
    long long max = x;
    while (min < max)
    {
        long long mid = min + (max - min) / 2;//�߽�����ȷʵ����
        long long mm = mid * mid;//int����� 
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
int mySqrt2(int x) {//����Ĵ���
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
//70. ��¥��
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
//83. ɾ�����������е��ظ�Ԫ��
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
//88. �ϲ�������������
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
//100. ��ͬ����
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
//101. �Գƶ�����
bool isSymmetric(TreeNode* root) {//��������
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
        //���һ���Ƿ���
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
bool isSymmetric2(TreeNode* root) {//�ݹ鷽��
    if (root == NULL)
        return true;
    return isSymmetric3(root->left,root->right);
}
//104. ��������������
int maxDepth(TreeNode* root) {
    if (root == NULL)
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return (left > right ? left : right) + 1;
}
//107. �������Ĳ�α��� II
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
//108. ����������ת��Ϊ����������
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
//110. ƽ�������
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
//111. ����������С���
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
//112. ·���ܺ�
bool hasPathSum(TreeNode* root, int sum) {//����𰸣���ʵ����ô���
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
bool hasPathSum2(TreeNode* root, int sum) {//�ҵ���ȷ��
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
//118. �������
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
//119. ������� II
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
                int tmp2 = rlt[j];//����е���
                rlt[j] = rlt[j] + tmp;
                tmp = tmp2;//����е���
            }
        }
    }
    return rlt;
}
//121. ������Ʊ�����ʱ��
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
//122. ������Ʊ�����ʱ�� II
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
//123. ������Ʊ�����ʱ�� III
int maxProfit3(vector<int>& prices) {
    return 0;
}
//125. ��֤���Ĵ�
bool isPalindrome(string s) {//�����
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
bool isPalindrome2(string s) {//����ʵʵд����case
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
//136. ֻ����һ�ε�����
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
//141. ��������
bool hasCycle(ListNode *head) {//�����
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
        p = p->next;//����д��
        pp = pp->next->next;//����д��
    }
    return false;
}
bool hasCycle2(ListNode *head) {//�ҵ���ȷ��

    if (head == NULL)
        return false;
    ListNode * p = head/*->next*/;
    ListNode * pp = head;
    while (/*p && */pp)
    {
        if (pp->next == NULL || pp->next->next == NULL)
            return false;
        p = p->next;//����д��
        pp = pp->next->next;//����д��
        if (p == pp)
            return true;
    }
    return false;
}
//155. ��Сջ
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
//160. �ཻ����
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
            headB = NULL;//û��д�͹�����
        }
        else
            ap = ap->next;
        //
        if (bp->next == NULL)
        {
            bp = headA;
            headA = NULL;//û��д�͹�����
        }
        else
            bp = bp->next;
    }
    return NULL;
}
//167. ����֮�� II - ������������
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
            break;//��д��
        }
    }
    return rlt;
}
//168. Excel��������
string convertToTitle(int n) {//�ѵ�����û��0
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
//171. Excel�������
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
//169. ������
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
//172. �׳˺����
int trailingZeroes(int n) {//5,25,125,625...
    int sum = 0;
    while (n)
    {
        n /= 5;
        sum += n;
    }
    return sum;
}
//175. ��������� MySQL
//select FirstName, LastName, City, State
//from
//Person left join Address
//on Person.PersonId = Address.PersonId;

//176. �����ߵ�нˮ
//SELECT * FROM table LIMIT[offset, ] rows | rows OFFSET offset

//SELECT
//IFNULL(
//(SELECT DISTINCT Salary
//    FROM Employee
//    ORDER BY Salary DESC
//    LIMIT 1 OFFSET 2),
//    NULL) AS SecondHighestSalary;

//181. �������������Ա��
//select A.Name as Employee
//from Employee as A left join Employee as B
//on A.ManagerId = B.Id
//where A.ManagerId = B.Id and A.Salary > B.Salary;//***A.ManagerId = B.Id

//select A.Name as Employee
//from Employee as A, Employee as B
//where A.ManagerId = B.Id and A.Salary > B.Salary;

//182. �����ظ��ĵ�������
//select Email
//from Person
//group by Email
//having count(Email) > 1;

//183. �Ӳ������Ŀͻ�
//select Name as Customers
//from Customers
//where Id not in
//(select distinct CustomerId from Orders);

//select Name as Customers
//from Customers left join Orders
//on Customers.Id = Orders.CustomerId
//where Orders.CustomerId is null;

//189. ��ת����
void rotate(vector<int>& nums, int k) {//�����
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
//190. �ߵ�������λ
uint32_t reverseBits(uint32_t n) {
    uint32_t rlt = 0;
    for (int i = 0; i < 32; i++)
    {
        rlt <<= 1;
        rlt |= (n & 1);
        n >>= 1;// n = n >> i;//��Ӧ��iѽ
    }
    return rlt;
}

int main190()
{
    reverseBits(43261596);
    return 0;
}

//191. λ1�ĸ���
int hammingWeight(uint32_t n) {
    int cnt = 0;
    while (n > 0)
    {
        n = n&(n - 1);
        cnt++;
    }
    return cnt;
}

//196. ɾ���ظ��ĵ�������
//delete p1 from Person p1, Person p2
//where p1.Email = p2.Email and p1.Id > p2.Id

//197. �������¶�
//select w1.id
//from weather w1, weather w2
//where w1.Temperature > w2.Temperature and w2.RecordDate = DATE_SUB(w1.RecordDate, INTERVAL 1 DAY)

//202. ������
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

//203. �Ƴ�����Ԫ��
ListNode* removeElements(ListNode* head, int val) {
    ListNode*pre = head;
    ListNode*p = head;
    while (p)
    {
        if (p->val == val)
        {
            if (pre == head)//pre���ԣ�Ӧ�ø�Ϊp
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

//204. ��������
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
//206. ��ת����
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

//217. �����ظ�Ԫ�� �������� ==

//bool containsDuplicate(vector<int>& nums) {
//    vector<int> num(nums);
//    sort(num.begin(), num.end());
//    num.erase(unique(num.begin(), num.end()), num.end());  //�����ȥ���ظ�Ԫ��
//
//    return(num.size() < nums.size());
//}

void MySwap(int &a, int &b)//300�ڴζԱȣ�������Ŀ�2.5%
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
    printf("\n    ����1��2, %d�ڴ�",N/100000000);
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
//226. ��ת������
TreeNode* invertTree(TreeNode* root) {
    if (root == NULL)
        return root;
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
    return root;//������д
}
//231. 2����
bool isPowerOfTwo(int n) {
    if (n <= 0)//©д=��
        return false;
    n = n & (-n);
    if (n == 0)
        return true;
    return false;
}
//234. ��������
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
    //p�м�ƫ��Ľڵ� ��תp����Ľڵ�
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
//235. �����������������������
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {//ͨ��
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
//237. ɾ�������еĽڵ�
void deleteNode(ListNode* node) {
    if (node == NULL || node->next == NULL)
        return;
    node->val = node->next->val;
    node->next = node->next->next;
}
//257. ������������·��
void binaryTreePaths2(vector<string> &v,TreeNode* root,string ss) {//�ҵĴ�
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
//����д��
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

//263. ����
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
//268. ȱʧ����
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
    while (min <= max)//���еȺ�
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
//283. �ƶ���
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
            if (cnt > 0)//��д��
            {
                nums[i - cnt] = nums[i];
                nums[i] = 0;
            }
        }
    }
}
//292. Nim��Ϸ
bool canWinNim(int n) {
    return n % 4 != 0;
}
//326. 3����
//342. 4����
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
//344. ��ת�ַ���
void reverseString(vector<char>& s) {
    for (int i = 0, j = s.size() - 1; i < j; i++,j--)
    {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}
//345. ��ת�ַ����е�Ԫ����ĸ
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
//367. ��Ч����ȫƽ����
bool isPerfectSquare(int num) {
    if (num <= 0)
        return false;
    unsigned long long min = 1;
    unsigned long long max = num;
    unsigned long long mid = 0;
    unsigned long long numl = num;
    while (min <= max)//��д��=��
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
//371. ������֮��
int getSum(int a, int b) {//-1 + 1 ����
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
//374. �����ִ�С
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
            break;//©д��
        case -1:
            max = mid - 1;
            break;//©д��
        }
    }
    return 0;
}
//383. �����
bool canConstruct(string ransomNote, string magazine) {
    return false;
}
//389. �Ҳ�ͬ
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
//404. ��Ҷ��֮��
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
//405. ����ת��Ϊʮ��������
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
        num2 >>= 4;//©д=��
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
//409. ����Ĵ� 
//����һ��������д��ĸ��Сд��ĸ���ַ������ҵ�ͨ����Щ��ĸ����ɵ���Ļ��Ĵ���
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
//434. �ַ����еĵ�����
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
//437. ·���ܺ� III
int pathSum3(TreeNode* root, int sum) {//�ҵĴ���𰸣����ټƣ���pathSum2�Ա�
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
//441. ����Ӳ��
int arrangeCoins(int n) {
    if (n == 0)
        return 0;
    int min = 1;
    int max = n;
    long long mid = 0;//int mid ���洦
    while (min <= max)
    {
        mid = min + (max - min) / 2;
        long long sum = mid*(1 + mid) / 2;//int sum ���洦
        if (n < sum)
            max = mid - 1;
        else if (n>sum)
            min = mid + 1;
        else 
            return mid;
    }
    return max;//***�߽�����
}
//443. ѹ���ַ���
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
                //����λ��
                int weishu = 0;
                for (int c = cnt; c > 0;) { weishu++; c /= 10; }
                //����ѹ����
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
            else//©д��
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
//453. ��С�ƶ�����ʹ����Ԫ�����
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
//455. �ַ�����
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
//461. ��������
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
//463. ������ܳ�
int islandPerimeter(vector<vector<int>>& grid) {
    int sum = 0;
    for (int i = 0; i < grid.size();i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                if (i-1 >= 0 && grid[i-1][j] == 0 || i - 1 < 0)//��
                    sum++;
                if (i + 1 < grid.size() && grid[i + 1][j] == 0 || i + 1 >= grid.size())//��
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
//19. ɾ������ĵ�����N���ڵ�
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
//24. �������������еĽڵ�
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
//25. k��һ�鷭ת����
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

ListNode* reverseKGroup2(ListNode* &head, int k) {//�ҵ���ȷ��
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
//61. ��ת����
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
//82. ɾ�����������е��ظ�Ԫ�� II
ListNode* deleteDuplicates2(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    //�ڵ���>=2
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
                if (pre == p)//p => head�ǲ��Ե�
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
//86. �ָ�����
ListNode* partition(ListNode* head, int x) {//��ͷ�ڵ�
    if (head == NULL || head->next == NULL)
        return head;
    //����1���ڵ�
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
            if (pre == p)//����ͷ���
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
ListNode* partition2(ListNode* head, int x) {//����ͷ���
    if (head == NULL || head->next == NULL)
        return head;
    //����1���ڵ�
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