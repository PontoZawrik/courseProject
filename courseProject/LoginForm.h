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
	public: User* currentUser = new User;
	public:
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			PasswordConfLabel->Visible = false;
			PasswordConfInp->Visible = false;
			IsAdminBox->Visible = false;
			RegistrationBtn->Visible = false;
			BackToLogBtn->Visible = false;
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
	private: System::Windows::Forms::Label^ Header;
	protected:

	private: System::Windows::Forms::TextBox^ UsernameInp;
	private: System::Windows::Forms::Label^ UsernameLabel;
	private: System::Windows::Forms::Label^ PasswordLabel;



	private: System::Windows::Forms::TextBox^ PasswordInp;
	private: System::Windows::Forms::Button^ LogInBtn;
	private: System::Windows::Forms::Button^ ToRegisterBtn;
	private: System::Windows::Forms::Label^ PasswordConfLabel;




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
			this->Header = (gcnew System::Windows::Forms::Label());
			this->UsernameInp = (gcnew System::Windows::Forms::TextBox());
			this->UsernameLabel = (gcnew System::Windows::Forms::Label());
			this->PasswordLabel = (gcnew System::Windows::Forms::Label());
			this->PasswordInp = (gcnew System::Windows::Forms::TextBox());
			this->LogInBtn = (gcnew System::Windows::Forms::Button());
			this->ToRegisterBtn = (gcnew System::Windows::Forms::Button());
			this->PasswordConfLabel = (gcnew System::Windows::Forms::Label());
			this->PasswordConfInp = (gcnew System::Windows::Forms::TextBox());
			this->IsAdminBox = (gcnew System::Windows::Forms::CheckBox());
			this->BackToLogBtn = (gcnew System::Windows::Forms::Button());
			this->RegistrationBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Header
			// 
			this->Header->AutoSize = true;
			this->Header->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Header->Location = System::Drawing::Point(12, 36);
			this->Header->Name = L"Header";
			this->Header->Size = System::Drawing::Size(261, 39);
			this->Header->TabIndex = 0;
			this->Header->Text = L"Вход в систему";
			// 
			// UsernameInp
			// 
			this->UsernameInp->Location = System::Drawing::Point(114, 163);
			this->UsernameInp->Name = L"UsernameInp";
			this->UsernameInp->Size = System::Drawing::Size(284, 22);
			this->UsernameInp->TabIndex = 1;
			// 
			// UsernameLabel
			// 
			this->UsernameLabel->AutoSize = true;
			this->UsernameLabel->Location = System::Drawing::Point(112, 145);
			this->UsernameLabel->Name = L"UsernameLabel";
			this->UsernameLabel->Size = System::Drawing::Size(132, 16);
			this->UsernameLabel->TabIndex = 3;
			this->UsernameLabel->Text = L"Имя пользователя:";
			// 
			// PasswordLabel
			// 
			this->PasswordLabel->AutoSize = true;
			this->PasswordLabel->Location = System::Drawing::Point(112, 192);
			this->PasswordLabel->Name = L"PasswordLabel";
			this->PasswordLabel->Size = System::Drawing::Size(59, 16);
			this->PasswordLabel->TabIndex = 5;
			this->PasswordLabel->Text = L"Пароль:";
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
			this->LogInBtn->Location = System::Drawing::Point(114, 244);
			this->LogInBtn->Name = L"LogInBtn";
			this->LogInBtn->Size = System::Drawing::Size(283, 30);
			this->LogInBtn->TabIndex = 6;
			this->LogInBtn->Text = L"Вход";
			this->LogInBtn->UseVisualStyleBackColor = true;
			this->LogInBtn->Click += gcnew System::EventHandler(this, &LoginForm::LogInBtn_Click);
			// 
			// ToRegisterBtn
			// 
			this->ToRegisterBtn->Location = System::Drawing::Point(116, 279);
			this->ToRegisterBtn->Name = L"ToRegisterBtn";
			this->ToRegisterBtn->Size = System::Drawing::Size(283, 30);
			this->ToRegisterBtn->TabIndex = 7;
			this->ToRegisterBtn->Text = L"Зарегистрироваться";
			this->ToRegisterBtn->UseVisualStyleBackColor = true;
			this->ToRegisterBtn->Click += gcnew System::EventHandler(this, &LoginForm::ToRegisterBtn_Click);
			// 
			// PasswordConfLabel
			// 
			this->PasswordConfLabel->AutoSize = true;
			this->PasswordConfLabel->Location = System::Drawing::Point(113, 237);
			this->PasswordConfLabel->Name = L"PasswordConfLabel";
			this->PasswordConfLabel->Size = System::Drawing::Size(147, 16);
			this->PasswordConfLabel->TabIndex = 9;
			this->PasswordConfLabel->Text = L"Подтвердить пароль:";
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
			this->BackToLogBtn->Click += gcnew System::EventHandler(this, &LoginForm::BackToLogBtn_Click);
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
			this->Controls->Add(this->PasswordConfLabel);
			this->Controls->Add(this->PasswordConfInp);
			this->Controls->Add(this->ToRegisterBtn);
			this->Controls->Add(this->LogInBtn);
			this->Controls->Add(this->PasswordLabel);
			this->Controls->Add(this->PasswordInp);
			this->Controls->Add(this->UsernameLabel);
			this->Controls->Add(this->UsernameInp);
			this->Controls->Add(this->Header);
			this->Name = L"LoginForm";
			this->Text = L"LoginForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RegistrationBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (PasswordInp->Text == PasswordConfInp->Text) {
			string username = ToStdString(UsernameInp->Text);
			string password = ToStdString(PasswordInp->Text);

			int id = RegisterUser(username, password, IsAdminBox->Checked);
			if (id) {
				currentUser->id = id;
				currentUser->username = username;
				currentUser->password = password;
				currentUser->isAdmin = IsAdminBox->Checked;

				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->Close();
			}
		}
	}

	private: System::Void LogInBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		string username = ToStdString(UsernameInp->Text);
		string password = ToStdString(PasswordInp->Text);

		if (LoginUser(username, password, currentUser)) {
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	}



	// Переключение форм
	private: System::Void ToRegisterBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		PasswordConfLabel->Visible = true;
		PasswordConfInp->Visible = true;
		IsAdminBox->Visible = true;
		RegistrationBtn->Visible = true;
		BackToLogBtn->Visible = true;

		LogInBtn->Visible = false;
		ToRegisterBtn->Visible = false;

		Header->Text = "Регистрация";
	}

	private: System::Void BackToLogBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		PasswordConfLabel->Visible = false;
		PasswordConfInp->Visible = false;
		IsAdminBox->Visible = false;
		RegistrationBtn->Visible = false;
		BackToLogBtn->Visible = false;

		LogInBtn->Visible = true;
		ToRegisterBtn->Visible = true;

		Header->Text = "Вход в систему";
	}
};
}
