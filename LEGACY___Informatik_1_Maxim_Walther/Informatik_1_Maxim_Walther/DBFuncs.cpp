#include "DBTypes.h"
#include "typeFuncs.h"
#include "typeFuncs.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

bool getYN() {  // Ja/Nein Abfrage vom User standartisiert
	char userInput;

	while (userInput != 'n') {
		userInput = _getch();

		if (userInput == 'y') {  // Nutzer wählt ja aus
			return true;
		}
	}

	return false;  // Nutzer wählt Nein aus
}

int DBinput(DataBank *db) {
	int input;

	char key[50];
	char tempfield[50];

	Source* currSource = &db->sources[db->entries];

	system("cls");

	// Auswahlen Quellentyp und zugewiesener Schlüssel
	printf("Welchen Typ hat deine Quelle?\n");
	printf("0  - article\n");
	printf("1  - book\n");
	printf("2  - booklet\n");
	printf("3  - conference\n");
	printf("4  - inbook\n");
	printf("5  - incollection\n");
	printf("6  - manual\n");
	printf("7  - masterthesis\n");
	printf("8  - misc\n");
	printf("9  - phdthesis\n");
	printf("a  - proceedings\n");
	printf("b  - techreport\n");
	printf("c  - unpublished\n");

	char temp = _getch();

	switch (temp) {
	case 'a':
		input = 10;
		break;
	case 'b':
		input = 11;
		break;
	case 'c':
		input = 12;
		break;
	default:
		input = atof(&temp);
		break;
	}

	system("cls");

	printf("\nGib dem Eintrag einen Namen (Max. 50 Zeichen): ");
	scanf(" %[^\n]s", key);

	if (initSource(currSource, (Sourcetype)input, key)) { // Falls Quelle mit Feldern und Typ angelegt werden konnte, wollen wir reinschreiben

		int i = 0;
		while (fieldValid(&currSource->fields[i])) { // alle angelegten Felder durchiterieren
			printf("%s: ", currSource->fields[i].fieldName);
			scanf(" %[^\n]s", currSource->fields[i].content);
			i++;
		}

		printf("\nOptionale Argumente hinzuf\x81gen? (y/n)\n");

		if (getYN()) {

			int j = 0;
			while (fieldValid(&currSource->optFields[j])) { // alle angelegten optionalen Felder durchiterieren

				printf("N\x84\chstes Feld: %s. Dieses Feld ausfl\x81llen? (y/n)\n", currSource->optFields[j].fieldName);
				
				if (getYN()) {
					printf("%s: ", currSource->optFields[j].fieldName);
					scanf(" %[^\n]s", currSource->optFields[j].content);
				}
				j++;
			}
		}

		return appendDB(db, *currSource);  // fertige Quelle einfügen
	}

	printf("Etwas ist schiefgelaufen...");
	return 0;
} // Eingabe optionale Felder optimieren

