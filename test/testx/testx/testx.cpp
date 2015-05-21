
#define WINDOWS_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include "..\interfaces\Composant6.h"

using std::vector;
bool hasCorrectInitialSpot(vector <double> S);
bool has505Values(vector<double> S);
bool hasNonNegativeValues(vector<double> S);
bool correctPath (vector<double> S, vector<double> N, vector<double> sigma);


int main()
{

	char * versionComposant=getComposant6Version();

	std::cout << "Version composant :" << versionComposant << std::endl;

	try
	{
		std::cout << "Test Spot de depart = 100 : ";
		if ( hasCorrectInitialSpot(getChemin(504,100)) )
		{
			std::cout << "OK ! " << std::endl;
		} else 
		{
			std::cout << "KO ! " << std::endl;
		}
		std::cout << "Test 505 valeurs : ";
		if ( has505Values(getChemin(504,100)) )
		{
			std::cout << "OK ! " << std::endl;
		} else 
		{
			std::cout << "KO ! " << std::endl;
		}
		std::cout << "Test valeurs non negatives : ";
		if ( hasNonNegativeValues(getChemin(504,100)) )
		{
			std::cout << "OK ! " << std::endl;
		} else 
		{
			std::cout << "KO ! " << std::endl;
		}
		std::cout << "Test de la bonne construction du chemin : ";
		vector<double> Scalc = getChemin(504,100);
		vector<double> N = getN(504);
		vector<double> sigma = getSigma(504);

		if ( correctPath(Scalc,N,sigma) )
		{
			std::cout << "OK ! " << std::endl;
		} else 
		{
			std::cout << "KO ! " << std::endl;
		}
	}
	catch ( const char * Msg ) 
	{
		std::cerr << std::endl;
		std::cerr << "erreur : ";
		std::cerr << Msg; 
	}

	Sleep(3000);
}

bool hasCorrectInitialSpot(vector<double> S)
{
	return S.at(0) == 100 ? true : false;
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

bool correctPath(vector<double> S, vector<double> N, vector<double> sigma)
{
	vector<double> Scalc(505);

	Scalc.at(0)=100;

	for(int i=1;i<N.size();i++)
	{
		Scalc.at(i) = Scalc.at(i-1) * (1. + (sigma.at(i-1) / sqrt(252.)) * N.at(i-1) );
		if ( (1./100.)*floor(Scalc.at(i) * 100) != (1./100.)*floor(S.at(i) * 100) )
		{
			std::cout << "i : " << i << std::endl;
			std::cout << "Scalc : " << Scalc.at(i) << std::endl;
			std::cout << "S : " << S.at(i) << std::endl;
			return false;
		}
	}
	return true;
}
