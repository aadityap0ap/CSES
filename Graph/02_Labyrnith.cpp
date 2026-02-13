#include <bits/stdc++.h>
using namespace std;

int main() {
     ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<char>> matrix(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 'A') {
                sx = i;
                sy = j;
            } else if (matrix[i][j] == 'B') {
                ex = i;
                ey = j;
            }
        }
    }

    vector<vector<char>> parent(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    queue<pair<int,int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    char direction[4] = {'U', 'D', 'L', 'R'};

    bool found = false;

    // BFS
    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        if (x == ex && y == ey) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                !visited[nx][ny] &&
                (matrix[nx][ny] == '.' || matrix[nx][ny] == 'B')) {

                visited[nx][ny] = true;
                parent[nx][ny] = direction[i];
                q.push({nx, ny});
            }
        }
    }

    if (!found) {
        cout << "NO\n";
        return 0;
    }

    // Path reconstruction
    string path = "";
    int x = ex, y = ey;

    while (x != sx || y != sy) {
        char c = parent[x][y];
        path.push_back(c);

        if (c == 'U') x++;
        else if (c == 'D') x--;
        else if (c == 'L') y++;
        else if (c == 'R') y--;
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";

    return 0;
}
