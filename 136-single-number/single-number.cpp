class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorx = 0;
        for(auto it: nums) xorx^=it;

        return xorx;

    }
};