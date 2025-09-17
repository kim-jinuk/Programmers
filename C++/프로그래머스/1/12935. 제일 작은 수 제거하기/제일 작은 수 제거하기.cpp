#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    if (arr.size() < 2) return vector(1, -1);
    
    int min_val = arr[0];
    
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    
    arr.erase(remove(arr.begin(), arr.end(), min_val), arr.end());
    
    return arr;
}