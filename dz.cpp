#include <iostream>
#include <string>
#include <vector>
// 1 задание
class Butterfly
{
public:
	std::string stage_name;
	int life_days;

	void changeStage()
	{
		if (stage_name == "гусеница" && life_days >= 7)
		{
			stage_name = "куколка";
			life_days = 0;
		}
		else if (stage_name == "куколка" && life_days >= 15)
		{
			stage_name = "бабочка";
			life_days = 0;
		}
		else if (stage_name == "бабочка" && life_days >= 23)
		{
			stage_name = "гусеница";
			life_days = 0;
		}
		else
		{
			life_days += 1;
		}
	}
};

int main()
{
	std::vector<Butterfly*> butterflies;

	for (int i = 0; i < 10; i++)
	{
		butterflies.push_back(new Butterfly);
	}

	
	for (int i = 0; i < 10; i++)
	{
		butterflies[i]->stage_name = "гусеница";
		butterflies[i]->life_days = 0;
	}

	std::cout << "Исходный вектор:" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << butterflies[i]->stage_name << " " << butterflies[i]->life_days << std::endl;
	}

	
	for (int i = 0; i < 10; i++)
	{
		butterflies[i]->changeStage();
	}

	std::cout << "\nПолучившийся вектор:" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << butterflies[i]->stage_name << " " << butterflies[i]->life_days << std::endl;
	}

	return 0;
}
// 2 Задание
#include <ctime>
#include <iostream>
#include <map>
using namespace std;

int main() {
	srand(time(0));
	int sum;
	map<int, int> m;
	for (int i = 0; i < 1000; i++) {
		sum = rand() % 6 + 1 + rand() % 6 + 1;
		cout << sum << " ";
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
		if (m.find(sum) != m.end()) {
			m[sum]++;
		}
		else {
			m[sum] = 1;
		}
	}
	cout << "Рез-ты бросания 2-ух кубиков:" << endl;
	for (auto n : m) {
		cout << "Сумма очков: " << n.first << ", Кол-Во исходов: " << n.second << endl;
	}
	return 0;
}