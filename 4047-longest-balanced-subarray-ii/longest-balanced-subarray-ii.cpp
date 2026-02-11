#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class SegmentTree {
    int n;
    vector<int> minv, maxv, lazy;

    void push(int node) {
        if (lazy[node] != 0) {
            for (int child : {node*2, node*2+1}) {
                minv[child] += lazy[node];
                maxv[child] += lazy[node];
                lazy[child] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void pull(int node) {
        minv[node] = min(minv[node*2], minv[node*2+1]);
        maxv[node] = max(maxv[node*2], maxv[node*2+1]);
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            minv[node] += val;
            maxv[node] += val;
            lazy[node] += val;
            return;
        }
        push(node);
        int mid = (l + r) / 2;
        if (ql <= mid) update(node*2, l, mid, ql, qr, val);
        if (qr > mid) update(node*2+1, mid+1, r, ql, qr, val);
        pull(node);
    }

    int query_leftmost_zero(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return -1;
        if (minv[node] > 0 || maxv[node] < 0) return -1;
        if (l == r) return l;
        push(node);
        int mid = (l + r) / 2;
        int left_res = query_leftmost_zero(node*2, l, mid, ql, qr);
        if (left_res != -1) return left_res;
        return query_leftmost_zero(node*2+1, mid+1, r, ql, qr);
    }

public:
    SegmentTree(int size) : n(size) {
        minv.resize(4 * n, 0);
        maxv.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void update(int l, int r, int val) {
        update(1, 1, n, l, r, val);
    }

    int query_leftmost_zero(int l, int r) {
        return query_leftmost_zero(1, 1, n, l, r);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> last;
        vector<int> prev(n + 1, 0), weight(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int x = nums[i - 1];
            if (last.count(x)) prev[i] = last[x];
            last[x] = i;
            weight[i] = (x % 2 == 0) ? 1 : -1;
        }

        SegmentTree st(n);
        int ans = 0;
        for (int R = 1; R <= n; ++R) {
            st.update(prev[R] + 1, R, weight[R]);
            int L = st.query_leftmost_zero(1, R);
            if (L != -1) {
                ans = max(ans, R - L + 1);
            }
        }
        return ans;
    }
};