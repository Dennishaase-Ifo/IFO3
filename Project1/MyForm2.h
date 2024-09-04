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
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::ToolTip^  toolTip4;
	private: System::Windows::Forms::ToolTip^  toolTip2;
	private: System::Windows::Forms::ToolTip^  toolTip3;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2::typeid));
			this->searchOptionsComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->startSearchButton = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->stopSearchButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip2 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip3 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip4 = (gcnew System::Windows::Forms::ToolTip(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// searchOptionsComboBox
			// 
			this->searchOptionsComboBox->BackColor = System::Drawing::SystemColors::HighlightText;
			this->searchOptionsComboBox->FormattingEnabled = true;
			this->searchOptionsComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Schlüssel", L"Autor", L"Titel" });
			this->searchOptionsComboBox->Location = System::Drawing::Point(110, 88);
			this->searchOptionsComboBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->searchOptionsComboBox->Name = L"searchOptionsComboBox";
			this->searchOptionsComboBox->Size = System::Drawing::Size(108, 24);
			this->searchOptionsComboBox->TabIndex = 0;
			this->toolTip1->SetToolTip(this->searchOptionsComboBox, L"Wählen Sie wonach Sie suchen möchten");
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(123, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(262, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Wonach möchten Sie suchen\?";
			// 
			// startSearchButton
			// 
			this->startSearchButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->startSearchButton->Location = System::Drawing::Point(150, 180);
			this->startSearchButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->startSearchButton->Name = L"startSearchButton";
			this->startSearchButton->Size = System::Drawing::Size(84, 36);
			this->startSearchButton->TabIndex = 2;
			this->startSearchButton->Text = L"Suchen";
			this->toolTip4->SetToolTip(this->startSearchButton, L"Eintrag suchen");
			this->startSearchButton->UseVisualStyleBackColor = true;
			this->startSearchButton->Click += gcnew System::EventHandler(this, &MyForm2::startSearchButton_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::HighlightText;
			this->textBox1->Location = System::Drawing::Point(251, 90);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(161, 22);
			this->textBox1->TabIndex = 3;
			this->toolTip2->SetToolTip(this->textBox1, L"Geben Sie den Suchbegriff ein");
			// 
			// stopSearchButton
			// 
			this->stopSearchButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stopSearchButton->Location = System::Drawing::Point(274, 180);
			this->stopSearchButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->stopSearchButton->Name = L"stopSearchButton";
			this->stopSearchButton->Size = System::Drawing::Size(84, 36);
			this->stopSearchButton->TabIndex = 4;
			this->stopSearchButton->Text = L"Beenden";
			this->toolTip4->SetToolTip(this->stopSearchButton, L"Suche beenden");
			this->stopSearchButton->UseVisualStyleBackColor = true;
			this->stopSearchButton->Visible = false;
			this->stopSearchButton->Click += gcnew System::EventHandler(this, &MyForm2::stopSearchButton_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-1, -1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(522, 159);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(-1, 164);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(537, 86);
			this->pictureBox2->TabIndex = 6;
			this->pictureBox2->TabStop = false;
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(521, 236);
			this->Controls->Add(this->stopSearchButton);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->startSearchButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->searchOptionsComboBox);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->Name = L"MyForm2";
			this->Text = L"Suche";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
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
