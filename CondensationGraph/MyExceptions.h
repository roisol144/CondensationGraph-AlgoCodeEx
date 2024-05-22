#pragma once
#include "MyExceptions.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


class MyExceptions{
public:
	virtual ~MyExceptions() = default; 
};

class ValueNotSupportedException : public MyExceptions {};

class OutOfBoundsException : public ValueNotSupportedException
{};

class WrongTypeException : public ValueNotSupportedException
{};


