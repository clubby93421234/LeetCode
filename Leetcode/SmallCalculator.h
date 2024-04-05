#pragma once
#include <string>
#include <stack>
enum MyOperator
{
	PLUS = 0,
	MINUS = 1,
	MULTI = 2,
	DIV = 3,
	ERROR=4
};

class SmallCalculator
{
public:
	SmallCalculator(std::string s);
private:
	std::stack<float> _numbers;
	std::stack<MyOperator> _operators;
	bool isDOT(MyOperator mo);
	MyOperator MyOperatorconverter(char s);
	float MyCalc(float a, float b, MyOperator mp);
};