void searchDB(DataBank* db) {  // weitere Felderoptionen und über strstr | Ausgabe Ergebnisse Anzahl
	char searchFor;
	int choice;
	int currIndex = 0;
	char searchTerm[40];

	Source* searchResults[1000];

	int results = 0;

	system("cls");

	printf("Wonach m\x94\chtest du suchen?\n(1) Schl\x81ssel\n(2) Name\n(3) Titel\n");

	searchFor = _getch();
	choice = atof(&searchFor);

	system("cls");

	printf("Suchterm: ");
	scanf(" %[^\n]s", &searchTerm);

	Source* currSource = &db->sources[currIndex];

	while (sourceExists(currSource)) {
		int i;
		int j;
		char chosenField[20];

		switch (choice) {  // unterscheidung der Suchoptionen
		case 1:  // nach Schlüssel
			if (strstr(currSource->key, searchTerm) != NULL) {  // Falls kein Pointer zu einem Vorkommen des Suchterms gefunden werden kann
				searchResults[results] = currSource;  // Pointer zu treffer speichern
				results++;
			}
			break;

		case 2:
			strcpy(chosenField, "author");  // setzen der Variable für später
			break;

		case 3:
			strcpy(chosenField, "title");  // setzen der Variable für später (2)
			break;

		default:
			printf("Ung\x81ltige Eingabe. Versuche es erneut... \n\n");
			printf("Wonach m\x94\chtest du suchen?\n(1) Schl\x81ssel\n(2) Name\n(3) Titel\n");

			searchFor = _getch();
			choice = atof(&searchFor);
			continue;
		} ;

		if (strlen(chosenField) > 0) {  // hier werden Optionen 2 & 3 verarbeitet
			// entsprechendes Feld raussuchen
			Field* authorField = NULL;
			for (i = 0; i < 6; i++) {  // alle notwendigen Felder ausprobieren
				if (&currSource->fields[i] != NULL && strstr(currSource->fields[i].fieldName, chosenField) != NULL) { // ist es das gesuchte Feld? (findet auch athor in author or editor)
					authorField = &currSource->fields[i];  // Feld merken
					break;
				}
			}
			for (i = 0; i < 8; i++) {  // alle optionalen Felder ausprobieren
				if (&currSource->optFields[i] != NULL && strstr(currSource->optFields[i].fieldName, chosenField) != NULL) {
					authorField = &currSource->optFields[i];
					break;
				}
			}
			if (authorField != NULL) { // Falls Feld gefunden suchbegriff überprüfen
				if (strstr(authorField->content, searchTerm) != NULL) {
					searchResults[results] = currSource;
					results++;
				}
			}
		}

		currIndex++;
		currSource = &db->sources[currIndex];
	}

	int index = 0;

	// Suchergebnisse analog zur normalen Ausgabe ausgeben
	if (results > 0 && searchResults[index] != NULL) {
		do {
			system("cls");

			currSource = searchResults[index];

			char SourcetypeName[13];
			// Quellentyp ausgeben
			printf("+ ======= ( %i / %i ) ======= ---\n", index + 1, results);
			readSourcetype(currSource->variant, SourcetypeName);
			printf("| Quellentyp: %s, Schl\x81ssel: %s\n", SourcetypeName, currSource->key);
			printf("+ ========================= ---\n");
			// Notwendige Felder ausgeben
			int i = 0; // iterationsparameter
			while (fieldValid(&currSource->fields[i]) && fieldHasContent(&currSource->fields[i])) { // Pointerarithmetik um alle existenten Felder durchzuiterieren
				printf("| %s: %s\n", currSource->fields[i].fieldName, currSource->fields[i].content);
				i++;
			}
			// Optionale Felder ausgeben
			printf("+ ========================= ---\n");
			printf("| Optionale Felder:\n");
			printf("+ ========================= ---\n");
			int j = 0; // iterationsparameter
			while (fieldValid(&currSource->optFields[j])) { // Pointerarithmetik um alle existenten Felder durchzuiterieren
				printf("| %s: %s\n", currSource->optFields[j].fieldName, currSource->optFields[j].content); 
				j++;
			}

			printf("+ ========================= ---\n");
			printf("<- (4) ===  quit (q) === (6) ->\n");
			printf("+ ========================= ---\n");
			char userInput = _getch();
			if (userInput == 'q') { return; }
			else if (userInput == '4') {
				if (index == 0) { index = results; }  // Randbedingungen abfangen
				index--;;
			}
			else if (userInput == '6') {
				if (index + 1 >= results) { index = -1; }  // Randbedingungen abfangen
				index++;
			}
		} while (true);
	}
	else {
		printf("Keine Ergebnisse gefunden...");
	}
}

