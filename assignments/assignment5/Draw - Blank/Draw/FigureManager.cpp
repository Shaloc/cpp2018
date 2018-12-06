#include "stdafx.h" 

#include "FigureManager.h"
#include "BlackBoard.h"

using std::cout; 
using std::endl;

void FigureManager::input(std::istream &is)
{
	// 线参数为端点1 X、Y坐标，端点2 X坐标、Y坐标
	// 矩形参数为左上顶点x、y，右下顶点x、y
	// 3，输入好参数后，将图形保存下来，用于之后绘制
	// 4，回到1，继续打印菜单，直到用户选择0，退出input函数
	int type = 0;
	_figures.clear();

	while ( true )
	{
		Figure *figure = NULL;
		cout << "input type(1 : Circle, 2 : Line, 3 : Rectangle, 0 : Quit)" << endl;
		is >> type;
		switch (type)
		{
		default: case 0:
			return;
		case 1: // 圆
			figure = new Circle;
			break;
		case 2: // 线
			figure = new Line;
			break;
		case 3: // 矩形
			figure = new Rectangle;
			break;
		}
		figure->input(is);
		_figures.push_back(figure);
	}
	return;
}


void FigureManager::display(BlackBoard &board)
{
	// 对于figure中的每一项
    for ( auto figure : _figures ) //需要C++11以上才能正确编译运行，目前最新的C++标准为C++17
    {
		figure->display(board);
    }
	return;
}

FigureManager::~FigureManager()
{
	// 尽量使用auto而不显式地指出它的具体类型来防止错误
	for ( auto iter = _figures.begin(); iter != _figures.end(); ++iter )
	{
		delete *iter;
	}
}

// 如果你的实现需要一些必要的初始化，可放在这个函数中，main函数会调用
// 如果没有，则忽略
void InitiateFigureManager()
{

}


