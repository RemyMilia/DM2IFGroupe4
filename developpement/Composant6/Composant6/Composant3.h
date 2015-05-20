#pragma once
#ifndef COMPOSANT3_H
#define COMPOSANT3_H

#ifdef COMPOSANT3_EXPORTS
	#define COMPOSANT3_INTERFACE __declspec(dllexport)
#else
	#define COMPOSANT3_INTERFACE __declspec(dllimport)
#endif

#include <vector>

COMPOSANT3_INTERFACE double composant3(double p1, double p2);

COMPOSANT3_INTERFACE char * getComposant3Version();
// renvoie une valeur aleatoire entre 0 et 1
COMPOSANT3_INTERFACE double uniformRandom();
// permet d'initialiser la graine du GNA
COMPOSANT3_INTERFACE void initialize();
// renvoie une valeur suivant une loi normale (box-muller) ; prend en parametre la taille
COMPOSANT3_INTERFACE std::vector<double> normalRandom(int);

#endif