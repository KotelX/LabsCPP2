#include <iostream>
#include <clocale>
#include <list>

using namespace std;

class Bus
{
public: string NumberBus;
public: string Name;
public: int Route;
};

void PrintBusList(list<Bus> bus) {
    for (Bus bs : bus)
    {
        cout << "   Маршрут:" << bs.Route << " Госномер:" << bs.NumberBus << " Имя водителя:" << bs.Name << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int busCount = 2;
    list<Bus> bus;
    for (size_t i = 0; i < busCount; i++)
    {
        Bus newBus = Bus();
        cout << "Гос.номер: " << endl;
        cin >> newBus.NumberBus;
        cout << "Инициалы водителя: " << endl;
        cin >> newBus.Name;
        cout << "Маршрут: " << endl;
        cin >> newBus.Route;
        cout << endl;
        bus.push_back(newBus);
    }
    list<Bus> park = bus;
    list<Bus> route;
    while (true)
    {
        cout << "Для перевода на маршрут: >" << endl << "Для перевода в парк : <" << endl << "Вывод всех автобусов : P" << endl;
        string d;
        cin >> d;
        if (d == ">") {
            cout << "Введите гос.номер автобуса для перевода его на маршрут" << endl;
            cin >> d;
            for (auto b = park.begin(); b != park.end(); b++)
                if ((*b).NumberBus == d)
                {
                    route.push_back(*b);
                    park.erase(b);
                    break;
                }
        }
        if (d == "<") {
            cout << "Введите гос.номер автобуса для перевода его на парк" << endl;
            cin >> d;
            for(auto b = route.begin(); b != route.end(); b++)
                if ((*b).NumberBus == d)
                {
                    park.push_back(*b);
                    route.erase(b);
                    break;
                }
        }
        if (d == "P") {
            cout << endl << "На маршрутах" << endl;
            PrintBusList(route);
            cout << endl << "В парке" << endl;
            PrintBusList(park);
            cout << endl;
        }
    }
}


