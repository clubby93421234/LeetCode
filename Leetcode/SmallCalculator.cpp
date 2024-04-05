#include "SmallCalculator.h"
#include <iostream>

SmallCalculator::SmallCalculator(std::string s)
{
	int lastpos = 0;
	float _a=0;
	char _op;
	float _temp=0;
	bool grabnextnumber = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			
			_a= std::stof(s.substr(lastpos, i-1));
			lastpos = i + 1;
			_numbers.push(_a);
			_operators.push(MyOperatorconverter(s[i]));

			if (grabnextnumber) {
				MyOperator _temp = _operators.top();
				_operators.pop();

				float a = _numbers.top();
				_numbers.pop();
				float b = _numbers.top();
				_numbers.pop();

				MyOperator c = _operators.top();
				_operators.pop();

				_operators.push(_temp);

				float _result = MyCalc(a, b, c);
				_numbers.push(_result);

				grabnextnumber = false;
			}

			if (isDOT(MyOperatorconverter(s[i]))) {
				grabnextnumber = true;
			}
			
		}
	}
	_a = std::stof(s.substr(lastpos, s.size() ) );
	_numbers.push(_a);

	while (!_numbers.empty())
	{
		float a = _numbers.top();
		_numbers.pop();
		float b = _numbers.top();
		_numbers.pop();
		MyOperator c = _operators.top();
		_operators.pop();
		float res = MyCalc(b, a, c);
		std::cout << "stacks: = " << b << c << a << " = " << res << std::endl;
		_numbers.push(res);

	}
}

bool SmallCalculator::isDOT(MyOperator mo)
{
	switch (mo)
	{
	case PLUS:		
	case MINUS:
			return false;
		break;
	case MULTI:		
	case DIV:
			return true;
		break;
	default:
			return false;
		break;
	}
}

MyOperator SmallCalculator::MyOperatorconverter(char s)
{
	if(s=='+')
	return MyOperator::PLUS;
	if (s == '-')
		return MyOperator::MINUS;
	if (s == '*')
		return MyOperator::MULTI;
	if (s == '/')
		return MyOperator::DIV;
	return MyOperator::ERROR;
}

float SmallCalculator::MyCalc(float a, float b, MyOperator mp)
{
	switch (mp)
	{
	case PLUS:
			return a + b;
		break;
	case MINUS:
			return a - b;
		break;
	case MULTI:
			return a * b;
		break;
	case DIV:
			return a / b;
		break;
	default:
			return 0;
		break;
	}
}
