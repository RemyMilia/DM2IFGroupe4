#include "..\interfaces\Composant3.h"
#include "Composant3Version.h"
#include <math.h>
#include <cstdlib>
#include <ctime>


double composant3(double p1, double p2)
{
	return pow(p1,p2);
}


char * getComposant3Version()
{
	return "Composant 3 version " COMPOSANT_VERSION_STR;
}

double uniformRandom()
{
	return ((double)(rand()) + 1. )/( (double)(RAND_MAX) + 1.);
}

void initialize()
{
	srand(std::time(0));
}

std::vector<double> normalRandom(int taille)
{	
	std::vector<double> N;
	for(int i=0;i<taille;i++)
	{
		double u1=uniformRandom();
		double u2=uniformRandom();
		N.push_back(cos(8.*atan(1.)*u2)*sqrt(-2.*log(u1)));
	}
	return N;
}