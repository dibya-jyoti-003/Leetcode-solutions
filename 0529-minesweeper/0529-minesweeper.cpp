#define vc vector<char>
#define vvc vector<vc>
#define vi vector<int>
class Solution {
public:
    vvc updateBoard(vvc& board, vi& click) {
        if (board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        int m = board.size(), n=board[0].size();
        bool vis[51][51]={0};
        queue<vi> q;
        q.push(click);
        vis[click[0]][click[1]]=true;
        while (!q.empty()){
            int r = q.front()[0], c = q.front()[1];
            q.pop();
            int cnt = 0;
            for (int i=-1;i<2;i++){
                for (int j=-1;j<2;j++){
                    if (r+i<0 or c+j<0 or r+i>=m or c+j>=n)continue;
                    cnt += (board[r+i][c+j] == 'M');
                }
            }
            if (!cnt){
                for (int i=-1;i<2;i++){
                    for (int j=-1;j<2;j++){
                        if (r+i<0 or c+j<0 or r+i>=m or c+j>=n)continue;
                        if (!vis[r+i][c+j]){
                            q.push({r+i,c+j});
                            vis[r+i][c+j]=true;
                        }
                    }
                }
                board[r][c]='B';
            }
            else board[r][c] = (char)(cnt+'0');
            // cout <<r<<" "<<c<<" "<<cnt<<endl;
        }
        return board;
    }
};