class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> evens;
        vector<int> odds;
        vector<int> result;
        
        for (int num : nums) {
            if (num % 2 == 0)
                evens.push_back(num);
            else
                odds.push_back(num);
        }
        
        result.insert(result.end(), evens.begin(), evens.end());
        result.insert(result.end(), odds.begin(), odds.end());
        
        return result;
    }
};