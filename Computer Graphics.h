#pragma onc
#include <iostream>
class Line;
class Point
{
public:
	Point();   //默认构造函数
	Point(double m, double n, double o);
	Point& operator =(const Point &m);
	void setPoint(double m, double n, double o);  //设置点坐标
	Point move(Point a, Point b);  //平移变换(按某个向量）
	Point move(Point a);  //平移变换至原点
	Point Rotate_Trans(Line L1, double degree);  //旋转变换
	void size();   //比例变换
	Point getPoint();   //得到点坐标
	double x;
	double y;
	double z;
	Point operator -();   //坐标取负
	friend std::ostream& operator<<(std::ostream &out, const Point &m);
};
class Line
{
public:
	Line();  //默认构造函数
	Line(Point a, Point b);
	Point p0;
	Point p1;
	void DDALine();    //DDA画直线方法
	void Liang_Barsky(Point a, Point b);   //Liang_Barsky算法
};