# CPP2018_lab5@12.06
## ��װһ�δ���
ͨ����װ�������Ӵ���Ŀ���չ�ԣ�origin����Ҫ����else if�������µĹ��ܣ�
�ع�֮��ֻ��Ҫ�����µ�Strategy���ɣ�ͬʱ���԰Ѳ�ͬ��Derived����ͬ��������������
Ҳ��ֹ�˹����if else���׵��µĴ���
### strategyģʽ
```cpp
// origin
class Client {
	int _mode;
public:
	void switch_mode(int mode){
		_mode = mode;
	}
	void func()
	{
		if (_mode)
		{
			do(A)
		} 
		else
		{
			do(B)
		}
	}
}
// after
class Strategy
{
public:
	virtual void function() = 0;
};

class StrategyA : public Strategy
{
public:
	virtual void function() {
		cout << "true" << endl;
	}
};

class StrategyB : public Strategy
{
	virtual void function() {
		cout << "false" << endl;
	}
};

class Client {
	Strategy* _strategy;
public:
	void switch_mode(Strategy* strategy) {
		_strategy = strategy;
	}
	void func() {
		_strategy->function();
	}
};

//Before
Client client;
client.switch_mode(true);
Client.func();
//After
StrategyA str1;
StrategyB str2;
Client client;
client.switch_mode(&str1);
client.func();
```
![��ͼ](https://i.loli.net/2018/12/06/5c0908434b2bd.png)
### �㷨(Alg)ģʽ
```cpp
class Strategy
{
public:
	virtual void function() = 0;
	virtual stage1() = 0;
	virtual stage2() = 0;
	//...
};
```
### ������ģʽ
��Circle��TextView
```cpp
class TextView
{
public:
	TextView(Circle* circle) : _circle(circle) { }
	void display();
private:
	Circle* _circle;
};

class Circle
{
public:
	Circle() : _x(0), _r(0) { }
	void set_x(int x)
	{
		_x = x;
		_tv->display();
	}
	void set_r(int r)
	{
		_r = r;
		_tv->display();
	}
	int get_x() { return _x; }
	int get_r() { return _r; }
	void bind_view(TextView* tv) { _tv = tv; }
private:
	int _x, _r;
	TextView* _tv;
};

void TextView::display()
{
	cout << _circle->get_x() << _circle->get_r() << endl;
}
```