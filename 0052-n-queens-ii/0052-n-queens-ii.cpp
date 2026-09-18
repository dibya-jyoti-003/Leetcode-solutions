#define vs vector<string>
#define vvs vector<vs>
class Solution {
private:
    int cnt = 0;
    bool check (vs& temp, int row, int col){
        int n=temp.size();
        for (int i=0;i<row;i++)if (temp[i][col]=='Q')return false;
        for (int i=1;i<=min(row,col);i++)if (temp[row-i][col-i] == 'Q')return false;
        for (int i=1;i<=row and col+i<n;i++)if (temp[row-i][col+i] == 'Q')return false;
        return true ;
    }

    void solve(vs &temp, vvs& ans ,int row){
        int n = temp.size();
        if (row == n){
            cnt++;
            return ;
        }
        for (int col=0;col<n;col++){
            if (check(temp,row,col)){
                temp[row][col]='Q';
                solve(temp,ans,row+1);
                temp[row][col]='.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        vvs ans ;
        vs temp;
        for (int i=0;i<n;i++){
            string st = "";
            for (int j=0;j<n;j++)st += '.';
            temp.push_back(st);
        }
        solve(temp,ans ,0);
        return cnt;
    }
};