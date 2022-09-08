#pragma once
#include "Result.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
namespace UI_Part {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for Quiz_Page
	/// </summary>
	public ref class Quiz_Page : public System::Windows::Forms::Form
	{
	public:
		Quiz_Page(void)
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
		~Quiz_Page()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected: 
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  end_btn;


	private: System::Windows::Forms::Button^  next_btn;

	private: System::Windows::Forms::Button^  start_btn;
	private: System::Windows::Forms::PictureBox^  picture_box;
	private: System::Windows::Forms::Button^  start_recording_btn;





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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Quiz_Page::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->picture_box = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->start_recording_btn = (gcnew System::Windows::Forms::Button());
			this->end_btn = (gcnew System::Windows::Forms::Button());
			this->next_btn = (gcnew System::Windows::Forms::Button());
			this->start_btn = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picture_box))->BeginInit();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->picture_box);
			this->panel1->Location = System::Drawing::Point(1, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(681, 561);
			this->panel1->TabIndex = 0;
			// 
			// picture_box
			// 
			this->picture_box->Location = System::Drawing::Point(0, 0);
			this->picture_box->Name = L"picture_box";
			this->picture_box->Size = System::Drawing::Size(681, 561);
			this->picture_box->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picture_box->TabIndex = 0;
			this->picture_box->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->Controls->Add(this->start_recording_btn);
			this->panel2->Controls->Add(this->end_btn);
			this->panel2->Controls->Add(this->next_btn);
			this->panel2->Controls->Add(this->start_btn);
			this->panel2->Location = System::Drawing::Point(0, 563);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(682, 95);
			this->panel2->TabIndex = 1;
			// 
			// start_recording_btn
			// 
			this->start_recording_btn->BackColor = System::Drawing::SystemColors::Control;
			this->start_recording_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->start_recording_btn->Location = System::Drawing::Point(294, 31);
			this->start_recording_btn->Name = L"start_recording_btn";
			this->start_recording_btn->Size = System::Drawing::Size(221, 40);
			this->start_recording_btn->TabIndex = 4;
			this->start_recording_btn->Text = L"Start Recording";
			this->start_recording_btn->UseVisualStyleBackColor = false;
			this->start_recording_btn->Click += gcnew System::EventHandler(this, &Quiz_Page::start_recording_btn_Click);
			// 
			// end_btn
			// 
			this->end_btn->BackColor = System::Drawing::SystemColors::Control;
			this->end_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->end_btn->Location = System::Drawing::Point(537, 31);
			this->end_btn->Name = L"end_btn";
			this->end_btn->Size = System::Drawing::Size(112, 40);
			this->end_btn->TabIndex = 3;
			this->end_btn->Text = L"End";
			this->end_btn->UseVisualStyleBackColor = false;
			this->end_btn->Click += gcnew System::EventHandler(this, &Quiz_Page::end_btn_Click);
			// 
			// next_btn
			// 
			this->next_btn->BackColor = System::Drawing::SystemColors::Control;
			this->next_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->next_btn->Location = System::Drawing::Point(152, 31);
			this->next_btn->Name = L"next_btn";
			this->next_btn->Size = System::Drawing::Size(112, 40);
			this->next_btn->TabIndex = 2;
			this->next_btn->Text = L"Next";
			this->next_btn->UseVisualStyleBackColor = false;
			this->next_btn->Click += gcnew System::EventHandler(this, &Quiz_Page::next_btn_Click);
			// 
			// start_btn
			// 
			this->start_btn->BackColor = System::Drawing::SystemColors::Control;
			this->start_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->start_btn->Location = System::Drawing::Point(12, 31);
			this->start_btn->Name = L"start_btn";
			this->start_btn->Size = System::Drawing::Size(112, 40);
			this->start_btn->TabIndex = 1;
			this->start_btn->Text = L"Start";
			this->start_btn->UseVisualStyleBackColor = false;
			this->start_btn->Click += gcnew System::EventHandler(this, &Quiz_Page::start_btn_Click);
			// 
			// Quiz_Page
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(682, 653);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"Quiz_Page";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Quiz_Page";
			this->Load += gcnew System::EventHandler(this, &Quiz_Page::Quiz_Page_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picture_box))->EndInit();
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		static array<String^>^ file_list = {"","","","","","","","","",""};
		int counter;


private: System::Void next_btn_Click(System::Object^  sender, System::EventArgs^  e) {
				picture_box->ImageLocation = file_list[counter];
				counter++;
				start_recording_btn->Enabled = true;
				next_btn->Enabled = false;
		 }
		 
private: System::Void start_btn_Click(System::Object^  sender, System::EventArgs^  e) {

		   StreamReader^ DataIn = File::OpenText("quiz.txt");
	       String^ DataStr;
           int count = 0;
           while ((DataStr = DataIn->ReadLine()) != nullptr) 
           {
			   file_list[count] = DataStr;
               count++;   
           }
		   	 picture_box->ImageLocation = file_list[counter];
			 counter++;
			 start_btn->Enabled = false;
			 start_recording_btn->Enabled = true;
		}


private: System::Void end_btn_Click(System::Object^  sender, System::EventArgs^  e) {
			  Result^ obj = gcnew Result();
			  obj->ShowDialog();
			  this->Hide();
		 }
private: System::Void Quiz_Page_Load(System::Object^  sender, System::EventArgs^  e) {
			 next_btn->Enabled = false;
			 end_btn->Enabled = false;
			 start_recording_btn->Enabled = false;
		 }
private: System::Void start_recording_btn_Click(System::Object^  sender, System::EventArgs^  e) {
			 char path_txt[100];
			 char path_wav[100];
			 char digit[4];
			 
			 strcpy(path_txt,"recording/");
			 sprintf(digit,"%d",counter);
			 strcat(path_txt,digit);
			 strcat(path_txt,".txt");

			 strcpy(path_wav,"recording/");
			 strcat(path_wav,digit);
			 strcat(path_wav,".wav ");


			 char command[100] = "Recording_Module.exe 3 ";
			 strcat(command,path_wav);
			 strcat(command,path_txt);
			 
			 system(command);
			 start_recording_btn->Enabled = false;
			 if(counter < 10)
				next_btn->Enabled = true;
			 else
				 end_btn->Enabled = true;
		 }
};
}
