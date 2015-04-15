#include "..\interfaces\Composant6.h"
#include "Composant6Version.h"
#include <math.h>


char * getComposant6Version()
{
	return "Composant 6 version " COMPOSANT_VERSION_STR;
}

// Debut : fonctions bidon
std::vector<double> getN()
{
	std::vector<double> N(504);
	for(int i=0;i<504;i++)
	{
		if(i%2 == 0)
		{
			N.at(i) =0;
		} else {
			N.at(i) = 0.5;
		}
	}

	return N;
}

std::vector<double> getSigma()
{
	std::vector<double> sigma(504);
	for(int i=0;i<504;i++)
	{
		if(i%2 == 0)
		{
			sigma.at(i) =0;
		} else {
			sigma.at(i) = 0.5;
		}
	}

	return sigma;
}

std::vector<double> getChemin(int taille)
{
	std::vector<double> S(505);
	std::vector<double> N(504);
	std::vector<double> sigma(504);
	S.at(0) = 100.0;
	for(int i=1;i<=taille;i++)
	{
		if(i%2==1)
		{
			S.at(i) = S.at(i-1) * (1. + (0. * 0.) / sqrt(252.));
		} else {
			S.at(i) = S.at(i-1) * (1. + (0.5  / sqrt(252.)) *0.5);
		}
	}
	return S;
}
