class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end(),[&](const vector<int>& a,const vector<int>& b){
           if(a[1]==b[1]){
               return a[0] < b[0];
           } 
           return a[1] < b[1];
        });
        vector<int> dp(n);
        dp[0] = jobs[0][2];
        for(int i=1;i<n;i++){
            dp[i] = dp[i-1];
            int l = 0,r = i - 1,prev = 0;
            while(l<=r){
                int mid = (l+r)/2;
                if(jobs[mid][1]<=jobs[i][0]){
                    prev = dp[mid];
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            dp[i] = max(dp[i],jobs[i][2]+prev);
        }
        return dp[n-1];
    }
};
