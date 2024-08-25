#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project1::MyForm form;

	// Datenbank initialisieren
	DataBank* db = (DataBank*)malloc(sizeof(DataBank));  // Zu groß für Stack, also ab aufn heap
	if (db == NULL) {
		// Falls nicht anlegbar...
		MessageBox::Show("Speicherplatz f\x81r Datenbank konnte nicht angelegt werden...\n", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	for (int i = 0; i < 1000; i++) { setNullSource(&db->sources[i]); }  // leere Quellen vorbereiten

	db->entries = 0;

	// Datenbank automatisch laden
	if (loadDB(db)) { // Laden erfolgreich
		MessageBox::Show("Quellenverzeichnis erfolgreich geladen. Es gibt %i Quellen...", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	else { // Fehler beim Laden
		MessageBox::Show("Datenbank konnte nicht automatisch geladen werden...", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

	Application::Run(%form);
}