#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//In this question 2 players are given numbered cards for 1,2,...,n.
//On each turn both players place one of their cards on the table. 
//The player who placed the higher card gets one point. If the cards are equal, neither player gets a point. 
//The game continues until all cards have been played.
// so the input will be textcases with t in which each line contains n , total points by player 'a' , total
//points by player 'b'. output will be 'NO' if the corresponding no. of cards with the combination of the points of players is invalid
//like no. cards from 1 to 2 cannot have a combination if player1 has 0 and player2 has 1 then it is not possible.
// 'yes' if the combination can form with one example.  
struct tcase {
    int n, a, b;
};

void solve(int n, int a_orig, int b_orig) {
    int a = a_orig;
    int b = b_orig;

    if (a + b > n) {
        cout << "NO\n";
        return;
    }

    vector<int> p1, p2;
    vector<bool> used(n + 1, false);

    for (int i = n; i >= 1 && a > 0; --i) {
        p1.push_back(i);
        --a;
    }

    for (int i = 1; i <= n && p1.size() < n; ++i) {
        if (find(p1.begin(), p1.end(), i) == p1.end()) {
            p1.push_back(i);
        }
    }

    fill(used.begin(), used.end(), false);
    p2.resize(n, 0);
    b = b_orig;

    for (int i = 0; i < n && b > 0; ++i) {
        for (int j = n; j >= 1; --j) {
            if (!used[j] && j > p1[i]) {
                p2[i] = j;
                used[j] = true;
                --b;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (p2[i] == 0) {
            for (int j = 1; j <= n; ++j) {
                if (!used[j]) {
                    p2[i] = j;
                    used[j] = true;
                    break;
                    }
        }
            }
        }

    int score1 = 0, score2 = 0;
    for (int i = 0; i < n; ++i) {
        if (p1[i] > p2[i]) ++score1;
        else if (p2[i] > p1[i]) ++score2;
    }

    if (score1 == a_orig && score2 == b_orig) {
        cout << "YES\n";
        for (int x : p1) cout << x << " ";
        cout << "\n";
        for (int x : p2) cout << x << " ";
        cout << "\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    tcase arr[t];
    for (int i = 0; i < t; ++i) {
        cin >> arr[i].n >> arr[i].a >> arr[i].b;
    }
    for (int i = 0; i < t; ++i) {
        solve(arr[i].n, arr[i].a, arr[i].b);
    }
    return 0;
}
