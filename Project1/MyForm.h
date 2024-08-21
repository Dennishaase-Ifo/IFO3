#pragma once

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
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

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

	protected:
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  dateiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  neuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  speichernToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ladenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exportToolStripMenuItem;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;



	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::TextBox^  textBox16;
	private: System::Windows::Forms::TextBox^  textBox17;
	private: System::Windows::Forms::TextBox^  textBox18;
	private: System::Windows::Forms::TextBox^  textBox21;
	private: System::Windows::Forms::TextBox^  textBox24;
	private: System::Windows::Forms::TextBox^  textBox19;
	private: System::Windows::Forms::TextBox^  textBox20;
	private: System::Windows::Forms::TextBox^  textBox22;
	private: System::Windows::Forms::TextBox^  textBox23;
	private: System::Windows::Forms::TextBox^  textBox25;
	private: System::Windows::Forms::TextBox^  textBox26;
	private: System::Windows::Forms::TextBox^  textBox27;
	private: System::Windows::Forms::TextBox^  textBox28;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox29;








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
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->textBox25 = (gcnew System::Windows::Forms::TextBox());
			this->textBox26 = (gcnew System::Windows::Forms::TextBox());
			this->textBox27 = (gcnew System::Windows::Forms::TextBox());
			this->textBox28 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox29 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->dateiToolStripMenuItem,
					this->toolStripMenuItem1, this->toolStripMenuItem2
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(535, 24);
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
			this->neuToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->neuToolStripMenuItem->Text = L"Neu";
			// 
			// speichernToolStripMenuItem
			// 
			this->speichernToolStripMenuItem->Name = L"speichernToolStripMenuItem";
			this->speichernToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->speichernToolStripMenuItem->Text = L"Speichern";
			this->speichernToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::speichernToolStripMenuItem_Click);
			// 
			// ladenToolStripMenuItem
			// 
			this->ladenToolStripMenuItem->Name = L"ladenToolStripMenuItem";
			this->ladenToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->ladenToolStripMenuItem->Text = L"Laden";
			this->ladenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ladenToolStripMenuItem_Click);
			// 
			// exportToolStripMenuItem
			// 
			this->exportToolStripMenuItem->Name = L"exportToolStripMenuItem";
			this->exportToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->exportToolStripMenuItem->Text = L"Export";
			this->exportToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exportToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(24, 20);
			this->toolStripMenuItem1->Text = L"\?";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem1_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(31, 20);
			this->toolStripMenuItem2->Text = L"🔍";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(102, 337);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"<---";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(184, 336);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Ändern";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(265, 336);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Löschen";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(347, 335);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"--->";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(59, 58);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(83, 20);
			this->textBox1->TabIndex = 9;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(59, 85);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(83, 20);
			this->textBox2->TabIndex = 10;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(59, 112);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(83, 20);
			this->textBox3->TabIndex = 11;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(159, 58);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(83, 20);
			this->textBox4->TabIndex = 12;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(159, 85);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(83, 20);
			this->textBox5->TabIndex = 13;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(159, 112);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(83, 20);
			this->textBox6->TabIndex = 14;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(387, 112);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(83, 20);
			this->textBox7->TabIndex = 20;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(387, 85);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(83, 20);
			this->textBox8->TabIndex = 19;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(387, 58);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(83, 20);
			this->textBox9->TabIndex = 18;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(287, 112);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(83, 20);
			this->textBox10->TabIndex = 17;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(287, 85);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(83, 20);
			this->textBox11->TabIndex = 16;
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(287, 58);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(83, 20);
			this->textBox12->TabIndex = 15;
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(159, 248);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(83, 20);
			this->textBox13->TabIndex = 26;
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(159, 221);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(83, 20);
			this->textBox14->TabIndex = 25;
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(159, 194);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(83, 20);
			this->textBox15->TabIndex = 24;
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(59, 248);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(83, 20);
			this->textBox16->TabIndex = 23;
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(59, 221);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(83, 20);
			this->textBox17->TabIndex = 22;
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(59, 194);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(83, 20);
			this->textBox18->TabIndex = 21;
			// 
			// textBox21
			// 
			this->textBox21->Location = System::Drawing::Point(159, 279);
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(83, 20);
			this->textBox21->TabIndex = 30;
			// 
			// textBox24
			// 
			this->textBox24->Location = System::Drawing::Point(59, 279);
			this->textBox24->Name = L"textBox24";
			this->textBox24->Size = System::Drawing::Size(83, 20);
			this->textBox24->TabIndex = 27;
			// 
			// textBox19
			// 
			this->textBox19->Location = System::Drawing::Point(387, 279);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(83, 20);
			this->textBox19->TabIndex = 38;
			// 
			// textBox20
			// 
			this->textBox20->Location = System::Drawing::Point(287, 279);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(83, 20);
			this->textBox20->TabIndex = 37;
			// 
			// textBox22
			// 
			this->textBox22->Location = System::Drawing::Point(387, 248);
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(83, 20);
			this->textBox22->TabIndex = 36;
			// 
			// textBox23
			// 
			this->textBox23->Location = System::Drawing::Point(387, 221);
			this->textBox23->Name = L"textBox23";
			this->textBox23->Size = System::Drawing::Size(83, 20);
			this->textBox23->TabIndex = 35;
			// 
			// textBox25
			// 
			this->textBox25->Location = System::Drawing::Point(387, 194);
			this->textBox25->Name = L"textBox25";
			this->textBox25->Size = System::Drawing::Size(83, 20);
			this->textBox25->TabIndex = 34;
			// 
			// textBox26
			// 
			this->textBox26->Location = System::Drawing::Point(287, 248);
			this->textBox26->Name = L"textBox26";
			this->textBox26->Size = System::Drawing::Size(83, 20);
			this->textBox26->TabIndex = 33;
			// 
			// textBox27
			// 
			this->textBox27->Location = System::Drawing::Point(287, 221);
			this->textBox27->Name = L"textBox27";
			this->textBox27->Size = System::Drawing::Size(83, 20);
			this->textBox27->TabIndex = 32;
			// 
			// textBox28
			// 
			this->textBox28->Location = System::Drawing::Point(287, 194);
			this->textBox28->Name = L"textBox28";
			this->textBox28->Size = System::Drawing::Size(83, 20);
			this->textBox28->TabIndex = 31;
			// 
			// label1
			// 
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Location = System::Drawing::Point(59, 159);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(411, 2);
			this->label1->TabIndex = 39;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(56, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 13);
			this->label2->TabIndex = 40;
			this->label2->Text = L"Pflichtfelder";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(56, 178);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 13);
			this->label3->TabIndex = 41;
			this->label3->Text = L"Optionale Felder";
			// 
			// textBox29
			// 
			this->textBox29->Location = System::Drawing::Point(315, 3);
			this->textBox29->Name = L"textBox29";
			this->textBox29->Size = System::Drawing::Size(172, 20);
			this->textBox29->TabIndex = 42;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(535, 392);
			this->Controls->Add(this->textBox29);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox19);
			this->Controls->Add(this->textBox20);
			this->Controls->Add(this->textBox22);
			this->Controls->Add(this->textBox23);
			this->Controls->Add(this->textBox25);
			this->Controls->Add(this->textBox26);
			this->Controls->Add(this->textBox27);
			this->Controls->Add(this->textBox28);
			this->Controls->Add(this->textBox21);
			this->Controls->Add(this->textBox24);
			this->Controls->Add(this->textBox13);
			this->Controls->Add(this->textBox14);
			this->Controls->Add(this->textBox15);
			this->Controls->Add(this->textBox16);
			this->Controls->Add(this->textBox17);
			this->Controls->Add(this->textBox18);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->textBox12);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"Quellenverwaltung";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
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

};
}
