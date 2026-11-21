#include<iostream>
#include"clsMainScreen.h"
#include"clsLoginScreen.h"
using namespace std;

int main()
{
	while (true)
	{
		if (!clsLoginScreen::ShowLogin())
		{
			break;
		}
	}
	return 0;
}