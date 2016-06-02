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
    // status: 0 = start; 1 = j; 2 = n; 3 = jj; 4 = jn;
    int status = 0;
    while (status != -1)
    {
	char *antwort = NULL;
	size_t len = 0;
	switch (status)
	{
	    case 0:
	    {
		// Dialogbeginn
		printf("Programmierst du? (j/n)\n");
		getline(&antwort, &len, stdin);
		if (strncmp(antwort, "j\n", 2) == 0)
		    status = 1;
		else if (strncmp(antwort, "n\n", 2) == 0)
		    status = 2;
		else
		    printf("Fehlerhafte Eingabe: %s Bitte erneut versuchen.\n", antwort);
		continue;
	    }
	    case 1:
	    {
		// Antworten: j
		printf("Gratuliere, du bist ein Programmierer.\nWirst du dafür bezahlt?\n");
	        getline(&antwort, &len, stdin);
		if (strncmp(antwort, "j\n", 2) == 0)
                    status = 3;
                else if (strncmp(antwort, "n\n", 2) == 0)
                    status = 4;
                else
                    printf("Fehlerhafte Eingabe: %s Bitte erneut versuchen.\n", antwort);
                continue;
	    }
	    case 2:
	    {
		// Antworten: n
		printf("Ach so, dann wirst du es aber bald lernen.\n");
                return 0;
	    }
	    case 3:
	    {
		// Antworten: jj
		printf("Gratuliere, du bist ein professioneller Programmierer.\n");
		return 0;
	    }
	    case 4:
	    {
		// Antworten: jn
		printf("Trotzdem cool, immerhin bist du ein Programmierer.\n");
		return 0;
	    }
	}
    }
    return 0;
}
