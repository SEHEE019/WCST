// TruckCrossingTheBridge.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculatesolution(int bridge_length, int weight, vector<int> truck_weights)
{
    //다리를 배열: 위치 확인 위함
    int* bridge = new int[bridge_length];
    for (int i = 0; i < bridge_length; i++)
        bridge[i] = 0;
    
    vector<int> passtedTrucks;//지나간 트럭
    int solution = 0; //걸린 시간
    int remainWeight = weight; //최대하중 - 다리의 트럭 무게
    int truckCount = truck_weights.size(); //트럭 갯수

    while (truckCount != passtedTrucks.size() || remainWeight != weight)
    {//다리를 지나야 하는 트럭이 남아있을 때, 최대 하중을 넘지 않았을 때
        for (int i = bridge_length - 1; i >= 0; i--)
        {
            if (i == bridge_length - 1) // 다리의 출구 검사
            {
                if (bridge[i] > 0) // i번째 위치에 트럭이 존재하는가?
                {

                    passtedTrucks.push_back(bridge[i]);//지나간 트럭에 추가
                    remainWeight += bridge[i]; 
                    bridge[i] = 0;
                }
                //if (bridge[i] == 0) // 0이 될 수 없음, 최소 1임
                //{
                //    //한 칸 이동
                //    bridge[i] = bridge[i - 1];
                //    bridge[i - 1] = 0;
                //}
            }
            else if (i == 0) // 다리의 입구 검사
            {
                // 입장
                if (truck_weights.size() > 0)
                {
                    if (remainWeight >= truck_weights.at(0))
                    {
                        if (bridge[i] == 0)
                        {
                            bridge[i] = truck_weights.at(0);
                            remainWeight -= bridge[i];
                            truck_weights.erase(truck_weights.begin());
                        }
                    }
                }
            }
            else // 다리의 나머지 검사
            {
                if (bridge[i] == 0) // 0이 될 수 없음, 최소 1임
                {
                    bridge[i] = bridge[i - 1];
                    bridge[i - 1] = 0;
                }
            }
        }

        solution++;
    }

    delete bridge;

    return solution;
}

int main()
{
    cout << "Hello World!\n";

    vector<int> trucks;
    trucks.push_back(10);
    trucks.push_back(10);
    trucks.push_back(10);
    trucks.push_back(10);
    trucks.push_back(10);
    trucks.push_back(10);
    trucks.push_back(10);
    trucks.push_back(10);
    trucks.push_back(10);
    trucks.push_back(10);
    int solution = calculatesolution(100, 100, trucks);


    cout << "solution: " << solution;
}
