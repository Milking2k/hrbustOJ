#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        n = grid.size(), m = grid[0].size();
        grids = grid;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j) {
                if(grids[i][j]=='1'){
                    bfs(i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
    
private:
    int ans=0,n,m;
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<char>> grids;
    
    bool check(int x,int y){
        return (x>=0 && x<n && y>=0 && y<m && grids[x][y] == '1');
    }

    void bfs(int sx, int sy)
    {
        queue<pair<int,int> > q;
        q.push(make_pair(sx,sy));
        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            grids[x][y] = '2';
            for(int i=0;i<4;++i){
                int nx = x+dir[i][0];
                int ny = y+dir[i][1];
                if(check(nx,ny))
                    q.push(make_pair(nx,ny));	
            }
        }
    }

};
int main()
{


	return 0;
}
