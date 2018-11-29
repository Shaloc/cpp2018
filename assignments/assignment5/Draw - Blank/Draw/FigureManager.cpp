#include "stdafx.h" 

#include "FigureManager.h"
#include "BlackBoard.h"

using std::cout; 

void FigureManager::input(std::istream &is)
{
    // 1����ӡ�˵������û�ѡ������ͼ��
	// �˵���ʽΪ
	// input type(1 : Circle, 2 : Line, 3 : Rectangle, 0 : Quit)

	// ���벻Ҫ��std::cin
	// �ñ��������������is���÷�ͬcin

	// 2���û���������(1/2/3/0)ѡ��󣬸��ݲ�ͬ��ͼ�Σ���ʾ����ͼ�εĲ���
	// ����Բ�Ĳ�������ΪԲ��x��y���뾶����˰�����ʾ����������������½��

#if 0
	std::cout << "Center X: "; 
	is >> _x; 

	std::cout << "Center Y: "; 
	is >> _y; 

	std::cout << "Radius: "; 
	is >> _radius;  
#endif

	// �߲���Ϊ�˵�1 X��Y���꣬�˵�2 X���ꡢY���ꡣ
#if 0
	std::cout << "X1: "; 
	is >> _x1; 
	std::cout << "Y1: "; 
	is >> _y1; 

	std::cout << "X2: "; 
	is >> _x2; 
	std::cout << "Y2: "; 
	is >> _y2; 
#endif

	// ���β���Ϊ���϶���x��y�����¶���x��y
#if 0
	std::cout << "Left: "; 
	is >> _left; 
	std::cout << "Top: "; 
	is >> _top; 

	std::cout << "Right: "; 
	is >> _right; 
	std::cout << "Bottom: "; 
	is >> _bottom; 
#endif

	// 3������ò����󣬽�ͼ�α�������������֮�����

	// 4���ص�1��������ӡ�˵���ֱ���û�ѡ��0���˳�input����


}

void FigureManager::display(BlackBoard &board)
{
	// ������input�������ͼ�����������λ���
    

	// ����board�ṩ��DrawCircle��DrawLine������ͼ����������һ��Բ����30,30λ�ã��뾶Ϊ100��Բ
	board.DrawCircle(30, 30, 100); 

	// �پ����������Σ��þ������Ͻ�Ϊ(30, 20)�����½�Ϊ��200,300��
	board.DrawLine(30, 20, 30, 300); 
	board.DrawLine(30, 300, 200, 300); 
	board.DrawLine(200, 300, 200, 20); 
	board.DrawLine(200, 20, 30, 20); 
}

// ������ʵ����ҪһЩ��Ҫ�ĳ�ʼ�����ɷ�����������У�main���������
// ���û�У������
void InitiateFigureManager()
{

}


