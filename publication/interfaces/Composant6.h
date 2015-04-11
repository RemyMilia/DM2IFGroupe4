#pragma once
#ifndef COMPOSANT6_H
#define COMPOSANT6_H

#ifdef COMPOSANT6_EXPORTS
	#define COMPOSANT6_INTERFACE __declspec(dllexport)
#else
	#define COMPOSANT6_INTERFACE __declspec(dllimport)
#endif

COMPOSANT6_INTERFACE char * getComposant6Version();

COMPOSANT6_INTERFACE vector<double> getChemin();

#endif