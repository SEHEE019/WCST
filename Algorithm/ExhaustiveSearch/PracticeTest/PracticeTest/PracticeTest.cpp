#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> firstPerson = { 1,2,3,4,5 };
	vector<int> secondPerson = { 2,1,2,3,2,4,2,5 };
	vector<int> thirdPerson = { 3,3,1,1,2,2,4,4,5,5 };
	vector<int> score = { 0,0,0 };
	int maxScore = 0;

	for (int i = 0; i < answers.size(); i++) {
		if (firstPerson[i % 5] == answers[i])
			score[0] += 1;
		if (secondPerson[i % 8] == answers[i])
			score[1] += 1;
		if (thirdPerson[i % 10] == answers[i])
			score[2] += 1;
	}

	maxScore = *max_element(score.begin(), score.end());

	for (int i = 0; i < score.size(); i++) {
		if (score[i] == maxScore)
			answer.push_back(i + 1);
	}

	return answer;
}

int main() {
	vector<int> answers = { 1,3,2,4,2 };
	vector<int> answer = solution(answers);

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "";
	}
	cout << endl;
	return 0;
}