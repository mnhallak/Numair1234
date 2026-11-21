#pragma once
#include<iostream>
#include<string>
using namespace std;
class AbstractClass
{

public:

	virtual void SendEmail(string title, string body) = 0;

};

