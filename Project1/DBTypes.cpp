#include "DBTypes.h"
#include <string.h>

// extract string literal source type from enum
int readSourcetype(Sourcetype type, char saveLocation[13]) {
	switch (type) {

	case article:
		strcpy(saveLocation, "article");
		break;

	case book:
		strcpy(saveLocation, "book");
		break;

	case booklet:
		strcpy(saveLocation, "booklet");
		break;

	case conference:
		strcpy(saveLocation, "conference");
		break;

	case inproceedings:
		strcpy(saveLocation, "inproceedings");
		break;

	case inbook:
		strcpy(saveLocation, "inbook");
		break;

	case incollection:
		strcpy(saveLocation, "incollection");
		break;

	case manual:
		strcpy(saveLocation, "manual");
		break;

	case masterthesis:
		strcpy(saveLocation, "masterthesis");
		break;

	case misc:
		strcpy(saveLocation, "misc");
		break;

	case phdthesis:
		strcpy(saveLocation, "phdthesis");
		break;

	case proceedings:
		strcpy(saveLocation, "proceedings");
		break;

	case techreport:
		strcpy(saveLocation, "techreport");
		break;

	case unpublished:
		strcpy(saveLocation, "unpublished");
		break;

	case variantcount:
		strcpy(saveLocation, "variantcount");
		break;

	default:
		return 0;
	}
	return 1;
}


// writes string of type to buffer, special cases return their int
int readFieldtype(Fieldtype readtype, char saveLocation[20]) {
	switch (readtype) {

	case author:
		strcpy(saveLocation, "author");
		break;

	case authororeditor:
		return authororeditor;

	case title:
		strcpy(saveLocation, "title");
		break;

	case journal:
		strcpy(saveLocation, "journal");
		break;

	case year:
		strcpy(saveLocation, "year");
		break;

	case volume:
		strcpy(saveLocation, "volume");
		break;

	case number:
		strcpy(saveLocation, "number");
		break;

	case pages:
		strcpy(saveLocation, "pages");
		break;

	case month:
		strcpy(saveLocation, "month");
		break;

	case note:
		strcpy(saveLocation, "note");
		break;

	case publisher:
		strcpy(saveLocation, "publisher");
		break;

	case editor:
		strcpy(saveLocation, "editor");
		break;

	case series:
		strcpy(saveLocation, "series");
		break;

	case address:
		strcpy(saveLocation, "address");
		break;

	case edition:
		strcpy(saveLocation, "edition");
		break;

	case booktitle:
		strcpy(saveLocation, "booktitle");
		break;

	case chapter:
		strcpy(saveLocation, "chapter");
		break;

	case chapterandorpages:
		return chapterandorpages;

	case organization:
		strcpy(saveLocation, "organization");
		break;

	case school:
		strcpy(saveLocation, "school");
		break;

	case howpublished:
		strcpy(saveLocation, "howpublished");
		break;

	case institution:
		strcpy(saveLocation, "institution");
		break;

	case type:
		strcpy(saveLocation, "type");
		break;

	case empty:
		strcpy(saveLocation, "");
		break;

	default:
		return 0; // Type not recognized
	}
	return 1;
}
