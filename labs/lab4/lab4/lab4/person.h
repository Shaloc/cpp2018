#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	Person(const string& name, int age) : _name(name), _age(age) { 
		cout << "Person::Person(const string& name, int age)" << endl;
	}
	Person(const Person& rhs) : _name(rhs._name), _age(rhs._age) { }
	~Person() { 
		cout << "Person::~Person()" << endl;
	}
	Person& operator=(const Person& rhs) {
		if (&rhs == this) return *this;
		_name = rhs._name;
		_age = rhs._age;
		return *this;
	}
	void say_hello(void) {
		cout << "Hi, i am " << _name << endl;
	}
private:
	string _name;
	int _age;
};