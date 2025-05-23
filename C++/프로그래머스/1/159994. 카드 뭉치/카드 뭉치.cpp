#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int i1 = 0, i2 = 0;
    for (const string& g : goal) {
        if (i1 < cards1.size() && cards1[i1] == g) {
            i1++;
        }
        else if (i2 < cards2.size() && cards2[i2] == g) {
            i2++;
        }
        else return "No";
    }
    return "Yes";
}