//for minimum

class node {
public:
    int lo, hi, value,sze;
    node *left, *right;
    node () {}
    node (const int _lo, const int _hi) {
        lo = _lo, hi = _hi;
        left = right = NULL;
        value = inf;
        sze=0;
    }
    void update (const int idx, const int new_value) {
        if (lo > idx or hi < idx)
            return;
        if (lo == idx and hi == idx) {
            value = new_value;
            return;
        }
        const int mid = (lo + hi) >> 1;
        if (idx <= mid) {
            if (!left)
            {
                sze++;
                left = new node(lo, mid);
            }
            left->update(idx, new_value);
        }
        else {
            if (!right)
            {
                sze++;
                right = new node(mid + 1, hi);
            }
            right->update(idx, new_value);
        }
        value = inf;
        if (left)
            value = min(value, left->value);
        if (right)
            value = min(value, right->value);
    }
    int query (const int qlo, const int qhi) {
        if (lo > qhi or hi < qlo)
            return inf;
        if (lo >= qlo and hi <= qhi)
            return value;
        int ans = inf;
        if (left)
            ans = min(ans, left->query(qlo, qhi));
        if (right)
            ans = min(ans, right->query(qlo, qhi));
        return ans;
    }
};
