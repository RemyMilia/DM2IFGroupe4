#define WINDOWS_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include "Composant3.h"


int main()
{
	double result;

	result=composant3(2,5);

	std::cout << "Resultat appel composant0 " << result << std::endl;

	char * versionComposant=getComposant3Version();

	std::cout << "Version composant :" << versionComposant << std::endl;

	Sleep(3000);
}