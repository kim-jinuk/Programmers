#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> phone_set;
    
    for (int i = 0; i < phone_book.size(); ++i) {
        string k;
        for (int j = 0; j < phone_book[i].length() - 1; ++j) {
            k += phone_book[i][j];
            phone_set.insert(k);
        }
    }
    
    for (string s : phone_book) {
        if (phone_set.find(s) != phone_set.end()) return false;
    }
    
    return true;
}