#include <string>
#include <vector>

using namespace std;

pair<int, int> key_tans(const string& s) {
    if (s == "left") return {-1, 0};
    else if (s == "right") return {1, 0};
    else if (s == "up") return {0, 1};
    else if (s == "down") return {0, -1};
    else return {0, 0};
}

bool isWithinRange(int x, int y, int bx, int by) {
    int bxx = (bx - 1) / 2;
    int byy = (by  -1) / 2;
    return -bxx <= x && x <= bxx && -byy <= y && y <= byy;
}

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer = {0, 0};
    int dx, dy;
    
    for (const string& s : keyinput) {
        pair<int, int> move = key_tans(s);
        int nx = answer[0] + move.first;
        int ny = answer[1] + move.second;
        if (isWithinRange(nx, ny, board[0], board[1])) {
            answer[0] = nx;
            answer[1] = ny;
        }
    }
    
    return answer;
}