void DBchange(DataBank* db, int index) {
	int input;

	char key[50];
	char tempfield[50];

	Source* currSource;

	currSource = &db->sources[index - 1];

	if (currSource == NULL) {
		return;
	}
	char SourcetypeName[13];
	// Start der Ausgabe
	system("cls");
	// Quellentyp ausgeben
	readSourcetype(currSource->variant, SourcetypeName);
	printf("Quellentyp: %s, Schl\x81ssel (s): %s\n", SourcetypeName, currSource->key);
	// Notwendige Felder ausgeben
	int i = 0; // iterationsparameter
	while (fieldValid(&currSource->fields[i])) { // alle Felder durchiterieren
		printf("(%i) %s: %s\n", i, currSource->fields[i].fieldName, currSource->fields[i].content);
		i++;
	}
	// Optionale Felder ausgeben
	int j = 0; // iterationsparameter
	if (currSource->optFields[0].fieldName != NULL && strcmp(currSource->optFields[0].fieldName, "") != 0) {
		printf("Optionale Felder:\n");
		while (fieldValid(&currSource->optFields[j])) { // alle Felder durchiterieren
			printf("(%i) %s: %s\n", i + j, currSource->optFields[j].fieldName, currSource->optFields[j].content);
			j++;
		}
	}

	printf("\nW\x84hle das zu ver\x84ndernde Feld aus. q dr\x81\cken um zu abzubrechen...\nAuswahl: ");

	// Auswahl des zu verändernden Feldes
	bool validChoice = false;  
	char chosenFieldIndex[3];  // "rohe" Nutzereingabe
	char newInput[20];

	while (!validChoice) {
		scanf(" %s", &chosenFieldIndex);  // Muss als Zeichenkette eingelesen werden, da durchaus Felder > 10
		int chosenFieldNum = atof(chosenFieldIndex);  // Zahl aus Zeichen bekommen

		system("cls");

		if (chosenFieldIndex[0] == 'q') {  // Verlassen
			return;
		}

		else if (chosenFieldIndex[0] == 's') {  // Schlüssel-Feld ausgewählt
			printf("Gib den neuen Wert ein: ");  // Neuer Wert wir angefragt und abgespeichert
			scanf(" %[^\n]s", newInput);
			strcpy(currSource->key, newInput);
			validChoice = true;
		}

		else if (chosenFieldNum >= 0 && chosenFieldNum < i) {  // Zahlenbereich für die zwingenden Felder wird abgefragt und dem gewählten Feld zugeordnet
			printf("Du hast folgendes Feld gew\x84hlt: %s\n", currSource->fields[chosenFieldNum].fieldName);  // Neuen Wert einlesen
			printf("Gib den neuen Wert ein: ");
			scanf(" %[^\n]s", newInput);
			strcpy(currSource->fields[chosenFieldNum].content, newInput);
			validChoice = true;
		} 

		else if (chosenFieldNum >= i && chosenFieldNum < i + j) {  // Wie bei zwingenden Feldern, nur quasi um i verschoben, da i = Anzahl zwingende Felder
			printf("Du hast folgendes Feld gew\x84hlt: %s\n", currSource->optFields[chosenFieldNum - i].fieldName);
			printf("Gib den neuen Wert ein: ");
			scanf(" %[^\n]s", newInput);
			strcpy(currSource->optFields[chosenFieldNum - i].content, newInput);
			validChoice = true;
		}

		else {
			printf("Ung\x81ltige Eingabe. Versuche es nochmal...");
			_getch();
		}
	}
}

int saveDB(DataBank* db) {
	FILE* fp;

	system("cls");

	if ((fp = fopen("Quellenverzeichnis.dat", "wb")) == NULL) {  // Versuchen Datei zu öffnen
		printf("Datei konnte nicht ge\x94\\ffnet werden...");
		return 0;
	}

	fwrite(db, sizeof(DataBank), 1, fp);  // Datenbank speichern

	fclose(fp);  // Datei wieder schließen
	return 1;  // Erfolg!
}

int loadDB(DataBank* db) {
	FILE* fp;

	system("cls");

	if ((fp = fopen("Quellenverzeichnis.dat", "rb")) == NULL) {  // Versuchen Datei zu öffnen
		printf("Datei konnte nicht ge\x94\\ffnet werden...");
		return 0;
	}

	fread(db, sizeof(DataBank), 1, fp);  // Datenbank laden

	fclose(fp);  // Datei wieder schließen
	return 1;  // Erfolg!
}

int exportDB(DataBank* db) {

	FILE* fp;

	system("cls");

	if ((fp = fopen("Quellenverzeichnis.bib", "w")) == NULL) {  // Versuchen Datei zu öffnen
		printf("Quellenverzeichnis konnte nicht angelegt werden...");
		return 0;
	}

	for (int i = 0; i < db->entries; i++) {  // durch alle Einträge iterieren
		Source* currSource = &db->sources[i];  // aktuellen Eintrag merken
		char currSourceType[20];
			
		readSourcetype(currSource->variant, currSourceType);  // Art der Quelle auslesen

		fprintf(fp, "@%s {%s,\n", currSourceType, currSource->key);  // Erste Zeile vom .bib Format

		// Notwendige Felder ausgeben
		int m = 0; // iterationsparameter
		while (fieldValid(&currSource->fields[m]) && fieldHasContent(&currSource->fields[m])) { // Pointerarithmetik um alle existenten Felder durchzuiterieren
			fprintf(fp, "\t%s = {%s},\n", currSource->fields[m].fieldName, currSource->fields[m].content);
			m++;
		}
		// Optionale Felder ausgeben
		int j = 0; // iterationsparameter
		while (fieldValid(&currSource->optFields[j])) { // Pointerarithmetik um alle existenten Felder durchzuiterieren
			if (fieldHasContent(&currSource->optFields[j])) { fprintf(fp, "\t%s = \"%s\",\n", currSource->optFields[j].fieldName, currSource->optFields[j].content); }
			j++;
		}

		fprintf(fp, "}\n\n");  
	}

	fclose(fp);
	printf("Exportieren erfolgreich!\n");

	return 1;  // Erfolg!
}

