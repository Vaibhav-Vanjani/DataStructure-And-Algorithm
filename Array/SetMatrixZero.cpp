class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        queue<pair<int,int>> q;
        int n=matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)q.push({i,j});
            }
        }

        int i=0;
        int j=0;

        while(!q.empty())
        {
            i=q.front().first;
            j=q.front().second;
            q.pop();
            
            for(int k=0;k<m;k++)
            {
                matrix[i][k]=0;
            }
            for(int k=0;k<n;k++)
            {
                matrix[k][j]=0;
            }
        }
        return ;
    }
};