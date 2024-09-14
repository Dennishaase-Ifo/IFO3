#include "DBTypes.h"
#include <string.h>
#include <stdio.h>
#include <corecrt_malloc.h>


int initSource(Source* DBEntry, Sourcetype variant) {

	// Start der Definitionen der Quellentypen
	if (variant == article) {
		Field reqFields[] = { {author, ""}, {title, ""}, {journal, ""}, {year, ""}, {empty, ""}, {empty, ""} };  // Festlegen notwendiger Felder
		Field optFields[] = { {volume, ""}, {number, ""}, {pages, ""}, {month, ""}, {note, ""}, {empty, ""}, {empty, ""}, {empty, ""} };  // Festlegen optionaler Felder

		// Übertragen in die Quellenstruktur
		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		// Variane der Quelle setzen
		DBEntry->variant = article;
	}
	// Und alles ganz oft wiederholen...
	else if (variant == book) {
		Field reqFields[] = { {authororeditor, ""}, {title, ""}, {publisher, ""}, {year, ""}, {empty, ""}, {empty, ""} };
		Field optFields[] = { {volume, ""}, {series, ""}, {address, ""}, {edition, ""}, {month, ""}, {note, ""}, {empty, ""}, {empty, ""} };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = book;
	}
	else if (variant == booklet) {
		Field reqFields[] = { {title, ""}, {empty, ""}, {empty, ""}, {empty, ""}, {empty, ""}, {empty, ""} };
		Field optFields[] = { {author, ""}, {howpublished, ""}, {address, ""}, {month, ""}, {year, ""}, {note, ""}, {empty, ""}, {empty, ""} };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = booklet;
	}
	else if (variant == conference) {
		Field reqFields[] = { {author, ""}, {title, ""}, {booktitle, ""}, {year, ""}, {empty, ""}, {empty, ""} };
		Field optFields[] = { {editor, ""}, {pages, ""}, {organization, ""}, {publisher, ""}, {address, ""}, {month, ""}, {note, ""}, {empty, ""} };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = conference;
	}
	else if (variant == inproceedings) {
		Field reqFields[] = { {author, ""}, {title, ""}, {booktitle, ""}, {year, ""}, {empty, ""}, {empty, ""} };
		Field optFields[] = { {editor, ""}, {pages, ""}, {organization, ""}, {publisher, ""}, {address, ""}, {month, ""}, {note, ""}, {empty, ""} };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = inproceedings;
	}
	else if (variant == inbook) {
		Field reqFields[] = { {authororeditor, ""}, {title, ""}, {chapterandorpages, ""}, {publisher, ""}, {year, ""}, {empty, ""} };
		Field optFields[] = { {volume, ""}, {series, ""}, {address, ""}, {edition, ""}, {month, ""}, {note, ""}, {empty, ""}, {empty, ""} };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = inbook;
	}
	else if (variant == incollection) {
		Field reqFields[] = { {author, ""}, {title, ""}, {booktitle, ""}, {publisher, ""}, {year, ""}, {empty, ""} };
		Field optFields[] = { {editor, ""}, {chapter, ""}, {pages, ""}, {address, ""}, {month, ""}, {note, ""}, {empty, ""}, {empty, ""} };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = incollection;
	}
	else if (variant == manual) {
		Field reqFields[] = { {title, ""}, {empty, ""}, {empty, ""}, {empty, ""}, {empty, ""}, {empty, ""} };
		Field optFields[] = { {author, ""}, {organization, ""}, {address, ""}, {edition, ""}, {month, ""}, {year, ""}, {note, ""}, {empty, ""} };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = manual;
	}
	else if (variant == masterthesis) {
		Field reqFields[] = { {author, ""}, {title, ""}, {school, ""}, {year, ""}, {empty, ""}, {empty, ""} };
		Field optFields[] = { {address, ""}, {month, ""}, {note, ""}, {empty, ""}, {empty, ""}, {empty, ""}, {empty, ""}, {empty, ""} };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = masterthesis;
	}
	else if (variant == misc) {
		Field reqFields[] = { {empty, ""}, {empty, ""}, {empty, ""}, {empty, ""}, {empty, ""}, {empty, ""} };
		Field optFields[] = { {author, ""}, {title, ""}, {howpublished, ""}, {month, ""}, {year, ""}, {note, ""}, {empty, ""}, {empty, ""} };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = misc;
	}
	else if (variant == phdthesis) {
		Field reqFields[] = { {author, ""}, {title, ""}, {school, ""}, {year, ""}, {empty, ""}, {empty, ""} };
		Field optFields[] = { {address, ""}, {month, ""}, {note, ""}, {empty, ""}, {empty, ""}, {empty, ""}, {empty, ""}, {empty, ""} };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = phdthesis;
	}
	else if (variant == proceedings) {
		Field reqFields[] = { {title, ""}, {year, ""}, {empty, ""}, {empty, ""}, {empty, ""}, {empty, ""} };
		Field optFields[] = { {editor, ""}, {publisher, ""}, {organization, ""}, {address, ""}, {month, ""}, {note, ""}, {empty, ""}, {empty, ""} };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = proceedings;
	}
	else if (variant == techreport) {
		Field reqFields[] = { {author, ""}, {title, ""}, {institution, ""}, {year, ""}, {empty, ""}, {empty, ""} };
		Field optFields[] = { {type, ""}, {number, ""}, {address, ""}, {month, ""}, {note, ""}, {empty, ""}, {empty, ""}, {empty, ""} };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = techreport;
	}
	else if (variant == unpublished) {
		Field reqFields[] = { {author, ""}, {title, ""}, {note, ""}, {empty, ""}, {empty, ""}, {empty, ""} };
		Field optFields[] = { {month, ""}, {year, ""}, {empty, ""}, {empty, ""}, {empty, ""}, {empty, ""}, {empty, ""}, {empty, ""} };

		memcpy(DBEntry->fields, reqFields, sizeof(DBEntry->fields));
		memcpy(DBEntry->optFields, optFields, sizeof(DBEntry->optFields));

		DBEntry->variant = unpublished;
	}
	else {
		// TODO change into popup
		printf("Ung\x81ltige Auswahl...");
		DBEntry = NULL;
		return 0;
	}

	// deprecated in V2
	  // Zuweisen des Schlüssels
	  //strcpy(DBEntry->key, key);

	return 1;
}

bool sourceExists(Source* source) {  // standartüberprüfung, ob Quelle schon angelegt
	return (source->fields != NULL && source->key != NULL && source->optFields != NULL && source->variant != empty);
}

bool fieldValid(Field* field) {  // standartüberprüfung, ob Feld angelegt
	return (field->type != empty);
}

bool fieldHasContent(Field* field) {  // standartüberprüfung, ob Feld inhalt hat
	return (field->content != NULL && strlen(field->content) > 0);
}

void setNullSource(Source* source) {  // klares Setzen der "leeren" Quellen
	for (int i = 0; i < 6; i++) {
		source->fields[i].type = empty;
		source->optFields[i].type = empty;
	}
	source->optFields[6].type = empty;
	source->optFields[7].type = empty;
	source->variant = nullSource;  // Einfach auszulesende ID für undefinierte Quellenstruktur
	strcpy(source->key, "");
}

// Neues Element an Datenbank anhängen
int appendDB(DataBank *db, Source newSource) {
	db->sources[db->entries] = newSource;  // neue Quelle einfügen
	db->entries++;  // Zahl der Einträge erhöhen
	return 1;
}
