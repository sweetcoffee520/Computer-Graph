#pragma onc
#include <iostream>
class Line;
class Point
{
public:
	Point();   //Ĭ�Ϲ��캯��
	Point(double m, double n, double o);
	Point& operator =(const Point &m);
	void setPoint(double m, double n, double o);  //���õ�����
	Point move(Point a, Point b);  //ƽ�Ʊ任(��ĳ��������
	Point move(Point a);  //ƽ�Ʊ任��ԭ��
	Point Rotate_Trans(Line L1, double degree);  //��ת�任
	void size();   //�����任
	Point getPoint();   //�õ�������
	double x;
	double y;
	double z;
	Point operator -();   //����ȡ��
	friend std::ostream& operator<<(std::ostream &out, const Point &m);
};
class Line
{
public:
	Line();  //Ĭ�Ϲ��캯��
	Line(Point a, Point b);
	Point p0;
	Point p1;
	void DDALine();    //DDA��ֱ�߷���
	void Liang_Barsky(Point a, Point b);   //Liang_Barsky�㷨
};