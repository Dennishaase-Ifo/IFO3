#include "DBTypes.h"
#include "typeFuncs.h"
#include "typeFuncs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cliext/adapter>

using namespace System::Windows::Forms;

using namespace System;

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

void searchDB(DataBank* db, Source* searchResults[1000]) {  // weitere Felderoptionen und über strstr | Ausgabe Ergebnisse Anzahl
	char searchFor;
	int choice;
	int currIndex = 0;
	char searchTerm[40];

	int results = 0;

	searchResults = { 0 }; // leer initialisieren

	Source* currSource = &db->sources[currIndex];

	while (sourceExists(currSource)) {
		int i;
		int j;
		int chosenField = -1;

		switch (choice) {  // unterscheidung der Suchoptionen
		case 1:  // nach Schlüssel
			if (strstr(currSource->key, searchTerm) != NULL) {  // Falls kein Pointer zu einem Vorkommen des Suchterms gefunden werden kann
				searchResults[results] = currSource;  // Pointer zu treffer speichern
				results++;
			}
			break;

		case 2:
			chosenField = author;  // setzen der Variable für später
			break;

		case 3:
			chosenField = title;  // setzen der Variable für später (2)
			break;

		default:
			MessageBox::Show("Ung\x81ltige Eingabe. Versuche es erneut...", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		} ;

		if (chosenField > 0) {  // hier werden Optionen 2 & 3 verarbeitet
			// entsprechendes Feld raussuchen
			Field* searchedField = NULL;
			for (i = 0; i < 6; i++) {  // alle notwendigen Felder ausprobieren
				if (&currSource->fields[i] != NULL && currSource->fields[i].type == chosenField) { // ist es das gesuchte Feld? (findet auch athor in author or editor)
					searchedField = &currSource->fields[i];  // Feld merken
					break;
				}
			}
			for (i = 0; i < 8; i++) {  // alle optionalen Felder ausprobieren
				if (&currSource->optFields[i] != NULL && currSource->optFields[i].type == chosenField) {
					searchedField = &currSource->optFields[i];
					break;
				}
			}
			if (searchedField != NULL) { // Falls Feld gefunden suchbegriff überprüfen
				if (strstr(searchedField->content, searchTerm) != NULL) {
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
	if (results < 0 ) {
		MessageBox::Show("Keine Ergebnisse gefunden...", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

int saveDB(DataBank* db) {
	FILE* fp;

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
	MessageBox::Show("Exportieren erfolgreich!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);

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


void convert(DataBank *db) { //Auf was muss die Funktion zugreifen?
	
	//Beispiel Char[]
	char Eingangschar[] = "Hello, World!";

	//Konvertierung von char[] zu string^ 
	String^ Ausgangsstring = gcnew String(Eingangschar);


}
