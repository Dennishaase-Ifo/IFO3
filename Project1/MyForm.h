#pragma once
#include <Windows.h>
#include <stdio.h>

#include "DBFuncs.h"	
#include "DBTypes.h"
#include "typeFuncs.h"

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

			output(0, false);
		}

		// overloading um spezifische Quellen auszugeben
		MyForm(DataBank* suppliedDB, int index, bool isEdit)
		{
			InitializeComponent();

			db = suppliedDB;

			output(index, isEdit);
		}

		void output(int index, bool isEditable) {
			Source* currSource = &db->sources[index];

			// Alles erstmal blank zurücksetzen
			resetFields();

			if (currSource->variant != nullSource) {
				// TODO für weitere Felder ausführen (bei optionalen Feldern logik einführen, dass von links nach recht, von oben nach unten populiert wird, dazwischen keine leeren Felder, da sieht kacke aus)
				//erstes feld populieren
				if (currSource->fields[0].type != empty) {
					// key feld populieren
					char buff[20];
					readFieldtype(currSource->fields[0].type, buff);
					// TODO String^ aus char[] machen...
					//strcpy(field1->Text, buff);

					// value feld populieren
					//strcpy(field1->Text, currSource->fields[0].content);
					if (isEditable) { field1->IsAccessible = true; }
				}
				else {
					// editierbar machen
					field1->ReadOnly = false;
				}
			}

			else { // kein Inhalt in der Quelle
				// alle ausgabe felder verstecken, ein neues einblenden als placeholder
			}
		}

		// TODO fill all other fields
		void resetFields() {
			field1->Text = "";
			field1->ReadOnly = true;
		}

	protected: 
		DataBank* db;
	private: System::Windows::Forms::Button^  saveChangeButton;
	protected:

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

	private: System::Windows::Forms::PictureBox^  pictureBox1;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
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
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
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
			this->menuStrip1->Padding = System::Windows::Forms::Padding(9, 3, 0, 3);
			this->menuStrip1->Size = System::Drawing::Size(1203, 35);
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
			this->dateiToolStripMenuItem->Size = System::Drawing::Size(65, 29);
			this->dateiToolStripMenuItem->Text = L"Datei";
			// 
			// neuToolStripMenuItem
			// 
			this->neuToolStripMenuItem->Name = L"neuToolStripMenuItem";
			this->neuToolStripMenuItem->Size = System::Drawing::Size(173, 30);
			this->neuToolStripMenuItem->Text = L"Neu";
			// 
			// speichernToolStripMenuItem
			// 
			this->speichernToolStripMenuItem->Name = L"speichernToolStripMenuItem";
			this->speichernToolStripMenuItem->Size = System::Drawing::Size(173, 30);
			this->speichernToolStripMenuItem->Text = L"Speichern";
			this->speichernToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::speichernToolStripMenuItem_Click);
			// 
			// ladenToolStripMenuItem
			// 
			this->ladenToolStripMenuItem->Name = L"ladenToolStripMenuItem";
			this->ladenToolStripMenuItem->Size = System::Drawing::Size(173, 30);
			this->ladenToolStripMenuItem->Text = L"Laden";
			this->ladenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ladenToolStripMenuItem_Click);
			// 
			// exportToolStripMenuItem
			// 
			this->exportToolStripMenuItem->Name = L"exportToolStripMenuItem";
			this->exportToolStripMenuItem->Size = System::Drawing::Size(173, 30);
			this->exportToolStripMenuItem->Text = L"Export";
			this->exportToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exportToolStripMenuItem_Click);
			// 
			// helpButton
			// 
			this->helpButton->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->helpButton->Name = L"helpButton";
			this->helpButton->Size = System::Drawing::Size(32, 29);
			this->helpButton->Text = L"\?";
			// 
			// searchButton
			// 
			this->searchButton->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(49, 29);
			this->searchButton->Text = L"🔍";
			// 
			// lastButton
			// 
			this->lastButton->Location = System::Drawing::Point(230, 760);
			this->lastButton->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->lastButton->Name = L"lastButton";
			this->lastButton->Size = System::Drawing::Size(168, 54);
			this->lastButton->TabIndex = 2;
			this->lastButton->Text = L"<---";
			this->lastButton->UseVisualStyleBackColor = true;
			this->lastButton->Click += gcnew System::EventHandler(this, &MyForm::lastButton_Click);
			// 
			// changeButton
			// 
			this->changeButton->Location = System::Drawing::Point(414, 757);
			this->changeButton->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->changeButton->Name = L"changeButton";
			this->changeButton->Size = System::Drawing::Size(168, 54);
			this->changeButton->TabIndex = 3;
			this->changeButton->Text = L"Ändern";
			this->changeButton->UseVisualStyleBackColor = true;
			this->changeButton->Click += gcnew System::EventHandler(this, &MyForm::changeButton_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->Location = System::Drawing::Point(597, 757);
			this->deleteButton->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(168, 54);
			this->deleteButton->TabIndex = 4;
			this->deleteButton->Text = L"Löschen";
			this->deleteButton->UseVisualStyleBackColor = true;
			// 
			// nextButton
			// 
			this->nextButton->Location = System::Drawing::Point(780, 755);
			this->nextButton->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->nextButton->Name = L"nextButton";
			this->nextButton->Size = System::Drawing::Size(168, 54);
			this->nextButton->TabIndex = 5;
			this->nextButton->Text = L"--->";
			this->nextButton->UseVisualStyleBackColor = true;
			this->nextButton->Click += gcnew System::EventHandler(this, &MyForm::nextButton_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBox1->Location = System::Drawing::Point(150, 366);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(879, 23);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// field1
			// 
			this->field1->Location = System::Drawing::Point(134, 137);
			this->field1->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->field1->Name = L"field1";
			this->field1->ReadOnly = true;
			this->field1->Size = System::Drawing::Size(182, 26);
			this->field1->TabIndex = 9;
			// 
			// field2
			// 
			this->field2->Location = System::Drawing::Point(134, 202);
			this->field2->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->field2->Name = L"field2";
			this->field2->ReadOnly = true;
			this->field2->Size = System::Drawing::Size(182, 26);
			this->field2->TabIndex = 10;
			// 
			// field3
			// 
			this->field3->Location = System::Drawing::Point(134, 265);
			this->field3->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->field3->Name = L"field3";
			this->field3->ReadOnly = true;
			this->field3->Size = System::Drawing::Size(182, 26);
			this->field3->TabIndex = 11;
			// 
			// value1
			// 
			this->value1->Location = System::Drawing::Point(358, 137);
			this->value1->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->value1->Name = L"value1";
			this->value1->ReadOnly = true;
			this->value1->Size = System::Drawing::Size(182, 26);
			this->value1->TabIndex = 12;
			// 
			// value2
			// 
			this->value2->Location = System::Drawing::Point(358, 202);
			this->value2->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->value2->Name = L"value2";
			this->value2->ReadOnly = true;
			this->value2->Size = System::Drawing::Size(182, 26);
			this->value2->TabIndex = 13;
			// 
			// value3
			// 
			this->value3->Location = System::Drawing::Point(358, 265);
			this->value3->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->value3->Name = L"value3";
			this->value3->ReadOnly = true;
			this->value3->Size = System::Drawing::Size(182, 26);
			this->value3->TabIndex = 14;
			// 
			// value6
			// 
			this->value6->Location = System::Drawing::Point(870, 265);
			this->value6->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->value6->Name = L"value6";
			this->value6->ReadOnly = true;
			this->value6->Size = System::Drawing::Size(182, 26);
			this->value6->TabIndex = 20;
			// 
			// value5
			// 
			this->value5->Location = System::Drawing::Point(870, 202);
			this->value5->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->value5->Name = L"value5";
			this->value5->ReadOnly = true;
			this->value5->Size = System::Drawing::Size(182, 26);
			this->value5->TabIndex = 19;
			// 
			// value4
			// 
			this->value4->Location = System::Drawing::Point(870, 137);
			this->value4->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->value4->Name = L"value4";
			this->value4->ReadOnly = true;
			this->value4->Size = System::Drawing::Size(182, 26);
			this->value4->TabIndex = 18;
			// 
			// field6
			// 
			this->field6->Location = System::Drawing::Point(645, 265);
			this->field6->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->field6->Name = L"field6";
			this->field6->ReadOnly = true;
			this->field6->Size = System::Drawing::Size(182, 26);
			this->field6->TabIndex = 17;
			// 
			// field5
			// 
			this->field5->Location = System::Drawing::Point(645, 202);
			this->field5->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->field5->Name = L"field5";
			this->field5->ReadOnly = true;
			this->field5->Size = System::Drawing::Size(182, 26);
			this->field5->TabIndex = 16;
			// 
			// field4
			// 
			this->field4->Location = System::Drawing::Point(645, 137);
			this->field4->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->field4->Name = L"field4";
			this->field4->ReadOnly = true;
			this->field4->Size = System::Drawing::Size(182, 26);
			this->field4->TabIndex = 15;
			// 
			// _value3
			// 
			this->_value3->Location = System::Drawing::Point(358, 549);
			this->_value3->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->_value3->Name = L"_value3";
			this->_value3->ReadOnly = true;
			this->_value3->Size = System::Drawing::Size(182, 26);
			this->_value3->TabIndex = 26;
			// 
			// _value2
			// 
			this->_value2->Location = System::Drawing::Point(358, 486);
			this->_value2->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->_value2->Name = L"_value2";
			this->_value2->ReadOnly = true;
			this->_value2->Size = System::Drawing::Size(182, 26);
			this->_value2->TabIndex = 25;
			// 
			// _value1
			// 
			this->_value1->Location = System::Drawing::Point(358, 422);
			this->_value1->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->_value1->Name = L"_value1";
			this->_value1->ReadOnly = true;
			this->_value1->Size = System::Drawing::Size(182, 26);
			this->_value1->TabIndex = 24;
			// 
			// _field3
			// 
			this->_field3->Location = System::Drawing::Point(134, 549);
			this->_field3->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->_field3->Name = L"_field3";
			this->_field3->ReadOnly = true;
			this->_field3->Size = System::Drawing::Size(182, 26);
			this->_field3->TabIndex = 23;
			// 
			// _field2
			// 
			this->_field2->Location = System::Drawing::Point(134, 486);
			this->_field2->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->_field2->Name = L"_field2";
			this->_field2->ReadOnly = true;
			this->_field2->Size = System::Drawing::Size(182, 26);
			this->_field2->TabIndex = 22;
			// 
			// _field1
			// 
			this->_field1->Location = System::Drawing::Point(134, 422);
			this->_field1->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->_field1->Name = L"_field1";
			this->_field1->ReadOnly = true;
			this->_field1->Size = System::Drawing::Size(182, 26);
			this->_field1->TabIndex = 21;
			// 
			// _value4
			// 
			this->_value4->Location = System::Drawing::Point(358, 622);
			this->_value4->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->_value4->Name = L"_value4";
			this->_value4->ReadOnly = true;
			this->_value4->Size = System::Drawing::Size(182, 26);
			this->_value4->TabIndex = 30;
			// 
			// _field4
			// 
			this->_field4->Location = System::Drawing::Point(134, 622);
			this->_field4->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->_field4->Name = L"_field4";
			this->_field4->ReadOnly = true;
			this->_field4->Size = System::Drawing::Size(182, 26);
			this->_field4->TabIndex = 27;
			// 
			// _value8
			// 
			this->_value8->Location = System::Drawing::Point(870, 622);
			this->_value8->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->_value8->Name = L"_value8";
			this->_value8->ReadOnly = true;
			this->_value8->Size = System::Drawing::Size(182, 26);
			this->_value8->TabIndex = 38;
			// 
			// _field8
			// 
			this->_field8->Location = System::Drawing::Point(645, 622);
			this->_field8->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->_field8->Name = L"_field8";
			this->_field8->ReadOnly = true;
			this->_field8->Size = System::Drawing::Size(182, 26);
			this->_field8->TabIndex = 37;
			// 
			// _value7
			// 
			this->_value7->Location = System::Drawing::Point(870, 549);
			this->_value7->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->_value7->Name = L"_value7";
			this->_value7->ReadOnly = true;
			this->_value7->Size = System::Drawing::Size(182, 26);
			this->_value7->TabIndex = 36;
			// 
			// _value6
			// 
			this->_value6->Location = System::Drawing::Point(870, 486);
			this->_value6->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->_value6->Name = L"_value6";
			this->_value6->ReadOnly = true;
			this->_value6->Size = System::Drawing::Size(182, 26);
			this->_value6->TabIndex = 35;
			// 
			// _value5
			// 
			this->_value5->Location = System::Drawing::Point(870, 422);
			this->_value5->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->_value5->Name = L"_value5";
			this->_value5->ReadOnly = true;
			this->_value5->Size = System::Drawing::Size(182, 26);
			this->_value5->TabIndex = 34;
			// 
			// _field7
			// 
			this->_field7->Location = System::Drawing::Point(645, 549);
			this->_field7->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->_field7->Name = L"_field7";
			this->_field7->ReadOnly = true;
			this->_field7->Size = System::Drawing::Size(182, 26);
			this->_field7->TabIndex = 33;
			// 
			// _field6
			// 
			this->_field6->Location = System::Drawing::Point(645, 486);
			this->_field6->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->_field6->Name = L"_field6";
			this->_field6->ReadOnly = true;
			this->_field6->Size = System::Drawing::Size(182, 26);
			this->_field6->TabIndex = 32;
			// 
			// _field5
			// 
			this->_field5->Location = System::Drawing::Point(645, 422);
			this->_field5->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->_field5->Name = L"_field5";
			this->_field5->ReadOnly = true;
			this->_field5->Size = System::Drawing::Size(182, 26);
			this->_field5->TabIndex = 31;
			// 
			// saveChangeButton
			// 
			this->saveChangeButton->Location = System::Drawing::Point(414, 757);
			this->saveChangeButton->Margin = System::Windows::Forms::Padding(6, 8, 6, 8);
			this->saveChangeButton->Name = L"saveChangeButton";
			this->saveChangeButton->Size = System::Drawing::Size(168, 54);
			this->saveChangeButton->TabIndex = 39;
			this->saveChangeButton->Text = L"Speichern";
			this->saveChangeButton->UseVisualStyleBackColor = true;
			this->saveChangeButton->Visible = false;
			this->saveChangeButton->Click += gcnew System::EventHandler(this, &MyForm::saveChangeButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1203, 909);
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
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->nextButton);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->changeButton);
			this->Controls->Add(this->lastButton);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"MyForm";
			this->Text = L"Quellenverwaltung";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void toolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {

	System::String^ pdfPath = "Bedienungsanleitung.pdf";
	System::Diagnostics::Process::Start(pdfPath);

}

