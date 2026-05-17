#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;

struct Node {
    vector<vector<int>> board;
    int g, h;
};

// Heuristic Function (Misplaced Tiles)
int heuristic(const vector<vector<int>>& a,const vector<vector<int>>& b) {
    int diff = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            // Ignore blank space
            if(a[i][j] != -1 && a[i][j] != b[i][j])
                diff++;
        }
    }
    return diff;
}

// Print Board
void printBoard(const vector<vector<int>>& a) {
    for(auto row : a) {
        for(auto val : row) {
            if(val == -1)
                cout << "_ ";
            else
                cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Make Move
vector<vector<int>> makeMove(vector<vector<int>> a,pair<int,int> move,int x, int y) {
    int nx = x + move.first;
    int ny = y + move.second;
    // Boundary Check
    if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {

        a[x][y] = a[nx][ny];
        a[nx][ny] = -1;
    }
    return a;
}

// Comparator for Priority Queue
struct cmp {
    bool operator()(Node a, Node b) {
        return (a.g + a.h) > (b.g + b.h);
    }
};

// Check Blank Space
bool hasBlank(const vector<vector<int>>& board) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == -1)
                return true;
        }
    }
    return false;
}

// A* Algorithm
void A_star(vector<vector<int>> start,vector<vector<int>> goal) {
    priority_queue<Node, vector<Node>, cmp> pq;
    set<vector<vector<int>>> vis;
    Node s;

    s.board = start;
    s.g = 0;
    s.h = heuristic(start, goal);
    pq.push(s);

    // Directions
    pair<int,int> dir[4] = {
        {-1,0}, // Up
        {1,0},  // Down
        {0,-1}, // Left
        {0,1}   // Right
    };

    while(!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        if(vis.count(cur.board))
            continue;
        vis.insert(cur.board);
        printBoard(cur.board);
        cout << "g(n) = " << cur.g
             << "  h(n) = " << cur.h
             << "  f(n) = "
             << cur.g + cur.h << endl << endl;

        // Goal Check
        if(cur.board == goal) {
            cout << "Goal Reached\n";
            return;
        }

        // Find Blank Space
        int x, y;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(cur.board[i][j] == -1) {
                    x = i;
                    y = j;
                }
            }
        }
        // Generate New States
        for(int i = 0; i < 4; i++) {
            vector<vector<int>> nxt =
                makeMove(cur.board, dir[i], x, y);
            if(nxt == cur.board)
                continue;
            if(vis.count(nxt))
                continue;
            Node temp;

            temp.board = nxt;
            temp.g = cur.g + 1;
            temp.h = heuristic(nxt, goal);
            pq.push(temp);
        }
    }
    cout << "No Solution Found\n";
}

int main() {
    vector<vector<int>> start(3, vector<int>(3));
    vector<vector<int>> goal(3, vector<int>(3));\
    cout << "Enter Initial State (-1 for blank):\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> start[i][j];
        }
    }

    // Check Blank Space
    if(!hasBlank(start)) {
        cout << "Error: No blank space found in initial state\n";
        return 0;
    }

    cout << "Enter Goal State (-1 for blank):\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> goal[i][j];
        }
    }

    // Check Blank Space
    if(!hasBlank(goal)) {
        cout << "Error: No blank space found in goal state\n";
        return 0;
    }
    A_star(start, goal);
    return 0;
}

/*
A* Algorithm

f(n) = g(n) + h(n)

*/