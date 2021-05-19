#pragma once
#include <iostream>
using namespace std;
template <class T>
bool negativeNumber(T number)
{
	return (number < 0);
}
/*Sort template by salary*/
template <typename T> bool PComp(const T * const & a, const T * const & b)
{
	return *a < *b;
}