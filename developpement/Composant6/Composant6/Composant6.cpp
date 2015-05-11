#include "..\interfaces\Composant6.h"
#include "Composant6Version.h"
#include <math.h>


char * getComposant6Version()
{
	return "Composant 6 version " COMPOSANT_VERSION_STR;
}

// Debut : fonctions bidon
std::vector<double> getN(int jours)
{
	std::vector<double> N(jours);
	for(int i=0;i<jours;i++)
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

std::vector<double> getSigma(int jours)
{
	std::vector<double> sigma(jours);
	for(int i=0;i<jours;i++)
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

std::vector<double> getChemin(int taille, double spot)
{
	std::vector<double> S(taille + 1);
	/*
	std::vector<double> N(taille);
	std::vector<double> sigma(taille);
	*/
	S.at(0) = spot;
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
