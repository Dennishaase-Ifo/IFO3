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
	private: System::Windows::Forms::Label^  label1;

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

	private: System::Windows::Forms::Button^  bookButton;

	private: System::Windows::Forms::Button^  conferenceButton;

	private: System::Windows::Forms::Button^  masterthesisButton;

	private: System::Windows::Forms::Button^  incollectionButton;

	private: System::Windows::Forms::Button^  manualButton;

	private: System::Windows::Forms::Button^  inbookButton;



	private: System::Windows::Forms::Button^  techreportButton;

	private: System::Windows::Forms::Button^  unpublishedButton;

	private: System::Windows::Forms::Button^  proceedingsButton;

	private: System::Windows::Forms::Button^  phdthesisButton;

	private: System::Windows::Forms::Button^  miscButton;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->articleButton = (gcnew System::Windows::Forms::Button());
			this->bookletButton = (gcnew System::Windows::Forms::Button());
			this->bookButton = (gcnew System::Windows::Forms::Button());
			this->conferenceButton = (gcnew System::Windows::Forms::Button());
			this->masterthesisButton = (gcnew System::Windows::Forms::Button());
			this->incollectionButton = (gcnew System::Windows::Forms::Button());
			this->manualButton = (gcnew System::Windows::Forms::Button());
			this->inbookButton = (gcnew System::Windows::Forms::Button());
			this->techreportButton = (gcnew System::Windows::Forms::Button());
			this->unpublishedButton = (gcnew System::Windows::Forms::Button());
			this->proceedingsButton = (gcnew System::Windows::Forms::Button());
			this->phdthesisButton = (gcnew System::Windows::Forms::Button());
			this->miscButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// articleButton
			// 
			this->articleButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->articleButton->Location = System::Drawing::Point(80, 41);
			this->articleButton->Margin = System::Windows::Forms::Padding(4);
			this->articleButton->Name = L"articleButton";
			this->articleButton->Size = System::Drawing::Size(100, 28);
			this->articleButton->TabIndex = 0;
			this->articleButton->Text = L"article";
			this->articleButton->UseVisualStyleBackColor = true;
			this->articleButton->Click += gcnew System::EventHandler(this, &MyForm1::articleButton_Click);
			// 
			// bookletButton
			// 
			this->bookletButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bookletButton->Location = System::Drawing::Point(188, 41);
			this->bookletButton->Margin = System::Windows::Forms::Padding(4);
			this->bookletButton->Name = L"bookletButton";
			this->bookletButton->Size = System::Drawing::Size(100, 28);
			this->bookletButton->TabIndex = 2;
			this->bookletButton->Text = L"booklet";
			this->bookletButton->UseVisualStyleBackColor = true;
			this->bookletButton->Click += gcnew System::EventHandler(this, &MyForm1::booklet_Click);
			// 
			// bookButton
			// 
			this->bookButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bookButton->Location = System::Drawing::Point(80, 76);
			this->bookButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bookButton->Name = L"bookButton";
			this->bookButton->Size = System::Drawing::Size(100, 28);
			this->bookButton->TabIndex = 14;
			this->bookButton->Text = L"book";
			this->bookButton->Click += gcnew System::EventHandler(this, &MyForm1::book_Click);
			// 
			// conferenceButton
			// 
			this->conferenceButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->conferenceButton->Location = System::Drawing::Point(188, 76);
			this->conferenceButton->Margin = System::Windows::Forms::Padding(4);
			this->conferenceButton->Name = L"conferenceButton";
			this->conferenceButton->Size = System::Drawing::Size(100, 28);
			this->conferenceButton->TabIndex = 3;
			this->conferenceButton->Text = L"conference";
			this->conferenceButton->UseVisualStyleBackColor = true;
			this->conferenceButton->Click += gcnew System::EventHandler(this, &MyForm1::conference_Click);
			// 
			// masterthesisButton
			// 
			this->masterthesisButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->masterthesisButton->Location = System::Drawing::Point(188, 148);
			this->masterthesisButton->Margin = System::Windows::Forms::Padding(4);
			this->masterthesisButton->Name = L"masterthesisButton";
			this->masterthesisButton->Size = System::Drawing::Size(100, 28);
			this->masterthesisButton->TabIndex = 7;
			this->masterthesisButton->Text = L"masterthesis";
			this->masterthesisButton->UseVisualStyleBackColor = true;
			this->masterthesisButton->Click += gcnew System::EventHandler(this, &MyForm1::masterthesis_Click);
			// 
			// incollectionButton
			// 
			this->incollectionButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->incollectionButton->Location = System::Drawing::Point(188, 112);
			this->incollectionButton->Margin = System::Windows::Forms::Padding(4);
			this->incollectionButton->Name = L"incollectionButton";
			this->incollectionButton->Size = System::Drawing::Size(100, 28);
			this->incollectionButton->TabIndex = 6;
			this->incollectionButton->Text = L"incollection";
			this->incollectionButton->UseVisualStyleBackColor = true;
			this->incollectionButton->Click += gcnew System::EventHandler(this, &MyForm1::incollection_Click);
			// 
			// manualButton
			// 
			this->manualButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->manualButton->Location = System::Drawing::Point(80, 148);
			this->manualButton->Margin = System::Windows::Forms::Padding(4);
			this->manualButton->Name = L"manualButton";
			this->manualButton->Size = System::Drawing::Size(100, 28);
			this->manualButton->TabIndex = 5;
			this->manualButton->Text = L"manual";
			this->manualButton->UseVisualStyleBackColor = true;
			this->manualButton->Click += gcnew System::EventHandler(this, &MyForm1::manual_Click);
			// 
			// inbookButton
			// 
			this->inbookButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inbookButton->Location = System::Drawing::Point(80, 112);
			this->inbookButton->Margin = System::Windows::Forms::Padding(4);
			this->inbookButton->Name = L"inbookButton";
			this->inbookButton->Size = System::Drawing::Size(100, 28);
			this->inbookButton->TabIndex = 4;
			this->inbookButton->Text = L"inbook";
			this->inbookButton->UseVisualStyleBackColor = true;
			this->inbookButton->Click += gcnew System::EventHandler(this, &MyForm1::inbook_Click);
			// 
			// techreportButton
			// 
			this->techreportButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->techreportButton->Location = System::Drawing::Point(188, 217);
			this->techreportButton->Margin = System::Windows::Forms::Padding(4);
			this->techreportButton->Name = L"techreportButton";
			this->techreportButton->Size = System::Drawing::Size(100, 28);
			this->techreportButton->TabIndex = 12;
			this->techreportButton->Text = L"techreport";
			this->techreportButton->UseVisualStyleBackColor = true;
			this->techreportButton->Click += gcnew System::EventHandler(this, &MyForm1::techreport_Click);
			// 
			// unpublishedButton
			// 
			this->unpublishedButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->unpublishedButton->Location = System::Drawing::Point(80, 252);
			this->unpublishedButton->Margin = System::Windows::Forms::Padding(4);
			this->unpublishedButton->Name = L"unpublishedButton";
			this->unpublishedButton->Size = System::Drawing::Size(100, 28);
			this->unpublishedButton->TabIndex = 11;
			this->unpublishedButton->Text = L"unpublished";
			this->unpublishedButton->UseVisualStyleBackColor = true;
			this->unpublishedButton->Click += gcnew System::EventHandler(this, &MyForm1::unpublished_Click);
			// 
			// proceedingsButton
			// 
			this->proceedingsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->proceedingsButton->Location = System::Drawing::Point(80, 217);
			this->proceedingsButton->Margin = System::Windows::Forms::Padding(4);
			this->proceedingsButton->Name = L"proceedingsButton";
			this->proceedingsButton->Size = System::Drawing::Size(100, 28);
			this->proceedingsButton->TabIndex = 10;
			this->proceedingsButton->Text = L"proceedings";
			this->proceedingsButton->UseVisualStyleBackColor = true;
			this->proceedingsButton->Click += gcnew System::EventHandler(this, &MyForm1::proceedings_Click);
			// 
			// phdthesisButton
			// 
			this->phdthesisButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phdthesisButton->Location = System::Drawing::Point(188, 181);
			this->phdthesisButton->Margin = System::Windows::Forms::Padding(4);
			this->phdthesisButton->Name = L"phdthesisButton";
			this->phdthesisButton->Size = System::Drawing::Size(100, 28);
			this->phdthesisButton->TabIndex = 9;
			this->phdthesisButton->Text = L"phdthesis";
			this->phdthesisButton->UseVisualStyleBackColor = true;
			this->phdthesisButton->Click += gcnew System::EventHandler(this, &MyForm1::phdthesis_Click);
			// 
			// miscButton
			// 
			this->miscButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->miscButton->Location = System::Drawing::Point(80, 181);
			this->miscButton->Margin = System::Windows::Forms::Padding(4);
			this->miscButton->Name = L"miscButton";
			this->miscButton->Size = System::Drawing::Size(100, 28);
			this->miscButton->TabIndex = 8;
			this->miscButton->Text = L"misc";
			this->miscButton->UseVisualStyleBackColor = true;
			this->miscButton->Click += gcnew System::EventHandler(this, &MyForm1::misc_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(76, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(238, 20);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Wählen Sie eine Quellenart";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm1::label1_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(379, 321);
			this->Controls->Add(this->label1);
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
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"MyForm1";
			this->Text = L"Auswahl Quellenangabe";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

// jeweils neue Quelle mit gewähltem Quellentypen anlegen
// -> zurück ins erste Fenster
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

private: System::Void MyForm1_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
