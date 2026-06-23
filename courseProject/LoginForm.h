#pragma once
#include "UserManage.h"
#include "Utils.h"

namespace courseProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ UsernameInp;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ PasswordInp;
	private: System::Windows::Forms::Button^ LogInBtn;
	private: System::Windows::Forms::Button^ ToRegisterBtn;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ PasswordConfInp;
	private: System::Windows::Forms::CheckBox^ IsAdminBox;
	private: System::Windows::Forms::Button^ BackToLogBtn;



	private: System::Windows::Forms::Button^ RegistrationBtn;



	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->UsernameInp = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->PasswordInp = (gcnew System::Windows::Forms::TextBox());
			this->LogInBtn = (gcnew System::Windows::Forms::Button());
			this->ToRegisterBtn = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->PasswordConfInp = (gcnew System::Windows::Forms::TextBox());
			this->IsAdminBox = (gcnew System::Windows::Forms::CheckBox());
			this->BackToLogBtn = (gcnew System::Windows::Forms::Button());
			this->RegistrationBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(261, 39);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Вход в систему";
			// 
			// UsernameInp
			// 
			this->UsernameInp->Location = System::Drawing::Point(114, 163);
			this->UsernameInp->Name = L"UsernameInp";
			this->UsernameInp->Size = System::Drawing::Size(284, 22);
			this->UsernameInp->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(112, 145);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(132, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Имя пользователя:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(112, 192);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Пароль:";
			// 
			// PasswordInp
			// 
			this->PasswordInp->Location = System::Drawing::Point(114, 210);
			this->PasswordInp->Name = L"PasswordInp";
			this->PasswordInp->Size = System::Drawing::Size(284, 22);
			this->PasswordInp->TabIndex = 4;
			// 
			// LogInBtn
			// 
			this->LogInBtn->Location = System::Drawing::Point(298, 415);
			this->LogInBtn->Name = L"LogInBtn";
			this->LogInBtn->Size = System::Drawing::Size(283, 30);
			this->LogInBtn->TabIndex = 6;
			this->LogInBtn->Text = L"Вход";
			this->LogInBtn->UseVisualStyleBackColor = true;
			// 
			// ToRegisterBtn
			// 
			this->ToRegisterBtn->Location = System::Drawing::Point(298, 452);
			this->ToRegisterBtn->Name = L"ToRegisterBtn";
			this->ToRegisterBtn->Size = System::Drawing::Size(283, 30);
			this->ToRegisterBtn->TabIndex = 7;
			this->ToRegisterBtn->Text = L"Зарегистрироваться";
			this->ToRegisterBtn->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(113, 237);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(147, 16);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Подтвердить пароль:";
			// 
			// PasswordConfInp
			// 
			this->PasswordConfInp->Location = System::Drawing::Point(115, 255);
			this->PasswordConfInp->Name = L"PasswordConfInp";
			this->PasswordConfInp->Size = System::Drawing::Size(284, 22);
			this->PasswordConfInp->TabIndex = 8;
			// 
			// IsAdminBox
			// 
			this->IsAdminBox->AutoSize = true;
			this->IsAdminBox->Location = System::Drawing::Point(116, 284);
			this->IsAdminBox->Name = L"IsAdminBox";
			this->IsAdminBox->Size = System::Drawing::Size(78, 20);
			this->IsAdminBox->TabIndex = 10;
			this->IsAdminBox->Text = L"Админ\?";
			this->IsAdminBox->UseVisualStyleBackColor = true;
			// 
			// BackToLogBtn
			// 
			this->BackToLogBtn->Location = System::Drawing::Point(115, 349);
			this->BackToLogBtn->Name = L"BackToLogBtn";
			this->BackToLogBtn->Size = System::Drawing::Size(283, 30);
			this->BackToLogBtn->TabIndex = 12;
			this->BackToLogBtn->Text = L"Назад";
			this->BackToLogBtn->UseVisualStyleBackColor = true;
			// 
			// RegistrationBtn
			// 
			this->RegistrationBtn->Location = System::Drawing::Point(115, 312);
			this->RegistrationBtn->Name = L"RegistrationBtn";
			this->RegistrationBtn->Size = System::Drawing::Size(283, 30);
			this->RegistrationBtn->TabIndex = 11;
			this->RegistrationBtn->Text = L"Создать аккаунт";
			this->RegistrationBtn->UseVisualStyleBackColor = true;
			this->RegistrationBtn->Click += gcnew System::EventHandler(this, &LoginForm::RegistrationBtn_Click);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(515, 484);
			this->Controls->Add(this->BackToLogBtn);
			this->Controls->Add(this->RegistrationBtn);
			this->Controls->Add(this->IsAdminBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->PasswordConfInp);
			this->Controls->Add(this->ToRegisterBtn);
			this->Controls->Add(this->LogInBtn);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->PasswordInp);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->UsernameInp);
			this->Controls->Add(this->label1);
			this->Name = L"LoginForm";
			this->Text = L"LoginForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RegistrationBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (PasswordInp->Text == PasswordConfInp->Text) {
			RegisterUser(
				ToStdString(UsernameInp->Text), 
				ToStdString(PasswordInp->Text), 
				IsAdminBox->Checked
			);
		}
	}
};
}