void deleteEntry(DataBank* db, int index) {  
	if (index < db->entries && index >= 0) {  // Überprüfen, ob eine gültige Stelle ausgewählt ist
		for (int i = index; i < db->entries; i++) {  // jeweils den inhalt des nächsten Eintrages an die aktuelle Stelle kopieren
			memcpy(&db->sources[i], &db->sources[i + 1], sizeof(Source));
		}
		db->entries--;  // Anzahl Einträge um 1 verringern
	}
	else { printf("Ung\x81ltige Auswahl"); }
}

void DBoutput(DataBank* db, int index) {

	system("cls");

	Source* currSource = &db->sources[index];  // Pointer zu erstem element anlegen
	if (currSource == NULL) {  // Gibt es diesen?
		printf("Ung\x81ltige Eingabe...");
		_getch();
		return;
	}

	if (db->entries == 0) {
		printf("Die Datenbank ist aktuell leer...");
		_getch();
		return;
	}

	char SourcetypeName[13];
	// Quellentyp ausgeben
	printf("+===============================--------\n");
	printf("| Eintrag %i\n", index + 1);
	printf("+---------------------------------------\n");
	readSourcetype(currSource->variant, SourcetypeName);
	printf("| Quellentyp: %s, Schl\x81ssel: %s\n", SourcetypeName, currSource->key);
	printf("+---------------------------------------\n");
	// Notwendige Felder ausgeben
	int i = 0; // iterationsparameter
	while (fieldValid(&currSource->fields[i])) { // Pointerarithmetik um alle existenten Felder durchzuiterieren
		printf("| - %s: %s\n", currSource->fields[i].fieldName, currSource->fields[i].content);
		i++;
	}
	// Optionale Felder ausgeben
	printf("+===============================--------\n");
	printf("| Optionale Felder:\n");
	printf("+---------------------------------------\n");
	int j = 0; // iterationsparameter
	while (fieldValid(&currSource->optFields[j])) { // Pointerarithmetik um alle existenten Felder durchzuiterieren
		printf("| - %s: %s\n", currSource->optFields[j].fieldName, currSource->optFields[j].content);
		j++;
	}

	// kleines Menü zum blättern und andere Funktionen
	printf("+=================================+\n");
	printf("<- (4) ====  men\x81 (m)   ==== (6) ->\n");
	printf("+=================================+\n");
	printf("| (e) eingabe   -----   (s) suche |\n");
	printf("| (x) export    -----  (v) \x84ndern |\n");
	printf("| (p) speichern -----   (l) laden |\n");
	printf("| (d) l\x94schen                     |\n");
	printf("+=================================+\n");

	char userInput = _getch();
	if (userInput == 'm') { return; }  // geht zurück zum Hauptmenü

	// Funktionen wie im Hauptmenü
	else if (userInput == 'e') { DBinput(db); }
	else if (userInput == 's') { searchDB(db); }
	else if (userInput == 'x') { exportDB(db); }
	else if (userInput == 'v') { DBchange(db, index + 1); }
	else if (userInput == 's') { saveDB(db); }
	else if (userInput == 'l') { loadDB(db); }
	else if (userInput == 'd') { deleteEntry(db, index); }

	// Logik zum "Blättern"
	else if (userInput == '4') {
		if (index == 0) { index = db->entries; }
		if (db->entries == 1) { DBoutput(db, 0); }
		else { DBoutput(db, index - 1); }
	}
	else if (userInput == '6') {
		if (index + 1 >= db->entries) { index = -1; }
		DBoutput(db, index + 1);
	}
	return;
}
