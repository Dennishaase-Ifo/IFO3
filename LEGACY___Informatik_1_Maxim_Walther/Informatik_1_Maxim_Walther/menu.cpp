#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int menu() {
	system("cls");

	printf("+=========================+\n");
	printf("| -------   Men\x81  ------- |\n");
	printf("+===+=====================+\n");
	printf("|(1)| Datensatz eingeben  |\n");
	printf("+---+---------------------+\n");
	printf("|(2)| Datensatz ausgeben  |\n");
	printf("+---+---------------------+\n");
	printf("|(3)| Datenbank speichern |\n");
	printf("+---+---------------------+\n");
	printf("|(4)| Datenbank laden     |\n");
	printf("+---+---------------------+\n");
	printf("|(5)| Datensatz \x84ndern    |\n");
	printf("+---+---------------------+\n");
	printf("|(6)| Datensatz suchen    |\n");
	printf("+---+---------------------+\n");
	printf("|(7)| Datenexport zu .bib |\n");
	printf("+---+---------------------+\n");
	printf("|(8)| l\x94schen             |\n");
	printf("+---+---------------------+\n");
	printf("|(0)| Beenden             |\n");
	printf("+===+=====================+\n");

	char input = _getch();
	if (atof(&input) != 0) {
		return atof(&input); // Agbfangenes Zeichen als int zurückgeben
	}
	else if (input == '0') { // Sonderfall, alles Zeichen != Zahl -> 0
		return 0;
	}
	else {  // Rückgabe von Wert für andere Eingabe, die sich nicht zu Zahl ummodeln lässt
		return -1;
	}
	  
}