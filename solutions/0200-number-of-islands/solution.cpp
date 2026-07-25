void toZero(vector<vector<char>> &grid,int i,int j,int rows,int columns){
    if(i<0 || j<0 || i>=rows || j>=columns || grid[i][j]=='0') return;
    grid[i][j] = '0';
    toZero(grid,i,j-1,rows,columns);
    toZero(grid,i,j+1,rows,columns);
    toZero(grid,i-1,j,rows,columns);
    toZero(grid,i+1,j,rows,columns);

}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size(),columns=grid[0].size();
        int islandCount=0;
        if(grid.size()==0 || grid.empty()) return 0;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j]=='1'){
                    islandCount++;
                    toZero(grid,i,j,rows,columns);
                }
            }
        }
        return islandCount;
    }
};
