#include <bits/stdc++.h>
using namespace std;
class gp {
    private:
        int n;
        vector<long long> tree;
    public:
        gp(int size) 
        {
            n = size;
            tree.resize(n + 1, 0);
        }
        void newChange(int idx, long long value) 
        {
            while (idx <= n) 
            {
                if (tree[idx] < value) {
                    tree[idx] = value;
                } else {
                    break;
                }
                idx += idx & -idx;
            }
        }
    
        long long query(int idx) {
            long long mv = 0;
            while (idx > 0) {
                if (tree[idx] > mv) {
                    mv = tree[idx];
                }
                idx -= idx & -idx;
            }
            return mv;
        }
    };
    
long long solve(int N, vector<int>& Numbers) {
    vector<int> DifferentNum = Numbers;
    sort(DifferentNum.begin(), DifferentNum.end());
    auto it = unique(DifferentNum.begin(), DifferentNum.end());
    DifferentNum.erase(it, DifferentNum.end());
    int m = DifferentNum.size();
    gp ft(m);
    long long ms = 0;
    for (int x : Numbers) 
    {
        int r = lower_bound(DifferentNum.begin(), DifferentNum.end(), x) - DifferentNum.begin() + 1;
        long long pm = ft.query(r - 1);
        long long cs = pm + x;
        if (cs > ms) 
        {
            ms = cs;
        }
        ft.newChange(r, cs);
    }
    return ms;
}