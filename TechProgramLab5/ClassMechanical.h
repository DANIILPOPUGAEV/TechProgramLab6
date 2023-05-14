#pragma once
#include <iostream>
#include <string>
#include <random>
#include "ClassWatch.h"

using namespace std;
using namespace CLassWatch;

namespace ClassMechanical
{
	class Mechanical; // ����������� ���������� ������������ ������ 

	class Mechanical : public Watch //�������� ������������
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
				cout << "���: " << mechanical[i].type << "\n";
				cout << "��������: " << mechanical[i].name << "\n";
				cout << "������: " << mechanical[i].country << "\n";
				cout << "����: " << mechanical[i].prise << " ���." << "\n";
				cout << "�������: " << mechanical[i].diametr << " �v" << "\n";
				cout << "���������: " << mechanical[i].weight << " �" << "\n";
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

