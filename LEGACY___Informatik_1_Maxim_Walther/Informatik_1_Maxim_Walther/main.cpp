#include <Windows.h>
#include <stdio.h>
#include <conio.h>

#include "menu.h"
#include "DBTypes.h"
#include "typeFuncs.h"
#include "DBFuncs.h"

void main() {
	int menuChoice;  // Auswahl aus dem Menü
	int chosenIndex;  // Variable für Nutzereingaben

	bool validChoice = false; // Variable um nur bestimmte Eingaben zuzulassen

	// Datenbank initialisieren
	DataBank* db = (DataBank*) malloc(sizeof(DataBank));  // Zu groß für Stack, also ab aufn heap
	if (db == NULL) {
		// Falls nicht anlegbar...
		printf("Speicherplatz f\x81r Datenbank konnte nicht angelegt werden...\n");
		return;
	}

	for (int i = 0; i < 1000; i++) { setNullSource(&db->sources[i]); }  // leere Quellen vorbereiten

	db->entries = 0;

	bool inited = false;
	bool endProgramme = false;

	// Datenbank automatisch laden
	if (loadDB(db)) { // Laden erfolgreich
		printf("Quellenverzeichnis erfolgreich geladen. Es gibt %i Quellen...\n\n", db->entries);
	}
	else { // Fehler beim Laden
		printf("Datenbank konnte nicht automatisch geladen werden...\n");
	}

	do {
		menuChoice = menu();

		switch (menuChoice)
		{
		case input: // 1
			if (DBinput(db) == 0) {
				printf("Fehler. Erneut versuchen...\n");
				_getch();
			}
			break;

		case output: // 2
			DBoutput(db, 0);
			break;

		case save: // 3
			if (saveDB(db)) { // speichern erfolgreich
				printf("Quellenverzeichnis erfolgreich gespeichert...\n");
			}
			else { // Fehler beim Speichern
				printf("Es gab einen Fehler beim Speichern...\n");
			}
			printf("Beliebige Taste dr\x81\cken um zum Hauptmen\x81 zur\x81\ckzugelangen...");
			_getch();
			break;

		case load: // 4
			if (loadDB(db)) { // Laden erfolgreich
				printf("Quellenverzeichnis erfolgreich geladen. Es gibt %i Quellen...\n", db->entries);
			}
			else { // Fehler beim Laden
				printf("Es gab einen Fehler beim Laden...");
			}
			printf("Beliebige Taste dr\x81\cken um zum Hauptmen\x81 zur\x81\ckzugelangen...");
			_getch();
			break;

		case search:
			searchDB(db);
			printf("Beliebige Taste dr\x81\cken um zum Hauptmen\x81 zur\x81\ckzugelangen...");
			_getch();
			break;

		case change: // 2
			system("cls");

			// Auswählen welche Quelle zu verändern
			printf("Welchen Quelle soll ver\x84ndert werden?\n");
			printf("Es gibt aktuell %i Eintraege.\n", db->entries);

			while (!validChoice) {
				scanf("%d", &chosenIndex);

				system("cls");

				if (chosenIndex > 0 && chosenIndex <= db->entries) {
					validChoice = true;
				}
				else {
					printf("Ung\x81ltige Auswahl. Es gibt aktuell %i Eintraege. \nNeue Eingabe: ", db->entries);
				}
			}

			DBchange(db, chosenIndex);
			break;

		case exportbib:
			if (!exportDB(db)) {
				printf("Es gab einen Fehler...\n");
				printf("Beliebige Taste dr\x81\cken um zum Hauptmen\x81 zur\x81\ckzugelangen...");
			}
			_getch();
			break;

		case deleteentry:
			int toDelete;
			printf("Welcher Eintrag soll gel\x94scht werden?");
			scanf("%i", &toDelete);
			deleteEntry(db, toDelete - 1);
			break;

		case quit: // 0
			return;

		default:
			printf("Ung\x81ltige Auswahl.\n");
			printf("Beliebige Taste dr\x81\cken...");
			_getch();
			break;
		}
	} while (!endProgramme);

	free(db);
}