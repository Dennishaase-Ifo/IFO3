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
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		MyForm2(DataBank* _db, SearchResults* _sRes, bool* _searching, Label^ _label) {
			InitializeComponent();
			db = _db;
			sRes = _sRes;
			searching = _searching;
			label = _label;
		}

	protected:
		DataBank* db;
		SearchResults* sRes;
		bool* searching;
		Label^ label;
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			*searching = false;
			label->Visible = false;

			stopSearchButton->Visible = false;

			sRes->entries = 0;
			for (int i = 0; i < 1000; i++) { sRes->searchResults[i] == NULL; }
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  searchOptionsComboBox;
	protected:

	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  startSearchButton;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  stopSearchButton;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->searchOptionsComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->startSearchButton = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->stopSearchButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// searchOptionsComboBox
			// 
			this->searchOptionsComboBox->FormattingEnabled = true;
			this->searchOptionsComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Schlüssel", L"Autor", L"Titel" });
			this->searchOptionsComboBox->Location = System::Drawing::Point(63, 79);
			this->searchOptionsComboBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->searchOptionsComboBox->Name = L"searchOptionsComboBox";
			this->searchOptionsComboBox->Size = System::Drawing::Size(82, 21);
			this->searchOptionsComboBox->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(61, 27);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(154, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Wonach möchten Sie suchen\?";
			// 
			// startSearchButton
			// 
			this->startSearchButton->Location = System::Drawing::Point(71, 141);
			this->startSearchButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->startSearchButton->Name = L"startSearchButton";
			this->startSearchButton->Size = System::Drawing::Size(63, 29);
			this->startSearchButton->TabIndex = 2;
			this->startSearchButton->Text = L"suchen";
			this->startSearchButton->UseVisualStyleBackColor = true;
			this->startSearchButton->Click += gcnew System::EventHandler(this, &MyForm2::startSearchButton_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(215, 80);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(122, 20);
			this->textBox1->TabIndex = 3;
			// 
			// stopSearchButton
			// 
			this->stopSearchButton->Location = System::Drawing::Point(257, 141);
			this->stopSearchButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->stopSearchButton->Name = L"stopSearchButton";
			this->stopSearchButton->Size = System::Drawing::Size(63, 29);
			this->stopSearchButton->TabIndex = 4;
			this->stopSearchButton->Text = L"beenden";
			this->stopSearchButton->UseVisualStyleBackColor = true;
			this->stopSearchButton->Visible = false;
			this->stopSearchButton->Click += gcnew System::EventHandler(this, &MyForm2::stopSearchButton_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(391, 192);
			this->Controls->Add(this->stopSearchButton);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->startSearchButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->searchOptionsComboBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaximizeBox = false;
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void startSearchButton_Click(System::Object^  sender, System::EventArgs^  e) {
		char buff[30];
		StringToChar(buff, textBox1->Text);
		searchDB(db, sRes, searchOptionsComboBox->SelectedIndex, buff);

		if (sRes->entries > 0) {
			*searching = true;
			stopSearchButton->Visible = true;
			// callback triggern...
			label->Visible = true;
		}
		else {
			MessageBox::Show("Keine Ergebnisse gefunden...", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
private: System::Void stopSearchButton_Click(System::Object^  sender, System::EventArgs^  e) {
	*searching = false;
	label->Visible = false;
	
	stopSearchButton->Visible = false;

	sRes->entries = 0;
	for (int i = 0; i < 1000; i++) { sRes->searchResults[i] == NULL; }
}
};
}
