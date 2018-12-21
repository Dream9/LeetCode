class Solution {
private:
    void dfs(vector<vector<char>>&board,int i,int j){
        int m=board.size();
        int n=board[0].size();
        if(i<0||j<0||i>=m||j>=n||board[i][j]!='O')
            return;
        board[i][j]='!';
        dfs(board,i-1,j);
        dfs(board,i+1,j);
        dfs(board,i,j-1);
        dfs(board,i,j+1);
    }
public:
    void solve(vector<vector<char>>& board) {
        
        int m=board.size();
        if(m==0)
            return;
        int n=board[0].size();
        if(n==0)
            return;
        //m*n的复杂度
        /*
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(i==0||i==m-1||
                  j==0||j==n-1)
                    if(board[i][j]=='O')
                        dfs(board,i,j);
            }
        }
        */
        //拆成2个循环,m+n复杂度
        //然后再减少if判断
        for(int i=0;i<m;++i){
            //if(board[i][0]=='O')
            dfs(board,i,0);
            //if(board[i][n-1]=='O')
            dfs(board,i,n-1);
        }
        for(int i=0;i<n;++i){
            //if(board[0][i]=='O')
            dfs(board,0,i);
            //if(board[m-1][i]=='O')
            dfs(board,m-1,i);
        }
        //恢复联通分量
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                board[i][j]=(board[i][j]=='!')?'O':'X';
    } /*      
        
        vector<vector<int>>angle{{0,1,1,0},{1,0,0,-1},
                                 {0,-1,-1,0},{-1,0,0,1}};//表示方向
        int A=0;
        int i=0;
        int j=0;
        int cnt=0;
        bool layer=true;
        int S=m*n;
        vector<vector<bool>>seen(m,vector<bool>{n,false});
        while(cnt<S){
            ++cnt; 
            if((layer&&board[i][j]=='O')||board[i][j]=='T'){
                board[i][j]='O';
                if(board[i+angle[A][2]][j+angle[A][3]]=='O')
                    board[i+angle[A][2]][j+angle[A][3]]='T';
            }
            seen[i][j]=true;
            int ti=i+angle[A][0];
            int tj=j+angle[A][1];
            if(ti==m||tj==n||ti<0||tj<0||seen[ti][tj])
                A=A+1;
            i=i+angle[A%4][0];
            j=j+angle[A%4][1];
                
            if(A==4){
                //if(board[i][j+1]=='T')
                //    board[i][j+1]='O';
                
                A=0;
                layer=false;
            }
        }
    }*/
};
