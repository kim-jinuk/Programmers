#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p = 0;
    int y = 0;

    for (char c : s) {
        if (c == 'P' || c == 'p') p++;
        else if (c == 'Y' || c == 'y') y++;
    }

    return p == y;
}