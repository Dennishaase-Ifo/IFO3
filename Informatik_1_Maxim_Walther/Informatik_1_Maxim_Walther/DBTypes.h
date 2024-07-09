/* -------------------
Definitionen der Datenbankelemente
  ----------------- */

#ifndef DB_TYPES  // falls dinge aus .h noch nicht definiert
#define DB_TYPES  // merken, dass ich sie definiert habe

typedef enum {  // Arten von Quellen zur besseren Lesbarkeit und eindeutigkeit (kann keine andere, undefinierte, Werte annehmen)
	article,
	book,
	booklet,
	conference,
	inbook,
	incollection,
	manual,
	masterthesis,
	misc,
	phdthesis,
	proceedings,
	techreport,
	unpublished,
	variantcount,
	empty, // stellt leeren Quellentypen dar
} Sourcetype;

extern int readSourcetype(Sourcetype type, char saveLocation[13]);

// Einzelnes Feld, z.B. Autor
typedef struct {
	char fieldName[20];  // Bsp. "author"
	char content[100];    // Bsp. content = "Karl Marx"
} Field;

// gesamte Quelle aus erzwungenen, sowie optionalen Feldern
typedef struct {
	Field fields[6];  // notwendige Attribute (erstes Element)
	//           ^ höchste Anzahl + 1 als Endelement
	Field optFields[8];  // optionale Argumente (erstes Element)
	Sourcetype variant;  // Variante der Quelle, Bsp. book
	char key[50];  // Bezeichnung der Quelle; Bsp. "Quelle zu Bienen bei Airbus"
} Source;

// Datenbank aus allen bis zu 1000 Quellen
typedef struct {
	Source sources[1000];  // maximal 1000 Quellen, siehe Aufgabenstellung
	int entries;  // Anzahl eingepflegter Quellen
} DataBank;

#endif