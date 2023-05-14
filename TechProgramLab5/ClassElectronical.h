#pragma once
#include <iostream>
#include <string>
#include <random>
#include "ClassWatch.h"

using namespace std;
using namespace CLassWatch;

namespace ClassElectronical
{
	class Electronical : private Watch //закрытое наследование 
	{
	private:

		static string type;
		int battery;
		int dial;

	public:

		void set_type(string s) { type = s; }
		string get_type() { return type; }

		void set_battery(int d) { battery = d; }
		int get_battery() { return battery; }

		void set_dial(int e) { dial = e; }
		int get_dial() { return dial; }

		void set_name(string a) { name = a; }
		string get_name() { return name; }

		void set_country(string b) { country = b; }
		string get_country() { return country; }

		void set_prise(int c) { prise = c; }
		int get_prise() { return prise; }

		bool operator>(int max);

		void ShowClass(Electronical electronical[2])
		{
			for (int i = 0; i < 2; i++)
			{
				cout << "Тип: " << electronical[i].type << "\n";
				cout << "Название: " << electronical[i].name << "\n";
				cout << "Страна: " << electronical[i].country << "\n";
				cout << "Цена: " << electronical[i].prise << " Руб." << "\n";
				cout << "Батарея: " << electronical[i].battery << " мАч" << "\n";
				cout << "Циферблат: " << electronical[i].dial << " мм" << "\n";
				cout << endl;
			}
		}

		friend int Maximum(Electronical electronical[2], int max);
	};

	string Electronical::type;

	bool Electronical :: operator>(int max)
	{
		if (prise > max)
			return true;
		else return false;
	}


	int Maximum(Electronical electronical[2], int max)
	{
		for (int i = 0; i < 2; i++)
		{
			if (electronical[i] > max)
			{
				max = electronical[i].get_prise();
			}
		}
		return max;
	}

};