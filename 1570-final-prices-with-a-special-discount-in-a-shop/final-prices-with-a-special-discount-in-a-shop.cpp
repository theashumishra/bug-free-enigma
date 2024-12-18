class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        int n = p.size();
        
        vector<int> ans;
        for(int i=0; i<n; i++){
            bool flag = 0;
            for(int j=i+1; j<n; j++){
                if(p[i]>=p[j]){
                    flag = 1;
                    ans.push_back(p[i]-p[j]);
                    break;
                }
                //else 
            }
            if(!flag) ans.push_back(p[i]);
        }
        for(int i=ans.size(); i<n; i++){
            ans.push_back(p[i]);
        }
        return ans;
    }
};