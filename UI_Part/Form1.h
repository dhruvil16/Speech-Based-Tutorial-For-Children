#pragma once
#include "Quiz_Page.h"
#include "quiz_generation.cpp"
#include "training_module.h"
#include "tutorial.h"
namespace UI_Part {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  quiz_btn;
	private: System::Windows::Forms::Button^  training_btn;
	private: System::Windows::Forms::Button^  tutorial_btn;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->quiz_btn = (gcnew System::Windows::Forms::Button());
			this->training_btn = (gcnew System::Windows::Forms::Button());
			this->tutorial_btn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// quiz_btn
			// 
			this->quiz_btn->BackColor = System::Drawing::SystemColors::Highlight;
			this->quiz_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->quiz_btn->Location = System::Drawing::Point(227, 282);
			this->quiz_btn->Name = L"quiz_btn";
			this->quiz_btn->Size = System::Drawing::Size(230, 81);
			this->quiz_btn->TabIndex = 0;
			this->quiz_btn->Text = L"Quiz";
			this->quiz_btn->UseVisualStyleBackColor = false;
			this->quiz_btn->Click += gcnew System::EventHandler(this, &Form1::quiz_btn_Click);
			// 
			// training_btn
			// 
			this->training_btn->BackColor = System::Drawing::SystemColors::Highlight;
			this->training_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->training_btn->Location = System::Drawing::Point(227, 457);
			this->training_btn->Name = L"training_btn";
			this->training_btn->Size = System::Drawing::Size(230, 81);
			this->training_btn->TabIndex = 1;
			this->training_btn->Text = L"Training";
			this->training_btn->UseVisualStyleBackColor = false;
			this->training_btn->Click += gcnew System::EventHandler(this, &Form1::training_btn_Click);
			// 
			// tutorial_btn
			// 
			this->tutorial_btn->BackColor = System::Drawing::SystemColors::Highlight;
			this->tutorial_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tutorial_btn->Location = System::Drawing::Point(227, 108);
			this->tutorial_btn->Name = L"tutorial_btn";
			this->tutorial_btn->Size = System::Drawing::Size(230, 81);
			this->tutorial_btn->TabIndex = 2;
			this->tutorial_btn->Text = L"Tutorial";
			this->tutorial_btn->UseVisualStyleBackColor = false;
			this->tutorial_btn->Click += gcnew System::EventHandler(this, &Form1::tutorial_btn_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(682, 653);
			this->Controls->Add(this->tutorial_btn);
			this->Controls->Add(this->training_btn);
			this->Controls->Add(this->quiz_btn);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Quiz app";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void quiz_btn_Click(System::Object^  sender, System::EventArgs^  e) {
				 Quiz_Page^ obj = gcnew Quiz_Page();
				 quiz_file_generate();
				 obj->ShowDialog();  
			 }
	private: System::Void training_btn_Click(System::Object^  sender, System::EventArgs^  e) {
				 training_module^ obj = gcnew training_module();
				 obj->ShowDialog();  
		}
	private: System::Void tutorial_btn_Click(System::Object^  sender, System::EventArgs^  e) {
				 tutorial^ obj = gcnew tutorial();
				 obj->ShowDialog();
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}

