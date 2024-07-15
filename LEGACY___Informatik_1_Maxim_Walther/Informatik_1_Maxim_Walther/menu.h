#ifndef MENU  // falls dinge aus .h noch nicht definiert
#define MENU  // merken, dass ich sie definiert habe

extern int menu();

// Definition aller Menüoptionen, da lesbarer als Zahlen
enum menuOpt { quit, input, output, save, load, change, search, exportbib, deleteentry };

#endif