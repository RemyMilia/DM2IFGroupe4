#include "..\interfaces\Composant3.h"
#define WINDOWS_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include <vector>

using std::vector;

int main()
{
	double result;

	result=composant6(2,5);

	std::cout << "Resultat appel composant6 " << result << std::endl;

	char * versionComposant=getComposant6Version();

	std::cout << "Version composant :" << versionComposant << std::endl;

	// TODO

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