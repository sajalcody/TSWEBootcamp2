#include<bits/stdc++.h>
using namespace std;
# define n 401
# define m 401
class Item{
    public:
    int row;int col; int dist;
    Item(int x , int y , int w):
    row(x),col(y),dist(w)
    {}
};
bool issafe(int i , int j , bool visited[n][m], int N, int M){
    return ( i >=1 && i <= N && j >=1 && j <=M && visited[i][j] == false);
}

int minDistance(char grid[n][m], int N, int M){
    int dx[]={0,0,-1,1};
    int dy[]={-1,1,0,0};
    Item source(1,1,0);
    bool visited [n][m];
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            if ( grid [i][j] == 'D'){
                visited[i][j] = true;
            }
            else{
                visited[i][j] = false;
            }
            
        }
    }
    queue<Item> q;
    q.push(source);
    visited[source.row][source.col] = true;
    while(!q.empty()){
       Item p = q.front();
       q.pop();
       if(p.row == N && p.col == M){
           return p.dist;
           
       }
       for(int i = 0 ; i < 4 ; i++ ){
           if (issafe(p.row + dy[i] , p.col + dx[i] , visited, N, M )){
               q.push(Item(p.row + dy[i] , p.col + dx[i] , p.dist+1));
               visited[p.row + dy[i]][p.col + dx [i]] = true;
           }
           
       }
       
    }
    return -1;
}


int main(){
    int N,M,l,d, a, b;
    cin >> N >> M >> d >> l;
    char grid[n][m];
    memset (grid, '.', sizeof (grid));
    while(d--){
        cin >> a >> b;
        grid[a][b] = 'D';
    }
    while(l--){
        cin >> a >> b;
        grid[a][b] = 'L';
    }
    cout << minDistance(grid, N, M);
    return 0;
}