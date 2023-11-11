class Graph {
public:
    vector<vector<long>> matrix;
    int N;
    bool fla;
    Graph(int n, vector<vector<int>>& edges) {
       int m = edges.size();
       N=n;
       fla=true;
       matrix.resize(101,vector<long> (101,INT_MAX));
        for(int i=0;i<n;i++)
        {
            matrix[i][i]=0;
        }

       for(int i=0;i<m;i++)
       {
          matrix[edges[i][0]][edges[i][1]] = edges[i][2];
       }

          for(int via=0;via<n;via++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
                    if(matrix[i][via]<INT_MAX && (matrix[via][j]<INT_MAX))
	                 matrix[i][j] = min(matrix[i][via]+matrix[via][j],matrix[i][j]);
	            }
	        }
	    }
    }
    
    void addEdge(vector<int> edge) {
        if (matrix[edge[0]][edge[1]] <= edge[2]) {
            return;
        }

          matrix[edge[0]][edge[1]] = edge[2];
       int n = N;
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {  
                if(matrix[i][edge[0]]<INT_MAX && matrix[edge[1]][j]<INT_MAX)          
                matrix[i][j] = min(matrix[i][edge[0]]+edge[2]+matrix[edge[1]][j],matrix[i][j]);
            }
        }
     
    }
    
    int shortestPath(int node1, int node2) {
        
        return matrix[node1][node2] == INT_MAX ? -1 : matrix[node1][node2] ;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */