class Solution52 {
public:
    int totalNQueens(int n) {
        N = (1 << n) - 1;
        FindNQueen(0, 0, 0);
        return num;
    }

    void FindNQueen(uint64_t k, uint64_t l, uint64_t r)
    {
        if (k == N)
        {
            num++;
            return;
        }
        uint64_t z = N & (~(k | l | r));  //能走的位置, 和nn取并可以去掉前面多余的1
        while (z != 0)
        {
            uint64_t index = z & (~z + 1);   //最右边的一个1， 即要放皇后的位置。
            z -= index;   //去掉这个位置。
            FindNQueen(k | index, (l | index) << 1, (r | index) >> 1);   //查找下一个。
        }
    }

    uint64_t N;
    uint64_t num;
};