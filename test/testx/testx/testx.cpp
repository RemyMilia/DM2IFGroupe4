#include "..\interfaces\Composant6.h"
#define WINDOWS_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include <vector>
#include <math.h>

using std::vector;
bool hasCorrectInitialSpot(vector <double> S);
bool has505Values(vector<double> S);
bool hasNonNegativeValues(vector<double> S);
bool isLogNormal(vector<double> S, double epsilon);

int main()
{

	char * versionComposant=getComposant6Version();

	std::cout << "Version composant :" << versionComposant << std::endl;

	try
	{
		std::cout << "Test Spot de depart = 100 : ";
		if ( hasCorrectInitialSpot(getChemin()) )
		{
			std::cout << "OK ! " << std::endl;
		} else 
		{
			std::cout << "KO ! " << std::endl;
		}
		std::cout << "Test 505 valeurs : ";
		if ( has505Values(getChemin()) )
		{
			std::cout << "OK ! " << std::endl;
		} else 
		{
			std::cout << "KO ! " << std::endl;
		}
		std::cout << "Test valeurs non negatives : ";
		if ( hasNonNegativeValues(getChemin()) )
		{
			std::cout << "OK ! " << std::endl;
		} else 
		{
			std::cout << "KO ! " << std::endl;
		}
		std::cout << "Test de l'hypothese log-normale : ";
		if ( isLogNormal(getChemin(),1.0) )
		{
			std::cout << "OK ! " << std::endl;
		} else 
		{
			std::cout << "KO ! " << std::endl;
		}
	}
	catch ( const char * Msg ) 
	{ 
		std::cerr << Msg; 
	}

	Sleep(3000);
}

bool hasCorrectInitialSpot(vector<double> S)
{
	return S[0] == 100 ? true : false;
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
			return false;
	}
	return true;
}

bool isLogNormal(vector<double> S, double epsilon)
{
	vector<double> sigma = getSigma();
	for(unsigned i=0;i<S.size()-1;i++)
	{
		double N = (S[i+1]-S[i]) / ( (double) ( sigma[i]/(double)sqrt(252.0) ));
		if( ( (N-1) >= epsilon ) || ( (N-1) <= -epsilon ) )
		{
			return false;
		}
	}
	return true;
}

