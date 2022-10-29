 public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n =grid.size();
        int m = grid[0].size();
        //visited
        vector<vector<int>> vis(n, vector<int>(m,0));
        int count=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                //when not visited and it is land
                if(!vis[row][col] && grid[row][col]=='1'){
                    //increment count
                    count++;
                    //apply bfs(can apply dfs also)
                    bfs(row,col,vis,grid);
                }
            }
        }
        return count;
    }

//bfs implementation
     private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid){
    vis[row][col]=1;
    //queue
    queue<pair<int,int>>q;
    q.push({row,col});
    //n=no. of rows
    int n=grid.size();
    //m=no. of columns
    int m=grid[0].size();
    
    //repaet till queue is not empty
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        
        //traverse the neighbors and mark them as visited if it is land
        //these two for loops will cover all the eight neighbors surrounding an element
        for(int delrow=-1;delrow<=1;delrow++){
            for(int delcol=-1;delcol<=1;delcol++){
                int nrow=row+delrow;
                int ncol=col+delcol;
                //when row in range and col in range 
                //and it is land and not visited
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                && grid[nrow][ncol] =='1' && !vis[nrow][ncol]){
                    //then make visited as one
                    vis[nrow][ncol]=1;
                    //and push into queue
                    q.push({nrow,ncol});
                }
            }
        }
    }
    }