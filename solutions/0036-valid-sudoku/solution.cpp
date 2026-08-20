class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char,int>> cubes(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                int row = i / 3;
                int col = j / 3;
                int cubeNum = row * 3 + col;
                cubes[cubeNum][board[i][j]]++;
                if(cubes[cubeNum][board[i][j]] == 2) return false;
            }
        }

        for(int i=0;i<9;i++){
            unordered_map<char,int> rows;
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                rows[board[i][j]]++;
                if(rows[board[i][j]] == 2) return false;
            }
        }

        for(int j=0;j<9;j++){
            unordered_map<char,int> columns;
            for(int i=0;i<9;i++){
                if(board[i][j] == '.') continue;
                columns[board[i][j]]++;
                if(columns[board[i][j]] == 2) return false;
            }
        }

        return true;
    }
};
