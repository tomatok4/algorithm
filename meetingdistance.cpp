#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    pair<int , int> location = make_pair(0, 0);
    pair<int , int> temp = make_pair(0, 0);
    set< pair< pair<int,int>, pair<int,int> > > visited;
    
    for(auto i : dirs) {
        if(i == 'U') {
            if(location.second < 5) {
                temp.second++;
            }
        }
        else if ( i == 'D') {
            if(location.second > -5) {
                temp.second--;
            }
        }
        else if (i == 'R') {
            if(location.first < 5) {
                temp.first++;
            }
        }
        else if (i == 'L') {
            if(location.first > -5) {
                temp.first--;
            }    
        }
        
        if(visited.find(make_pair(location, temp)) == visited.end() && location != temp) {
            visited.insert(make_pair(location, temp));
            visited.insert(make_pair(temp, location));   
            answer++;
        }
        location = temp;
    }
    return answer;
}