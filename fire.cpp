#include <iostream>
#include <utility>
#include <queue>
#include <string>
#define X first
#define Y second
 
using namespace std;
char board[1001][1001];
int fb[1001][1001];
int pb[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
 int x, y;
 string str;
 queue<pair<int, int>> FQ;
 queue<pair<int, int>> PQ;
 cin >> y >> x;
 for(int i = 0; i < x; i ++)
 {
   cin >> str;
   for(int j = 0; j < y; j++)
   {
     board[i][j] = str[j];
     if(board[i][j] == '*') {FQ.push({i, j}); fb[i][j] = 1;}
     else if(board[i][j] == '@') {PQ.push({i, j}); pb[i][j] = 1;}
   }
 }
 while(!FQ.empty())
 {
   pair<int, int> CUR = FQ.front(); FQ.pop();
   for(int i = 0; i < 4; i++)
   {
     int nx = CUR.X + dx[i];
     int ny = CUR.Y + dy[i];
     if(nx < 0 || nx >= x || ny < 0 || ny >= y) continue; //범위만
     if(board[nx][ny] == '#' || fb[nx][ny] != 0) continue;
     fb[nx][ny] = fb[CUR.X][CUR.Y] + 1;
     FQ.push({nx, ny});
   }
 }
 while(!PQ.empty())
 {
   pair<int, int> CUR = PQ.front(); PQ.pop();
   for(int i = 0; i < 4; i++)
   {
     int nx = CUR.X + dx[i];
     int ny = CUR.Y + dy[i];
     if(nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
     if(board[nx][ny] == '#' || fb[nx][ny] <= pb[CUR.X][CUR.Y] + 1 || pb[nx][ny] != 0) continue;
     if(nx == x-1 || ny == y-1 || nx == 0 || ny == 0) {cout << pb[CUR.X][CUR.Y] + 1; break;}
     pb[nx][ny] = pb[CUR.X][CUR.Y] + 1; PQ.push({nx, ny});
   }
 }
}
