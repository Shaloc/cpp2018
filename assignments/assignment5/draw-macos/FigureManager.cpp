
#include "FigureManager.h"
#include "BlackBoard.h"

using std::cout; 
using std::endl;

void FigureManager::input(std::istream &is)
{
	// �߲���Ϊ�˵�1 X��Y���꣬�˵�2 X���ꡢY����
	// ���β���Ϊ���϶���x��y�����¶���x��y
	// 3������ò����󣬽�ͼ�α�������������֮�����
	// 4���ص�1��������ӡ�˵���ֱ���û�ѡ��0���˳�input����
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
		case 1: // Բ
			figure = new Circle;
			break;
		case 2: // ��
			figure = new Line;
			break;
		case 3: // ����
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
	// ����figure�е�ÿһ��
    for ( auto figure : _figures ) //��ҪC++11���ϲ�����ȷ�������У�Ŀǰ���µ�C++��׼ΪC++17
    {
		figure->display(board);
    }
	return;
}

FigureManager::~FigureManager()
{
	// ����ʹ��auto������ʽ��ָ�����ľ�����������ֹ����
	for ( auto iter = _figures.begin(); iter != _figures.end(); ++iter )
	{
		delete *iter;
	}
}

// ������ʵ����ҪһЩ��Ҫ�ĳ�ʼ�����ɷ�����������У�main���������
// ���û�У������
void InitiateFigureManager()
{

}


