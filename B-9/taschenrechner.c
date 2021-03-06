/*********************************/
/* Benedikt Abel, Justus Faust   */
/* Gruppe: Do08                  */
/* Uebungsblatt: 4, Aufgabe: B-8 */
/* Thema: Flowchart              */
/* Version: v1.0.0               */
/* Datum: 20160509               */
/* Status: WIP                   */
/*********************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // status: 0 = Programmbeginn/1. Wert abfragen; 1 = 2. Wert abfragen; 2 = Operation eingeben; 3 = Berechnung abgeschlossen; 4 = Berechnung abgeschlossen (nach division durch 0)
    int status = 0, operation = 0, aktion = 0;
    float wert1 = 0, wert2 = 0, ergebnis = 0;
    while (status != -1)
    {
	switch (status)
	{
	    // Einlesen der Werte und abspeichern in wert1, wert2
	    case 0:
	    {
		printf("Bitte den ersten Wert eingeben:\n");
		scanf("%f",&wert1);
		status = 1;
		break;
	    }
	    case 1:
	    {
		printf("Bitte den zweiten Wert eingeben:\n");
                scanf("%f",&wert2);
                status = 2;
                break;
	    }
	    case 2:
	    {
		printf("Die eingegebenen Werte sind %f und %f.\nBitte Rechenoperation auswählen (1 +; 2 -; 3 *; 4 /; 5 Eingabe korrigieren)", wert1, wert2);
		scanf("%i", &operation);
		// Operationen: 1 = +; 2 = -; 3 = *; 4 = /; 5 = Werte neu eingeben
		switch (operation)
		{
		    // 1-3 können ohne weiteres einfach berechnet werden
		    case 1:
		    {
			ergebnis = wert1 + wert2;
			printf("Die Gewählte Operation ist die Addition. %f + %f = %f\n", wert1, wert2, ergebnis);
			status = 3;
			break;
		    }
		    case 2:
		    {
			ergebnis = wert1 - wert2;
                        printf("Die Gewählte Operation ist die Subtraktion. %f - %f = %f\n", wert1, wert2, ergebnis);
                        status = 3;
                        break;
		    }
		    case 3:
                    {
                        ergebnis = wert1 * wert2;
                        printf("Die Gewählte Operation ist die Multiplikation. %f * %f = %f\n", wert1, wert2, ergebnis);
                        status = 3;
                        break;
                    }
		    case 4:
                    {
			// Pruefen ob eine Division durch 0 stattfindet, wenn nicht dann fortfahren, sonst Sonderfall ausführen
			if (wert2 != 0)
			{
			    ergebnis = wert1 / wert2;
			    printf("Die Gewählte Operation ist die Division. %f / %f = %f\n", wert1, wert2, ergebnis);
			    status = 3;
                        }
			else
			{
			    printf("Die Gewählte Operation ist die Division. %f / %f = NaN\n", wert1, wert2);
			    status = 4;
                        }
			break;
                    }
		    case 5:
		    {
			// Status auf 0 setzen um neue Eingabe zu verlangen
			status = 0;
			break;
		    }
		    default:
		    {
			printf("Fehlerhafte Eingabe (%i). Bitte erneut versuchen.\n", operation);
			break;
		    }
		}
		break;
	    }
	    case 3:
	    {
		printf("Aktion eingeben (1: Mit %f weiterrechnen; 2: Neue Werte eingeben; 3: Programm beenden)\n", ergebnis);
		scanf("%i", &aktion);
		switch (aktion)
		{
		    case 1:
		    {
			wert1 = ergebnis;
			wert2 = 0;
			ergebnis = 0;
			status = 1;
			break;
		    }
		    case 2:
		    {
			wert1 = 0;
			wert2 = 0;
			ergebnis = 0;
			status = 0;
			break;
		    }
		    case 3:
		    {
			status = -1;
			break;
		    }
		    default:
		    {
			printf("Fehlerhafte Eingabe (&i), bitte erneut versuchen.\n");
			break;
		    }
		}
		break;
	    }
	    case 4:
	    {
		printf("Aktion eingeben (1: Weiterrechnen nicht verfügbar; 2: Neue Werte eingeben; 3: Programm beenden)\n");
                scanf("%i", &aktion);
                switch (aktion)
		{
                    case 1:
                    {
                        printf("Weiterreichen nicht verfügbar.\n");
                        break;
		      }
                    case 2:
                    {
                        wert1 = 0;
                        wert2 = 0;
                        ergebnis = 0;
                        status = 0;
                        break;
                    }
                    case 3:
                    {
                        status = -1;
                        break;
                    }
                    default:
                    {
                        printf("Fehlerhafte Eingabe (&i), bitte erneut versuchen.\n");
                        break;
                    }
                }
                break;
	    }
	}
    }
    return 0;
}
