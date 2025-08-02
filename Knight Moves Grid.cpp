#include<iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;
//There is a knight on an n \times n chessboard. For each square, print the minimum number of moves the knight needs to do to 
//reach the top-left corner.
//Input- The only line has an integer n.
//Output - Print the number of moves for each square.
//Example
//Input:8
//Output:
//0 3 2 3 2 3 4 5 
//3 4 1 2 3 4 3 4 
//2 1 4 3 2 3 4 5 
//3 2 3 2 3 4 3 4 
//2 3 2 3 4 3 4 5 
//3 4 3 4 3 4 5 4 
//4 3 4 3 4 5 4 5 
//5 4 5 4 5 4 5 6 

struct Node {
    int x, y;
};
int main() {
    int n;
    cin >> n; 
    vector<vector<int>> dist(n, vector<int>(n, -1));
    vector<Node> q;
    int head = 0;
    dist[0][0] = 0;
    q.push_back({0, 0});
    int dx[8] = { -2, -2, -1, -1,  1,  1,  2,  2 };
    int dy[8] = { -1,  1, -2,  2, -2,  2, -1,  1 };

    while (head < (int)q.size()) {
        Node cur = q[head++];
        int x = cur.x, y = cur.y;
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push_back({nx, ny});
            }
        }
    }
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            cout << dist[x][y];
            if (x + 1 < n) cout << ' ';
        }
        cout << '\n';
    }
}
