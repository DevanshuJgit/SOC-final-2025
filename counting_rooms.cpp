#include <iostream>
#include <vector>
using namespace std;
// You are given a map of a building, and your task is to count the number of its rooms.
// The size of the map is n \times m squares, and each square is either floor or wall. 
//You can walk left, right, up, and down through the floor squares.
// Input
// The first input line has two integers n and m: the height and width of the map.
// Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).
// Output
// Print one integer: the number of rooms.
int n, m;
vector<string> grid;
vector<vector<bool>> visited;
int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0, 1, 0, -1};

bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m &&
            grid[x][y] == '.' && !visited[x][y]);
}
void room(int x, int y) {
    visited[x][y] = true;
    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (valid(nx, ny)) {room(nx, ny);}
       }
   }

int main() {
    cin >> n >> m;
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i)
        cin >> grid[i];
    int room_count = 0;
    for (int i = 0; i < n; ++i) 
      for (int j = 0; j < m; ++j) 
         if (grid[i][j] == '.' && !visited[i][j]) {
             room(i, j);
             ++room_count;}
             
   cout << room_count << endl;
}
