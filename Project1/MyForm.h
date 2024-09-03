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

			for (int i = 0; i < 1000; i++) { setNullSource(&db->sources[i]); }  // leere Quellen vorbereiten

			db->entries = 0;

			// Datenbank automatisch laden
			if (loadDB(db)) { // Laden erfolgreich
				MessageBox::Show("Quellenverzeichnis erfolgreich geladen. Es gibt %i Quellen...", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
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

		// overloading um spezifische Quellen auszugeben
		// vllt überflüssig
		MyForm(DataBank* suppliedDB, int index, bool isEdit)
		{
			InitializeComponent();

			db = suppliedDB;

			output(index, isEdit);

			isInited = true;
			*newSorceCreated = false;
		}

		void output(int index, bool isEditable) {
			Source* currSource = &db->sources[index];

			// Alles erstmal blank zurücksetzen
			resetFields();

			if (currSource->variant != nullSource) {
				// TODO für weitere Felder ausführen (bei optionalen Feldern logik einführen, dass von links nach recht, von oben nach unten populiert wird, dazwischen keine leeren Felder, da sieht kacke aus)
				//erstes feld populieren

				// index ausgeben
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
				
				// Name
				String^ name;
				charToString(currSource->key, &name);
				keyField->Text = name;
				keyField->ReadOnly = !isEditable;

				if (currSource->fields[0].type != empty) {
					value1->Visible = true;
					field1->Visible = true;

					String^ tmp;
					charToString(currSource->fields[0].content, &tmp);
					value1->Text = tmp;

					char buff[20];
					readFieldtype(currSource->fields[0].type, buff);

					charToString(buff, &tmp);
					field1->Text = tmp;

					value1->ReadOnly = !isEditable;
				}
				else {
					value1->Visible = false;
					field1->Visible = false;
				}

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
					while (!fieldHasContent(&currSource->optFields[optFieldIndex])) {
						optFieldIndex++;

						if (optFieldIndex >= 8) { return; }
					}
					_field1->Visible = true;
					_value1->Visible = true;

					String^ tmp;
					charToString(currSource->optFields[optFieldIndex].content, &tmp);
					_value1->Text = tmp;

					char buff[20];
					readFieldtype(currSource->optFields[optFieldIndex].type, buff);

					charToString(buff, &tmp);
					_field1->Text = tmp;
					optFieldIndex++;

					// _field2
					// alle leeren vor dem nächsten nicht leeren überspringen
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
				// alle ausgabe felder verstecken, ein neues einblenden als placeholder
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

		int saveToSource() {
			// TODO extend to filter out faulty/empty non-optional field entries
			Source* currSource = &db->sources[currEntry];

			// save key
			StringToChar(currSource->key, keyField->Text);

			// save needed fields
			Field* currField = &currSource->fields[0];
			if (fieldValid(currField) && value1->Text->Length > 0) {
				StringToChar(currField->content, value1->Text);
			}
			
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

			currField = &currSource->fields[2];
			if (fieldValid(currField) && value3->Text->Length > 0) {
				StringToChar(currField->content, value3->Text);
			}

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

			currField = &currSource->fields[4];
			if (fieldValid(currField) && value5->Text->Length > 0) {
				StringToChar(currField->content, value5->Text);
			}

			currField = &currSource->fields[5];
			if (fieldValid(currField) && value6->Text->Length > 0) {
				StringToChar(currField->content, value6->Text);
			}

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

			// TODO extend for optFields
			return 1;
		}
		
		// TODO fill all other fields
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
private: System::Windows::Forms::Label^  seperationline;


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
			this->seperationline = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
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
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(802, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// dateiToolStripMenuItem
			// 
			this->dateiToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->neuToolStripMenuItem,
					this->speichernToolStripMenuItem, this->ladenToolStripMenuItem, this->exportToolStripMenuItem
			});
			this->dateiToolStripMenuItem->Name = L"dateiToolStripMenuItem";
			this->dateiToolStripMenuItem->Size = System::Drawing::Size(46, 20);
			this->dateiToolStripMenuItem->Text = L"Datei";
			// 
			// neuToolStripMenuItem
			// 
			this->neuToolStripMenuItem->Name = L"neuToolStripMenuItem";
			this->neuToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->neuToolStripMenuItem->Text = L"Neu";
			this->neuToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::neuToolStripMenuItem_Click);
			// 
			// speichernToolStripMenuItem
			// 
			this->speichernToolStripMenuItem->Name = L"speichernToolStripMenuItem";
			this->speichernToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->speichernToolStripMenuItem->Text = L"Speichern";
			this->speichernToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::speichernToolStripMenuItem_Click);
			// 
			// ladenToolStripMenuItem
			// 
			this->ladenToolStripMenuItem->Name = L"ladenToolStripMenuItem";
			this->ladenToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->ladenToolStripMenuItem->Text = L"Laden";
			this->ladenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ladenToolStripMenuItem_Click);
			// 
			// exportToolStripMenuItem
			// 
			this->exportToolStripMenuItem->Name = L"exportToolStripMenuItem";
			this->exportToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->exportToolStripMenuItem->Text = L"Export";
			this->exportToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exportToolStripMenuItem_Click);
			// 
			// helpButton
			// 
			this->helpButton->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->helpButton->Name = L"helpButton";
			this->helpButton->Size = System::Drawing::Size(24, 20);
			this->helpButton->Text = L"\?";
			// 
			// searchButton
			// 
			this->searchButton->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(31, 20);
			this->searchButton->Text = L"🔍";
			this->searchButton->Click += gcnew System::EventHandler(this, &MyForm::searchButton_Click);
			// 
			// lastButton
			// 
			this->lastButton->Location = System::Drawing::Point(153, 494);
			this->lastButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->lastButton->Name = L"lastButton";
			this->lastButton->Size = System::Drawing::Size(112, 35);
			this->lastButton->TabIndex = 2;
			this->lastButton->Text = L"<---";
			this->lastButton->UseVisualStyleBackColor = true;
			this->lastButton->Click += gcnew System::EventHandler(this, &MyForm::lastButton_Click);
			// 
			// changeButton
			// 
			this->changeButton->Location = System::Drawing::Point(276, 492);
			this->changeButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->changeButton->Name = L"changeButton";
			this->changeButton->Size = System::Drawing::Size(112, 35);
			this->changeButton->TabIndex = 3;
			this->changeButton->Text = L"Ändern";
			this->changeButton->UseVisualStyleBackColor = true;
			this->changeButton->Click += gcnew System::EventHandler(this, &MyForm::changeButton_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->Location = System::Drawing::Point(398, 492);
			this->deleteButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(112, 35);
			this->deleteButton->TabIndex = 4;
			this->deleteButton->Text = L"Löschen";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &MyForm::deleteButton_Click);
			// 
			// nextButton
			// 
			this->nextButton->Location = System::Drawing::Point(520, 491);
			this->nextButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->nextButton->Name = L"nextButton";
			this->nextButton->Size = System::Drawing::Size(112, 35);
			this->nextButton->TabIndex = 5;
			this->nextButton->Text = L"--->";
			this->nextButton->UseVisualStyleBackColor = true;
			this->nextButton->Click += gcnew System::EventHandler(this, &MyForm::nextButton_Click);
			// 
			// field1
			// 
			this->field1->Location = System::Drawing::Point(89, 89);
			this->field1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->field1->Name = L"field1";
			this->field1->ReadOnly = true;
			this->field1->Size = System::Drawing::Size(123, 20);
			this->field1->TabIndex = 9;
			// 
			// field2
			// 
			this->field2->Location = System::Drawing::Point(89, 131);
			this->field2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->field2->Name = L"field2";
			this->field2->ReadOnly = true;
			this->field2->Size = System::Drawing::Size(123, 20);
			this->field2->TabIndex = 10;
			// 
			// field3
			// 
			this->field3->Location = System::Drawing::Point(89, 172);
			this->field3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->field3->Name = L"field3";
			this->field3->ReadOnly = true;
			this->field3->Size = System::Drawing::Size(123, 20);
			this->field3->TabIndex = 11;
			// 
			// value1
			// 
			this->value1->Location = System::Drawing::Point(239, 89);
			this->value1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->value1->Name = L"value1";
			this->value1->ReadOnly = true;
			this->value1->Size = System::Drawing::Size(123, 20);
			this->value1->TabIndex = 12;
			// 
			// value2
			// 
			this->value2->Location = System::Drawing::Point(239, 131);
			this->value2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->value2->Name = L"value2";
			this->value2->ReadOnly = true;
			this->value2->Size = System::Drawing::Size(123, 20);
			this->value2->TabIndex = 13;
			// 
			// value3
			// 
			this->value3->Location = System::Drawing::Point(239, 172);
			this->value3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->value3->Name = L"value3";
			this->value3->ReadOnly = true;
			this->value3->Size = System::Drawing::Size(123, 20);
			this->value3->TabIndex = 14;
			// 
			// value6
			// 
			this->value6->Location = System::Drawing::Point(580, 172);
			this->value6->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->value6->Name = L"value6";
			this->value6->ReadOnly = true;
			this->value6->Size = System::Drawing::Size(123, 20);
			this->value6->TabIndex = 20;
			// 
			// value5
			// 
			this->value5->Location = System::Drawing::Point(580, 131);
			this->value5->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->value5->Name = L"value5";
			this->value5->ReadOnly = true;
			this->value5->Size = System::Drawing::Size(123, 20);
			this->value5->TabIndex = 19;
			// 
			// value4
			// 
			this->value4->Location = System::Drawing::Point(580, 89);
			this->value4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->value4->Name = L"value4";
			this->value4->ReadOnly = true;
			this->value4->Size = System::Drawing::Size(123, 20);
			this->value4->TabIndex = 18;
			// 
			// field6
			// 
			this->field6->Location = System::Drawing::Point(430, 172);
			this->field6->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->field6->Name = L"field6";
			this->field6->ReadOnly = true;
			this->field6->Size = System::Drawing::Size(123, 20);
			this->field6->TabIndex = 17;
			// 
			// field5
			// 
			this->field5->Location = System::Drawing::Point(430, 131);
			this->field5->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->field5->Name = L"field5";
			this->field5->ReadOnly = true;
			this->field5->Size = System::Drawing::Size(123, 20);
			this->field5->TabIndex = 16;
			// 
			// field4
			// 
			this->field4->Location = System::Drawing::Point(430, 89);
			this->field4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->field4->Name = L"field4";
			this->field4->ReadOnly = true;
			this->field4->Size = System::Drawing::Size(123, 20);
			this->field4->TabIndex = 15;
			// 
			// _value3
			// 
			this->_value3->Location = System::Drawing::Point(239, 357);
			this->_value3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_value3->Name = L"_value3";
			this->_value3->ReadOnly = true;
			this->_value3->Size = System::Drawing::Size(123, 20);
			this->_value3->TabIndex = 26;
			// 
			// _value2
			// 
			this->_value2->Location = System::Drawing::Point(239, 316);
			this->_value2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_value2->Name = L"_value2";
			this->_value2->ReadOnly = true;
			this->_value2->Size = System::Drawing::Size(123, 20);
			this->_value2->TabIndex = 25;
			// 
			// _value1
			// 
			this->_value1->Location = System::Drawing::Point(239, 274);
			this->_value1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_value1->Name = L"_value1";
			this->_value1->ReadOnly = true;
			this->_value1->Size = System::Drawing::Size(123, 20);
			this->_value1->TabIndex = 24;
			// 
			// _field3
			// 
			this->_field3->Location = System::Drawing::Point(89, 357);
			this->_field3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_field3->Name = L"_field3";
			this->_field3->ReadOnly = true;
			this->_field3->Size = System::Drawing::Size(123, 20);
			this->_field3->TabIndex = 23;
			// 
			// _field2
			// 
			this->_field2->Location = System::Drawing::Point(89, 316);
			this->_field2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_field2->Name = L"_field2";
			this->_field2->ReadOnly = true;
			this->_field2->Size = System::Drawing::Size(123, 20);
			this->_field2->TabIndex = 22;
			// 
			// _field1
			// 
			this->_field1->Location = System::Drawing::Point(89, 274);
			this->_field1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_field1->Name = L"_field1";
			this->_field1->ReadOnly = true;
			this->_field1->Size = System::Drawing::Size(123, 20);
			this->_field1->TabIndex = 21;
			// 
			// _value4
			// 
			this->_value4->Location = System::Drawing::Point(239, 404);
			this->_value4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_value4->Name = L"_value4";
			this->_value4->ReadOnly = true;
			this->_value4->Size = System::Drawing::Size(123, 20);
			this->_value4->TabIndex = 30;
			// 
			// _field4
			// 
			this->_field4->Location = System::Drawing::Point(89, 404);
			this->_field4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_field4->Name = L"_field4";
			this->_field4->ReadOnly = true;
			this->_field4->Size = System::Drawing::Size(123, 20);
			this->_field4->TabIndex = 27;
			// 
			// _value8
			// 
			this->_value8->Location = System::Drawing::Point(580, 404);
			this->_value8->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_value8->Name = L"_value8";
			this->_value8->ReadOnly = true;
			this->_value8->Size = System::Drawing::Size(123, 20);
			this->_value8->TabIndex = 38;
			// 
			// _field8
			// 
			this->_field8->Location = System::Drawing::Point(430, 404);
			this->_field8->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_field8->Name = L"_field8";
			this->_field8->ReadOnly = true;
			this->_field8->Size = System::Drawing::Size(123, 20);
			this->_field8->TabIndex = 37;
			// 
			// _value7
			// 
			this->_value7->Location = System::Drawing::Point(580, 357);
			this->_value7->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_value7->Name = L"_value7";
			this->_value7->ReadOnly = true;
			this->_value7->Size = System::Drawing::Size(123, 20);
			this->_value7->TabIndex = 36;
			// 
			// _value6
			// 
			this->_value6->Location = System::Drawing::Point(580, 316);
			this->_value6->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_value6->Name = L"_value6";
			this->_value6->ReadOnly = true;
			this->_value6->Size = System::Drawing::Size(123, 20);
			this->_value6->TabIndex = 35;
			// 
			// _value5
			// 
			this->_value5->Location = System::Drawing::Point(580, 274);
			this->_value5->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_value5->Name = L"_value5";
			this->_value5->ReadOnly = true;
			this->_value5->Size = System::Drawing::Size(123, 20);
			this->_value5->TabIndex = 34;
			// 
			// _field7
			// 
			this->_field7->Location = System::Drawing::Point(430, 357);
			this->_field7->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_field7->Name = L"_field7";
			this->_field7->ReadOnly = true;
			this->_field7->Size = System::Drawing::Size(123, 20);
			this->_field7->TabIndex = 33;
			// 
			// _field6
			// 
			this->_field6->Location = System::Drawing::Point(430, 316);
			this->_field6->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_field6->Name = L"_field6";
			this->_field6->ReadOnly = true;
			this->_field6->Size = System::Drawing::Size(123, 20);
			this->_field6->TabIndex = 32;
			// 
			// _field5
			// 
			this->_field5->Location = System::Drawing::Point(430, 274);
			this->_field5->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->_field5->Name = L"_field5";
			this->_field5->ReadOnly = true;
			this->_field5->Size = System::Drawing::Size(123, 20);
			this->_field5->TabIndex = 31;
			// 
			// saveChangeButton
			// 
			this->saveChangeButton->Location = System::Drawing::Point(276, 492);
			this->saveChangeButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->saveChangeButton->Name = L"saveChangeButton";
			this->saveChangeButton->Size = System::Drawing::Size(112, 35);
			this->saveChangeButton->TabIndex = 39;
			this->saveChangeButton->Text = L"Speichern";
			this->saveChangeButton->UseVisualStyleBackColor = true;
			this->saveChangeButton->Visible = false;
			this->saveChangeButton->Click += gcnew System::EventHandler(this, &MyForm::saveChangeButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->Location = System::Drawing::Point(398, 492);
			this->cancelButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(112, 35);
			this->cancelButton->TabIndex = 40;
			this->cancelButton->Text = L"Abbrechen";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Visible = false;
			this->cancelButton->Click += gcnew System::EventHandler(this, &MyForm::cancelButton_Click);
			// 
			// keyField
			// 
			this->keyField->Location = System::Drawing::Point(291, 41);
			this->keyField->Margin = System::Windows::Forms::Padding(2);
			this->keyField->Name = L"keyField";
			this->keyField->ReadOnly = true;
			this->keyField->Size = System::Drawing::Size(221, 20);
			this->keyField->TabIndex = 41;
			// 
			// sourceTypeTextBox
			// 
			this->sourceTypeTextBox->Location = System::Drawing::Point(89, 41);
			this->sourceTypeTextBox->Margin = System::Windows::Forms::Padding(2);
			this->sourceTypeTextBox->Name = L"sourceTypeTextBox";
			this->sourceTypeTextBox->ReadOnly = true;
			this->sourceTypeTextBox->Size = System::Drawing::Size(136, 20);
			this->sourceTypeTextBox->TabIndex = 42;
			// 
			// currIndexTextBox
			// 
			this->currIndexTextBox->Location = System::Drawing::Point(673, 41);
			this->currIndexTextBox->Margin = System::Windows::Forms::Padding(2);
			this->currIndexTextBox->Name = L"currIndexTextBox";
			this->currIndexTextBox->ReadOnly = true;
			this->currIndexTextBox->Size = System::Drawing::Size(91, 20);
			this->currIndexTextBox->TabIndex = 43;
			// 
			// authororeditorDropdownComboBox
			// 
			this->authororeditorDropdownComboBox->FormattingEnabled = true;
			this->authororeditorDropdownComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"author", L"editor" });
			this->authororeditorDropdownComboBox->Location = System::Drawing::Point(713, 229);
			this->authororeditorDropdownComboBox->Margin = System::Windows::Forms::Padding(2);
			this->authororeditorDropdownComboBox->Name = L"authororeditorDropdownComboBox";
			this->authororeditorDropdownComboBox->Size = System::Drawing::Size(82, 21);
			this->authororeditorDropdownComboBox->TabIndex = 44;
			this->authororeditorDropdownComboBox->Visible = false;
			// 
			// chapterandorpageDropdownComboBox
			// 
			this->chapterandorpageDropdownComboBox->FormattingEnabled = true;
			this->chapterandorpageDropdownComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"chapter", L"page" });
			this->chapterandorpageDropdownComboBox->Location = System::Drawing::Point(713, 281);
			this->chapterandorpageDropdownComboBox->Margin = System::Windows::Forms::Padding(2);
			this->chapterandorpageDropdownComboBox->Name = L"chapterandorpageDropdownComboBox";
			this->chapterandorpageDropdownComboBox->Size = System::Drawing::Size(82, 21);
			this->chapterandorpageDropdownComboBox->TabIndex = 45;
			this->chapterandorpageDropdownComboBox->Visible = false;
			// 
			// suchtLabel
			// 
			this->suchtLabel->AutoSize = true;
			this->suchtLabel->Location = System::Drawing::Point(586, 45);
			this->suchtLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->suchtLabel->Name = L"suchtLabel";
			this->suchtLabel->Size = System::Drawing::Size(75, 13);
			this->suchtLabel->TabIndex = 46;
			this->suchtLabel->Text = L"Suchergebnis:";
			this->suchtLabel->Visible = false;
			this->suchtLabel->VisibleChanged += gcnew System::EventHandler(this, &MyForm::suchtLabel_VisibleChanged);
			// 
			// seperationline
			// 
			this->seperationline->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->seperationline->Location = System::Drawing::Point(89, 223);
			this->seperationline->Name = L"seperationline";
			this->seperationline->Size = System::Drawing::Size(614, 2);
			this->seperationline->TabIndex = 47;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(802, 591);
			this->Controls->Add(this->seperationline);
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
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Quellenverwaltung";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->VisibleChanged += gcnew System::EventHandler(this, &MyForm::MyForm_VisibleChanged);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void toolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	// TODO einbindung pdf machen/testen?
	System::String^ pdfPath = "Bedienungsanleitung.pdf";
	System::Diagnostics::Process::Start(pdfPath);
}

