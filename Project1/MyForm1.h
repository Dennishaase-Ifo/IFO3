#pragma once

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
	private: System::Windows::Forms::Button^  article;
	private: System::Windows::Forms::Button^  booklet;
	protected:

	protected:

	private: System::Windows::Forms::Button^  book;
	private: System::Windows::Forms::Button^  conference;
	private: System::Windows::Forms::Button^  masterthesis;



	private: System::Windows::Forms::Button^  incollection;
	private: System::Windows::Forms::Button^  manual;


	private: System::Windows::Forms::Button^  inbook;
	private: System::Windows::Forms::Button^  variantcount;


	private: System::Windows::Forms::Button^  techreport;
	private: System::Windows::Forms::Button^  unpublished;


	private: System::Windows::Forms::Button^  proceedings;

	private: System::Windows::Forms::Button^  phdthesis;

	private: System::Windows::Forms::Button^  misc;


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
			this->article = (gcnew System::Windows::Forms::Button());
			this->booklet = (gcnew System::Windows::Forms::Button());
			this->book = (gcnew System::Windows::Forms::Button());
			this->conference = (gcnew System::Windows::Forms::Button());
			this->masterthesis = (gcnew System::Windows::Forms::Button());
			this->incollection = (gcnew System::Windows::Forms::Button());
			this->manual = (gcnew System::Windows::Forms::Button());
			this->inbook = (gcnew System::Windows::Forms::Button());
			this->variantcount = (gcnew System::Windows::Forms::Button());
			this->techreport = (gcnew System::Windows::Forms::Button());
			this->unpublished = (gcnew System::Windows::Forms::Button());
			this->proceedings = (gcnew System::Windows::Forms::Button());
			this->phdthesis = (gcnew System::Windows::Forms::Button());
			this->misc = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// article
			// 
			this->article->Location = System::Drawing::Point(60, 33);
			this->article->Name = L"article";
			this->article->Size = System::Drawing::Size(75, 23);
			this->article->TabIndex = 0;
			this->article->Text = L"article";
			this->article->UseVisualStyleBackColor = true;
			this->article->Click += gcnew System::EventHandler(this, &MyForm1::article_Click);
			// 
			// booklet
			// 
			this->booklet->Location = System::Drawing::Point(60, 62);
			this->booklet->Name = L"booklet";
			this->booklet->Size = System::Drawing::Size(75, 23);
			this->booklet->TabIndex = 1;
			this->booklet->Text = L"booklet";
			this->booklet->UseVisualStyleBackColor = true;
			this->booklet->Click += gcnew System::EventHandler(this, &MyForm1::booklet_Click);
			// 
			// book
			// 
			this->book->Location = System::Drawing::Point(141, 33);
			this->book->Name = L"book";
			this->book->Size = System::Drawing::Size(75, 23);
			this->book->TabIndex = 2;
			this->book->Text = L"book";
			this->book->UseVisualStyleBackColor = true;
			this->book->Click += gcnew System::EventHandler(this, &MyForm1::book_Click);
			// 
			// conference
			// 
			this->conference->Location = System::Drawing::Point(141, 62);
			this->conference->Name = L"conference";
			this->conference->Size = System::Drawing::Size(75, 23);
			this->conference->TabIndex = 3;
			this->conference->Text = L"conference";
			this->conference->UseVisualStyleBackColor = true;
			this->conference->Click += gcnew System::EventHandler(this, &MyForm1::conference_Click);
			// 
			// masterthesis
			// 
			this->masterthesis->Location = System::Drawing::Point(141, 120);
			this->masterthesis->Name = L"masterthesis";
			this->masterthesis->Size = System::Drawing::Size(75, 23);
			this->masterthesis->TabIndex = 7;
			this->masterthesis->Text = L"masterthesis";
			this->masterthesis->UseVisualStyleBackColor = true;
			this->masterthesis->Click += gcnew System::EventHandler(this, &MyForm1::masterthesis_Click);
			// 
			// incollection
			// 
			this->incollection->Location = System::Drawing::Point(141, 91);
			this->incollection->Name = L"incollection";
			this->incollection->Size = System::Drawing::Size(75, 23);
			this->incollection->TabIndex = 6;
			this->incollection->Text = L"incollection";
			this->incollection->UseVisualStyleBackColor = true;
			this->incollection->Click += gcnew System::EventHandler(this, &MyForm1::incollection_Click);
			// 
			// manual
			// 
			this->manual->Location = System::Drawing::Point(60, 120);
			this->manual->Name = L"manual";
			this->manual->Size = System::Drawing::Size(75, 23);
			this->manual->TabIndex = 5;
			this->manual->Text = L"manual";
			this->manual->UseVisualStyleBackColor = true;
			this->manual->Click += gcnew System::EventHandler(this, &MyForm1::manual_Click);
			// 
			// inbook
			// 
			this->inbook->Location = System::Drawing::Point(60, 91);
			this->inbook->Name = L"inbook";
			this->inbook->Size = System::Drawing::Size(75, 23);
			this->inbook->TabIndex = 4;
			this->inbook->Text = L"inbook";
			this->inbook->UseVisualStyleBackColor = true;
			this->inbook->Click += gcnew System::EventHandler(this, &MyForm1::inbook_Click);
			// 
			// variantcount
			// 
			this->variantcount->Location = System::Drawing::Point(141, 205);
			this->variantcount->Name = L"variantcount";
			this->variantcount->Size = System::Drawing::Size(75, 23);
			this->variantcount->TabIndex = 13;
			this->variantcount->Text = L"variantcount";
			this->variantcount->UseVisualStyleBackColor = true;
			this->variantcount->Click += gcnew System::EventHandler(this, &MyForm1::variantcount_Click);
			// 
			// techreport
			// 
			this->techreport->Location = System::Drawing::Point(141, 176);
			this->techreport->Name = L"techreport";
			this->techreport->Size = System::Drawing::Size(75, 23);
			this->techreport->TabIndex = 12;
			this->techreport->Text = L"techreport";
			this->techreport->UseVisualStyleBackColor = true;
			this->techreport->Click += gcnew System::EventHandler(this, &MyForm1::techreport_Click);
			// 
			// unpublished
			// 
			this->unpublished->Location = System::Drawing::Point(60, 205);
			this->unpublished->Name = L"unpublished";
			this->unpublished->Size = System::Drawing::Size(75, 23);
			this->unpublished->TabIndex = 11;
			this->unpublished->Text = L"unpublished";
			this->unpublished->UseVisualStyleBackColor = true;
			this->unpublished->Click += gcnew System::EventHandler(this, &MyForm1::unpublished_Click);
			// 
			// proceedings
			// 
			this->proceedings->Location = System::Drawing::Point(60, 176);
			this->proceedings->Name = L"proceedings";
			this->proceedings->Size = System::Drawing::Size(75, 23);
			this->proceedings->TabIndex = 10;
			this->proceedings->Text = L"proceedings";
			this->proceedings->UseVisualStyleBackColor = true;
			this->proceedings->Click += gcnew System::EventHandler(this, &MyForm1::proceedings_Click);
			// 
			// phdthesis
			// 
			this->phdthesis->Location = System::Drawing::Point(141, 147);
			this->phdthesis->Name = L"phdthesis";
			this->phdthesis->Size = System::Drawing::Size(75, 23);
			this->phdthesis->TabIndex = 9;
			this->phdthesis->Text = L"phdthesis";
			this->phdthesis->UseVisualStyleBackColor = true;
			this->phdthesis->Click += gcnew System::EventHandler(this, &MyForm1::phdthesis_Click);
			// 
			// misc
			// 
			this->misc->Location = System::Drawing::Point(60, 147);
			this->misc->Name = L"misc";
			this->misc->Size = System::Drawing::Size(75, 23);
			this->misc->TabIndex = 8;
			this->misc->Text = L"misc";
			this->misc->UseVisualStyleBackColor = true;
			this->misc->Click += gcnew System::EventHandler(this, &MyForm1::misc_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->variantcount);
			this->Controls->Add(this->techreport);
			this->Controls->Add(this->unpublished);
			this->Controls->Add(this->proceedings);
			this->Controls->Add(this->phdthesis);
			this->Controls->Add(this->misc);
			this->Controls->Add(this->masterthesis);
			this->Controls->Add(this->incollection);
			this->Controls->Add(this->manual);
			this->Controls->Add(this->inbook);
			this->Controls->Add(this->conference);
			this->Controls->Add(this->book);
			this->Controls->Add(this->booklet);
			this->Controls->Add(this->article);
			this->Name = L"MyForm1";
			this->Text = L"Auswahl Quellentyp";
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void article_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void book_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void booklet_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void conference_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void inbook_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void incollection_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void manual_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void masterthesis_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void misc_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void phdthesis_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void proceedings_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void techreport_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void unpublished_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void variantcount_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
