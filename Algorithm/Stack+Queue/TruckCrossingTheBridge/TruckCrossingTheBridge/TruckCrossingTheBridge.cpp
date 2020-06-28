// TruckCrossingTheBridge.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculatesolution(int bridge_length, int weight, vector<int> truck_weights)
{
    //�ٸ��� �迭: ��ġ Ȯ�� ����
    int* bridge = new int[bridge_length];
    for (int i = 0; i < bridge_length; i++)
        bridge[i] = 0;
    
    vector<int> passtedTrucks;//������ Ʈ��
    int solution = 0; //�ɸ� �ð�
    int remainWeight = weight; //�ִ����� - �ٸ��� Ʈ�� ����
    int truckCount = truck_weights.size(); //Ʈ�� ����

    while (truckCount != passtedTrucks.size() || remainWeight != weight)
    {//�ٸ��� ������ �ϴ� Ʈ���� �������� ��, �ִ� ������ ���� �ʾ��� ��
        for (int i = bridge_length - 1; i >= 0; i--)
        {
            if (i == bridge_length - 1) // �ٸ��� �ⱸ �˻�
            {
                if (bridge[i] > 0) // i��° ��ġ�� Ʈ���� �����ϴ°�?
                {

                    passtedTrucks.push_back(bridge[i]);//������ Ʈ���� �߰�
                    remainWeight += bridge[i]; 
                    bridge[i] = 0;
                }
                //if (bridge[i] == 0) // 0�� �� �� ����, �ּ� 1��
                //{
                //    //�� ĭ �̵�
                //    bridge[i] = bridge[i - 1];
                //    bridge[i - 1] = 0;
                //}
            }
            else if (i == 0) // �ٸ��� �Ա� �˻�
            {
                // ����
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
            else // �ٸ��� ������ �˻�
            {
                if (bridge[i] == 0) // 0�� �� �� ����, �ּ� 1��
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