private: System::Void speichernToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (saveDB(db)) {
		MessageBox::Show("Erfolgreich gespeichert", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

private: System::Void ladenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (loadDB(db)) {
		MessageBox::Show("Erfolgreich geladen", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

private: System::Void exportToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (exportDB(db)) {
	
	}
}

// TODO abfangen, ob in ändern modu? -> nutzer hinweisen erst zu speichern / möglichkeit cancel? bieten
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
private: System::Void lastButton_Click(System::Object^  sender, System::EventArgs^  e) {
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
	currEntry = (currEntry <= 0) ? db->entries-1 : currEntry - 1;
	output(currEntry, false);
}
private: System::Void changeButton_Click(System::Object^  sender, System::EventArgs^  e) {
	output(currEntry, true);
	saveChangeButton->Visible = true;
	changeButton->Visible = false;
	cancelButton->Visible = true;
}
private: System::Void saveChangeButton_Click(System::Object^  sender, System::EventArgs^  e) {
	// wieder in Ausgabe wechseln
	if (this->saveToSource()) {
		output(currEntry, false);
		saveChangeButton->Visible = false;
		changeButton->Visible = true;
		cancelButton->Visible = false;
	}
}
private: System::Void neuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Form^ f2 = gcnew MyForm1(this, db, newSorceCreated);
	f2->Show();
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
	}
}
private: System::Void cancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
	output(currEntry, false);
	saveChangeButton->Visible = false;
	changeButton->Visible = true;
	cancelButton->Visible = false;
}
private: System::Void deleteButton_Click(System::Object^  sender, System::EventArgs^  e) {
	deleteEntry(db, currEntry);
	if (currEntry >= db->entries) { currEntry -= 1; }
	if (currEntry < 0) { currEntry = (db->entries <= 0)? 0 : db->entries - 1; }
	output(currEntry, false);
}
private: System::Void searchButton_Click(System::Object^  sender, System::EventArgs^  e) {
	Form^ searchForm = gcnew MyForm2(db, searchResults, isSearching, suchtLabel);
	searchForm->Show();
	// TODO
	// irgendwie den Nutzer zwinden auf eine der Pfeiltasten zu drücken, damit Suchergebnisse auch angezeigt werden...
	// alles ausblenden? mit Hinweis -> Taste drücken?
	// suche doch in eine combobox quetschen?
}
private: System::Void suchtLabel_VisibleChanged(System::Object^  sender, System::EventArgs^  e) {
	// Hacky callback from search Form to trigger new output on search completion
	// import "MyForm.h" im zweiten Skript sorgt für Unmengen an Fehlern...
	// -> hier ein "toller" work-around
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
	else if (suchtLabel->Visible == false && isInited) {
		output(currEntry, false);
	}
}
};
}
