#ifdef _MSC_VER						//S� vi kan kj�re med strcpy
#define _CRT_SECURE_NO_WARNINGS
#endif


#include "medaljer.h"


void Medaljer::display()
{
	if (antallNasjoner > 0)
	{
		std::cout << "\n\n\t++Medaljeoversikt++" << std::endl;

		for (int i = 0; i < antallNasjoner; i++)
		{
			printf("\nNasjon: %s har %d gull, %d solv og %d bronsjemedaljer",
				nasjon[i], medaljer[i].gull, medaljer[i].solv, medaljer[i].bronsje);
		}
		std::cout << std::endl;
	}
	else
		std::cout << "\nIngen medaljer registrert" << std::endl;
}

void Medaljer::oppdater(char* nasjon, Medaljetype medaljetype, bool fjern)		//oppdaterer medaljer
{
	int nr = nyNasjon(nasjon);		//lager ny om ikke funnet, returnerer plass i array

	if (fjern)
	{
		switch (medaljetype)				//trekker fra medalje
		{
		case GULL: medaljer[nr].gull--; break;
		case SOLV: medaljer[nr].solv--; break;
		case BRONSJE: medaljer[nr].bronsje--; break;
		}
	}
	else
	{
		switch (medaljetype)				//legger til medalje
		{
		case GULL: medaljer[nr].gull++; break;
		case SOLV: medaljer[nr].solv++; break;
		case BRONSJE: medaljer[nr].bronsje++; break;
		}

		
	}
	sorterElementer(0, antallNasjoner - 1);			//sorterer det oppdaterte elementet p� plass med tilh�rende medaljeklasse
	skrivTilFil();
}

void Medaljer::sorterElementer(int start, int slutt)				//sorterer medaljene med quicksort
{
	char nasjonTemp[NASJONID];	
	Medaljene medaljeTemp;

	int pivot, j, i;

	if (start < slutt)				//g�r gjennom hele arrayen
	{
		pivot = start;					//setter pviot lik start (objektet de to tellerne som kommer fra h�yre og venstre vil bli sammenliknet med)
		i = start; j = slutt;				//venstre teller er i, h�yre teller er j

		while (i < j)			//s� lenge tellerne ikke krysser hverandre
		{

			while (venstreVidere(medaljer[i], medaljer[pivot]) && (i < slutt))		
				i++;			//om venstre kan g� videre og det ikke er slutt p� arrayen g�r den ett steg til h�yre

			while (hoyreVidere(medaljer[j], medaljer[pivot]))
				j--;			//om h�yre kan g� videre g�r den ett steg til venstre

			if (i < j)		//om de enda ikke har krysset
			{
				medaljeTemp = medaljer[i];			//bytter plass p� elem nr. i og elem nr. j
				strcpy(nasjonTemp, nasjon[i]);

				medaljer[i] = medaljer[j];
				strcpy(nasjon[i], nasjon[j]);

				medaljer[j] = medaljeTemp;
				strcpy(nasjon[j], nasjonTemp);
			}
		}

		strcpy(nasjonTemp, nasjon[pivot]);		//da tellerne har krysset
		medaljeTemp = medaljer[pivot];			//bytter plass p� pivot og j

		medaljer[pivot] = medaljer[j];
		strcpy(nasjon[pivot], nasjon[j]);

		medaljer[j] = medaljeTemp;
		strcpy(nasjon[j], nasjonTemp);

		sorterElementer(start, j - 1);		//deler arrayen i to og kaller rekursivt p� seg selv
		sorterElementer(j + 1, slutt);

														//da sorteringen er ferdig
		
		i = 0; j = antallNasjoner - 1;			//inverterer vi til synkende rekkef�lge
		while (i < j)
		{
			medaljeTemp = medaljer[i];
			strcpy(nasjonTemp, nasjon[i]);

			medaljer[i] = medaljer[j];
			strcpy(nasjon[i], nasjon[j]);

			medaljer[j] = medaljeTemp;
			strcpy(nasjon[j], nasjonTemp);
			i++; j--;
		}
	}
}

