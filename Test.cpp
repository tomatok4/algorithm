#include <iostream>
#include <vector>
using namespace std;
//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
// 6 3 5 2 4 1 3
// + + - - + + -
// 5 3 0 1 4 2 1

// 12 49 11 48 10 47 9 46 8 45 7 44 6 43 5 42 4 41 3 40 2 39 1 38
// +  +  -  -  +  +  - -  + +  - -  + +  - -  +  + -  - + +  - -
// 11 49 0  1  10 48 1 2  9 47 2  3 8 46 3 4  7 45 4  5 6 44 5 6

class Solution{
public:
    vector<int> solution(int width, int length){
        int visit = 0;
        int king = width * length;
        int tempx = 0;
        int tempy = 0;
        int th = -1;
        vector<int> answer;
        visit = width;
        tempx = width -1;
        width--;
        length--;
        visit+= length;
        tempy = length;
        cout << length<< endl;
        while(visit < king) {
            visit += width;
            tempx = tempx + (th * width);
            cout << "temp x : "<< tempx << endl;
            if(visit == king) {
                break;
            }
            length--;
            visit += length;
            cout << length << endl;
            tempy = tempy + (th * length);
            width--;
            cout << "temp y : "<< tempy << endl;
            th = -1 * th;
        }
        answer.push_back(tempx);
        answer.push_back(tempy);
        return answer;
        
    }
};

int main() {
    Solution a;
    vector<int> b= a.solution(12,50);
    cout << b[0] << "," << b[1]<< endl;
}