class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int ec=0;
        for(auto it: nums){
            if(it%2==0) ec++;
        } return ec>=2;
    }
};