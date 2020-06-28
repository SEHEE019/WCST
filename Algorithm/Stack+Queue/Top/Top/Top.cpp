/*
Problem:
수평 직선에 탑 N대를 세웠습니다. 모든 탑의 꼭대기에는 신호를 송/수신하는 장치를 설치했습니다. 
발사한 신호는 신호를 보낸 탑보다 높은 탑에서만 수신합니다. 또한, 한 번 수신된 신호는 다른 탑으로 송신되지 않습니다.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
    int hSize = heights.size();
    vector<int> answer(hSize,0);
    for (int i = hSize-1; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (heights[i] < heights[j]){
                answer[i] = j+1;
                break;
            }else 
                answer[i] = 0;
        }
    }
    return answer;
}

int main() {
    cout << "reception: \n";
    vector<int> heights;
    heights.push_back(6);
    heights.push_back(9);
    heights.push_back(5);
    heights.push_back(7);
    heights.push_back(4);

    for(auto e:solution(heights))
        cout << e;

}