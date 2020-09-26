#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i = 0; i < prices.size(); i++) {
        int price = 0;
        for (int j = i + 1; j < prices.size(); j++) {
            if (prices[j] >= prices[i]) price++;
            else {
                price++;
                break;
            }
        }
        answer.push_back(price);
    }
    return answer;
}

int main() {
    vector<int> prices;
    vector<int> answer;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(3);
    answer = solution(prices);

    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << ' ';
}