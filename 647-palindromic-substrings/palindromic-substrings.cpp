int dp[1000][1000]={0};
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int i=0;
        int cnt = 0;
        while(i<n){
            dp[i][i]=1;
            i++;
            cnt++;
        }
        i=0;
        while(i<n-1){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                cnt++;
            }
            else dp[i][i+1]=0;
            i++;
        }
        int length = 3;
        while(length<=n){
            i=0;
            while(i<n-length+1){
                int j = i+length-1;
                if(s[i]==s[j] && dp[i+1][j-1]==1){
                    dp[i][j] = 1; 
                    cnt++;
                }
                else dp[i][j]=0;
                i++;
            }
            length++;
        }
        return cnt;
    }
};