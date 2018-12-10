#ifndef _FIGUREMANAGER_H_
#define _FIGUREMANAGER_H_

#include <iostream>
#include <vector>
#include "BlackBoard.h"

using namespace std;

class Figure;

class FigureManager
{
public:
	static FigureManager &handle()
	{
		static FigureManager manager; 
		return manager; 
	}
    
    // FigureManager����������
	virtual ~FigureManager();
 
    // FigureManager��ӿ�.
public:
	void input(std::istream &is);
    void display(BlackBoard &board);
private:
	// ����洢�������ݵ���ʱ����
	vector<Figure *> _figures;
}; // class FigureManager�ඨ�����.

void InitiateFigureManager(); 

// ����ͼ����
class Figure
{
public:
	Figure(int id) : _type(id) { }
	int type() { return _type; }
	// ��������һ�����麯��
	virtual ~Figure() { }
	// �麯��input��display, ��������Ķ�Ӧ����
	virtual void input(std::istream &is) { }
	virtual void display(BlackBoard &board) { }
private:
	int _type;
};

class Circle : public Figure
{
public:
	Circle() : Figure(1) { }
	virtual void input(std::istream &is)
	{
		std::cout << "Center X: ";
		is >> _x;
		std::cout << "Center Y: ";
		is >> _y;
		std::cout << "Radius: ";
		is >> _radius;
	}
	virtual void display(BlackBoard &board)
	{
		board.DrawCircle(_x, _y, _radius);
	}
private:
	int _x;
	int _y;
	int _radius;
};

class Line : public Figure
{
public:
	Line() : Figure(2) { }
	virtual void input(std::istream &is)
	{
		std::cout << "X1: ";
		is >> _x1;
		std::cout << "Y1: ";
		is >> _y1;
		std::cout << "X2: ";
		is >> _x2;
		std::cout << "Y2: ";
		is >> _y2;
	}
	virtual void display(BlackBoard &board)
	{
		board.DrawLine(_x1, _y1, _x2, _y2);
	}
private:
	int _x1;
	int _y1;
	int _x2;
	int _y2;
};

class Rectangle : public Figure
{
public:
	Rectangle() : Figure(3) { }

	virtual void input(std::istream &is)
	{
		std::cout << "Left: ";
		is >> _left;
		std::cout << "Top: ";
		is >> _top;
		std::cout << "Right: ";
		is >> _right;
		std::cout << "Bottom: ";
		is >> _bottom;
	}
	virtual void display(BlackBoard &board)
	{
		board.DrawLine(_left, _top, _right, _top);
		board.DrawLine(_left, _bottom, _right, _bottom);
		board.DrawLine(_left, _top, _left, _bottom);
		board.DrawLine(_right, _top, _right, _bottom);
	}
private:
	int _left;
	int _top;
	int _right;
	int _bottom;
};

#endif // #ifndef _FIGUREMANAGER_H_
