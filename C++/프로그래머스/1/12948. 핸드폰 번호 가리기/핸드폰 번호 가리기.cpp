#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int n = phone_number.length();
    return phone_number.replace(phone_number.begin(), phone_number.end() - 4, n - 4, '*');
}