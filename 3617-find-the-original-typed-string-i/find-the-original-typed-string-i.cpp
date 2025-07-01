class Solution {
public:
    int possibleStringCount(string word) {
        int ans=1;
        unordered_map<char, int> mpp;
        for(int i=0; i<word.size()-1; i++){
            mpp[word[i]]++;
            if(word[i]==word[i+1]) ans++;
        }
        // for(auto it: mpp){
        //     if(it.second>1) ans+=it.second-1;
        // } 
        return ans;
    }
};