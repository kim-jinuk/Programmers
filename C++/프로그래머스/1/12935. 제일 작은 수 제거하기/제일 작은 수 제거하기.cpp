#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    if (arr.size() < 2) return vector(1, -1);
    
    int min_val = *min_element(arr.begin(), arr.end());
    arr.erase(remove(arr.begin(), arr.end(), min_val), arr.end());
    
    return arr;
}