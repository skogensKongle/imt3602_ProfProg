#if !defined(MEDALJER_H)
#define MEDALJER_H
#include "const.h"
#include "statistikk.h"
#include "enum.h"
#include <fstream>
#include <cstring>



struct Medaljene
{
	int gull;
	int solv;
	int bronsje;
};


class Medaljer : public Statistikk
{
private:
	Medaljene medaljer[STRLEN];
public:
	Medaljer() {};
	void display();
	int nyNasjon(char* forkortelse);
	void oppdater(char* nasjon, Medaljetype medaljetype, bool fjern);
	void sorterElementer(int start, int slutt);
	void skrivTilFil();
	void lesFraFil();
	bool venstreVidere(Medaljene medalje, Medaljene pivot);
	bool hoyreVidere(Medaljene medalje, Medaljene pivot);
};

#endif 