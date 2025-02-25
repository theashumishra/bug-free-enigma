
class Solution {
public:
    void mergeCount(const vector<int>& nums, vector<int>& counts, int start, int end) {
    if (start >= end) return;
    int mid = start + (end - start) / 2;
    mergeCount(nums, counts, start, mid);
    mergeCount(nums, counts, mid + 1, end);
    
    // Create left_sorted and right_sorted with pairs (value, original_index)
    vector<pair<int, int>> left_sorted;
    for (int i = start; i <= mid; i++) {
        left_sorted.push_back({nums[i], i});
    }
    vector<pair<int, int>> right_sorted;
    for (int i = mid + 1; i <= end; i++) {
        right_sorted.push_back({nums[i], i});
    }
    
    // Sort both
    sort(left_sorted.begin(), left_sorted.end());
    sort(right_sorted.begin(), right_sorted.end());
    
    // For each element in left_sorted, find number of elements in right_sorted with value < left_sorted.value
    for (const auto& p : left_sorted) {
        int value = p.first;
        int original_index = p.second;
        auto it = lower_bound(right_sorted.begin(), right_sorted.end(), make_pair(value, -1));
        int count = it - right_sorted.begin();
        counts[original_index] += count;
    }
}

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> counts(n, 0);
    mergeCount(nums, counts, 0, n - 1);
    return counts;
}
};