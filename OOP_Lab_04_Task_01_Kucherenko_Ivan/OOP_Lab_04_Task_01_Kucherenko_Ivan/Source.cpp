#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Transportation
{
private:
	int number;
	char driver[50];
public:
	Transportation();
	Transportation(int numberauto, char* driverauto);
	void SetNumber(int numberauto);
	void SetDriver(char* driverauto);
	const int GetNumber(int numberauto) const;
	const char* GetDriver(char* driverauto) const;
	~Transportation();
};


class Taxi : public Transportation
{
private:
	double costOrder;
	double costKilometer;
public:
	Taxi();
	Taxi(double costorder, double costkilometer);
	void SetCostPerKilomete(double costkilo);
	void SetCostOfOrder(double costorder);
	const double GetCostPerKilomete() const;
	const double GetCostOfOrder() const;
	const double CostOfTrip(double distance) const;
	~Taxi();
};


int main()
{
	setlocale(LC_CTYPE, "ukr");
	Taxi a;
	char driverauto[50];

	cout << "ВВедіть ім'я водія" << endl;
	scanf("%s", driverauto);
	a.SetDriver(driverauto);

	int numberauto;
	cout << "ВВедіть номер авто" << endl;
	cin >> numberauto;
	a.SetNumber(numberauto);

	int costorder, costkilo;
	cout << "Введіть ціну проїзду за 1 кілометр" << endl;
	cin >> costkilo;
	a.SetCostPerKilomete(costkilo);

	cout << "Введіть ціну замовлення " << endl;
	cin >> costorder;
	a.SetCostOfOrder(costorder);
	double distance;

	cout << "Введіть довжину маршруту" << endl;
	cin >> distance;

	cout << "Вартість поїздки - " << a.CostOfTrip(distance) << endl;
}

Transportation::Transportation()
{
}

Transportation::Transportation(int numberauto, char* driverauto)
{
	this->number = numberauto;
	strcpy(this->driver, driverauto);
}

void Transportation::SetNumber(int numberauto)
{
	this->number = numberauto;
}

void Transportation::SetDriver(char* driverauto)
{
	strcpy(this->driver, driverauto);
}

const int Transportation::GetNumber(int numberauto) const
{
	return this->number;
}

const char * Transportation::GetDriver(char * driverauto) const
{
	return this->driver;
}

Transportation::~Transportation()
{
}



Taxi::Taxi()
{
}

Taxi::Taxi(double costorder, double costkilometer)
{
	this->costOrder = costorder;
	this->costKilometer = costkilometer;
}

void Taxi::SetCostPerKilomete(double costkilo)
{
	this->costKilometer = costkilo;
}

void Taxi::SetCostOfOrder(double costorder)
{

	this->costOrder = costorder;
}

const double Taxi::GetCostPerKilomete() const
{
	return this->costKilometer;
}

const double Taxi::GetCostOfOrder() const
{
	return this->costOrder;
}

const double Taxi::CostOfTrip(double distance) const
{
	return this->GetCostOfOrder() + this->GetCostPerKilomete()*distance;
}

Taxi::~Taxi()
{
}