#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Result.h"
#include "cstring"
namespace UI_Part {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for training_module
	/// </summary>
	public ref class training_module : public System::Windows::Forms::Form
	{
	public:
		training_module(void)
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
		~training_module()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  training_btn;
	private: System::Windows::Forms::Button^  testing_btn;
	protected: 

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox_tb;



	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  predicted_word_label;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  actual_word_label;
	private: System::Windows::Forms::Button^  submit_btn;




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
			this->training_btn = (gcnew System::Windows::Forms::Button());
			this->testing_btn = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->submit_btn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_tb = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->predicted_word_label = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->actual_word_label = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// training_btn
			// 
			this->training_btn->BackColor = System::Drawing::SystemColors::Control;
			this->training_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->training_btn->Location = System::Drawing::Point(46, 120);
			this->training_btn->Name = L"training_btn";
			this->training_btn->Size = System::Drawing::Size(201, 50);
			this->training_btn->TabIndex = 0;
			this->training_btn->Text = L"Start Recording";
			this->training_btn->UseVisualStyleBackColor = false;
			this->training_btn->Click += gcnew System::EventHandler(this, &training_module::training_btn_Click);
			// 
			// testing_btn
			// 
			this->testing_btn->BackColor = System::Drawing::SystemColors::Control;
			this->testing_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->testing_btn->Location = System::Drawing::Point(46, 115);
			this->testing_btn->Name = L"testing_btn";
			this->testing_btn->Size = System::Drawing::Size(201, 47);
			this->testing_btn->TabIndex = 1;
			this->testing_btn->Text = L"Testing";
			this->testing_btn->UseVisualStyleBackColor = false;
			this->testing_btn->Click += gcnew System::EventHandler(this, &training_module::testing_btn_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->submit_btn);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox_tb);
			this->groupBox1->Controls->Add(this->training_btn);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(71, 68);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(548, 226);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Training";
			// 
			// submit_btn
			// 
			this->submit_btn->BackColor = System::Drawing::SystemColors::Control;
			this->submit_btn->Location = System::Drawing::Point(441, 32);
			this->submit_btn->Name = L"submit_btn";
			this->submit_btn->Size = System::Drawing::Size(101, 32);
			this->submit_btn->TabIndex = 4;
			this->submit_btn->Text = L"Submit";
			this->submit_btn->UseVisualStyleBackColor = false;
			this->submit_btn->Click += gcnew System::EventHandler(this, &training_module::submit_btn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(6, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(225, 24);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Enter the word for training";
			// 
			// textBox_tb
			// 
			this->textBox_tb->Location = System::Drawing::Point(249, 36);
			this->textBox_tb->Name = L"textBox_tb";
			this->textBox_tb->Size = System::Drawing::Size(168, 28);
			this->textBox_tb->TabIndex = 1;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->predicted_word_label);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->actual_word_label);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->testing_btn);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(71, 351);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(548, 243);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Testing";
			// 
			// predicted_word_label
			// 
			this->predicted_word_label->AutoSize = true;
			this->predicted_word_label->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->predicted_word_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->predicted_word_label->Location = System::Drawing::Point(224, 205);
			this->predicted_word_label->Name = L"predicted_word_label";
			this->predicted_word_label->Size = System::Drawing::Size(40, 26);
			this->predicted_word_label->TabIndex = 5;
			this->predicted_word_label->Text = L"NIL";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(46, 205);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(141, 24);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Predicted Word";
			// 
			// actual_word_label
			// 
			this->actual_word_label->AutoSize = true;
			this->actual_word_label->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->actual_word_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->actual_word_label->Location = System::Drawing::Point(224, 48);
			this->actual_word_label->Name = L"actual_word_label";
			this->actual_word_label->Size = System::Drawing::Size(40, 26);
			this->actual_word_label->TabIndex = 3;
			this->actual_word_label->Text = L"NIL";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(43, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(113, 24);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Actual Word";
			this->label2->Click += gcnew System::EventHandler(this, &training_module::label2_Click);
			// 
			// training_module
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gold;
			this->ClientSize = System::Drawing::Size(682, 653);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"training_module";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"training_module";
			this->Load += gcnew System::EventHandler(this, &training_module::training_module_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void training_btn_Click(System::Object^  sender, System::EventArgs^  e) {
			
			 char path_txt[100];
			 char path_wav[100];
			 char digit[4];
			 
			 for(int i = 0; i < 20; i++)
			 {
				 strcpy(path_txt,"test_utterence/");
				 sprintf(digit,"%d",i);
				 strcat(path_txt,digit);
				 strcat(path_txt,".txt");

				 strcpy(path_wav,"test_utterence/");
				 strcat(path_wav,digit);
				 strcat(path_wav,".wav ");

				 char command[100] = "Recording_Module.exe 2 ";
				 strcat(command,path_wav);
				 strcat(command,path_txt);
			 
				 system(command);
			 
			 }
			 training_btn->Enabled = false;



			 generate_observation_sequence_for_live_data();

			 train_model(20);

			 testing_btn->Enabled = true;


		 }

private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void training_module_Load(System::Object^  sender, System::EventArgs^  e) {
		
			 training_btn->Enabled = false;
			 testing_btn->Enabled = false;
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void submit_btn_Click(System::Object^  sender, System::EventArgs^  e) {
			 training_btn->Enabled = true;
			 submit_btn->Enabled = false;
			 actual_word_label->Text = textBox_tb->Text;
		 } 

private: System::Void testing_btn_Click(System::Object^  sender, System::EventArgs^  e) {

			char path_txt[40] = "Live_Data_Test/test.txt";//to store the live data test file

			char path_wav[40] = "Live_Data_Test/test.wav ";
			
			char command[100] = "Recording_Module.exe 2 ";
			strcat(command,path_wav);
			strcat(command,path_txt);			 
			
			system(command);

			seq_live_test_observation();

			int a = model_testing_using_live_data();
			
			if(a == 20)
				predicted_word_label->Text = textBox_tb->Text;
			else
				predicted_word_label->Text = gcnew String(mapping[a]);
				
		 }
};
}
