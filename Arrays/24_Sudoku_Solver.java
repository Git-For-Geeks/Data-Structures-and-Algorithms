class Solution {
public void solveSudoku(char[][] board) {
    solve(board);
}
static boolean solve(char[][] board){
    int n = board.length;
    int row = -1;
    int col = -1;
	boolean noEmptyLeft = true;
   for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='.'){
                row = i;
                col = j;
                noEmptyLeft = false;
                break;
            }
        }
        if(!noEmptyLeft)
            break;
    }
    if(noEmptyLeft)
        return true;
    for(int number = 1;number<=9;number++){
        if(isSafe(board,row,col,number)){
            board[row][col]= (char)(number +'0');
            if(solve(board)){
                return true;
            }
            else{
                board[row][col] = '.';
            }
        }
    }
    return false;
}

private static boolean isSafe(char[][] board,int row,int col,int num){

    for(int i=0;i<board.length;i++){
        if(num == (board[row][i]-'0')){
            return false;
        }
    }

    for(int i=0;i<board.length;i++){
        if(num == (board[i][col]-'0')){
            return false;
        }
    }

    int sqrt = (int)Math.sqrt(board.length);
    int rowStart = row - row%sqrt;
    int colStart = col - col%sqrt;

    for(int i=rowStart;i<rowStart+sqrt;i++){
        for(int j=colStart;j<colStart+sqrt;j++){
            if(num == (board[i][j] - '0'))
                return false;
        }
    }

    return true;
}