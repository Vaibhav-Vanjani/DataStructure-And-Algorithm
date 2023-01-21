class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        

        priority_queue<int,vector<int>,greater<int>> minh;
        // matrix
        // a b c
        // d e f
        // g h i

        int n=matrix.size();
        int m=matrix[0].size();
	// Step 1
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                matrix[i][j] = matrix[i][j-1] ^ matrix[i][j];
            }
        }

         // a a^b a^b^c
         // d d^e d^e^f
         // g g^h g^h^i



        
		// Step 2
        for(int i = 0; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                matrix[j][i] = matrix[j-1][i] ^ matrix[j][i];

            }
        }

        // a      a^b            a^b^c
         //a^d    a^b^d^e        a^b^c^d^e^f
         //a^d^g  a^b^d^eg^h     a^b^c^d^e^f^g^h^i




        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
               minh.push(matrix[i][j]);
                if(minh.size()>k)
                minh.pop();
            }
        }

        int top =minh.top();
        return top;


       
    }
};