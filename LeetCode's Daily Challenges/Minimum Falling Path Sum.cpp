class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>>arr(matrix.size(),vector<int>(matrix[0].size()));
        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[i].size();j++){
                arr[i][j] = matrix[i][j];
            }
        }
        for(int i = matrix.size()-1;i >= 0;i--){
            for(int j = 0;j < matrix[i].size();j++){
                int temp = 0;
                if(i+1 < matrix.size()){
                    temp = arr[i+1][j];
                    if(j-1 >= 0 && j+1 < matrix[i].size()){
                        temp = min(temp,min(arr[i+1][j-1],arr[i+1][j+1]));
                    }
                    else if(j-1 < 0 && j+1 < matrix[i].size()){
                        temp = min(temp,arr[i+1][j+1]);
                    }
                    else if(j-1 >= 0 && j+1 >= matrix[i].size()){
                        temp = min(temp,arr[i+1][j-1]);
                    }
                }
                arr[i][j] += temp;
            }
        }
        int ans = INT_MAX;
        for(int i = 0;i < matrix[0].size();i++){
            ans = min(ans,arr[0][i]);
        }
        return ans;
    }
};
