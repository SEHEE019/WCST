#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string front, string end) {
    return front + end > end + front;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;

    //numbers int -> string
    for (auto n : numbers)
        temp.push_back(to_string(n));
    //���� �� ������������ ����
    sort(temp.begin(), temp.end(), compare);
    //0��° ���� 0�̸� "0"���� ��ȯ
    if (temp.at(0) == "0")
        return "0";
    //���ĵ� temp �� ���ļ� answer��
    for (auto n : temp)
        answer += n;

    return answer;
}

void print(vector<int> numbers, string answer) {
    string t = solution(numbers);
    if (t == answer)
        cout << "����" << endl;
    else
        cout << "Ʋ��" << endl;
}

int main() {
    print({ 6, 10, 2 }, "6210");
    print({ 3, 30, 34, 5, 9 }, "9534330");
    print({ 0,0,0,0,0,0,0 }, "0");
    return 0;
}