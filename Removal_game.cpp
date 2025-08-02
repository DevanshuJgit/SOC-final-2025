#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// There is a list of n numbers and two players who move alternately. 
// On each move, a player removes either the first or last number from the list, 
// and their score increases by that number. Both players try to maximize their scores.
// What is the maximum possible score for the first player when both players play optimally?
// Input
// The first input line contains an integer n: the size of the list.
// The next line has n integers x_1,x_2,\ldots,x_n: the contents of the list.
// Output
// Print the maximum possible score for the first player.
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
      }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            if (i == j) {
                dp[i][j] = a[i];
              } 
            else {
                dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
             }
           }
           }
    int p1= (total + dp[0][n - 1]) / 2;
    cout <<p1 << endl;

    return 0;
}
