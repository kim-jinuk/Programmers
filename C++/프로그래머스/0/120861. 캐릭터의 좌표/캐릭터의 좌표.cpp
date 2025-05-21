#include <string>
#include <vector>

using namespace std;

pair<int, int> get_move(string s) {
    if (s == "left") return {-1, 0};
    else if (s == "right") return {1, 0};
    else if (s == "up") return {0, 1};
    else if (s == "down") return {0, -1};
}

bool isWithinRange(int x, int y, int xx, int yy) {
    return (-xx) / 2 <= x &&  x <= (xx / 2) && (-yy) / 2 <= y && y <= (yy / 2);
}

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    pair<int, int> move;
    int x = 0, y = 0;
    
    for (string s : keyinput) {
        move = get_move(s);
        int nx = x + move.first;
        int ny = y + move.second;
        if (isWithinRange(nx, ny, board[0], board[1])) {
            x = nx;
            y = ny;
        }
    }
    
    return {x, y};
}