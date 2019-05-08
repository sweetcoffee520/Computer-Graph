#include <iostream>
#include "Computer Graphics.h"
using namespace std;
int main()
{
	int mark;
	while (1)
	{	
		std::cout << "请选择功能：\n1、用DDA画线法计算已知两端点的直线经过的所有点\n2、计算某点绕某条直线选择多少度的坐标\n3、Liang_Barsky算法\n0、退出程序\n\n";
		std::cin >> mark;
		if (mark == 1)
		{
			Line L1;
			std::cout << "输入直线两点x,y坐标\n";
			std::cin >> L1.p0.x >> L1.p0.y >> L1.p1.x >> L1.p1.y;
			L1.DDALine();
			std::cout << std::endl;
			std::cin.get();
		}
		else if (mark == 2)
		{
			Point p;
			std::cout << "输入p点x,y,z坐标:\n";
			std::cin >> p.x >> p.y >> p.z;
			Line L1;    //旋转直线
			double degree;   //旋转角度
			std::cout << "输入旋转直线（首尾坐标x,y,z）:\n";
			std::cin >> L1.p0.x >> L1.p0.y >> L1.p0.z >> L1.p1.x >> L1.p1.y >> L1.p1.z;
			std::cout << "输入旋转角度（角度值）:    \n";
			std::cin >> degree;
			Point res;
			res = p.move(L1.p0).Rotate_Trans(L1, degree).move(-L1.p0);
			std::cout << "结果是\n";
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
			//窗口左下角和右上角坐标
			Point a, b;
			//需要截取的直线
			Line L0;
			cout << "输入直线两端点坐标" << endl;
			cin >> L0.p0.x >> L0.p0.y >> L0.p1.x >> L0.p1.y;
			cout << "输入窗口左下角和右上角坐标"<<endl;
			cin >> a.x >> a.y >> b.x >> b.y;
			L0.Liang_Barsky(a, b);

		}
		else if (mark == 0)
			break;
	}
	return 0;
}