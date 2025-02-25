class FenwickTree {
private:
    vector<int> tree;
    int size;
    
public:
    FenwickTree(int n) {
        size = n;
        tree.resize(n + 1, 0); // 1-based indexing
    }
    
    void update(int index, int delta) {
        while (index <= size) {
            tree[index] += delta;
            index += index & -index;
        }
    }
    
    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    FenwickTree fenwick(20001);
    vector<int> counts(n, 0);
    
    for (int i = n - 1; i >= 0; i--) {
        int mapped_index = nums[i] + 10000 + 1;
        counts[i] = fenwick.query(mapped_index - 1);
        fenwick.update(mapped_index, 1);
    }
    
    return counts;
}
};