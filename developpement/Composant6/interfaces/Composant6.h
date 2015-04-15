#pragma once
#ifndef COMPOSANT6_H
#define COMPOSANT6_H

#ifdef COMPOSANT6_EXPORTS
	#define COMPOSANT6_INTERFACE __declspec(dllexport)
#else
	#define COMPOSANT6_INTERFACE __declspec(dllimport)
#endif

#include<vector>

// obtenir la version du dll
COMPOSANT6_INTERFACE char * getComposant6Version();
// obtenir le chemin genere
COMPOSANT6_INTERFACE std::vector<double> getChemin(int);
// obtenir la variable aleatoire N de moyenne 0 et variance 1
COMPOSANT6_INTERFACE std::vector<double> getN();
// obtenir la volatilite locale en t
COMPOSANT6_INTERFACE std::vector<double> getSigma();

#endif