/*
Problem:
���� ������ ž N�븦 �������ϴ�. ��� ž�� ����⿡�� ��ȣ�� ��/�����ϴ� ��ġ�� ��ġ�߽��ϴ�. 
�߻��� ��ȣ�� ��ȣ�� ���� ž���� ���� ž������ �����մϴ�. ����, �� �� ���ŵ� ��ȣ�� �ٸ� ž���� �۽ŵ��� �ʽ��ϴ�.
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