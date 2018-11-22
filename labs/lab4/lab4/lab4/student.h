#pragma once

#include "person.h"

class Member
{
public:
	Member() {
		cout << "Member::Member()" << endl;
	}
	~Member() {
		cout << "Member::~Member()" << endl;
	}
private:

};

class Student : public Person
{
public:
	Student(const string& name, int age) : Person(name, age), _member()
	{
		cout << "Student::Student(const string& name, int age)" << endl;
	}
	Student(const Student& rhs) : Person(rhs), _member(rhs._member) { }//¿½±´¹¹Ôìº¯Êý
	Student& operator=(const Student& rhs) {
		if (&rhs == this) return *this;
		this->Person::operator=(rhs);
		_member = rhs._member;
		return *this;
	}
	~Student() {
		cout << "Student::~Student()" << endl;
	}
private:
	Member _member;
};