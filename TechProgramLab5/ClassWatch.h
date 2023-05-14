#pragma once
#include <iostream>
#include <string>
#include <random>

using namespace std;

namespace CLassWatch
{
	class Watch
	{
	protected: //защищенные поля

		string name;
		string country;
		int prise;

	public:

		void set_name(string a) { name = a; }
		string get_name() { return name; }

		void set_country(string b) { country = b; }
		string get_country() { return country; }

		void set_prise(int c) { prise = c; }
		int get_prise() { return prise; }

		virtual void ShowClass()
		{
			cout << "Название: " << name << "\n";
			cout << "Страна: " << country << "\n";
			cout << "Цена: " << prise << " Руб." << "\n";
		}

	};
}