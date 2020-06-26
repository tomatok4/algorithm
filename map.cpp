#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> a = {1, 4, 1, 2, 4, 2, 4, 2, 3, 4, 4};
    for ( int i = 1; i <= 5; i ++) {
        cout << i << "의 개수: " << count(a.begin(), a.end(), i);
        cout << '\n';
    }

    int even = count_if(a.begin(), a.end(), [](int x) {
        return x % 2 == 0;
    });
    int odd = count_if(a.begin(), a.end(), [](int x) {
        return x % 2 == 1;
    });

    cout << "짝수의 개수: " << even << '\n';
    cout << "홀수의 개수: " << odd << '\n';

    return 0;
}