#include<vector>
template<typename T>
class ArrayTree{
    std::vector<T> df;
    std::vector<T> mf;
    int n;
    int lowbit(int x){
        return (-x) & x;
    }
    void add(int x, T v){
        for(int i = x + 1; i <= n; i += lowbit(i)){
            df[i] += v;
            mf[i] += v * (x + 1);
        }
    }
    T ask(int x){
        T ans = 0;
        for(int i = x + 1; i > 0; i -= lowbit(i)){
            ans += (x + 2) * df[i] - mf[i];
        }
        return ans;
    }
public:
    ArrayTree(int _n){
        n = _n + 1;
        df.resize(n, 0);
        mf.resize(n, 0);
    }
    ArrayTree(const std::vector<int> &v){
        new(this) ArrayTree(v.size());
        if(v.size() > 0){
            add(0, v[0]);
            for(int i = 1; i < n - 1; i++){
                add(i, v[i] - v[i - 1]);
            }
        }
    }
    T query(int l, int r){
        return ask(r) - ask(l - 1);
    }
    T query(int x){
        return query(x, x);
    }
    void update(int l, int r, T v){
        add(l, v);
        add(r + 1, -v);
    }
    void update(int x, T v){
        update(x, x, v);
    }
};
