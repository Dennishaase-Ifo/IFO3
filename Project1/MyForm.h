#pragma once
#include <Windows.h>
#include <stdio.h>

#include "DBFuncs.h"	
#include "DBTypes.h"
#include "typeFuncs.h"

#include "GUIUtils.h"
#include "MyForm1.h"
#include "MyForm2.h"


namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		//  Konstruktor um standart quelle 0 auszugeben?
		MyForm(void)
		{
			InitializeComponent();

			// Datenbank initialisieren
			db = (DataBank*)malloc(sizeof(DataBank));  // Zu groß für Stack, also ab aufn heap
			if (db == NULL) {
				// Falls nicht anlegbar...
				MessageBox::Show("Speicherplatz f\x81r Datenbank konnte nicht angelegt werden...\n", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			for (int i = 0; i < 1000; i++) { (&db->sources[i]); }  // leere Quellen vorbereiten

			db->entries = 0;

			// Datenbank automatisch laden
			if (loadDB(db)) { // Laden erfolgreich
				// nicht nutzerfreundlich, deswegen erstmal weg
				//MessageBox::Show("Quellenverzeichnis erfolgreich geladen. Es gibt %i Quellen...", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			else { // Fehler beim Laden
				MessageBox::Show("Datenbank konnte nicht automatisch geladen werden...", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}

			currEntry = 0;

			isInited = true;
			newSorceCreated = (bool*)malloc(sizeof(bool));
			*newSorceCreated = false;

			// Suchparameter initialisieren
			isSearching = (bool*)malloc(sizeof(bool));
			*isSearching = false;
			searchResults = (SearchResults*)malloc(sizeof(SearchResults));  // Zu groß für Stack, also ab aufn heap
			if (searchResults == NULL) {
				// Falls nicht anlegbar...
				MessageBox::Show("Speicherplatz f\x81r Suchergebnisse konnte nicht angelegt werden...\n", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			for (int i = 0; i < 1000; i++) { searchResults->searchResults[i] = NULL; }  // leere Quellen vorbereiten

			searchResults->entries = 0;
			searchIndex = 0;

			output(currEntry, false);
		}

		// util um Ausgabefelder zu populieren
		void output(int index, bool isEditable) {
			Source* currSource = &db->sources[index];

			// Alles erstmal blank zurücksetzen
			resetFields(); 

			if (db->entries <= 0) { return; }

			if (currSource->variant != nullSource) {
				// index ausgeben/anzeigen
				int currNum = (*isSearching) ? searchIndex : currEntry + 1;
				int totalNum = (*isSearching) ? searchResults->entries : db->entries;
				String^ indexString = String::Format("{0:D}/{1:D}", currNum, totalNum);
				currIndexTextBox->Text = indexString;

				// Sourcetype ausgeben
				String^ sTypeString;
				char buff[20];
				readSourcetype(currSource->variant, buff);

				charToString(buff, &sTypeString);
				sourceTypeTextBox->Text = sTypeString;
				
				// Schlüssel ausgeben
				String^ name;
				charToString(currSource->key, &name);
				keyField->Text = name;
				keyField->ReadOnly = !isEditable;

				// Leere Felder rausfiltern
				if (currSource->fields[0].type != empty) {
					value1->Visible = true;
					field1->Visible = true;

					// inhalt des Feldes populieren
					String^ tmp;
					charToString(currSource->fields[0].content, &tmp);
					value1->Text = tmp;

					// art des Feldes populieren
					char buff[20];
					readFieldtype(currSource->fields[0].type, buff);

					charToString(buff, &tmp);
					field1->Text = tmp;

					// inhalt mögl. veränderbar
					value1->ReadOnly = !isEditable;
				}
				else {
					value1->Visible = false;
					field1->Visible = false;
				}

				// wiederholen für alle anderen Felder, da iterierbare Liste aus den Feldern viel zu komplex anzulegen
				if (currSource->fields[1].type != empty) {
					value2->Visible = true;
					field2->Visible = true;

					String^ tmp;
					charToString(currSource->fields[1].content, &tmp);
					value2->Text = tmp;

					char buff[20];
					readFieldtype(currSource->fields[1].type, buff);

					charToString(buff, &tmp);
					field2->Text = tmp;

					value2->ReadOnly = !isEditable;
				}
				else {
					value2->Visible = false;
					field2->Visible = false;
				}

				if (currSource->fields[2].type != empty) {
					value3->Visible = true;
					field3->Visible = true;

					String^ tmp;
					charToString(currSource->fields[2].content, &tmp);
					value3->Text = tmp;

					char buff[20];
					readFieldtype(currSource->fields[2].type, buff);

					charToString(buff, &tmp);
					field3->Text = tmp;

					value3->ReadOnly = !isEditable;
				}
				else {
					value3->Visible = false;
					field3->Visible = false;
				}

				if (currSource->fields[3].type != empty) {
					value4->Visible = true;
					field4->Visible = true;

					String^ tmp;
					charToString(currSource->fields[3].content, &tmp);
					value4->Text = tmp;

					char buff[20];
					readFieldtype(currSource->fields[3].type, buff);

					charToString(buff, &tmp);
					field4->Text = tmp;

					value4->ReadOnly = !isEditable;
				}
				else {
					value4->Visible = false;
					field4->Visible = false;
				}

				if (currSource->fields[4].type != empty) {
					value5->Visible = true;
					field5->Visible = true;

					String^ tmp;
					charToString(currSource->fields[4].content, &tmp);
					value5->Text = tmp;

					char buff[20];
					readFieldtype(currSource->fields[4].type, buff);

					charToString(buff, &tmp);
					field5->Text = tmp;

					value5->ReadOnly = !isEditable;
				}
				else {
					value5->Visible = false;
					field5->Visible = false;
				}

				if (currSource->fields[5].type != empty) {
					value6->Visible = true;
					field6->Visible = true;

					String^ tmp;
					charToString(currSource->fields[5].content, &tmp);
					value6->Text = tmp;

					char buff[20];
					readFieldtype(currSource->fields[5].type, buff);

					charToString(buff, &tmp);
					field6->Text = tmp;

					value6->ReadOnly = !isEditable;
				}
				else {
					value6->Visible = false;
					field6->Visible = false;
				}

				/*
					special "or"-field possible at:
					- inbook 0:authororeditor; 2:chapterandorpages
					- book 0:authororeditor
				*/
				// sonderfall mit variablen Felderbezeichnungen abfangen
				if (isEditable && currSource->variant == book) {
					// put Dropdown at location of output field
					authororeditorDropdownComboBox->Visible = true;
					authororeditorDropdownComboBox->Location = field1->Location;
					authororeditorDropdownComboBox->Size = field1->Size;
					// disable output field
					field1->Visible = false;
					// set standart value
					switch (currSource->fields[0].type) {
					case author:
						authororeditorDropdownComboBox->SelectedIndex = 0;
						break;
					case editor:
						authororeditorDropdownComboBox->SelectedIndex = 1;
						break;
					default:
						authororeditorDropdownComboBox->SelectedIndex = 0;
						break;
					}
				}
				if (!isEditable) { authororeditorDropdownComboBox->Visible = false; }

				if (isEditable && currSource->variant == inbook) {
					// put Dropdown at location of output field
					authororeditorDropdownComboBox->Visible = true;
					authororeditorDropdownComboBox->Location = field1->Location;
					authororeditorDropdownComboBox->Size = field1->Size;
					// disable output field
					field1->Visible = false;
					// set standart value
					switch (currSource->fields[0].type) {
					case author:
						authororeditorDropdownComboBox->SelectedIndex = 0;
						break;
					case editor:
						authororeditorDropdownComboBox->SelectedIndex = 1;
						break;
					default:
						authororeditorDropdownComboBox->SelectedIndex = 0;
						break;
					}

					// put Dropdown at location of output field
					chapterandorpageDropdownComboBox->Visible = true;
					chapterandorpageDropdownComboBox->Location = field3->Location;
					chapterandorpageDropdownComboBox->Size = field3->Size;
					// disable output field
					field3->Visible = false;
					// set standart value
					switch (currSource->fields[2].type) {
					case chapter:
						chapterandorpageDropdownComboBox->SelectedIndex = 0;
						break;
					case pages:
						chapterandorpageDropdownComboBox->SelectedIndex = 1;
						break;
					default:
						chapterandorpageDropdownComboBox->SelectedIndex = 0;
						break;
					}
				}
				if (!isEditable) { chapterandorpageDropdownComboBox->Visible = false; }

				// Optionale Felder ausgeben
				int optFieldIndex = 0;

				// erstmal alle ausblenden, falls sie nicht verändert werden
				// -> keine leeren Felder anzeigen
				// (Ausgabe sieht sonst "zersprengt" aus)
				if (!isEditable) {
					// Set visibility to false for _field1 through _field8
					_field1->Visible = false;
					_value1->Visible = false;

					_field2->Visible = false;
					_value2->Visible = false;

					_field3->Visible = false;
					_value3->Visible = false;

					_field4->Visible = false;
					_value4->Visible = false;

					_field5->Visible = false;
					_value5->Visible = false;

					_field6->Visible = false;
					_value6->Visible = false;

					_field7->Visible = false;
					_value7->Visible = false;

					_field8->Visible = false;
					_value8->Visible = false;

					// alle leeren vor dem nächsten nicht leeren überspringen
					// wir wollen keine leeren optionalen Felder ausgeben -> sieht nicht aus
					while (!fieldHasContent(&currSource->optFields[optFieldIndex])) {
						optFieldIndex++;
						// wenn ´kein Feld inhalt hat, dann sind wir gleich fertig
						if (optFieldIndex >= 8) { return; }
					}
					// wir haben eine legitime Ausgabe, also erstmal ein Feld anzeigen
					_field1->Visible = true;
					_value1->Visible = true;

					// wie bei zwingenden Feldern ausgeben...
					String^ tmp;
					charToString(currSource->optFields[optFieldIndex].content, &tmp);
					_value1->Text = tmp;

					char buff[20];
					readFieldtype(currSource->optFields[optFieldIndex].type, buff);

					charToString(buff, &tmp);
					_field1->Text = tmp;
					optFieldIndex++;

					// _field2
					// hier dann immer wieder das Gleiche...
					while (!fieldHasContent(&currSource->optFields[optFieldIndex])) {
						optFieldIndex++;

						if (optFieldIndex >= 8) { return; }
					}
					_field2->Visible = true;
					_value2->Visible = true;

					tmp;
					charToString(currSource->optFields[optFieldIndex].content, &tmp);
					_value2->Text = tmp;

					readFieldtype(currSource->optFields[optFieldIndex].type, buff);

					charToString(buff, &tmp);
					_field2->Text = tmp;
					optFieldIndex++;

					// _field3
					// alle leeren vor dem nächsten nicht leeren überspringen
					while (!fieldHasContent(&currSource->optFields[optFieldIndex])) {
						optFieldIndex++;

						if (optFieldIndex >= 8) { return; }
					}
					_field3->Visible = true;
					_value3->Visible = true;

					tmp;
					charToString(currSource->optFields[optFieldIndex].content, &tmp);
					_value3->Text = tmp;

					readFieldtype(currSource->optFields[optFieldIndex].type, buff);

					charToString(buff, &tmp);
					_field3->Text = tmp;
					optFieldIndex++;

					// _field4
					// alle leeren vor dem nächsten nicht leeren überspringen
					while (!fieldHasContent(&currSource->optFields[optFieldIndex])) {
						optFieldIndex++;

						if (optFieldIndex >= 8) { return; }
					}
					_field4->Visible = true;
					_value4->Visible = true;

					tmp;
					charToString(currSource->optFields[optFieldIndex].content, &tmp);
					_value4->Text = tmp;

					readFieldtype(currSource->optFields[optFieldIndex].type, buff);

					charToString(buff, &tmp);
					_field4->Text = tmp;
					optFieldIndex++;

					// _field4
					// alle leeren vor dem nächsten nicht leeren überspringen
					while (!fieldHasContent(&currSource->optFields[optFieldIndex])) {
						optFieldIndex++;

						if (optFieldIndex >= 8) { return; }
					}
					_field5->Visible = true;
					_value5->Visible = true;

					tmp;
					charToString(currSource->optFields[optFieldIndex].content, &tmp);
					_value5->Text = tmp;

					readFieldtype(currSource->optFields[optFieldIndex].type, buff);

					charToString(buff, &tmp);
					_field5->Text = tmp;
					optFieldIndex++;

					// _field6
					// alle leeren vor dem nächsten nicht leeren überspringen
					while (!fieldHasContent(&currSource->optFields[optFieldIndex])) {
						optFieldIndex++;

						if (optFieldIndex >= 8) { return; }
					}
					_field6->Visible = true;
					_value6->Visible = true;

					tmp;
					charToString(currSource->optFields[optFieldIndex].content, &tmp);
					_value6->Text = tmp;

					readFieldtype(currSource->optFields[optFieldIndex].type, buff);

					charToString(buff, &tmp);
					_field6->Text = tmp;
					optFieldIndex++;

					// _field7
					// alle leeren vor dem nächsten nicht leeren überspringen
					while (!fieldHasContent(&currSource->optFields[optFieldIndex])) {
						optFieldIndex++;

						if (optFieldIndex >= 8) { return; }
					}
					_field7->Visible = true;
					_value7->Visible = true;

					tmp;
					charToString(currSource->optFields[optFieldIndex].content, &tmp);
					_value7->Text = tmp;

					readFieldtype(currSource->optFields[optFieldIndex].type, buff);

					charToString(buff, &tmp);
					_field7->Text = tmp;
					optFieldIndex++;

					// _field8
					// alle leeren vor dem nächsten nicht leeren überspringen
					while (!fieldHasContent(&currSource->optFields[optFieldIndex])) {
						optFieldIndex++;

						if (optFieldIndex >= 8) { return; }
					}
					_field8->Visible = true;
					_value8->Visible = true;

					tmp;
					charToString(currSource->optFields[optFieldIndex].content, &tmp);
					_value8->Text = tmp;

					readFieldtype(currSource->optFields[optFieldIndex].type, buff);

					charToString(buff, &tmp);
					_field8->Text = tmp;
					optFieldIndex++;
				}
				// beim editieren wollen wir auf alle Felder zugreifen können...
				// ausgabe genau wie bei zwingenden
				else {
					// _field 1
					if (currSource->optFields[0].type != empty) {
						_field1->Visible = true;
						_value1->Visible = true;

						String^ tmp;
						charToString(currSource->optFields[0].content, &tmp);
						_value1->Text = tmp;

						char buff[20];
						readFieldtype(currSource->optFields[0].type, buff);

						charToString(buff, &tmp);
						_field1->Text = tmp;

						_value1->ReadOnly = !isEditable;
					}
					else {
						_field1->Visible = false;
						_value1->Visible = false;
					}

					// _field 2
					if (currSource->optFields[1].type != empty) {
						_field2->Visible = true;
						_value2->Visible = true;

						String^ tmp;
						charToString(currSource->optFields[1].content, &tmp);  // Incremented index for optFields array
						_value2->Text = tmp;

						char buff[20];
						readFieldtype(currSource->optFields[1].type, buff);  // Incremented index for optFields array

						charToString(buff, &tmp);
						_field2->Text = tmp;

						_value2->ReadOnly = !isEditable;
					}
					else {
						_field2->Visible = false;
						_value2->Visible = false;
					}

					// _field 3
					if (currSource->optFields[2].type != empty) {
						_field3->Visible = true;
						_value3->Visible = true;

						String^ tmp;
						charToString(currSource->optFields[2].content, &tmp);  // Incremented index for optFields array
						_value3->Text = tmp;

						char buff[20];
						readFieldtype(currSource->optFields[2].type, buff);  // Incremented index for optFields array

						charToString(buff, &tmp);
						_field3->Text = tmp;

						_value3->ReadOnly = !isEditable;
					}
					else {
						_field3->Visible = false;
						_value3->Visible = false;
					}

					// _field 4
					if (currSource->optFields[3].type != empty) {
						_field4->Visible = true;
						_value4->Visible = true;

						String^ tmp;
						charToString(currSource->optFields[3].content, &tmp);  // Incremented index for optFields array
						_value4->Text = tmp;

						char buff[20];
						readFieldtype(currSource->optFields[3].type, buff);  // Incremented index for optFields array

						charToString(buff, &tmp);
						_field4->Text = tmp;

						_value4->ReadOnly = !isEditable;
					}
					else {
						_field4->Visible = false;
						_value4->Visible = false;
					}

					// _field 5
					if (currSource->optFields[4].type != empty) {
						_field5->Visible = true;
						_value5->Visible = true;

						String^ tmp;
						charToString(currSource->optFields[4].content, &tmp);  // Incremented index for optFields array
						_value5->Text = tmp;

						char buff[20];
						readFieldtype(currSource->optFields[4].type, buff);  // Incremented index for optFields array

						charToString(buff, &tmp);
						_field5->Text = tmp;

						_value5->ReadOnly = !isEditable;
					}
					else {
						_field5->Visible = false;
						_value5->Visible = false;
					}

					// _field 6
					if (currSource->optFields[5].type != empty) {
						_field6->Visible = true;
						_value6->Visible = true;

						String^ tmp;
						charToString(currSource->optFields[5].content, &tmp);  // Incremented index for optFields array
						_value6->Text = tmp;

						char buff[20];
						readFieldtype(currSource->optFields[5].type, buff);  // Incremented index for optFields array

						charToString(buff, &tmp);
						_field6->Text = tmp;

						_value6->ReadOnly = !isEditable;
					}
					else {
						_field6->Visible = false;
						_value6->Visible = false;
					}

					// _field 7
					if (currSource->optFields[6].type != empty) {
						_field7->Visible = true;
						_value7->Visible = true;

						String^ tmp;
						charToString(currSource->optFields[6].content, &tmp);  // Incremented index for optFields array
						_value7->Text = tmp;

						char buff[20];
						readFieldtype(currSource->optFields[6].type, buff);  // Incremented index for optFields array

						charToString(buff, &tmp);
						_field7->Text = tmp;

						_value7->ReadOnly = !isEditable;
					}
					else {
						_field7->Visible = false;
						_value7->Visible = false;
					}

					// _field 8
					if (currSource->optFields[7].type != empty) {
						_field8->Visible = true;
						_value8->Visible = true;

						String^ tmp;
						charToString(currSource->optFields[7].content, &tmp);  // Incremented index for optFields array
						_value8->Text = tmp;

						char buff[20];
						readFieldtype(currSource->optFields[7].type, buff);  // Incremented index for optFields array

						charToString(buff, &tmp);
						_field8->Text = tmp;

						_value8->ReadOnly = !isEditable;
					}
					else {
						_field8->Visible = false;
						_value8->Visible = false;
					}
				}
			}

			else { // kein Inhalt in der Quelle
				// hier sollten wir nie hinkommen, außer wenn alle Datensätze gelöscht werden
				// Leere dem Nutzer darstellen
				field1->Text = "keine Daten vorhanden";
				field2->Text = "keine Daten vorhanden";
				field3->Text = "keine Daten vorhanden";
				field4->Text = "keine Daten vorhanden";
				field5->Text = "keine Daten vorhanden";
				field6->Text = "keine Daten vorhanden";
				_field1->Text = "keine Daten vorhanden";
				_field2->Text = "keine Daten vorhanden";
				_field3->Text = "keine Daten vorhanden";
				_field4->Text = "keine Daten vorhanden";
				_field5->Text = "keine Daten vorhanden";
				_field6->Text = "keine Daten vorhanden";
				_field7->Text = "keine Daten vorhanden";
				_field8->Text = "keine Daten vorhanden";

				value1->Text = "keine Daten vorhanden";
				value2->Text = "keine Daten vorhanden";
				value3->Text = "keine Daten vorhanden";
				value4->Text = "keine Daten vorhanden";
				value5->Text = "keine Daten vorhanden";
				value6->Text = "keine Daten vorhanden";
				_value1->Text = "keine Daten vorhanden";
				_value2->Text = "keine Daten vorhanden";
				_value3->Text = "keine Daten vorhanden";
				_value4->Text = "keine Daten vorhanden";
				_value5->Text = "keine Daten vorhanden";
				_value6->Text = "keine Daten vorhanden";
				_value7->Text = "keine Daten vorhanden";
				_value8->Text = "keine Daten vorhanden";
			}
		}

		// speichern der geänderten Daten
		int saveToSource() {
			// TODO extend to filter out faulty/empty non-optional field entries
			Source* currSource = &db->sources[currEntry];

			// save key
			// muss inhalt haben
			if (!keyField->Text->Length > 0) { return 0; }
			StringToChar(currSource->key, keyField->Text);

			// save needed fields
			Field* currField = &currSource->fields[0];
			if (fieldValid(currField) && value1->Text->Length > 0) {
				StringToChar(currField->content, value1->Text);
			}
			// user-input muss hier existieren, das Feld ist notwendig -> muss einen Wert haben wenn nicht empty
			else if (fieldValid(currField)) { return 0; }
			
			if (currSource->variant == book || currSource->variant == inbook) {
				switch (authororeditorDropdownComboBox->SelectedIndex) {
				case 0:
					currField->type = author;
					break;
				case 1:
					currField->type = editor;
					break;
				default:
					currField->type = author;
					break;
				}
			}

			currField = &currSource->fields[1];
			if (fieldValid(currField) && value2->Text->Length > 0) {
				StringToChar(currField->content, value2->Text);
			}
			else if (fieldValid(currField)) { return 0; }

			currField = &currSource->fields[2];
			if (fieldValid(currField) && value3->Text->Length > 0) {
				StringToChar(currField->content, value3->Text);
			}
			else if (fieldValid(currField)) { return 0; }

			// sonderfall -> dropdown ausgabe ersetzt aktuellen FieldType
			if (currSource->variant == inbook) {
				switch (chapterandorpageDropdownComboBox->SelectedIndex) {
				case 0:
					currField->type = chapter;
					break;
				case 1:
					currField->type = pages;
					break;
				default:
					currField->type = chapter;
					break;
				}
			}

			currField = &currSource->fields[3];
			if (fieldValid(currField) && value4->Text->Length > 0) {
				StringToChar(currField->content, value4->Text);
			}
			else if (fieldValid(currField)) { return 0; }

			currField = &currSource->fields[4];
			if (fieldValid(currField) && value5->Text->Length > 0) {
				StringToChar(currField->content, value5->Text);
			}
			else if (fieldValid(currField)) { return 0; }

			currField = &currSource->fields[5];
			if (fieldValid(currField) && value6->Text->Length > 0) {
				StringToChar(currField->content, value6->Text);
			}
			else if (fieldValid(currField)) { return 0; }

			// opt fields speichern
			// _field1
			currField = &currSource->optFields[0];
			if (fieldValid(currField) && _value1->Text->Length > 0) {
				StringToChar(currField->content, _value1->Text);
			}

			// _field2
			currField = &currSource->optFields[1];
			if (fieldValid(currField) && _value2->Text->Length > 0) {
				StringToChar(currField->content, _value2->Text);
			}

			// _field3
			currField = &currSource->optFields[2];
			if (fieldValid(currField) && _value3->Text->Length > 0) {
				StringToChar(currField->content, _value3->Text);
			}

			// _field4
			currField = &currSource->optFields[3];
			if (fieldValid(currField) && _value4->Text->Length > 0) {
				StringToChar(currField->content, _value4->Text);
			}

			// _field5
			currField = &currSource->optFields[4];
			if (fieldValid(currField) && _value5->Text->Length > 0) {
				StringToChar(currField->content, _value5->Text);
			}

			// _field6
			currField = &currSource->optFields[5];
			if (fieldValid(currField) && _value6->Text->Length > 0) {
				StringToChar(currField->content, _value6->Text);
			}

			// _field7
			currField = &currSource->optFields[6];
			if (fieldValid(currField) && _value7->Text->Length > 0) {
				StringToChar(currField->content, _value7->Text);
			}

			// _field8
			currField = &currSource->optFields[7];
			if (fieldValid(currField) && _value8->Text->Length > 0) {
				StringToChar(currField->content, _value8->Text);
			}
			return 1;
		}
		
		// util zum Leeren
		void resetFields() {
			field1->Text = "";
			field1->ReadOnly = true;

			field2->Text = "";
			field2->ReadOnly = true;

			field3->Text = "";
			field3->ReadOnly = true;

			field4->Text = "";
			field4->ReadOnly = true;

			field5->Text = "";
			field5->ReadOnly = true;

			field6->Text = "";
			field6->ReadOnly = true;

			value1->Text = "";
			value1->ReadOnly = true;

			value2->Text = "";
			value2->ReadOnly = true;

			value3->Text = "";
			value3->ReadOnly = true;

			value4->Text = "";
			field4->ReadOnly = true;

			value5->Text = "";
			value5->ReadOnly = true;

			value6->Text = "";
			value6->ReadOnly = true;

			_field1->Text = "";
			_field1->ReadOnly = true;

			_field2->Text = "";
			_field2->ReadOnly = true;

			_field3->Text = "";
			_field3->ReadOnly = true;

			_field4->Text = "";
			_field4->ReadOnly = true;

			_field5->Text = "";
			_field5->ReadOnly = true;

			_field6->Text = "";
			_field6->ReadOnly = true;

			_field7->Text = "";
			_field7->ReadOnly = true;

			_field8->Text = "";
			_field8->ReadOnly = true;

			_value1->Text = "";
			_value1->ReadOnly = true;

			_value2->Text = "";
			_value2->ReadOnly = true;

			_value3->Text = "";
			_value3->ReadOnly = true;

			_value4->Text = "";
			_field4->ReadOnly = true;

			_value5->Text = "";
			_value5->ReadOnly = true;

			_value6->Text = "";
			_value6->ReadOnly = true;

			_value7->Text = "";
			_value7->ReadOnly = true;

			_value8->Text = "";
			_value8->ReadOnly = true;
		}

	protected: 
		DataBank* db;
		bool isInited;
		SearchResults* searchResults;
		int searchIndex;
	public: 
		bool* newSorceCreated;
		bool* isSearching;
	private: System::Windows::Forms::Button^  saveChangeButton;
private: System::Windows::Forms::Button^  cancelButton;
private: System::Windows::Forms::TextBox^  keyField;

private: System::Windows::Forms::TextBox^  sourceTypeTextBox;
private: System::Windows::Forms::TextBox^  currIndexTextBox;
private: System::Windows::Forms::ComboBox^  authororeditorDropdownComboBox;

private: System::Windows::Forms::ComboBox^  chapterandorpageDropdownComboBox;
private: System::Windows::Forms::Label^  suchtLabel;

private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::PictureBox^  pictureBox2;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::PictureBox^  pictureBox3;
private: System::Windows::Forms::ToolTip^  toolTip1;
private: System::Windows::Forms::ToolTip^  toolTip5;
private: System::Windows::Forms::ToolTip^  toolTip6;
private: System::Windows::Forms::ToolTip^  toolTip4;
private: System::Windows::Forms::ToolTip^  toolTip2;
private: System::Windows::Forms::ToolTip^  toolTip3;
private: System::Windows::Forms::ToolTip^  toolTip10;
private: System::Windows::Forms::ToolTip^  toolTip9;
private: System::Windows::Forms::ToolTip^  toolTip11;
private: System::Windows::Forms::ToolTip^  toolTip8;
private: System::Windows::Forms::ToolTip^  toolTip7;
private: System::Windows::Forms::ToolTip^  toolTip12;

private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label5;





	protected:
		int currEntry;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip1;

	private: System::Windows::Forms::ToolStripMenuItem^  dateiToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  helpButton;

	private: System::Windows::Forms::ToolStripMenuItem^  searchButton;

	private: System::Windows::Forms::ToolStripMenuItem^  neuToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  speichernToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  ladenToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  exportToolStripMenuItem;

	private: System::Windows::Forms::Button^  lastButton;

	private: System::Windows::Forms::Button^  changeButton;

	private: System::Windows::Forms::Button^  deleteButton;

	private: System::Windows::Forms::Button^  nextButton;



	private: System::Windows::Forms::TextBox^  field1;

	private: System::Windows::Forms::TextBox^  field2;

	private: System::Windows::Forms::TextBox^  field3;

	private: System::Windows::Forms::TextBox^  value1;

	private: System::Windows::Forms::TextBox^  value2;

	private: System::Windows::Forms::TextBox^  value3;

	private: System::Windows::Forms::TextBox^  value6;

	private: System::Windows::Forms::TextBox^  value5;

	private: System::Windows::Forms::TextBox^  value4;

	private: System::Windows::Forms::TextBox^  field6;

	private: System::Windows::Forms::TextBox^  field5;

	private: System::Windows::Forms::TextBox^  field4;

	private: System::Windows::Forms::TextBox^  _value3;

	private: System::Windows::Forms::TextBox^  _value2;

	private: System::Windows::Forms::TextBox^  _value1;

	private: System::Windows::Forms::TextBox^  _field3;

	private: System::Windows::Forms::TextBox^  _field2;

	private: System::Windows::Forms::TextBox^  _field1;

	private: System::Windows::Forms::TextBox^  _value4;

	private: System::Windows::Forms::TextBox^  _field4;

	private: System::Windows::Forms::TextBox^  _value8;

	private: System::Windows::Forms::TextBox^  _field8;

	private: System::Windows::Forms::TextBox^  _value7;

	private: System::Windows::Forms::TextBox^  _value6;

	private: System::Windows::Forms::TextBox^  _value5;

	private: System::Windows::Forms::TextBox^  _field7;

	private: System::Windows::Forms::TextBox^  _field6;

	private: System::Windows::Forms::TextBox^  _field5;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->dateiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->neuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->speichernToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ladenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpButton = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->searchButton = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lastButton = (gcnew System::Windows::Forms::Button());
			this->changeButton = (gcnew System::Windows::Forms::Button());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->nextButton = (gcnew System::Windows::Forms::Button());
			this->field1 = (gcnew System::Windows::Forms::TextBox());
			this->field2 = (gcnew System::Windows::Forms::TextBox());
			this->field3 = (gcnew System::Windows::Forms::TextBox());
			this->value1 = (gcnew System::Windows::Forms::TextBox());
			this->value2 = (gcnew System::Windows::Forms::TextBox());
			this->value3 = (gcnew System::Windows::Forms::TextBox());
			this->value6 = (gcnew System::Windows::Forms::TextBox());
			this->value5 = (gcnew System::Windows::Forms::TextBox());
			this->value4 = (gcnew System::Windows::Forms::TextBox());
			this->field6 = (gcnew System::Windows::Forms::TextBox());
			this->field5 = (gcnew System::Windows::Forms::TextBox());
			this->field4 = (gcnew System::Windows::Forms::TextBox());
			this->_value3 = (gcnew System::Windows::Forms::TextBox());
			this->_value2 = (gcnew System::Windows::Forms::TextBox());
			this->_value1 = (gcnew System::Windows::Forms::TextBox());
			this->_field3 = (gcnew System::Windows::Forms::TextBox());
			this->_field2 = (gcnew System::Windows::Forms::TextBox());
			this->_field1 = (gcnew System::Windows::Forms::TextBox());
			this->_value4 = (gcnew System::Windows::Forms::TextBox());
			this->_field4 = (gcnew System::Windows::Forms::TextBox());
			this->_value8 = (gcnew System::Windows::Forms::TextBox());
			this->_field8 = (gcnew System::Windows::Forms::TextBox());
			this->_value7 = (gcnew System::Windows::Forms::TextBox());
			this->_value6 = (gcnew System::Windows::Forms::TextBox());
			this->_value5 = (gcnew System::Windows::Forms::TextBox());
			this->_field7 = (gcnew System::Windows::Forms::TextBox());
			this->_field6 = (gcnew System::Windows::Forms::TextBox());
			this->_field5 = (gcnew System::Windows::Forms::TextBox());
			this->saveChangeButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->keyField = (gcnew System::Windows::Forms::TextBox());
			this->sourceTypeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->currIndexTextBox = (gcnew System::Windows::Forms::TextBox());
			this->authororeditorDropdownComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->chapterandorpageDropdownComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->suchtLabel = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip2 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip3 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip4 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip5 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip6 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip7 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip8 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip9 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip10 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip11 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip12 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->dateiToolStripMenuItem,
					this->helpButton, this->searchButton
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->MinimumSize = System::Drawing::Size(0, 36);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(6, 1, 0, 1);
			this->menuStrip1->Size = System::Drawing::Size(802, 36);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// dateiToolStripMenuItem
			// 
			this->dateiToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->neuToolStripMenuItem,
					this->speichernToolStripMenuItem, this->ladenToolStripMenuItem, this->exportToolStripMenuItem
			});
			this->dateiToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dateiToolStripMenuItem->Name = L"dateiToolStripMenuItem";
			this->dateiToolStripMenuItem->Size = System::Drawing::Size(52, 34);
			this->dateiToolStripMenuItem->Text = L"Datei";
			this->dateiToolStripMenuItem->ToolTipText = L"Aktion auswählen";
			// 
			// neuToolStripMenuItem
			// 
			this->neuToolStripMenuItem->Name = L"neuToolStripMenuItem";
			this->neuToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->neuToolStripMenuItem->Text = L"Neu";
			this->neuToolStripMenuItem->ToolTipText = L"Eintrag hinzufügen";
			this->neuToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::neuToolStripMenuItem_Click);
			// 
			// speichernToolStripMenuItem
			// 
			this->speichernToolStripMenuItem->Name = L"speichernToolStripMenuItem";
			this->speichernToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->speichernToolStripMenuItem->Text = L"Speichern";
			this->speichernToolStripMenuItem->ToolTipText = L"Einträge speichern";
			this->speichernToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::speichernToolStripMenuItem_Click);
			// 
			// ladenToolStripMenuItem
			// 
			this->ladenToolStripMenuItem->Name = L"ladenToolStripMenuItem";
			this->ladenToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->ladenToolStripMenuItem->Text = L"Laden";
			this->ladenToolStripMenuItem->ToolTipText = L"Einträge laden";
			this->ladenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ladenToolStripMenuItem_Click);
			// 
			// exportToolStripMenuItem
			// 
			this->exportToolStripMenuItem->Name = L"exportToolStripMenuItem";
			this->exportToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->exportToolStripMenuItem->Text = L"Export";
			this->exportToolStripMenuItem->ToolTipText = L"Einträge exportieren";
			this->exportToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exportToolStripMenuItem_Click);
			// 
			// helpButton
			// 
			this->helpButton->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->helpButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->helpButton->Name = L"helpButton";
			this->helpButton->Size = System::Drawing::Size(27, 34);
			this->helpButton->Text = L"\?";
			this->helpButton->ToolTipText = L"Hilfe";
			// 
			// searchButton
			// 
			this->searchButton->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->searchButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"searchButton.Image")));
			this->searchButton->Margin = System::Windows::Forms::Padding(1);
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(87, 32);
			this->searchButton->Text = L"suchen";
			this->searchButton->ToolTipText = L"nach Einträgen suchen";
			this->searchButton->Click += gcnew System::EventHandler(this, &MyForm::searchButton_Click);
			// 
			// lastButton
			// 
			this->lastButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lastButton->Location = System::Drawing::Point(138, 527);
			this->lastButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->lastButton->Name = L"lastButton";
			this->lastButton->Size = System::Drawing::Size(112, 35);
			this->lastButton->TabIndex = 2;
			this->lastButton->Text = L"<";
			this->toolTip1->SetToolTip(this->lastButton, L"Gehe zur vorherigen Seite");
			this->lastButton->UseVisualStyleBackColor = true;
			this->lastButton->Click += gcnew System::EventHandler(this, &MyForm::lastButton_Click);
			// 
			// changeButton
			// 
			this->changeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->changeButton->Location = System::Drawing::Point(272, 527);
			this->changeButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->changeButton->Name = L"changeButton";
			this->changeButton->Size = System::Drawing::Size(112, 35);
			this->changeButton->TabIndex = 3;
			this->changeButton->Text = L"Ändern";
			this->toolTip5->SetToolTip(this->changeButton, L"Eintrag ändern");
			this->changeButton->UseVisualStyleBackColor = true;
			this->changeButton->Click += gcnew System::EventHandler(this, &MyForm::changeButton_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deleteButton->Location = System::Drawing::Point(409, 527);
			this->deleteButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(112, 35);
			this->deleteButton->TabIndex = 4;
			this->deleteButton->Text = L"Löschen";
			this->toolTip6->SetToolTip(this->deleteButton, L"Eintrag löschen");
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &MyForm::deleteButton_Click);
			// 
			// nextButton
			// 
			this->nextButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nextButton->Location = System::Drawing::Point(546, 527);
			this->nextButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->nextButton->Name = L"nextButton";
			this->nextButton->Size = System::Drawing::Size(112, 35);
			this->nextButton->TabIndex = 5;
			this->nextButton->Text = L">";
			this->toolTip4->SetToolTip(this->nextButton, L"Gehe zur nächsten Seite");
			this->nextButton->UseVisualStyleBackColor = true;
			this->nextButton->Click += gcnew System::EventHandler(this, &MyForm::nextButton_Click);
			// 
			// field1
			// 
			this->field1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->field1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->field1->Location = System::Drawing::Point(89, 146);
			this->field1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->field1->Name = L"field1";
			this->field1->ReadOnly = true;
			this->field1->Size = System::Drawing::Size(108, 22);
			this->field1->TabIndex = 9;
			this->field1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// field2
			// 
			this->field2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->field2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->field2->Location = System::Drawing::Point(89, 185);
			this->field2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->field2->Name = L"field2";
			this->field2->ReadOnly = true;
			this->field2->Size = System::Drawing::Size(108, 22);
			this->field2->TabIndex = 10;
			this->field2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// field3
			// 
			this->field3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->field3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->field3->Location = System::Drawing::Point(89, 225);
			this->field3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->field3->Name = L"field3";
			this->field3->ReadOnly = true;
			this->field3->Size = System::Drawing::Size(108, 22);
			this->field3->TabIndex = 11;
			this->field3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// value1
			// 
			this->value1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->value1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->value1->Location = System::Drawing::Point(208, 146);
			this->value1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->value1->MaxLength = 99;
			this->value1->Name = L"value1";
			this->value1->ReadOnly = true;
			this->value1->Size = System::Drawing::Size(180, 22);
			this->value1->TabIndex = 12;
			// 
			// value2
			// 
			this->value2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->value2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->value2->Location = System::Drawing::Point(208, 185);
			this->value2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->value2->MaxLength = 99;
			this->value2->Name = L"value2";
			this->value2->ReadOnly = true;
			this->value2->Size = System::Drawing::Size(180, 22);
			this->value2->TabIndex = 13;
			// 
			// value3
			// 
			this->value3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->value3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->value3->Location = System::Drawing::Point(208, 225);
			this->value3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->value3->MaxLength = 99;
			this->value3->Name = L"value3";
			this->value3->ReadOnly = true;
			this->value3->Size = System::Drawing::Size(180, 22);
			this->value3->TabIndex = 14;
			// 
			// value6
			// 
			this->value6->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->value6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->value6->Location = System::Drawing::Point(549, 225);
			this->value6->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->value6->MaxLength = 99;
			this->value6->Name = L"value6";
			this->value6->ReadOnly = true;
			this->value6->Size = System::Drawing::Size(180, 22);
			this->value6->TabIndex = 20;
			// 
			// value5
			// 
			this->value5->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->value5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->value5->Location = System::Drawing::Point(549, 185);
			this->value5->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->value5->MaxLength = 99;
			this->value5->Name = L"value5";
			this->value5->ReadOnly = true;
			this->value5->Size = System::Drawing::Size(180, 22);
			this->value5->TabIndex = 19;
			// 
			// value4
			// 
			this->value4->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->value4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->value4->Location = System::Drawing::Point(549, 146);
			this->value4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->value4->MaxLength = 99;
			this->value4->Name = L"value4";
			this->value4->ReadOnly = true;
			this->value4->Size = System::Drawing::Size(180, 22);
			this->value4->TabIndex = 18;
			// 
			// field6
			// 
			this->field6->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->field6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->field6->Location = System::Drawing::Point(430, 225);
			this->field6->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->field6->Name = L"field6";
			this->field6->ReadOnly = true;
			this->field6->Size = System::Drawing::Size(108, 22);
			this->field6->TabIndex = 17;
			this->field6->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// field5
			// 
			this->field5->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->field5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->field5->Location = System::Drawing::Point(430, 185);
			this->field5->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->field5->Name = L"field5";
			this->field5->ReadOnly = true;
			this->field5->Size = System::Drawing::Size(108, 22);
			this->field5->TabIndex = 16;
			this->field5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// field4
			// 
			this->field4->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->field4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->field4->Location = System::Drawing::Point(430, 146);
			this->field4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->field4->Name = L"field4";
			this->field4->ReadOnly = true;
			this->field4->Size = System::Drawing::Size(108, 22);
			this->field4->TabIndex = 15;
			this->field4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// _value3
			// 
			this->_value3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->_value3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_value3->Location = System::Drawing::Point(208, 409);
			this->_value3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_value3->MaxLength = 99;
			this->_value3->Name = L"_value3";
			this->_value3->ReadOnly = true;
			this->_value3->Size = System::Drawing::Size(180, 22);
			this->_value3->TabIndex = 26;
			// 
			// _value2
			// 
			this->_value2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->_value2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_value2->Location = System::Drawing::Point(208, 373);
			this->_value2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_value2->MaxLength = 99;
			this->_value2->Name = L"_value2";
			this->_value2->ReadOnly = true;
			this->_value2->Size = System::Drawing::Size(180, 22);
			this->_value2->TabIndex = 25;
			// 
			// _value1
			// 
			this->_value1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->_value1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_value1->Location = System::Drawing::Point(208, 335);
			this->_value1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_value1->MaxLength = 99;
			this->_value1->Name = L"_value1";
			this->_value1->ReadOnly = true;
			this->_value1->Size = System::Drawing::Size(180, 22);
			this->_value1->TabIndex = 24;
			// 
			// _field3
			// 
			this->_field3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->_field3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_field3->Location = System::Drawing::Point(89, 409);
			this->_field3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_field3->Name = L"_field3";
			this->_field3->ReadOnly = true;
			this->_field3->Size = System::Drawing::Size(108, 22);
			this->_field3->TabIndex = 23;
			this->_field3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// _field2
			// 
			this->_field2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->_field2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_field2->Location = System::Drawing::Point(89, 373);
			this->_field2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_field2->Name = L"_field2";
			this->_field2->ReadOnly = true;
			this->_field2->Size = System::Drawing::Size(108, 22);
			this->_field2->TabIndex = 22;
			this->_field2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// _field1
			// 
			this->_field1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->_field1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_field1->Location = System::Drawing::Point(89, 335);
			this->_field1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_field1->Name = L"_field1";
			this->_field1->ReadOnly = true;
			this->_field1->Size = System::Drawing::Size(108, 22);
			this->_field1->TabIndex = 21;
			this->_field1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// _value4
			// 
			this->_value4->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->_value4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_value4->Location = System::Drawing::Point(208, 447);
			this->_value4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_value4->MaxLength = 99;
			this->_value4->Name = L"_value4";
			this->_value4->ReadOnly = true;
			this->_value4->Size = System::Drawing::Size(180, 22);
			this->_value4->TabIndex = 30;
			// 
			// _field4
			// 
			this->_field4->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->_field4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_field4->Location = System::Drawing::Point(89, 447);
			this->_field4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_field4->Name = L"_field4";
			this->_field4->ReadOnly = true;
			this->_field4->Size = System::Drawing::Size(108, 22);
			this->_field4->TabIndex = 27;
			this->_field4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// _value8
			// 
			this->_value8->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->_value8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_value8->Location = System::Drawing::Point(549, 447);
			this->_value8->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_value8->MaxLength = 99;
			this->_value8->Name = L"_value8";
			this->_value8->ReadOnly = true;
			this->_value8->Size = System::Drawing::Size(180, 22);
			this->_value8->TabIndex = 38;
			// 
			// _field8
			// 
			this->_field8->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->_field8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_field8->Location = System::Drawing::Point(430, 447);
			this->_field8->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_field8->Name = L"_field8";
			this->_field8->ReadOnly = true;
			this->_field8->Size = System::Drawing::Size(108, 22);
			this->_field8->TabIndex = 37;
			this->_field8->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// _value7
			// 
			this->_value7->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->_value7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_value7->Location = System::Drawing::Point(549, 409);
			this->_value7->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_value7->MaxLength = 99;
			this->_value7->Name = L"_value7";
			this->_value7->ReadOnly = true;
			this->_value7->Size = System::Drawing::Size(180, 22);
			this->_value7->TabIndex = 36;
			// 
			// _value6
			// 
			this->_value6->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->_value6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_value6->Location = System::Drawing::Point(549, 373);
			this->_value6->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_value6->MaxLength = 99;
			this->_value6->Name = L"_value6";
			this->_value6->ReadOnly = true;
			this->_value6->Size = System::Drawing::Size(180, 22);
			this->_value6->TabIndex = 35;
			// 
			// _value5
			// 
			this->_value5->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->_value5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_value5->Location = System::Drawing::Point(549, 335);
			this->_value5->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_value5->MaxLength = 99;
			this->_value5->Name = L"_value5";
			this->_value5->ReadOnly = true;
			this->_value5->Size = System::Drawing::Size(180, 22);
			this->_value5->TabIndex = 34;
			// 
			// _field7
			// 
			this->_field7->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->_field7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_field7->Location = System::Drawing::Point(430, 409);
			this->_field7->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_field7->Name = L"_field7";
			this->_field7->ReadOnly = true;
			this->_field7->Size = System::Drawing::Size(108, 22);
			this->_field7->TabIndex = 33;
			this->_field7->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// _field6
			// 
			this->_field6->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->_field6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_field6->Location = System::Drawing::Point(430, 373);
			this->_field6->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_field6->Name = L"_field6";
			this->_field6->ReadOnly = true;
			this->_field6->Size = System::Drawing::Size(108, 22);
			this->_field6->TabIndex = 32;
			this->_field6->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// _field5
			// 
			this->_field5->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->_field5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->_field5->Location = System::Drawing::Point(430, 335);
			this->_field5->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_field5->Name = L"_field5";
			this->_field5->ReadOnly = true;
			this->_field5->Size = System::Drawing::Size(108, 22);
			this->_field5->TabIndex = 31;
			this->_field5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// saveChangeButton
			// 
			this->saveChangeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->saveChangeButton->Location = System::Drawing::Point(272, 527);
			this->saveChangeButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->saveChangeButton->Name = L"saveChangeButton";
			this->saveChangeButton->Size = System::Drawing::Size(112, 35);
			this->saveChangeButton->TabIndex = 39;
			this->saveChangeButton->Text = L"Annehmen";
			this->toolTip2->SetToolTip(this->saveChangeButton, L"Änderungen speichern");
			this->saveChangeButton->UseVisualStyleBackColor = true;
			this->saveChangeButton->Visible = false;
			this->saveChangeButton->Click += gcnew System::EventHandler(this, &MyForm::saveChangeButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancelButton->Location = System::Drawing::Point(409, 527);
			this->cancelButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(112, 35);
			this->cancelButton->TabIndex = 40;
			this->cancelButton->Text = L"Abbrechen";
			this->toolTip3->SetToolTip(this->cancelButton, L"Änderungen verwerfen");
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Visible = false;
			this->cancelButton->Click += gcnew System::EventHandler(this, &MyForm::cancelButton_Click);
			// 
			// keyField
			// 
			this->keyField->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->keyField->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->keyField->Location = System::Drawing::Point(337, 98);
			this->keyField->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->keyField->Name = L"keyField";
			this->keyField->ReadOnly = true;
			this->keyField->Size = System::Drawing::Size(249, 22);
			this->keyField->TabIndex = 41;
			this->toolTip10->SetToolTip(this->keyField, L"Schlüsselwort");
			// 
			// sourceTypeTextBox
			// 
			this->sourceTypeTextBox->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->sourceTypeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->sourceTypeTextBox->Location = System::Drawing::Point(27, 98);
			this->sourceTypeTextBox->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->sourceTypeTextBox->Name = L"sourceTypeTextBox";
			this->sourceTypeTextBox->ReadOnly = true;
			this->sourceTypeTextBox->Size = System::Drawing::Size(105, 22);
			this->sourceTypeTextBox->TabIndex = 42;
			this->sourceTypeTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->toolTip9->SetToolTip(this->sourceTypeTextBox, L"Art der Literatur");
			// 
			// currIndexTextBox
			// 
			this->currIndexTextBox->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->currIndexTextBox->Location = System::Drawing::Point(731, 55);
			this->currIndexTextBox->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->currIndexTextBox->Name = L"currIndexTextBox";
			this->currIndexTextBox->ReadOnly = true;
			this->currIndexTextBox->Size = System::Drawing::Size(65, 20);
			this->currIndexTextBox->TabIndex = 43;
			this->toolTip11->SetToolTip(this->currIndexTextBox, L"Seitenanzahl");
			// 
			// authororeditorDropdownComboBox
			// 
			this->authororeditorDropdownComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->authororeditorDropdownComboBox->FormattingEnabled = true;
			this->authororeditorDropdownComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"author", L"editor" });
			this->authororeditorDropdownComboBox->Location = System::Drawing::Point(1, 183);
			this->authororeditorDropdownComboBox->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->authororeditorDropdownComboBox->Name = L"authororeditorDropdownComboBox";
			this->authororeditorDropdownComboBox->Size = System::Drawing::Size(82, 24);
			this->authororeditorDropdownComboBox->TabIndex = 44;
			this->authororeditorDropdownComboBox->Visible = false;
			// 
			// chapterandorpageDropdownComboBox
			// 
			this->chapterandorpageDropdownComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->chapterandorpageDropdownComboBox->FormattingEnabled = true;
			this->chapterandorpageDropdownComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"chapter", L"page" });
			this->chapterandorpageDropdownComboBox->Location = System::Drawing::Point(1, 223);
			this->chapterandorpageDropdownComboBox->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->chapterandorpageDropdownComboBox->Name = L"chapterandorpageDropdownComboBox";
			this->chapterandorpageDropdownComboBox->Size = System::Drawing::Size(82, 24);
			this->chapterandorpageDropdownComboBox->TabIndex = 45;
			this->chapterandorpageDropdownComboBox->Visible = false;
			// 
			// suchtLabel
			// 
			this->suchtLabel->AutoSize = true;
			this->suchtLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->suchtLabel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"suchtLabel.Image")));
			this->suchtLabel->Location = System::Drawing::Point(622, 56);
			this->suchtLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->suchtLabel->Name = L"suchtLabel";
			this->suchtLabel->Size = System::Drawing::Size(107, 16);
			this->suchtLabel->TabIndex = 46;
			this->suchtLabel->Text = L"Suchergebnis:";
			this->suchtLabel->Visible = false;
			this->suchtLabel->VisibleChanged += gcnew System::EventHandler(this, &MyForm::suchtLabel_VisibleChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-8, 498);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(813, 129);
			this->pictureBox1->TabIndex = 48;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(0, 276);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(802, 218);
			this->pictureBox2->TabIndex = 49;
			this->pictureBox2->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(342, 294);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(142, 20);
			this->label1->TabIndex = 50;
			this->label1->Text = L"Optionale Felder";
			this->toolTip8->SetToolTip(this->label1, L"Optionale Felder sind freiwillig");
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label2.Image")));
			this->label2->Location = System::Drawing::Point(331, 48);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(168, 20);
			this->label2->TabIndex = 51;
			this->label2->Text = L"Erforderliche Felder";
			this->toolTip7->SetToolTip(this->label2, L"Es müssen alle erforderlichen Felder ausgefüllt werden");
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(-8, 29);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(813, 241);
			this->pictureBox3->TabIndex = 52;
			this->pictureBox3->TabStop = false;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(236, 98);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(85, 22);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Schlüssel:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(28, 67);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(104, 22);
			this->label5->TabIndex = 54;
			this->label5->Text = L"Quellentyp";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(802, 591);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->suchtLabel);
			this->Controls->Add(this->chapterandorpageDropdownComboBox);
			this->Controls->Add(this->authororeditorDropdownComboBox);
			this->Controls->Add(this->currIndexTextBox);
			this->Controls->Add(this->sourceTypeTextBox);
			this->Controls->Add(this->keyField);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->saveChangeButton);
			this->Controls->Add(this->_value8);
			this->Controls->Add(this->_field8);
			this->Controls->Add(this->_value7);
			this->Controls->Add(this->_value6);
			this->Controls->Add(this->_value5);
			this->Controls->Add(this->_field7);
			this->Controls->Add(this->_field6);
			this->Controls->Add(this->_field5);
			this->Controls->Add(this->_value4);
			this->Controls->Add(this->_field4);
			this->Controls->Add(this->_value3);
			this->Controls->Add(this->_value2);
			this->Controls->Add(this->_value1);
			this->Controls->Add(this->_field3);
			this->Controls->Add(this->_field2);
			this->Controls->Add(this->_field1);
			this->Controls->Add(this->value6);
			this->Controls->Add(this->value5);
			this->Controls->Add(this->value4);
			this->Controls->Add(this->field6);
			this->Controls->Add(this->field5);
			this->Controls->Add(this->field4);
			this->Controls->Add(this->value3);
			this->Controls->Add(this->value2);
			this->Controls->Add(this->value1);
			this->Controls->Add(this->field3);
			this->Controls->Add(this->field2);
			this->Controls->Add(this->field1);
			this->Controls->Add(this->nextButton);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->changeButton);
			this->Controls->Add(this->lastButton);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"BibTex Datenbank-Verwaltung";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->VisibleChanged += gcnew System::EventHandler(this, &MyForm::MyForm_VisibleChanged);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

