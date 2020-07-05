class Solution {
public:
    
    int numSubmat(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        
        vector<vector<int>>prefix(r,vector<int>(c));
        
        for(int i=0;i<r;i++){
            int count = 0;
            for(int j=c-1;j>=0;j--){
                if(mat[i][j]) count++;
                else count = 0;
                prefix[i][j] = count;
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int cmin = INT_MAX;
                for(int k=i;k<r;k++){
                    cmin = min(cmin,prefix[k][j]);
                    ans+=cmin;
                }
            }
        }
        return ans;
    }
};