#include "DBTypes.h"
#include "typeFuncs.h"
#include "typeFuncs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace System::Windows::Forms;

int DBinput(DataBank *db, Source* newSourc) {
	Source* currSource = &db->sources[db->entries];

	// pop-up quellentyp
	// neues fenster erstellen + quellentype abfragen

	Sourcetype chosenType; // aus popup

	if (initSource(currSource, chosenType)) { // Falls Quelle mit Feldern und Typ angelegt werden konnte, wollen wir reinschreiben
		return appendDB(db, *currSource);  // fertige Quelle einfügen
	}

	// neue quelle anzeigen und in ändern modus wechseln
	//DBoutput(db, db->entries - 1, true);

	MessageBox::Show("Etwas ist schiefgelaufen...", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	return 0;
} // Eingabe optionale Felder optimieren

void searchDB(DataBank* db) {  // weitere Felderoptionen und über strstr | Ausgabe Ergebnisse Anzahl
	char searchFor;
	int choice;
	int currIndex = 0;
	char searchTerm[40];

	int results = 0;

	Source* searchResults[1000];

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
		
	}
	else {
		MessageBox::Show("Keine Ergebnisse gefunden...", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

int saveDB(DataBank* db) {
	FILE* fp;

	system("cls");

	if ((fp = fopen("Quellenverzeichnis.dat", "wb")) == NULL) {  // Versuchen Datei zu öffnen
		MessageBox::Show("Datei konnte nicht ge\x94\\ffnet werden...", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
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
		MessageBox::Show("Datei konnte nicht ge\x94\\ffnet werden...", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
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
		MessageBox::Show("Quellenverzeichnis konnte nicht angelegt werden...", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
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
			char fieldname[20];
			readFieldtype(currSource->fields[m].type, fieldname);
			fprintf(fp, "\t%s = {%s},\n", fieldname, currSource->fields[m].content);
			m++;
		}
		// Optionale Felder ausgeben
		int j = 0; // iterationsparameter
		while (fieldValid(&currSource->optFields[j])) { // Pointerarithmetik um alle existenten Felder durchzuiterieren
			char fieldname[20];
			readFieldtype(currSource->optFields[j].type, fieldname);
			if (fieldHasContent(&currSource->optFields[j])) { fprintf(fp, "\t%s = \"%s\",\n", fieldname, currSource->optFields[j].content); }
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
	else { MessageBox::Show("Ung\x81ltige Auswahl", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning); }
}
