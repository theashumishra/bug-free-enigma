class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    int xor_result = 0;
    for (int num : nums) {
        xor_result ^= num; // XOR all elements
    }
    return xor_result; // The result is the unique element
}
};