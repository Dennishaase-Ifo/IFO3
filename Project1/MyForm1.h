#pragma once

#include "DBFuncs.h"	
#include "DBTypes.h"
#include "typeFuncs.h"

#include "GUIUtils.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

		MyForm1(Form^ _mainForm, DataBank* _db, bool* _newSourceMarker) {
			InitializeComponent();
			db = _db;
			mainForm = _mainForm;
			newSourceMarker = _newSourceMarker;
		}

	private: 
		DataBank* db;
		Form^ mainForm;
		bool* newSourceMarker;

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  articleButton;
	private: System::Windows::Forms::Button^  bookletButton;
	protected:

	protected:

	private: System::Windows::Forms::Button^  bookButton;
	private: System::Windows::Forms::Button^  conferenceButton;
	private: System::Windows::Forms::Button^  masterthesisButton;



	private: System::Windows::Forms::Button^  incollectionButton;
	private: System::Windows::Forms::Button^  manualButton;


	private: System::Windows::Forms::Button^  inbookButton;
	private: System::Windows::Forms::Button^  variantcountButton;


	private: System::Windows::Forms::Button^  techreportButton;
	private: System::Windows::Forms::Button^  unpublishedButton;


	private: System::Windows::Forms::Button^  proceedingsButton;

	private: System::Windows::Forms::Button^  phdthesisButton;

	private: System::Windows::Forms::Button^  miscButton;


	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->articleButton = (gcnew System::Windows::Forms::Button());
			this->bookletButton = (gcnew System::Windows::Forms::Button());
			this->bookButton = (gcnew System::Windows::Forms::Button());
			this->conferenceButton = (gcnew System::Windows::Forms::Button());
			this->masterthesisButton = (gcnew System::Windows::Forms::Button());
			this->incollectionButton = (gcnew System::Windows::Forms::Button());
			this->manualButton = (gcnew System::Windows::Forms::Button());
			this->inbookButton = (gcnew System::Windows::Forms::Button());
			this->variantcountButton = (gcnew System::Windows::Forms::Button());
			this->techreportButton = (gcnew System::Windows::Forms::Button());
			this->unpublishedButton = (gcnew System::Windows::Forms::Button());
			this->proceedingsButton = (gcnew System::Windows::Forms::Button());
			this->phdthesisButton = (gcnew System::Windows::Forms::Button());
			this->miscButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// article
			// 
			this->articleButton->Location = System::Drawing::Point(90, 51);
			this->articleButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->articleButton->Name = L"article";
			this->articleButton->Size = System::Drawing::Size(112, 35);
			this->articleButton->TabIndex = 0;
			this->articleButton->Text = L"article";
			this->articleButton->UseVisualStyleBackColor = true;
			this->articleButton->Click += gcnew System::EventHandler(this, &MyForm1::articleButton_Click);
			// 
			// booklet
			// 
			this->bookletButton->Location = System::Drawing::Point(90, 95);
			this->bookletButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->bookletButton->Name = L"booklet";
			this->bookletButton->Size = System::Drawing::Size(112, 35);
			this->bookletButton->TabIndex = 1;
			this->bookletButton->Text = L"booklet";
			this->bookletButton->UseVisualStyleBackColor = true;
			this->bookletButton->Click += gcnew System::EventHandler(this, &MyForm1::booklet_Click);
			// 
			// book
			// 
			this->bookletButton->Location = System::Drawing::Point(212, 51);
			this->bookletButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->bookletButton->Name = L"book";
			this->bookletButton->Size = System::Drawing::Size(112, 35);
			this->bookletButton->TabIndex = 2;
			this->bookletButton->Text = L"book";
			this->bookletButton->UseVisualStyleBackColor = true;
			this->bookletButton->Click += gcnew System::EventHandler(this, &MyForm1::book_Click);
			// 
			// conference
			// 
			this->conferenceButton->Location = System::Drawing::Point(212, 95);
			this->conferenceButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->conferenceButton->Name = L"conference";
			this->conferenceButton->Size = System::Drawing::Size(112, 35);
			this->conferenceButton->TabIndex = 3;
			this->conferenceButton->Text = L"conference";
			this->conferenceButton->UseVisualStyleBackColor = true;
			this->conferenceButton->Click += gcnew System::EventHandler(this, &MyForm1::conference_Click);
			// 
			// masterthesis
			// 
			this->masterthesisButton->Location = System::Drawing::Point(212, 185);
			this->masterthesisButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->masterthesisButton->Name = L"masterthesis";
			this->masterthesisButton->Size = System::Drawing::Size(112, 35);
			this->masterthesisButton->TabIndex = 7;
			this->masterthesisButton->Text = L"masterthesis";
			this->masterthesisButton->UseVisualStyleBackColor = true;
			this->masterthesisButton->Click += gcnew System::EventHandler(this, &MyForm1::masterthesis_Click);
			// 
			// incollection
			// 
			this->incollectionButton->Location = System::Drawing::Point(212, 140);
			this->incollectionButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->incollectionButton->Name = L"incollection";
			this->incollectionButton->Size = System::Drawing::Size(112, 35);
			this->incollectionButton->TabIndex = 6;
			this->incollectionButton->Text = L"incollection";
			this->incollectionButton->UseVisualStyleBackColor = true;
			this->incollectionButton->Click += gcnew System::EventHandler(this, &MyForm1::incollection_Click);
			// 
			// manual
			// 
			this->manualButton->Location = System::Drawing::Point(90, 185);
			this->manualButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->manualButton->Name = L"manual";
			this->manualButton->Size = System::Drawing::Size(112, 35);
			this->manualButton->TabIndex = 5;
			this->manualButton->Text = L"manual";
			this->manualButton->UseVisualStyleBackColor = true;
			this->manualButton->Click += gcnew System::EventHandler(this, &MyForm1::manual_Click);
			// 
			// inbook
			// 
			this->inbookButton->Location = System::Drawing::Point(90, 140);
			this->inbookButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->inbookButton->Name = L"inbook";
			this->inbookButton->Size = System::Drawing::Size(112, 35);
			this->inbookButton->TabIndex = 4;
			this->inbookButton->Text = L"inbook";
			this->inbookButton->UseVisualStyleBackColor = true;
			this->inbookButton->Click += gcnew System::EventHandler(this, &MyForm1::inbook_Click);
			// 
			// variantcount
			// 
			this->variantcountButton->Location = System::Drawing::Point(212, 315);
			this->variantcountButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->variantcountButton->Name = L"variantcount";
			this->variantcountButton->Size = System::Drawing::Size(112, 35);
			this->variantcountButton->TabIndex = 13;
			this->variantcountButton->Text = L"variantcount";
			this->variantcountButton->UseVisualStyleBackColor = true;
			this->variantcountButton->Click += gcnew System::EventHandler(this, &MyForm1::variantcount_Click);
			// 
			// techreport
			// 
			this->techreportButton->Location = System::Drawing::Point(212, 271);
			this->techreportButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->techreportButton->Name = L"techreport";
			this->techreportButton->Size = System::Drawing::Size(112, 35);
			this->techreportButton->TabIndex = 12;
			this->techreportButton->Text = L"techreport";
			this->techreportButton->UseVisualStyleBackColor = true;
			this->techreportButton->Click += gcnew System::EventHandler(this, &MyForm1::techreport_Click);
			// 
			// unpublished
			// 
			this->unpublishedButton->Location = System::Drawing::Point(90, 315);
			this->unpublishedButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->unpublishedButton->Name = L"unpublished";
			this->unpublishedButton->Size = System::Drawing::Size(112, 35);
			this->unpublishedButton->TabIndex = 11;
			this->unpublishedButton->Text = L"unpublished";
			this->unpublishedButton->UseVisualStyleBackColor = true;
			this->unpublishedButton->Click += gcnew System::EventHandler(this, &MyForm1::unpublished_Click);
			// 
			// proceedings
			// 
			this->proceedingsButton->Location = System::Drawing::Point(90, 271);
			this->proceedingsButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->proceedingsButton->Name = L"proceedings";
			this->proceedingsButton->Size = System::Drawing::Size(112, 35);
			this->proceedingsButton->TabIndex = 10;
			this->proceedingsButton->Text = L"proceedings";
			this->proceedingsButton->UseVisualStyleBackColor = true;
			this->proceedingsButton->Click += gcnew System::EventHandler(this, &MyForm1::proceedings_Click);
			// 
			// phdthesis
			// 
			this->phdthesisButton->Location = System::Drawing::Point(212, 226);
			this->phdthesisButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->phdthesisButton->Name = L"phdthesis";
			this->phdthesisButton->Size = System::Drawing::Size(112, 35);
			this->phdthesisButton->TabIndex = 9;
			this->phdthesisButton->Text = L"phdthesis";
			this->phdthesisButton->UseVisualStyleBackColor = true;
			this->phdthesisButton->Click += gcnew System::EventHandler(this, &MyForm1::phdthesis_Click);
			// 
			// misc
			// 
			this->miscButton->Location = System::Drawing::Point(90, 226);
			this->miscButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->miscButton->Name = L"misc";
			this->miscButton->Size = System::Drawing::Size(112, 35);
			this->miscButton->TabIndex = 8;
			this->miscButton->Text = L"misc";
			this->miscButton->UseVisualStyleBackColor = true;
			this->miscButton->Click += gcnew System::EventHandler(this, &MyForm1::misc_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(426, 402);
			this->Controls->Add(this->variantcountButton);
			this->Controls->Add(this->techreportButton);
			this->Controls->Add(this->unpublishedButton);
			this->Controls->Add(this->proceedingsButton);
			this->Controls->Add(this->phdthesisButton);
			this->Controls->Add(this->miscButton);
			this->Controls->Add(this->masterthesisButton);
			this->Controls->Add(this->incollectionButton);
			this->Controls->Add(this->manualButton);
			this->Controls->Add(this->inbookButton);
			this->Controls->Add(this->conferenceButton);
			this->Controls->Add(this->bookButton);
			this->Controls->Add(this->bookletButton);
			this->Controls->Add(this->articleButton);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MyForm1";
			this->Text = L"Auswahl Quellentyp";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void articleButton_Click(System::Object^  sender, System::EventArgs^  e) {
	initSource(&db->sources[db->entries], article);
	db->entries += 1;  
	*newSourceMarker = true;
	mainForm->Show();
	this->Close();
}

private: System::Void book_Click(System::Object^  sender, System::EventArgs^  e) {
	initSource(&db->sources[db->entries], book);
	db->entries += 1; 
	*newSourceMarker = true;
	mainForm->Show();
	this->Close();
}

private: System::Void booklet_Click(System::Object^  sender, System::EventArgs^  e) {
	initSource(&db->sources[db->entries], booklet);
	db->entries += 1; 
	*newSourceMarker = true;
	mainForm->Show();
	this->Close();
}

private: System::Void conference_Click(System::Object^  sender, System::EventArgs^  e) {
	initSource(&db->sources[db->entries], conference);
	db->entries += 1; 
	*newSourceMarker = true;
	mainForm->Show();
	this->Close();
}

private: System::Void inbook_Click(System::Object^  sender, System::EventArgs^  e) {
	initSource(&db->sources[db->entries], inbook);
	db->entries += 1; 
	*newSourceMarker = true;
	mainForm->Show();
	this->Close();
}

private: System::Void incollection_Click(System::Object^  sender, System::EventArgs^  e) {
	initSource(&db->sources[db->entries], incollection);
	db->entries += 1; 
	*newSourceMarker = true;
	mainForm->Show();
	this->Close();
}

private: System::Void manual_Click(System::Object^  sender, System::EventArgs^  e) {
	initSource(&db->sources[db->entries], manual);
	db->entries += 1; 
	*newSourceMarker = true;
	mainForm->Show();
	this->Close();
}

private: System::Void masterthesis_Click(System::Object^  sender, System::EventArgs^  e) {
	initSource(&db->sources[db->entries], masterthesis);
	db->entries += 1; 
	*newSourceMarker = true;
	mainForm->Show();
	this->Close();
}

private: System::Void misc_Click(System::Object^  sender, System::EventArgs^  e) {
	initSource(&db->sources[db->entries], misc);
	db->entries += 1; 
	*newSourceMarker = true;
	mainForm->Show();
	this->Close();
}

private: System::Void phdthesis_Click(System::Object^  sender, System::EventArgs^  e) {
	initSource(&db->sources[db->entries], phdthesis);
	db->entries += 1; 
	*newSourceMarker = true;
	mainForm->Show();
	this->Close();
}

private: System::Void proceedings_Click(System::Object^  sender, System::EventArgs^  e) {
	initSource(&db->sources[db->entries], proceedings);
	db->entries += 1; 
	*newSourceMarker = true;
	mainForm->Show();
	this->Close();
}

private: System::Void techreport_Click(System::Object^  sender, System::EventArgs^  e) {
	initSource(&db->sources[db->entries], techreport);
	db->entries += 1; 
	*newSourceMarker = true;
	mainForm->Show();
	this->Close();
}

private: System::Void unpublished_Click(System::Object^  sender, System::EventArgs^  e) {
	initSource(&db->sources[db->entries], unpublished);
	db->entries += 1; 
	*newSourceMarker = true;
	mainForm->Show();
	this->Close();
}

private: System::Void variantcount_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MyForm1_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
