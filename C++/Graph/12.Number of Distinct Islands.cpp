#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0 , -1 , 0};
int dy[4] = {0 , 1 , 0 , -1};
vector<pair<int,int>> bfs(int row, int col, int** arr, int n, int m , vector<vector<int>>& vis){
    queue<pair<int,int>> q;
    vis[row][col] = 1;
    q.push({row, col});
    vector<pair<int,int>> v;
    while(q.size()){
        int nrow = q.front().first;
        int ncol = q.front().second;
        q.pop();
        v.push_back({nrow - row, ncol-col});
        for(int i = 0 ; i < 4 ; i++){
            int calrow = nrow + dx[i];
            int calcol = ncol + dy[i];
            if(calrow >= 0 && calrow < n && calcol >= 0 && calcol < m && arr[calrow][calcol] == 1 
            && vis[calrow][calcol] == 0){
                vis[calrow][calcol] = 1;
                q.push({calrow, calcol});
            }
        }
    }
    return v;
}


int distinctIslands(int** arr, int n, int m){
    //Write your code here
    
    vector<vector<int>> vis(n, vector<int>(m, 0));

    set<vector<pair<int,int>>> elements;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0  ; j < m ; j++){
            if(arr[i][j] == 1 && vis[i][j] == 0){
                elements.insert(bfs(i, j, arr, n, m , vis));
            }
        }
    }
    return (int)elements.size();

}