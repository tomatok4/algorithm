#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution{
public:
    int solution(vector<int> candles){
        vector<int> temp;
        sort(candles.begin(), candles.end(),greater<int>());
        int answer = 1;
        while(answer <= candles.size()) {
            temp.clear();
            for(int i = 0; i < answer; i++) {
                candles[i]--;
                if(candles[i] == 0) {
                    temp.push_back(i-temp.size());
                }
            }
            for(int i = 0; i < temp.size(); i++) {
                candles.erase(candles.begin()+temp[i]);
            }
            sort(candles.begin(), candles.end(),greater<int>());
            answer++;
        }
        answer--;
        return answer;
    }
};
int main() {
    Solution s;
    vector<int> candles = {5, 2, 2, 1};

    int n = s.solution(candles);

    cout << n << endl;
    return 0;
}
	// 1.	vector<int> candles = [2,2,2]리턴(정답): 3 문제 내용에 나온 예제이다.
	// 2.	vector<int> candles = [2,2,2,4]리턴(정답): 4 여분의 양초로 4일 밤동안 초를 태울 수 있다.
	// 3. 	vector<int> candles = [5,2,2,1]리턴(정답): 3
	// 4.	vector<int> candles = [1,2,3,4,5,6]리턴(정답): 6
	// 5.	vector<int> candles = [4,5,2]리턴(정답): 3
