#include <iostream>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<int, int>> rotten;
    int freshOranges = 0;
    int minutes = 0;

    // Count fresh oranges and add rotten oranges to the queue
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1)
                freshOranges++;
            else if (grid[i][j] == 2)
                rotten.push({i, j});
        }
    }

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    while (!rotten.empty() && freshOranges > 0) {
        int size = rotten.size();
        for (int i = 0; i < size; i++) {
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();

            for (int d = 0; d < 4; d++) {
                int newX = x + dx[d];
                int newY = y + dy[d];

                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;
                    rotten.push({newX, newY});
                    freshOranges--;
                }
            }
        }
        if (!rotten.empty())
            minutes++;
    }

    return (freshOranges == 0) ? minutes : -1;
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = orangesRotting(grid);

    if (result == -1)
        cout << "It is not possible to rot all oranges." << endl;
    else
        cout << "Minimum time to rot all oranges: " << result << " minutes." << endl;

    return 0;
}