void Medaljer::skrivTilFil()			//skriver medaljer til fil
{
	std::ofstream medaljefil("medaljer.dta");

	medaljefil << antallNasjoner << std::endl;
	for (int i = 0; i < antallNasjoner; i++)
	{
		medaljefil << nasjon[i] << std::endl;
		medaljefil << medaljer[i].gull << " " << medaljer[i].solv << " " << medaljer[i].bronsje << std::endl;
	}
}


int Medaljer::nyNasjon(char* forkortelse)		//legger inn ny nasjonsforkortelse og returnerer posisjon i array
{

	for (int i = 0; i < antallNasjoner; i++)
	{
		if (strcmp(forkortelse, nasjon[i]) == 0)			//om den finner nasjonen fra f�r
			return i;													// returnerer posisjon p� eksisterende objekt

	}
	nasjon[antallNasjoner] = new char[NASJONID];		//om den ikke ble funnet lager vi en ny entry i array
	strcpy(this->nasjon[antallNasjoner], forkortelse);

	medaljer[antallNasjoner].gull = 0;				//initialiserer verdier
	medaljer[antallNasjoner].solv = 0;
	medaljer[antallNasjoner].bronsje = 0;
	antallNasjoner++;					//og �ker antall nasjoner

	return (antallNasjoner - 1);		//returnerer nummer i array p� nyopprettet nasjon
}


void Medaljer::lesFraFil()			//leser medaljer fra fil
{
	std::ifstream medaljefil("medaljer.dta");
	char navn[NASJONID];
	int nNasjoner;

	if (!medaljefil)
		std::cout << "\n\tmedaljer.dta ikke funnet";
	
	else
	{
		std::cout << "\n\tmedaljer.dta laster inn ";
		medaljefil >> nNasjoner; medaljefil.ignore();	//henter antall nasjoner

		for (int i = 0; i < nNasjoner; i++)	//g�r gjennom alle nasjoner om den fant fil
		{
			std::cout << ".";					//sier ifra at den laster inn
			medaljefil.getline(navn, NASJONID);
			int n = nyNasjon(navn);		//henter nasjonsforkortelses plass i array

			medaljefil >> medaljer[n].gull;		//skriver verdiene til nasjonen i samme plass
			medaljefil >> medaljer[n].solv;
			medaljefil >> medaljer[n].bronsje; medaljefil.ignore();
		}

		sorterElementer(0, antallNasjoner - 1);			//sorterer de nye elementene i synkende rekkef�lge
	}
}

bool Medaljer::venstreVidere(Medaljene medalje, Medaljene pivot)	//sjekker om venstre pointer kan g� videre
{																										// venstre pointer g�r videre om den har lik eller mindre verdi
	if (medalje.gull < pivot.gull) return true;		//g�r videre om den har f�rre gull enn neste
	else if (medalje.gull == pivot.gull)		
	{
		if (medalje.solv < pivot.solv) return true;	//om gull er likt men s�lv f�rre
		else if (medalje.solv == pivot.solv)
		{
			if (medalje.bronsje <= pivot.bronsje) return true;	//og om gull, s�lv er likt, men bronsje er likt eller mindre
		}
	}
	return false;
}

bool Medaljer::hoyreVidere(Medaljene medalje, Medaljene pivot)	//sjekker om h�yre pointer kan g� videre
{																									//venstre pointer g�r videre s� lenge den har mer
	if (medalje.gull > pivot.gull) return true;			//g�r videre om mer gull
	else if (medalje.gull == pivot.gull)
	{
		if (medalje.solv > pivot.solv) return true;		//g�r videre om likt gull og mer s�lv
		else if (medalje.solv == pivot.solv)
		{
			if (medalje.bronsje > pivot.bronsje) return true;		//g�r videre om likt gull, s�lv og mer bronsje 
		}
	}
	return false;
}