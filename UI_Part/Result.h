#pragma once
#include "hmm.h"
#include "comparison_output.cpp"
namespace UI_Part {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Result
	/// </summary>
	public ref class Result : public System::Windows::Forms::Form
	{
	public:
		Result(void)
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
		~Result()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected: 
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::Label^  score_label;

	protected: 










	protected: 

	protected: 

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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->score_label = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::OutsetPartial;
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33333F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33334F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33334F)));
			this->tableLayoutPanel1->Controls->Add(this->label33, 2, 10);
			this->tableLayoutPanel1->Controls->Add(this->label32, 1, 10);
			this->tableLayoutPanel1->Controls->Add(this->label31, 0, 10);
			this->tableLayoutPanel1->Controls->Add(this->label30, 2, 9);
			this->tableLayoutPanel1->Controls->Add(this->label29, 1, 9);
			this->tableLayoutPanel1->Controls->Add(this->label28, 0, 9);
			this->tableLayoutPanel1->Controls->Add(this->label27, 2, 8);
			this->tableLayoutPanel1->Controls->Add(this->label26, 1, 8);
			this->tableLayoutPanel1->Controls->Add(this->label25, 0, 8);
			this->tableLayoutPanel1->Controls->Add(this->label24, 2, 7);
			this->tableLayoutPanel1->Controls->Add(this->label23, 1, 7);
			this->tableLayoutPanel1->Controls->Add(this->label22, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->label21, 2, 6);
			this->tableLayoutPanel1->Controls->Add(this->label20, 1, 6);
			this->tableLayoutPanel1->Controls->Add(this->label19, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->label18, 2, 5);
			this->tableLayoutPanel1->Controls->Add(this->label17, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->label16, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->label15, 2, 4);
			this->tableLayoutPanel1->Controls->Add(this->label14, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->label13, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->label12, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->label11, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->label10, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->label9, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->label8, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->label7, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label6, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->label5, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label4, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label3, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->label2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(1, 76);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 11;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.090909F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.090909F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.090909F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.090909F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.090909F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.090909F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.090909F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.090909F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.090909F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.090909F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.090909F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(682, 576);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// label33
			// 
			this->label33->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label33->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label33->Location = System::Drawing::Point(458, 523);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(218, 50);
			this->label33->TabIndex = 32;
			this->label33->Text = L"label33";
			this->label33->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label32
			// 
			this->label32->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label32->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label32->Location = System::Drawing::Point(232, 523);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(217, 50);
			this->label32->TabIndex = 31;
			this->label32->Text = L"label32";
			this->label32->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label31
			// 
			this->label31->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label31->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label31->Location = System::Drawing::Point(6, 523);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(217, 50);
			this->label31->TabIndex = 30;
			this->label31->Text = L"label31";
			this->label31->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label30
			// 
			this->label30->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label30->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label30->Location = System::Drawing::Point(458, 471);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(218, 49);
			this->label30->TabIndex = 29;
			this->label30->Text = L"label30";
			this->label30->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label29
			// 
			this->label29->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label29->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label29->Location = System::Drawing::Point(232, 471);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(217, 49);
			this->label29->TabIndex = 28;
			this->label29->Text = L"label29";
			this->label29->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label28
			// 
			this->label28->BackColor = System::Drawing::SystemColors::Highlight;
			this->label28->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label28->Location = System::Drawing::Point(6, 471);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(217, 49);
			this->label28->TabIndex = 27;
			this->label28->Text = L"label28";
			this->label28->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label27
			// 
			this->label27->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label27->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label27->Location = System::Drawing::Point(458, 419);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(218, 49);
			this->label27->TabIndex = 26;
			this->label27->Text = L"label27";
			this->label27->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label26
			// 
			this->label26->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label26->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label26->Location = System::Drawing::Point(232, 419);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(217, 49);
			this->label26->TabIndex = 25;
			this->label26->Text = L"label26";
			this->label26->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label25
			// 
			this->label25->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label25->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label25->Location = System::Drawing::Point(6, 419);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(217, 49);
			this->label25->TabIndex = 24;
			this->label25->Text = L"label25";
			this->label25->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label24
			// 
			this->label24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label24->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label24->Location = System::Drawing::Point(458, 367);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(218, 49);
			this->label24->TabIndex = 23;
			this->label24->Text = L"label24";
			this->label24->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label23
			// 
			this->label23->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label23->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label23->Location = System::Drawing::Point(232, 367);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(217, 49);
			this->label23->TabIndex = 22;
			this->label23->Text = L"label23";
			this->label23->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label22
			// 
			this->label22->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label22->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label22->Location = System::Drawing::Point(6, 367);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(217, 49);
			this->label22->TabIndex = 21;
			this->label22->Text = L"label22";
			this->label22->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label21
			// 
			this->label21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label21->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label21->Location = System::Drawing::Point(458, 315);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(218, 49);
			this->label21->TabIndex = 20;
			this->label21->Text = L"label21";
			this->label21->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label20
			// 
			this->label20->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label20->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(232, 315);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(217, 49);
			this->label20->TabIndex = 19;
			this->label20->Text = L"label20";
			this->label20->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label19
			// 
			this->label19->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label19->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(6, 315);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(217, 49);
			this->label19->TabIndex = 18;
			this->label19->Text = L"label19";
			this->label19->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label18
			// 
			this->label18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label18->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(458, 263);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(218, 49);
			this->label18->TabIndex = 17;
			this->label18->Text = L"label18";
			this->label18->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label17
			// 
			this->label17->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label17->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(232, 263);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(217, 49);
			this->label17->TabIndex = 16;
			this->label17->Text = L"label17";
			this->label17->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label16
			// 
			this->label16->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label16->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(6, 263);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(217, 49);
			this->label16->TabIndex = 15;
			this->label16->Text = L"label16";
			this->label16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label15
			// 
			this->label15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label15->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(458, 211);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(218, 49);
			this->label15->TabIndex = 14;
			this->label15->Text = L"label15";
			this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label14
			// 
			this->label14->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label14->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(232, 211);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(217, 49);
			this->label14->TabIndex = 13;
			this->label14->Text = L"label14";
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label13
			// 
			this->label13->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label13->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(6, 211);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(217, 49);
			this->label13->TabIndex = 12;
			this->label13->Text = L"label13";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label12
			// 
			this->label12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label12->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(458, 159);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(218, 49);
			this->label12->TabIndex = 11;
			this->label12->Text = L"label12";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label11
			// 
			this->label11->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label11->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(232, 159);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(217, 49);
			this->label11->TabIndex = 10;
			this->label11->Text = L"label11";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label10
			// 
			this->label10->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label10->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(6, 159);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(217, 49);
			this->label10->TabIndex = 9;
			this->label10->Text = L"label10";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label9->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(458, 107);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(218, 49);
			this->label9->TabIndex = 8;
			this->label9->Text = L"label9";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label8
			// 
			this->label8->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label8->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(232, 107);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(217, 49);
			this->label8->TabIndex = 7;
			this->label8->Text = L"label8";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label7
			// 
			this->label7->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label7->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(6, 107);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(217, 49);
			this->label7->TabIndex = 6;
			this->label7->Text = L"label7";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label6->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(458, 55);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(218, 49);
			this->label6->TabIndex = 5;
			this->label6->Text = L"label6";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label5->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(232, 55);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(217, 49);
			this->label5->TabIndex = 4;
			this->label5->Text = L"label5";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label4->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(6, 55);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(217, 49);
			this->label4->TabIndex = 3;
			this->label4->Text = L"label4";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label3->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(458, 3);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(218, 49);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Correct / Incorrect";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label2->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(232, 3);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(217, 49);
			this->label2->TabIndex = 1;
			this->label2->Text = L" Correct Answer";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label1->Font = (gcnew System::Drawing::Font(L"Californian FB", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(6, 3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(217, 49);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Your Answer";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label34->Location = System::Drawing::Point(458, 22);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(111, 32);
			this->label34->TabIndex = 1;
			this->label34->Text = L"Score :";
			// 
			// score_label
			// 
			this->score_label->AutoSize = true;
			this->score_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->score_label->Location = System::Drawing::Point(593, 22);
			this->score_label->Name = L"score_label";
			this->score_label->Size = System::Drawing::Size(0, 32);
			this->score_label->TabIndex = 2;
			// 
			// Result
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Peru;
			this->ClientSize = System::Drawing::Size(682, 653);
			this->Controls->Add(this->score_label);
			this->Controls->Add(this->label34);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"Result";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Result";
			this->Load += gcnew System::EventHandler(this, &Result::Result_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Result_Load(System::Object^  sender, System::EventArgs^  e) {
				int count = 10;
				 
				 generate_observation_sequence();


				int* predicted_label = model_testing_using_static_data();
				int* actual_label = read_actual_label();
				
				
				label5->Text = gcnew String(mapping[actual_label[0]]);
				label8->Text = gcnew String(mapping[actual_label[1]]);
				label11->Text = gcnew String(mapping[actual_label[2]]);
				label14->Text = gcnew String(mapping[actual_label[3]]);
				label17->Text = gcnew String(mapping[actual_label[4]]);
				label20->Text = gcnew String(mapping[actual_label[5]]);
				label23->Text = gcnew String(mapping[actual_label[6]]);
				label26->Text = gcnew String(mapping[actual_label[7]]);
				label29->Text = gcnew String(mapping[actual_label[8]]);
				label32->Text = gcnew String(mapping[actual_label[9]]);
				
				label4->Text = gcnew String(mapping[predicted_label[0]]);
				label7->Text = gcnew String(mapping[predicted_label[1]]);
				label10->Text = gcnew String(mapping[predicted_label[2]]);
				label13->Text = gcnew String(mapping[predicted_label[3]]);
				label16->Text = gcnew String(mapping[predicted_label[4]]);
				label19->Text = gcnew String(mapping[predicted_label[5]]);
				label22->Text = gcnew String(mapping[predicted_label[6]]);
				label25->Text = gcnew String(mapping[predicted_label[7]]);
				label28->Text = gcnew String(mapping[predicted_label[8]]);
				label31->Text = gcnew String(mapping[predicted_label[9]]);

				
				if(predicted_label[0]==actual_label[0])
					label6->Text = "correct";
				else
				{
					label6->BackColor = System::Drawing::Color::Orange;
					label6->Text = "Incorrect";
					count--;
				}
					
				if(predicted_label[1]==actual_label[1])
					label9->Text = "correct";
				else
				{
					label9->BackColor = System::Drawing::Color::Orange;
					label9->Text = "Incorrect";
					count--;
				}

				if(predicted_label[2]==actual_label[2])
					label12->Text = "correct";
				else
				{
					label12->BackColor = System::Drawing::Color::Orange;
					label12->Text = "Incorrect";
					count--;
				}
				
				if(predicted_label[3]==actual_label[3])
					label15->Text = "correct";
				else
				{
					label15->BackColor = System::Drawing::Color::Orange;
					label15->Text = "Incorrect";
					count--;
				}

				if(predicted_label[4]==actual_label[4])
					label18->Text = "correct";
				else
				{
					label18->BackColor = System::Drawing::Color::Orange;
					label18->Text = "Incorrect";
					count--;
				}

				if(predicted_label[5]==actual_label[5])
					label21->Text = "correct";
				else
				{
					label21->BackColor = System::Drawing::Color::Orange;
					label21->Text = "Incorrect";
					count--;
				}


				if(predicted_label[6]==actual_label[6])
					label24->Text = "correct";
				else
				{
					label24->BackColor = System::Drawing::Color::Orange;
					label24->Text = "Incorrect";
					count--;
				}


				if(predicted_label[7]==actual_label[7])
					label27->Text = "correct";
				else
				{
					label27->BackColor = System::Drawing::Color::Orange;
					label27->Text = "Incorrect";
					count--;
				}
				
				if(predicted_label[8]==actual_label[8])
					label30->Text = "correct";
				else
				{
					label30->BackColor = System::Drawing::Color::Orange;
					label30->Text = "Incorrect";
					count--;
				}

				if(predicted_label[9]==actual_label[9])
					label33->Text = "correct";
				else
				{
					label33->BackColor = System::Drawing::Color::Orange;
					label33->Text = "Incorrect";
					count--;
				}

				score_label->Text = System::Convert::ToString(count) + "/" + "10";
	}



};
}
