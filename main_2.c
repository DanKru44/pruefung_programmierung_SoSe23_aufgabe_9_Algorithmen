#include <stdio.h>
#include <stdbool.h>

#define MAX_SAMPLES 3000
#define SAMPLINGRATE 89800

void einlesen_daten ( FILE* datei_ed , int samples_und_spannungen_ed [ ] [ 2 ] )
{	
	int anzahl_samples = 0 ;
	int sample_nummer = 0 ;
	int spannung = 0 ;

	while ( fscanf ( datei_ed , "%d,%d" , &sample_nummer , &spannung ) == 2 && anzahl_samples < MAX_SAMPLES )
	{
		samples_und_spannungen_ed [ anzahl_samples ] [ 0 ] = sample_nummer ;
		samples_und_spannungen_ed [ anzahl_samples ] [ 1 ] = spannung ;
		anzahl_samples ++ ;
	}
}


void suche_erstes_minima ( int samples_und_spannungen_sem [ ] [ 2 ] , int* sample_minima_1 , int* index_minima_1 )
{
	int spannung_minima_1 = samples_und_spannungen_sem [ 0 ] [ 1 ] ;
	*sample_minima_1 = samples_und_spannungen_sem [ 0 ] [ 0 ] ;
    *index_minima_1 = 0 ;
	for ( int i = 0 ; i < MAX_SAMPLES ; i++ )
	{
		if ( samples_und_spannungen_sem [ i ] [ 1 ] < spannung_minima_1 )
		{
			spannung_minima_1 = samples_und_spannungen_sem [ i ] [ 1 ] ;
			*sample_minima_1 = samples_und_spannungen_sem [ i ] [ 0 ] ;
			*index_minima_1 = i ;
		}
	}
}


int suche_zweites_minima ( int samples_und_spannungen_szm [ ] [ 2 ] , int start_index )
{
	int spannung_minimum_2 = samples_und_spannungen_szm [ start_index ] [ 1 ] ;
	int sample_minimum_2 = samples_und_spannungen_szm [ start_index ] [ 0 ] ;
	int schwellenwert = 2 ;
	bool aufstieg = false ;

	for ( int i = start_index ; i < MAX_SAMPLES ; i++ ) 
	{
		 if ( !aufstieg && samples_und_spannungen_szm [ i ] [ 1 ] >= spannung_minimum_2 + schwellenwert)
		{
			aufstieg = true ;
			spannung_minimum_2 = samples_und_spannungen_szm [ i ] [ 1 ]  ;
		}

		 if ( aufstieg && samples_und_spannungen_szm [ i ] [ 1 ] < spannung_minimum_2 )
		{
			spannung_minimum_2 = samples_und_spannungen_szm [ i ] [ 1 ] ;
			sample_minimum_2 = samples_und_spannungen_szm [ i ] [ 0 ] ;
		}
	}
		
	return sample_minimum_2 ;
}


int main ( int argc , char* argv [ ] )
{
	char* dateiname = argv [ 1 ] ;
	int samples_und_spannungen [ MAX_SAMPLES ] [ 2 ] ;
	char buffer_erste_zeile [ 256 ] ;
	int erstes_minima = 0 ;
	int erstes_minima_index = 0 ;
	int zweites_minima = 0 ;
	float frequenz = 0 ;

	FILE* datei = fopen ( dateiname , "r" ) ;
	if ( datei == NULL )
	{
		printf ( "Fehler beim öffnen der Datei!\n" ) ;
		return 1 ;
	}

	fgets ( buffer_erste_zeile , sizeof ( buffer_erste_zeile ) , datei ) ;

	einlesen_daten ( datei , samples_und_spannungen ) ;

	fclose ( datei ) ;

	suche_erstes_minima ( samples_und_spannungen , &erstes_minima , &erstes_minima_index ) ;
	zweites_minima = suche_zweites_minima ( samples_und_spannungen , erstes_minima_index ) ;

	frequenz = SAMPLINGRATE / ( zweites_minima - erstes_minima ) ;

	printf ( "Die Frequenz beträgt: %.2f Hz\n" , frequenz ) ;

	return 0 ;
}
