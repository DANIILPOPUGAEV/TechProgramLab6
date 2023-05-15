#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include "ClassWatch.h"
#include "ClassElectronical.h"
#include "ClassMechanical.h"
#include "MainFunctions.h"

using namespace std;
using namespace ClassElectronical;
using namespace ClassMechanical;
using namespace CLassWatch;
using namespace Main;

void Main::MainFunction()
{
	Electronical* electronical; //������������ ��������� ������ 
	Mechanical* mechanical;
	electronical = new Electronical[2];
	mechanical = new Mechanical[2];

	mechanical[0].set_type("Mechanical");
	electronical[0].set_type("Electronical");

	mechanical[0].set_name("Edifice"); mechanical[0].set_country("�����");
	mechanical[1].set_name("MAST"); mechanical[1].set_country("�����");

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(2000, 12000); //������������� ���������� ��������� �����

	for (int i = 0; i < 2; ++i)
	{
		mechanical[i].set_prise(dist(gen));
		electronical[i].set_prise(dist(gen));
	}

	random_device sd;
	mt19937 gen1(sd());
	uniform_int_distribution<> dist1(25, 65);

	for (int i = 0; i < 2; ++i)
	{
		mechanical[i].set_diametr(dist1(gen1));
		electronical[i].set_dial(dist1(gen1));
	}

	random_device pd;
	mt19937 gen2(pd());
	uniform_int_distribution<> dist2(150, 350);
	for (int i = 0; i < 2; ++i)
	{
		mechanical[i].set_weight(dist2(gen2));
		electronical[i].set_battery(dist2(gen2));
	}

	electronical[0].set_name("G-Shock"); electronical[0].set_country("�������");
	electronical[1].set_name("WFS"); electronical[1].set_country("�����");

	electronical->ShowClass(electronical);
	mechanical->ShowClass(mechanical);

	int max1 = Maximum(electronical, 0);
	int max2 = Maximum(mechanical, 0);

	if (max1 < max2)
	{
		for (int i = 0; i < 2; ++i)
		{
			if (max2 == mechanical[i].get_prise())
			{
				cout << "����� ������� ���������: " << mechanical[i].get_name() << " (" << max2 << " ���.)\n"; break;
			}
		}
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			if (max1 == electronical[i].get_prise())
			{
				cout << "����� ������� ���������: " << electronical[i].get_name() << " (" << max1 << " ���.)\n"; break;
			}
		}
	}
	delete[] electronical;
	delete[] mechanical; //�������� ������
}
