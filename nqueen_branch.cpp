#include <bits/stdc++.h>
using namespace std;

int N;
int totalSolutions = 0;

vector<int> board;

// Arrays used for Branch and Bound optimization
vector<bool> colUsed;
vector<bool> diag1Used;
vector<bool> diag2Used;

vector<int> firstSolution;

// Function to solve using Backtracking + Branch and Bound
void solve(int row) {

    // Base case
    if (row == N) {
        totalSolutions++;

        // Store first solution
        if (firstSolution.empty())
            firstSolution = board;

        return;
    }

    // Try placing queen in every column
    for (int col = 0; col < N; col++) {

        // Branch and Bound check
        // If column or diagonal already occupied, prune branch
        if (colUsed[col] ||
            diag1Used[row - col + N - 1] ||
            diag2Used[row + col]) {

            continue;
        }

        // Place queen
        board[row] = col;

        colUsed[col] = true;
        diag1Used[row - col + N - 1] = true;
        diag2Used[row + col] = true;

        // Recursive call
        solve(row + 1);

        // Backtrack
        colUsed[col] = false;
        diag1Used[row - col + N - 1] = false;
        diag2Used[row + col] = false;
    }
}

// Print board
void printBoard(vector<int> &sol) {

    cout << "\nOne Solution:\n\n";

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {

            if (sol[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }

        cout << endl;
    }
}

int main() {

    cout << "Enter value of N: ";
    cin >> N;

    board.resize(N);

    // Initialize Branch and Bound arrays
    colUsed.resize(N, false);
    diag1Used.resize(2 * N - 1, false);
    diag2Used.resize(2 * N - 1, false);

    // Start solving
    solve(0);

    // Output
    cout << "\nTotal Solutions = " << totalSolutions << endl;

    if (!firstSolution.empty())
        printBoard(firstSolution);
    else
        cout << "No Solution Exists\n";

    return 0;
}
