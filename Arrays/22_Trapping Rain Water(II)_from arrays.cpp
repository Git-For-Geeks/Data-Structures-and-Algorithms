class Solution {
public:
    vector<pair<int,int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int trapRainWater(vector<vector<int>>& mat)
    {
        int ROW = mat.size();
        int COL = mat[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<bool>> vis(ROW,vector<bool>(COL, 0));
        
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                if(i==0 || j==0 || i==ROW-1 || j==COL-1) {
                    pq.push({mat[i][j],{i,j}});
                    vis[i][j]=true;
                }
            }
        }
        
        int res=0;
        while(!pq.empty()){
            auto [val, coord]=pq.top(); pq.pop();
            auto [x, y] = coord;
    
            for(auto [_x, _y] : dirs){
                int nx = x + _x, ny = y + _y;
                
                if(nx < 0 || ny < 0 || nx == ROW || ny == COL || vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                res += max(0, val - mat[nx][ny]);
                pq.push({max(val, mat[nx][ny]), {nx,ny}});
            }
        }
        return res;
    }
};