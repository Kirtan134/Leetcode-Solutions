/*
[Amazon interview question]
    Original | New | State
       0     |  0  |  0
       1     |  0  |  1
       0     |  1  |  2
       1     |  1  |  3
*/

class Solution {
private:
    int countNeighbors(int r, int c, int n, int m, vector<vector<int>>& board){
        int nei=0;
        for(int i=r-1;i<=r+1;i++){
            for(int j=c-1;j<=c+1;j++){
                if((i==r && j==c) || i<0 || j<0 || i>=n || j>=m) continue;
                if(board[i][j]==1 || board[i][j]==3) nei++;
            }
        }
        return nei;
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size(), nei = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nei = countNeighbors(i,j,n,m,board);
                if(board[i][j]){
                    if(nei==2 || nei==3){
                        board[i][j] = 3;
                    }
                }
                else if (nei==3){
                    board[i][j] = 2;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nei = countNeighbors(i,j,n,m,board);
                if(board[i][j]==2 || board[i][j]==3){
                    board[i][j]=1;
                }
                else if(board[i][j]==1){
                    board[i][j]=0;
                }
            }
        }
    }
};