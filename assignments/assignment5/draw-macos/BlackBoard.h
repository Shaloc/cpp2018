#ifndef _BLACK_BOARD_H_
#define _BLACK_BOARD_H_

#include "GL/freeglut.h"

typedef void (*CallbackFunction)(); 
typedef void (*KeyboardFunction)(unsigned char key, int x, int y);
typedef void (*ReshapeFunction)(int width, int height); 
typedef void (*MouseButtonFunction)(int button, int state, int x, int y); 
typedef void (*MouseMotionFunction)(int x, int y); 
typedef void (*IdleFunction)(void); 
typedef void (*TimerFunction)(int value); 


class BlackBoard
{
public:

public:
	void InitCommandLine(int *argc, char **argv); 
	void InitWindowSize(int width, int height); 
	void UpdateWindowSize(int width, int height); 

	// ���ô��ڻ��ƻص�����
	void InitDisplayCallback(CallbackFunction callback); 
	
	// ���ü����¼��ص�����
	void InitKeyboardCallback(KeyboardFunction callback);
	
	// ���ô��������¼��ص�����
	void InitReshapeCallback(ReshapeFunction callback);
	
	// ����������¼��ص�����
	void InitMouseButtonCallback(MouseButtonFunction callback);
	
	// ��������ƶ��¼��ص�����
	void InitMouseMotionCallback(MouseMotionFunction callback);
	
	// ���ÿ���״̬�ص�����
	void InitIdleCallback(IdleFunction callback);

	// ����һ����ʱ����ע�⣬ֻ�ᴥ��һ�Σ��������ڴ���
	// ��Ҫ���ڴ������ڻص������У��ٴ�����һ��ͬ���Ķ�ʱ��
	void InstallTimerCallback(unsigned int millis, TimerFunction callback, int value);



	// ��������ʾ���ڣ�������һ�Σ�֮�󣬽������¼�ѭ��
	void Show(); 



	// ��־������Ҫ���£�ͨ�������ݷ����仯����������Ҫ�󴰿��ػ�
	void Update(); 


	// ���º���ֻ���ڻ��ƻص������У�ͨ��ʱ���������Update��ϵͳ����Update-> �����ػ棨�¼�ѭ�����û��ƻص������� -> �����º�������ͼ��

	// ������ɫ��r/g/bΪ��ɫ������0-1֮�䣬
	// �紿��Ϊ1,0,0;
	// ����Ϊ1,1,1
	void SetColor(double r, double g, double b); 
	// ����
	void Clear(); 
	// ������ͼ����ʾ����
	void Flush(); 

	// ���ߣ�����Ϊ�����˵��x��y����
	void DrawLine(int x1, int y1, int x2, int y2);

	// ��Բ������ΪԲԲ��x��y���뾶
	void DrawCircle(int x, int y, int r); 


private:
	int _width, _height; 
}; 









#endif // ifndef _BLACK_BOARD_H_
