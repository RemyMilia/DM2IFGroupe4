// Composant6.cpp : définit les fonctions exportées pour l'application DLL.
//

#include "Composant3.h"
#include "Composant6.h"
#include "Composant6Version.h"
#include <math.h>
#include <cstdlib>
#include <ctime>


int T;
std::vector<double> sigma(T) ;
std::vector<double> N(T);

/*
double composant6(double p1, double p2)
{
	return pow(p1,p2);
}*/


char * getComposant6Version()
{

	return "Composant 6 version " ;
}



double getLocalVol(double strike, double maturity)

{

	return 3.0;
}



std::vector<double> getN(int taille)
{
	return N;
}

// obtenir la volatilite locale en t
std::vector<double> getSigma(int)
{
	return sigma;
}


std::vector<double> getChemin(int jours, double spot)

{
	std::vector<double> v(505);
	T = jours;
	N = normalRandom(jours);

	v.at(0) = spot;

	for (int i = 1; i<=jours; i++){
		double x = v.at(i - 1);
		sigma.at(i)= getLocalVol(v.at(i-1),T);
		v.at(i) = x*(1 + sigma[i]*N[i] / sqrt(252.0));
	}
	return v;
}





