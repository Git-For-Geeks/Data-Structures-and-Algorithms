class Solution {
public:
    vector<int> seg;
vector<int> ar;
int x;

void build(int v, int l, int r) {
    if (l == r) {
        seg[v] = ar[l];
    }
    else {
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        seg[v] = max(seg[2 * v], seg[2 * v + 1]);
    }
}

int f(int v, int a, int b, int l, int r) {
    if (l > r) {return 0;}
    if (a == l && b == r) {return seg[v];}
    if(l==r){return seg[l];}
    int mid = (a + b) / 2;
    return max(
               f(2 * v, a, mid, l, min(mid, r)),
               f(2 * v + 1, mid + 1, b, max(l, mid + 1), r)
           );
}

void update(int a, int k) {
    if(a==1){
        int xx=x;
        while(xx>=1){seg[xx]=max(seg[xx],1);xx/=2;}
        return;
    }
    int val = f(1, x, 2 * x - 1, max(x, x - 1 + a - k), max(x, x - 1 + a - 1));
    int nn = x - 1 + a;
    val = max(val + 1, 1);
    while (nn >= 1) {
        seg[nn] = max(seg[nn],val); nn /= 2;
    }
}

int lengthOfLIS(vector<int>& nums, int k) {
    x = 0; for (int xx : nums) {x = max(x, xx);}
    int xx = log2(x);
    if ((1 << xx) != x) {
        xx++;
    }
    ar = nums;
    x = 1 << xx;
    while (ar.size() < x) {ar.push_back(0);}
    seg.resize(2 * x);
    for (int i = 0; i < 2 * x; i++) {seg[i] = 0;}
    int ans = 0;
    for (int a : nums) {
        update(a, k);
        ans = max(ans, seg[a + x - 1]);
    }
    return ans;
}
};