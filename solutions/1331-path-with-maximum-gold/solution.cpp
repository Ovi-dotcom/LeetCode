int findMaxGold(vector<vector<int>> &grid,int i, int j,int rows,int columns,vector<vector<bool>> &visited){
    if(i<0 || j<0 || i>=rows || j>=columns || grid[i][j]==0 || visited[i][j]) return 0;
    visited[i][j]=true;

    int left = findMaxGold(grid,i,j-1,rows,columns,visited);
    int right = findMaxGold(grid,i,j+1,rows,columns,visited);
    int up = findMaxGold(grid,i-1,j,rows,columns,visited);
    int down = findMaxGold(grid,i+1,j,rows,columns,visited);

    visited[i][j]=false;
    return max({left,right,up,down}) + grid[i][j];
}


class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int rows=grid.size(),columns=grid[0].size();
        int maximum=0;
        if(grid.empty() || grid.size()==0) return 0;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j]>0){
                    int gold = findMaxGold(grid,i,j,rows,columns,visited);
                    maximum = max(maximum,gold);
                }
            }
        }
        return maximum;
    }
};
