#include <iostream>
using namespace std;

int a[50][2];
void preorder(int x) {
    if ( x == -1) return;
    cout << (char)(x+'A');
    preorder(a[x][0]);
    preorder(a[x][1]);
}

void inorder(int x) {
    if ( x == -1) return;
    inorder(a[x][0]);
    cout << (char)(x+'A');
    inorder(a[x][1]);
}

void postorder(int x) {
    if ( x == -1) return;
    postorder(a[x][0]);
    postorder(a[x][1]);
    cout << (char)(x+'A');
}
int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        char root, left, right;

        cin >> root >> left >> right;

        a[root - 'A'][0] = left != '.' ? left - 'A' : -1;
        a[root - 'A'][1] = right != '.' ? right - 'A' : -1;
    }
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';

    return 0;
}