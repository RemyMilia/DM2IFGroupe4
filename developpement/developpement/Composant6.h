#pragma once
#ifndef COMPOSANT6_H
#define COMPOSANT6_H

#ifdef COMPOSANT0_EXPORTS
	#define COMPOSANT6_INTERFACE __declspec(dllexport)
#else
	#define COMPOSANT6_INTERFACE __declspec(dllimport)
#endif

COMPOSANT6_INTERFACE char * getComposant0Version();

COMPOSANT6_INTERFACE vector<double> getChemin();

#endif