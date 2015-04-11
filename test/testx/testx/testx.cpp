#include "..\interfaces\Composant3.h"
#define WINDOWS_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>


int main()
{
	double result;

	result=composant3(2,5);

	std::cout << "Resultat appel composant0 " << result << std::endl;

	char * versionComposant=getComposant3Version();

	std::cout << "Version composant :" << versionComposant << std::endl;

	std::cout << "Nombre aleatoire :" << uniformRandom() << std::endl;

	Sleep(3000);
}
