bool safe(int row,int col,int board[9][9],int val)
{
    int n=9;
    for(int i=0;i<n;i++)
    {
        if(board[row][i]==val)
        {
            return false;
        }
        if(board[i][col]==val)
        {
            return false;
        }
        if(board[3*(row/3)+i/3 ][3*(col/3)+i%3]==val)
        {
            return false;
        }
    }
    return true;
}
bool isItSudoku(int board[9][9]) {
    int n=9;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]==0)
            {
                for(int val=1;val<=9;val++)
                {
                    if(safe(i,j,board,val))
                    {
                        board[i][j]=val;
                        bool poss=isItSudoku(board);
                        if(poss)
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j]=0;
                        }
                    }
                    
                }
                return false;
            }
        }
    }
    return true;
    // Write your code here.
}
