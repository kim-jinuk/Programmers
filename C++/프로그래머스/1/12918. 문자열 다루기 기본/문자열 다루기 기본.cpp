#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
    if (!(s.length() == 4 || s.length() == 6)) return false;
    
    for (char c : s) {
        if (c >= '0' && c <= '9') continue;
        return false;
    }
    return true;
}