#include "DBTypes.h"

#ifndef TYPE_FUNCS  // falls dinge aus .h noch nicht definiert
#define TYPE_FUNCS  // merken, dass ich sie definiert habe

extern int initSource(Source* DBEntry, Sourcetype variant, char* key);

extern int appendDB(DataBank* db, Source newSource);

extern bool sourceExists(Source* source);

extern bool fieldValid(Field* field);

extern bool fieldHasContent(Field* field);

extern void setNullSource(Source* source);

#endif