// Bedienungsanleitung öffnen
private: System::Void toolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	// TODO einbindung pdf machen/testen?
	System::String^ pdfPath = "Bedienungsanleitung.pdf";
	System::Diagnostics::Process::Start(pdfPath);
}
// in datei speichern
private: System::Void speichernToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (saveDB(db)) {
		MessageBox::Show("Erfolgreich gespeichert", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
// aus datei laden
private: System::Void ladenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (loadDB(db)) {
		MessageBox::Show("Erfolgreich geladen", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
// exportieren starten
private: System::Void exportToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (exportDB(db)) {
	
	}
}

// wie nachfolgende Methode, nur vorwärts
private: System::Void nextButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (isSearching && searchResults->entries > 0) {
		for (int j = 0; j < db->entries; j++) {
			currEntry = (currEntry >= db->entries - 1) ? 0 : currEntry + 1;
			for (int i = 0; i < searchResults->entries; i++) {
				if (&db->sources[currEntry] == searchResults->searchResults[i]) {
					searchIndex = i + 1;
					output(currEntry, false);
					return;
				}
			}
			
		}
	}
	currEntry = (currEntry >= db->entries-1) ? 0 : currEntry + 1;
	output(currEntry, false);
}
// rückwärts blättern
private: System::Void lastButton_Click(System::Object^  sender, System::EventArgs^  e) {	
	// wenn wir grade suchen, solange weiter gehen, bis aktuelle Quelle in den Suchergebnissen vorhanden ist
	if (isSearching && searchResults->entries > 0) {
		for (int j = 0; j < db->entries; j++) {
			currEntry = (currEntry <= 0) ? db->entries - 1 : currEntry - 1;
			for (int i = 0; i < searchResults->entries; i++) {
				if (&db->sources[currEntry] == searchResults->searchResults[i]) {
					searchIndex = i+1;
					output(currEntry, false);
					return;
				}
			}

		}


	}
	// wrap-around
	currEntry = (currEntry <= 0) ? db->entries-1 : currEntry - 1;
	output(currEntry, false);
}
// ändern der aktuellen Quelle starten
private: System::Void changeButton_Click(System::Object^  sender, System::EventArgs^  e) {
	output(currEntry, true);
	saveChangeButton->Visible = true;
	changeButton->Visible = false;
	cancelButton->Visible = true;
	nextButton->Visible = false;
	lastButton->Visible = false;
}
private: System::Void saveChangeButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->saveToSource()) {
		// wieder in Ausgabe wechseln
		output(currEntry, false);
		saveChangeButton->Visible = false;
		changeButton->Visible = true;
		cancelButton->Visible = false;
		nextButton->Visible = true;
		lastButton->Visible = true;
	}
	// nicht alles ausgefüllt
	else { MessageBox::Show("Zwingende Felder müssen alle Inhalt haben", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information); }
}
// neues Fenster öffnen -> Auswahl neuer Quellentyp
private: System::Void neuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Form^ f2 = gcnew MyForm1(this, db, newSorceCreated);
	f2->Show();
	// dies erstmal ausblenden, wird dann über das andere wieder geöffnet
	this->Visible = false;
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MyForm_VisibleChanged(System::Object^  sender, System::EventArgs^  e) {
	// triggert, wenn zweites Fenster zurückmeldet, dass neue Quelle angelegt wurde
	if (isInited && *newSorceCreated && Visible == true) {
		// die Neue Quelle direkt bearbeiten
		currEntry = db->entries - 1;
		output(currEntry, true);
		// Merker zurücksetzen
		*newSorceCreated = false;
		// Speicher Button anzeigen
		saveChangeButton->Visible = true;
		changeButton->Visible = false;
		nextButton->Visible = false;
		lastButton->Visible = false;
		// leeres key feld kompensieren
		keyField->Text = "";
	}
}
//ändern abbrechen -> nix neues speichern, wieder nnormale ausgabe
private: System::Void cancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
	output(currEntry, false);
	saveChangeButton->Visible = false;
	changeButton->Visible = true;
	cancelButton->Visible = false;
	nextButton->Visible = true;
	lastButton->Visible = true;
}
// aktuelle Quelle löschen
private: System::Void deleteButton_Click(System::Object^  sender, System::EventArgs^  e) {
	deleteEntry(db, currEntry);
	if (currEntry >= db->entries) { currEntry -= 1; }
	if (currEntry < 0) { currEntry = (db->entries <= 0)? 0 : db->entries - 1; }
	output(currEntry, false);
	nextButton->Visible = true;
	lastButton->Visible = true;
}
// starten des Suchfensters
private: System::Void searchButton_Click(System::Object^  sender, System::EventArgs^  e) {
	Form^ searchForm = gcnew MyForm2(db, searchResults, isSearching, suchtLabel);
	searchForm->Show();
}
private: System::Void suchtLabel_VisibleChanged(System::Object^  sender, System::EventArgs^  e) {
	// Hacky callback from search Form to trigger new output on search completion
	// import "MyForm.h" im zweiten Skript sorgt für Unmengen an Fehlern...
	// -> hier ein "toller" work-around


	changeButton->Visible = false;
	deleteButton->Visible = false;
	dateiToolStripMenuItem->Visible = false;
	searchButton->Visible = false;

	if (suchtLabel->Visible == true && isInited && isSearching) { 
		currEntry = 0;
		if (isSearching && searchResults->entries > 0) {
			for (int j = 0; j < db->entries; j++) {
				currEntry = (currEntry >= db->entries - 1) ? 0 : currEntry + 1;
				for (int i = 0; i < searchResults->entries; i++) {
					if (&db->sources[currEntry] == searchResults->searchResults[i]) {
						searchIndex = i + 1;
						output(currEntry, false);
						return;

					}

					
					
				}


			}


		}


	}



	// Hier suche beenden
	else if (suchtLabel->Visible == false && isInited) {
		output(currEntry, false);


		changeButton->Visible = true;
		deleteButton->Visible = true;
		dateiToolStripMenuItem->Visible = true;
		searchButton->Visible = true;

	}



}

};



}
