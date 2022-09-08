#pragma once
#include "Result.h"
#include "string.h"
namespace UI_Part {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for tutorial
	/// </summary>
	public ref class tutorial : public System::Windows::Forms::Form
	{
	public:
		tutorial(void)
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
		~tutorial()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  end_btn;
	protected: 

	private: System::Windows::Forms::Button^  next_btn;

	private: System::Windows::Forms::Button^  start_btn;

	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  name_label;
	private: System::Windows::Forms::PictureBox^  picture_box;


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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->end_btn = (gcnew System::Windows::Forms::Button());
			this->next_btn = (gcnew System::Windows::Forms::Button());
			this->start_btn = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->name_label = (gcnew System::Windows::Forms::Label());
			this->picture_box = (gcnew System::Windows::Forms::PictureBox());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picture_box))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Gold;
			this->panel1->Controls->Add(this->end_btn);
			this->panel1->Controls->Add(this->next_btn);
			this->panel1->Controls->Add(this->start_btn);
			this->panel1->Location = System::Drawing::Point(2, 584);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(679, 69);
			this->panel1->TabIndex = 1;
			// 
			// end_btn
			// 
			this->end_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->end_btn->Location = System::Drawing::Point(497, 21);
			this->end_btn->Name = L"end_btn";
			this->end_btn->Size = System::Drawing::Size(113, 36);
			this->end_btn->TabIndex = 2;
			this->end_btn->Text = L" End";
			this->end_btn->UseVisualStyleBackColor = true;
			this->end_btn->Click += gcnew System::EventHandler(this, &tutorial::end_btn_Click);
			// 
			// next_btn
			// 
			this->next_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->next_btn->Location = System::Drawing::Point(271, 21);
			this->next_btn->Name = L"next_btn";
			this->next_btn->Size = System::Drawing::Size(113, 36);
			this->next_btn->TabIndex = 1;
			this->next_btn->Text = L" Next";
			this->next_btn->UseVisualStyleBackColor = true;
			this->next_btn->Click += gcnew System::EventHandler(this, &tutorial::next_btn_Click);
			// 
			// start_btn
			// 
			this->start_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->start_btn->Location = System::Drawing::Point(49, 21);
			this->start_btn->Name = L"start_btn";
			this->start_btn->Size = System::Drawing::Size(113, 36);
			this->start_btn->TabIndex = 0;
			this->start_btn->Text = L" Start";
			this->start_btn->UseVisualStyleBackColor = true;
			this->start_btn->Click += gcnew System::EventHandler(this, &tutorial::start_btn_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Gold;
			this->panel2->Controls->Add(this->name_label);
			this->panel2->Location = System::Drawing::Point(2, 516);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(679, 69);
			this->panel2->TabIndex = 2;
			// 
			// name_label
			// 
			this->name_label->AutoSize = true;
			this->name_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->name_label->Location = System::Drawing::Point(292, 25);
			this->name_label->Name = L"name_label";
			this->name_label->Size = System::Drawing::Size(0, 32);
			this->name_label->TabIndex = 0;
			// 
			// picture_box
			// 
			this->picture_box->Location = System::Drawing::Point(0, 0);
			this->picture_box->Name = L"picture_box";
			this->picture_box->Size = System::Drawing::Size(682, 517);
			this->picture_box->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picture_box->TabIndex = 3;
			this->picture_box->TabStop = false;
			// 
			// tutorial
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(682, 653);
			this->Controls->Add(this->picture_box);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Name = L"tutorial";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"tutorial";
			this->Load += gcnew System::EventHandler(this, &tutorial::tutorial_Load);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picture_box))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		static array<String^>^ file_list = {"","","","","","","","","","","","","","","","","","","","" };
		int counter;


private: System::Void start_btn_Click(System::Object^  sender, System::EventArgs^  e) {

		   StreamReader^ DataIn = File::OpenText("tutorial.txt");
	       String^ DataStr;
           int count = 0;
           while ((DataStr = DataIn->ReadLine()) != nullptr) 
           {
			   file_list[count] = DataStr;
               count++;   
           }
		   	picture_box->ImageLocation = file_list[counter];
			name_label->Text = (gcnew String(mapping[counter]))->ToUpper();
			counter++;
		   	next_btn->Enabled = true;
			start_btn->Enabled = false;
		}


private: System::Void end_btn_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
		 }
private: System::Void next_btn_Click(System::Object^  sender, System::EventArgs^  e) {
			picture_box->ImageLocation = file_list[counter];
			name_label->Text = (gcnew String(mapping[counter]))->ToUpper();
			counter++;
			if(counter >= 20)
			{
				 next_btn->Enabled = false;
				 end_btn->Enabled = true;
			}
	}

private: System::Void tutorial_Load(System::Object^  sender, System::EventArgs^  e) {
			 next_btn->Enabled = false;
			 end_btn->Enabled = false;

		 }
};
}
