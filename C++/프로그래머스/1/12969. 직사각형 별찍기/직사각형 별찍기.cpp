#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int a;
    int b;
    string s;
    cin >> a >> b;
    
    s.append(a, '*');
    
    for (int i = 0; i < b; ++i) {
        cout << s << endl;
    }
    
    return 0;
}