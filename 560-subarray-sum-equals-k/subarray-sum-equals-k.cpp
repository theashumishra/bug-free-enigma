class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // To store frequency of prefix sums
        freq[0] = 1; // Initialize with prefix sum 0 having frequency 1
        int count = 0, curr_sum = 0;

        for (int num : nums) {
            curr_sum += num; // Update current prefix sum
            // Check if there exists a prefix sum such that curr_sum - prefix_sum = k
            if (freq.find(curr_sum - k) != freq.end()) {
                count += freq[curr_sum - k];
            }
            // Update the frequency of the current prefix sum
            freq[curr_sum]++;
        }

        return count;
    }
};