#include "DBTypes.h"

#ifndef DB_FUNCS  // falls dinge aus .h noch nicht definiert
#define DB_FUNCS  // merken, dass ich sie definiert habe

extern int DBinput(DataBank *db);

extern void DBoutput(DataBank* db, int index);

extern int saveDB(DataBank* db);

extern int loadDB(DataBank* db);

extern void DBchange(DataBank* db, int index);

extern int exportDB(DataBank* db);

extern void searchDB(DataBank* db);

extern void deleteEntry(DataBank* db, int index);

#endif