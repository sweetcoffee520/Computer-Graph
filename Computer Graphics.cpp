#include <iostream>
#include <cmath>
#include "Computer Graphics.h"
#include "Matrix.h"
#define PI 3.1415926535898
Point::Point()
{
	x = 0;
	y = 0;
	z = 0;
}
Point::Point(double m, double n, double o)
{
	x = m;
	y = n;
	z = o;
}
Line::Line()
{
	p0.x = 0;
	p0.y = 0;
	p1.x = 1;
	p1.y = 1;
}
Line::Line(Point a, Point b)
{
	p0 = a;
	p1 = b;
}
std::ostream& operator<<(std::ostream &out, const Point &m)
{
	out << "(" << m.x << "," << m.y << "," << m.z << ")" << std::endl;
	return out;
}
void Point::setPoint(double m, double n, double o)
{
	x = m;
	y = n;
	z = o;
}
Point Point::getPoint()
{
	Point temp;
	temp.x = x;
	temp.y = y;
	temp.z = z;
	return temp;
}
Point Point::operator-()
{
	Point temp;
	temp.x = -x;
	temp.y = -y;
	temp.z = -z;
	return temp;
}
Point& Point::operator =(const Point &m)
{
	x = m.x;
	y = m.y;
	z = m.z;
	return *this;
}
void Line::DDALine()
{
	int x0 = p0.x;
	int y0 = p0.y;
	int x1 = p1.x;
	int y1 = p1.y;
	int dx = x1 - x0;
	int dy = y1 - y0;
	int startX = 0;
	int startY = 0;
	int endX = 0;
	int endY = 0;
	Point temp;
	if (dx == 0)
	{
		int x = x0;
		startY = y0 > y1 ? y1 : y0;
		endY = y0 > y1 ? y0 : y1;
		for (int i = startY;i < endY;i++)
		{
			Point temp;
			temp.x = x, temp.y = i;
			std::cout << temp;
		}
	}
	else if (dy == 0)
	{
		int y = y0;
		startX = x0 > x1 ? x1 : x0;
		endX = x0 > x1 ? x0 : x1;
		for (int i = startX;i < endX;i++)
		{
			temp.x = i, temp.y = y;
			std::cout << temp;
		}
	}
	else
	{
		if (abs(dy) > abs(dx))
		{
			double k, x;
			int y;
			k = (double)dx / (double)dy;
			if (y0 > y1)
			{
				startX = x1;
				startY = y1;
				endX = x0;
				endY = y0;
			}
			else
			{
				startX = x0;
				startY = y0;
				endX = x1;
				endY = y1;
			}
			x = startX;
			for (y = startY;y < endY;y++)
			{
				temp.x = (int)(x+0.5), temp.y = y;
				std::cout << temp;
				x += k;
			}
		}
		else
		{
			double k, y;
			int x;
			k = (double)dy / (double)dx;
			if (y0 > y1)
			{
				startX = x1;
				startY = y1;
				endX = x0;
				endY = y0;
			}
			else
			{
				startX = x0;
				startY = y0;
				endX = x1;
				endY = y1;
			}
			y = startY;
			for (x = startX;x < endX;x++)
			{
				temp.x = x, temp.y = (int)(y+0.5);
				std::cout << temp;
				y += k;
			}
		}
	}
}
void Line::Liang_Barsky(Point a, Point b)
{
	int i;
	double umax = 0, umin = 1;
	//入点坐标和出点坐标
	Point PIN, POUT;
	//直线两端点坐标
	double x0, y0, x1, y1, xmin, ymin, xmax, ymax;
	double u[4];
	x0 = p0.x;
	x1 = p1.x;
	y0 = p0.y;
	y1 = p1.y;
	xmin = x0 > x1 ? x1 : x0;
	xmax = x0 > x1 ? x0 : x1;
	ymin = y0 > y1 ? y1 : y0;
	ymax = y0 > y1 ? y0 : y1;
	PIN.x = x0;
	PIN.y = y0;
	POUT.x = x1;
	POUT.y = y1;
	double dx, dy;
	dx = x1 - x0;
	dy = y1 - y0;
	//计算p和q的四个值
	double p[4] = { -dx,dx,-dy,dy }, q[4] = { x0 - a.x,b.x - x0,y0 - a.y,b.y - y0 };
	//平行y轴
	if (p[0] == 0)
	{
		if (ymax<a.y || ymin>b.y)
		{
			std::cout << "直线不在窗口内" << std::endl << std::endl;
		}
		else
		{
			if (q[0] >= 0 && q[1] >= 0)
			{
				if (PIN.y < a.y) PIN.y = a.y;
				if (POUT.y > b.y) POUT.y = b.y;
				std::cout << "入点坐标:" << PIN << "出点坐标:" << POUT;
			}
			else
			{
				std::cout << "直线不在窗口内" << std::endl << std::endl;
			}
		}
	}
    //平行x轴
	if (p[3] == 0)
	{
		if(xmax<a.x||xmin>b.x)
		{ 
			std::cout << "直线不在窗口内" << std::endl << std::endl;
		}
		else
		{
			if (q[2] >= 0 && q[3] >= 0)
			{
				if (PIN.x < a.x) PIN.x = a.x;
				if (POUT.x > b.x) POUT.x = b.x;
				std::cout << "入点坐标:" << PIN << "出点坐标:" << POUT;
			}
			else
			{
				std::cout << "直线不在窗口内" << std::endl << std::endl;
			}
		}
	}
	else
	{
		for (i = 0;i < 4;i++)
		{
			if (p[i] < 0)
			{

				u[i] = q[i] / p[i];
				if (u[i] > umax)
					umax = u[i];
			}
			else
			{
				u[i] = q[i] / p[i];
				if (u[i] < umin)
					umin = u[i];
			}
		}
		if (umax > umin) std::cout << "直线不在窗口内" << std::endl << std::endl;
		else
		{
			PIN.x = x0 + umax * dx;
			PIN.y = y0 + umax * dy;
			POUT.x = x0 + umin * dx;
			POUT.y = y0 + umin * dy;
			std::cout << "入点坐标:" << PIN << "出点坐标:" << POUT;
		}
	}
}
Point Point::move(Point a,Point b)
{
	Point c;
	double dx, dy, dz;
	dx = a.x - b.x;
	dy = a.y - b.y;
	dz = a.z - b.z;
	Matrix temp(4);
	temp.set(0, 3, x);
	temp.set(1, 3, y);
	temp.set(2, 3, z);
	double a1[] = { dx,dy,dz,1 };
	Matrix temp1(a1,4,1);
	Matrix res;
	res = temp * temp1;
	c.x = res.get(0, 0);
	c.y = res.get(1, 0);
	c.z = res.get(2, 0);
	return c;
}
Point Point::move(Point a)
{
	Point c;
	Matrix temp(4);
	temp.set(0, 3, -a.x);
	temp.set(1, 3, -a.y);
	temp.set(2, 3, -a.z);
	double a1[] = { x,y,z,1 };
	Matrix temp1(a1, 4, 1);
	Matrix res;
	res = temp * temp1;
	c.x = res.get(0, 0);
	c.y = res.get(1, 0);
	c.z = res.get(2, 0);
	//std::cout << temp<<std::endl<<c<<std::endl;
	return c;
}
Point Point::Rotate_Trans(Line L1,double degree)
{
	Point a;
	a.x = L1.p1.x - L1.p0.x;
	a.y = L1.p1.y - L1.p0.y;
	a.z = L1.p1.z - L1.p0.z;
	double x0, y0, z0;   //单位向坐标
	x0 = a.x / sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
	y0 = a.y / sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
	z0 = a.z / sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
	double a0, b0, c0, d0;   //绕y轴的余弦值和正弦值和绕x轴的余弦值和正弦值
	a0 = z0 / (sqrt(x0*x0 + z0 * z0));
	b0 = x0 / (sqrt(x0*x0 + z0 * z0));
	c0 = sqrt(x0*x0 + z0 * z0);
	d0 = y0;
	double z1;  //绕z轴的旋转角度
	z1 = degree * PI / 180;
	Matrix temp(4);
	Matrix temp1(4);
	Matrix temp2(4);
	Matrix temp_(4);
	Matrix temp_1(4);
	if (x0 != 0.0)  //绕y轴旋转
	{
		temp.set(0, 0, a0);
		temp.set(0, 2, -b0);
		temp.set(2, 0, b0);
		temp.set(2, 2, a0);
		temp_.set(0, 0, a0);
		temp_.set(0, 2, b0);
		temp_.set(2, 0, -b0);
		temp_.set(2, 2, a0);
	}
	if (y0 !=0.0)  //绕x轴旋转
	{
		temp1.set(1, 1, c0);
		temp1.set(1, 2, -d0);
		temp1.set(2, 1, d0);
		temp1.set(2, 2, c0);
		temp_1.set(1, 1, c0);
		temp_1.set(1, 2, d0);
		temp_1.set(2, 1, -d0);
		temp_1.set(2, 2, c0);
	}
	//绕z轴旋转
	temp2.set(0, 0, cos(z1));
	temp2.set(0, 1, -sin(z1));
	temp2.set(1, 0, sin(z1));
	temp2.set(1, 1, cos(z1));
	double a1[] = { x,y,z,1 };
	Matrix temp3(a1, 4, 1);

	Matrix res;
	res = temp_*temp1*temp2*temp_1*temp*temp3;
	Point b;
	b.x = res.get(0, 0);
	b.y = res.get(1, 0);
	b.z = res.get(2, 0);
	//std::cout << temp_ << std::endl << temp1 << std::endl << temp2 << std::endl << temp3 << std::endl << res << std::endl<<b<<std::endl;
	return b;
}