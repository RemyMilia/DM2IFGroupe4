// Composant6.cpp : définit les fonctions exportées pour l'application DLL.
//

#include "Composant3.h"
#include "Composant6.h"
#include "Composant6Version.h"
#include <math.h>
#include <cstdlib>
#include <ctime>

int T;
std::vector<double> *sigma ;
std::vector<double> N(T);

/*
double composant6(double p1, double p2)
{
	return pow(p1,p2);
}*/


char * getComposant6Version()
{

	return "Composant 6 version " COMPOSANT_VERSION_STR;
}



double getLocalVol(double strike, double maturity)

{
	return 0.3;
}



std::vector<double> getN(int taille)
{
	return N;
}

// obtenir la volatilite locale en t
std::vector<double> getSigma(int)
{
	return *sigma;
}


std::vector<double> getChemin(int jours, double spot)

{
	if (spot <0 )
	{
		throw "valeur neg : 0";
	}

	std::vector<double> v(jours+1);
	sigma = new std::vector<double>(jours);
	T = jours;
	N = normalRandom(jours);
	if( N.size() != jours )
	{ 
		throw "unvalid size : " + N.size();
	}

	v.at(0) = spot;

	for (int i = 1; i<=jours; i++){
		double x = v.at(i - 1);
		sigma->at(i-1)= getLocalVol( (v.at(i-1)/(double)100) ,T);
		v.at(i) = x*(1 + (*sigma)[i-1]*N[i-1] / sqrt(252.0));
		if (v.at(i-1) < 0)
		{
			throw "valeur_neg : " + (i-1);
		}
	}

	if (v.at(jours) < 0)
	{
		throw "valeur_neg : " + jours;
	}
	return v;
}





