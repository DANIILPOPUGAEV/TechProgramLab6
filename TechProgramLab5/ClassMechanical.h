#pragma once
#include <iostream>
#include <string>
#include <random>
#include "ClassWatch.h"

using namespace std;
using namespace CLassWatch;

namespace ClassMechanical
{
	class Mechanical; // опережающее объявление производного класса 

	class Mechanical : public Watch //открытое наследование
	{
	private:

		static string type;
		int weight;
		int diametr;

	public:

		void set_type(string s) { type = s; }
		string get_type() { return type; }

		void set_weight(int f) { weight = f; }
		int get_weight() { return weight; }

		void set_diametr(int g) { diametr = g; }
		int get_diametr() { return diametr; }

		bool operator>(int max);

		void ShowClass(Mechanical mechanical[2])
		{
			for (int i = 0; i < 2; i++)
			{
				cout << "Тип: " << mechanical[i].type << "\n";
				cout << "Название: " << mechanical[i].name << "\n";
				cout << "Страна: " << mechanical[i].country << "\n";
				cout << "Цена: " << mechanical[i].prise << " Руб." << "\n";
				cout << "Батарея: " << mechanical[i].diametr << " мv" << "\n";
				cout << "Циферблат: " << mechanical[i].weight << " г" << "\n";
				cout << endl;
			}
		}

		friend int Maximum(Mechanical mechanical[2], int max);
	};

	string Mechanical::type;

	bool Mechanical :: operator>(int max)
	{
		if (prise > max)
			return true;
		else return false;
	}


	int Maximum(Mechanical mechanical[2], int max)
	{
		for (int i = 0; i < 2; i++)
		{
			if (mechanical[i] > max)
			{
				max = mechanical[i].get_prise();
			}
		}
		return max;
	}
}

