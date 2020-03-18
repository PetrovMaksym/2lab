#include <iostream>
#include <string>
#include <Windows.h>
#define garbage_collector() cin.ignore(cin.rdbuf()->in_avail())

using namespace std;
struct Flight///<summary>Рейс</summary>
{
	char car_model[20];
	char destination[50];//пункт назначения
	char noumber_car[10];
	int carrying_capacity,// грузоподьемность(в тонах)
		unit_cost,
		total_cost;
};

Flight* InitArray(int _countFlight);
Flight InitFlight();
void DisplayArray(Flight* MassiveFlights, int _countFlight);
void DisplayFlight(Flight);
void SortCapacity(Flight* MassiveFlights, int);
int& CheckCorectDigitValue(int&);

int main(int argc, char* argv[])
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(0, "");

	cout << "Hard level task\n";
	int _countFlight(0);
	bool begin = true;
tryagain:
	Flight* MassiveStruct = nullptr;
	do
	{
		cout << "\nEnter the number of flight(s)]$~ ";
		do {
			cin >> _countFlight;
			if (cin.fail())
			{
				cout << "~$]Previous input failed, please re-enter !!!" << endl;
				cin.clear();
				cin.ignore(32222, '\n');
			}
			else
				break;
		} while (true);
		MassiveStruct = InitArray(_countFlight);
		if (MassiveStruct == nullptr)
		{
			cout << "\n~$]Dynamic array don't exist!\n";

			do {
				cout << "~$]Введите '+' для того чтобы повторить попытку или нажмите '-' чтобы выйти из програмы... ";
				char symbol;
				symbol = getchar();
				(symbol == '+') ? begin == true : begin == false;
				if (symbol == '+')
					goto tryagain;
				exit(777);

			} while (!begin);
		}


	} while (begin != true);

	cout << "\nThe list of Flight: ";
	DisplayArray(MassiveStruct, _countFlight);

	cout << "\nList of machines in increasing capacity : ";
	SortCapacity(MassiveStruct, _countFlight);
	DisplayArray(MassiveStruct, _countFlight);

	delete MassiveStruct;
}

Flight InitFlight()
{
	Flight Flight;
	cout << "\nEnter car model:";
	garbage_collector();
	cin.getline(Flight.car_model, 50);
	cout << "Enter noumber car: ";
	garbage_collector();
	cin.getline(Flight.noumber_car, 20);
	cout << "Enter destination: ";
	garbage_collector();
	cin.getline(Flight.destination, 50);
	cout << "Enter carrying capacity: ";
	garbage_collector();
	//cin >> Flight.carrying_capacity;
	CheckCorectDigitValue(Flight.carrying_capacity);
	garbage_collector();
	cout << "Enter unit cost: ";
	CheckCorectDigitValue(Flight.unit_cost);
	garbage_collector();
	cout << "Enter total cost: ";
	CheckCorectDigitValue(Flight.total_cost);
	return Flight;
}

Flight* InitArray(int _countFlight)
{
	Flight* Massive = new Flight[_countFlight];
	if (Massive == nullptr)
		return nullptr;
	for (size_t i = 0; i < _countFlight; i++)
	{
		printf("\n]$~Enter the information about %d Flight ", i + 1);
		Massive[i] = InitFlight();
	}
	return Massive;
}



void DisplayArray(Flight* Massive, int _countFlight)
{
	for (size_t i = 0; i < _countFlight; i++) { DisplayFlight(Massive[i]); }
}



void DisplayFlight(Flight MassiveFlights)
{
	printf("\n%s %s №%d %df %d$ %d$ ", MassiveFlights.destination, MassiveFlights.car_model, MassiveFlights.noumber_car, MassiveFlights.carrying_capacity, MassiveFlights.unit_cost, MassiveFlights.total_cost);


}


void SortCapacity(Flight* Massive, int Dimension)
{
	Flight Temp;
	for (size_t i = 0; i <= Dimension; i++)
	{
		for (size_t q = Dimension - 1; q > i; q--)
		{
			if (Massive[q].carrying_capacity > Massive[q - 1].carrying_capacity)
			{
				Temp = Massive[q];
				Massive[q] = Massive[q - 1];
				Massive[q - 1] = Temp;
			}
		}
	}
}
int& CheckCorectDigitValue(int& value)
{
	bool flag = false;
	do {
		if (flag) {
			cout << "Please re-enter!!!";
		}flag = false;
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32222, '\n');
		}
		else
		{
			return value;
		}
	} while (true);
}
