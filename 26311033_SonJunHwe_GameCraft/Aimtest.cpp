#include "Aimtest.h"
#include "Utility.h"
#include "glc2window.h"


Aimtest::Aimtest()
{
	SetConsole();

	window.Initialize();

	window.Run();

	window.Destroy();
}

int Aimtest::Main()
{
	window.Initialize();

	window.Run();

	window.Destroy();
	return SUCCESS;
}

Aimtest::~Aimtest()
{
}


