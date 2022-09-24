class Solution51 {
public:
    
    vector<vector<string>> solveNQueens(int n) {
        NN = new uint64_t[n];
        N = (1 << n) - 1;

        FindNQueen(0, 0, 0, 0);

        return result;
    }

    void FindNQueen(int deep, uint64_t k, uint64_t l, uint64_t r)
    {
        if (k == N)
        {
            result.push_back(change(deep));
            return;
        }
        uint64_t z = N & (~(k | l | r));  //能走的位置, 和N取并可以去掉前面多余的1
        while (z != 0)
        {
            uint64_t index = z & (~z + 1);   //最右边的一个1, 即要放皇后的位置。
            z -= index;   //去掉这个位置。
            NN[deep] = index;
            FindNQueen(deep + 1, k | index, (l | index) << 1, (r | index) >> 1);   //查找下一个。
        }
    }

    vector<string> change(int n)
    {
        vector<string> res;
        for (int i = 0; i < n; i++) {
            string q;
            uint64_t p = 1 << (n - 1);
            for (int j = 0; j < n; j++, p >> 1) {
                if (NN[i] & p) {
                    q.push_back('Q');
                } else {
                    q.push_back('.');
                }
                p = p >> 1;
            }
            res.push_back(q);
        }
        return res;
    }

    uint64_t *NN;
    uint64_t N;
    vector<vector<string>> result;
};