#include "..\interfaces\Composant3.h"
#define WINDOWS_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include <vector>

using std::vector;

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

bool has505Values(vector<double> S)
{
	return S.size() == 505 ? true : false;
}

bool hasNonNegativeValues(vector<double> S)
{
	for (unsigned i=0; i<S.size(); i++)
	{
		if (S[i] < 0.0)
			return true;
	}
	return false;
}