#include "DBTypes.h"
#include <string.h>

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