private: System::Void speichernToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	MessageBox::Show("Erfolgreich gespeichert", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);

}

private: System::Void ladenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	MessageBox::Show("Erfolgreich geladen", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);

}

private: System::Void exportToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	MessageBox::Show("Erfolgreich exportiert", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);

}
// TODO abfangen, ob in ändern modu? -> nutzer hinweisen erst zu speichern / möglichkeit cancel? bieten
private: System::Void nextButton_Click(System::Object^  sender, System::EventArgs^  e) {
	currEntry = (currEntry >= db->entries) ? 0 : currEntry++;
	output(currEntry, false);
}
private: System::Void lastButton_Click(System::Object^  sender, System::EventArgs^  e) {
	currEntry = (currEntry <= 0) ? db->entries : currEntry--;
	output(currEntry, false);
}
private: System::Void changeButton_Click(System::Object^  sender, System::EventArgs^  e) {
	output(currEntry, true);
	saveChangeButton->Visible = true;
	changeButton->Visible = false;
}
private: System::Void saveChangeButton_Click(System::Object^  sender, System::EventArgs^  e) {
	// TODO Speichern der neuen Eingaben

	// wieder in Ausgabe wechseln
	output(currEntry, false);
	saveChangeButton->Visible = false;
	changeButton->Visible = true;
}
};
}
