The bomberman game(c++14)
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(const vector<vector<char>> &grid);
vector<vector<char>> explode(const vector<vector<char>> &grid);

int main() {
    int R, C, N;
    cin >> R >> C >> N;

    vector<vector<char>> grid(R, vector<char>(C, '.'));
    for (int i = 0; i < R; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < C; j++) {
            grid[i][j] = row[j];
        }
    }

    if (N == 1) {
        // Initial state
        print(grid);
    } else if (N % 2 == 0) {
        // All bombs
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) cout << "O";
            cout << "\n";
        }
    } else {
        // Precompute two explosion states
        vector<vector<char>> afterFirst = explode(grid);
        vector<vector<char>> afterSecond = explode(afterFirst);

        if (N % 4 == 3) {
            print(afterFirst);
        } else {
            print(afterSecond);
        }
    }

    return 0;
}

vector<vector<char>> explode(const vector<vector<char>> &grid) {
    int R = grid.size(), C = grid[0].size();
    vector<vector<char>> result(R, vector<char>(C, 'O'));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 'O') {
                result[i][j] = '.';
                if (i > 0) result[i-1][j] = '.';
                if (i < R-1) result[i+1][j] = '.';
                if (j > 0) result[i][j-1] = '.';
                if (j < C-1) result[i][j+1] = '.';
            }
        }
    }
    return result;
}

void print(const vector<vector<char>> &grid) {
    for (auto &row : grid) {
        for (char c : row) cout << c;
        cout << "\n";
    }
}
