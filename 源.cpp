#include <iostream>
#include "Computer Graphics.h"
using namespace std;
int main()
{
	int mark;
	while (1)
	{	
		std::cout << "��ѡ���ܣ�\n1����DDA���߷�������֪���˵��ֱ�߾��������е�\n2������ĳ����ĳ��ֱ��ѡ����ٶȵ�����\n3��Liang_Barsky�㷨\n0���˳�����\n\n";
		std::cin >> mark;
		if (mark == 1)
		{
			Line L1;
			std::cout << "����ֱ������x,y����\n";
			std::cin >> L1.p0.x >> L1.p0.y >> L1.p1.x >> L1.p1.y;
			L1.DDALine();
			std::cout << std::endl;
			std::cin.get();
		}
		else if (mark == 2)
		{
			Point p;
			std::cout << "����p��x,y,z����:\n";
			std::cin >> p.x >> p.y >> p.z;
			Line L1;    //��תֱ��
			double degree;   //��ת�Ƕ�
			std::cout << "������תֱ�ߣ���β����x,y,z��:\n";
			std::cin >> L1.p0.x >> L1.p0.y >> L1.p0.z >> L1.p1.x >> L1.p1.y >> L1.p1.z;
			std::cout << "������ת�Ƕȣ��Ƕ�ֵ��:    \n";
			std::cin >> degree;
			Point res;
			res = p.move(L1.p0).Rotate_Trans(L1, degree).move(-L1.p0);
			std::cout << "�����\n";
			std::cout << res;
			std::cout << std::endl;
			std::cin.get();
		}
		else if (mark == 3)
		{
			/*Point a;
			a.x = 1;
			a.y = 2;
			Point b;
			b.x = 9;
			b.y = 8;
			Line x;
			x.p0.x = 6;
			x.p0.y = 6;
			x.p1.x = 8;
			x.p1.y = 9;*/
			//�������½Ǻ����Ͻ�����
			Point a, b;
			//��Ҫ��ȡ��ֱ��
			Line L0;
			cout << "����ֱ�����˵�����" << endl;
			cin >> L0.p0.x >> L0.p0.y >> L0.p1.x >> L0.p1.y;
			cout << "���봰�����½Ǻ����Ͻ�����"<<endl;
			cin >> a.x >> a.y >> b.x >> b.y;
			L0.Liang_Barsky(a, b);

		}
		else if (mark == 0)
			break;
	}
	return 0;
}