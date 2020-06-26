#include <iostream>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

int fr;
int t = 1;
queue<pair<string, string>> q;

map<string, int> c;
int main(void) {

    int ca;
    string f1, f2;
    string temp;
    cin >> ca;

    for (int i =0; i < ca; i++) {
        cin >> fr;
        for(int j=0; j < fr; j++) {
            cin >> f1 >> f2;
            q.push(make_pair(f1, f2));
        }
    }
    f1 = q.front().first;
    f2 = q.front().second;

    q.pop();
    c.insert(make_pair(f1, 1));
    c.insert(make_pair(f2, 1));
    while(!q.empty()) {
        f1 = q.front().first;
        f2 = q.front().second;

        q.pop();
        if(c.find(f1)!=c.end()) {
            t = c.find(f1)->second;
            c.insert(make_pair(f2, t));
        }
        else if(c.find(f2)!=c.end()) {
            c.insert(make_pair(f1, t));
        }
        else {
            c.insert(make_pair(f1, t+1));
        }

    }

    for(auto it = c.begin(); it!= c.end(); ++it)
        cout << it->first << it->second << '\n';
    return 0;
}