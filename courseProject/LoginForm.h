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

			this->BackColor = GlobalSettings::GetTheme();
			ApplySettings();
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
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ViewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ LanguageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ThemeToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^ LangRUToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ LangENToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ LangBYToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ WhiteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ BlueToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ PurpleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ HelpToolStripMenuItem;
	private: System::Windows::Forms::Label^ ErrorInfo;






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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ViewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LanguageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LangRUToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LangENToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LangBYToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ThemeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->WhiteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BlueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->PurpleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->HelpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ErrorInfo = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
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
			this->UsernameInp->ForeColor = System::Drawing::Color::Gray;
			this->UsernameInp->Location = System::Drawing::Point(114, 163);
			this->UsernameInp->Name = L"UsernameInp";
			this->UsernameInp->Size = System::Drawing::Size(284, 22);
			this->UsernameInp->TabIndex = 1;
			this->UsernameInp->Text = L"Введите имя:";
			this->UsernameInp->Enter += gcnew System::EventHandler(this, &LoginForm::UsernameInp_Enter);
			this->UsernameInp->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &LoginForm::UsernameInp_KeyPress);
			this->UsernameInp->Leave += gcnew System::EventHandler(this, &LoginForm::UsernameInp_Leave);
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
			this->PasswordInp->ForeColor = System::Drawing::Color::Gray;
			this->PasswordInp->Location = System::Drawing::Point(114, 210);
			this->PasswordInp->Name = L"PasswordInp";
			this->PasswordInp->Size = System::Drawing::Size(284, 22);
			this->PasswordInp->TabIndex = 4;
			this->PasswordInp->Text = L"Введите пароль:";
			this->PasswordInp->Enter += gcnew System::EventHandler(this, &LoginForm::PasswordInp_Enter);
			this->PasswordInp->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &LoginForm::PasswordInp_KeyPress);
			this->PasswordInp->Leave += gcnew System::EventHandler(this, &LoginForm::PasswordInp_Leave);
			// 
			// LogInBtn
			// 
			this->LogInBtn->Location = System::Drawing::Point(114, 261);
			this->LogInBtn->Name = L"LogInBtn";
			this->LogInBtn->Size = System::Drawing::Size(283, 30);
			this->LogInBtn->TabIndex = 6;
			this->LogInBtn->Text = L"Вход";
			this->LogInBtn->UseVisualStyleBackColor = true;
			this->LogInBtn->Click += gcnew System::EventHandler(this, &LoginForm::LogInBtn_Click);
			// 
			// ToRegisterBtn
			// 
			this->ToRegisterBtn->Location = System::Drawing::Point(116, 296);
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
			this->PasswordConfInp->ForeColor = System::Drawing::Color::Gray;
			this->PasswordConfInp->Location = System::Drawing::Point(115, 255);
			this->PasswordConfInp->Name = L"PasswordConfInp";
			this->PasswordConfInp->Size = System::Drawing::Size(284, 22);
			this->PasswordConfInp->TabIndex = 8;
			this->PasswordConfInp->Text = L"Подтвердите пароль:";
			this->PasswordConfInp->Enter += gcnew System::EventHandler(this, &LoginForm::PasswordConfInp_Enter);
			this->PasswordConfInp->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &LoginForm::PasswordConfInp_KeyPress);
			this->PasswordConfInp->Leave += gcnew System::EventHandler(this, &LoginForm::PasswordConfInp_Leave);
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
			this->BackToLogBtn->Location = System::Drawing::Point(115, 366);
			this->BackToLogBtn->Name = L"BackToLogBtn";
			this->BackToLogBtn->Size = System::Drawing::Size(283, 30);
			this->BackToLogBtn->TabIndex = 12;
			this->BackToLogBtn->Text = L"Назад";
			this->BackToLogBtn->UseVisualStyleBackColor = true;
			this->BackToLogBtn->Click += gcnew System::EventHandler(this, &LoginForm::BackToLogBtn_Click);
			// 
			// RegistrationBtn
			// 
			this->RegistrationBtn->Location = System::Drawing::Point(115, 329);
			this->RegistrationBtn->Name = L"RegistrationBtn";
			this->RegistrationBtn->Size = System::Drawing::Size(283, 30);
			this->RegistrationBtn->TabIndex = 11;
			this->RegistrationBtn->Text = L"Создать аккаунт";
			this->RegistrationBtn->UseVisualStyleBackColor = true;
			this->RegistrationBtn->Click += gcnew System::EventHandler(this, &LoginForm::RegistrationBtn_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ViewToolStripMenuItem,
					this->HelpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(515, 30);
			this->menuStrip1->TabIndex = 13;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ViewToolStripMenuItem
			// 
			this->ViewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->LanguageToolStripMenuItem,
					this->ThemeToolStripMenuItem
			});
			this->ViewToolStripMenuItem->Name = L"ViewToolStripMenuItem";
			this->ViewToolStripMenuItem->Size = System::Drawing::Size(49, 26);
			this->ViewToolStripMenuItem->Text = L"Вид";
			// 
			// LanguageToolStripMenuItem
			// 
			this->LanguageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->LangRUToolStripMenuItem,
					this->LangENToolStripMenuItem, this->LangBYToolStripMenuItem
			});
			this->LanguageToolStripMenuItem->Name = L"LanguageToolStripMenuItem";
			this->LanguageToolStripMenuItem->Size = System::Drawing::Size(127, 26);
			this->LanguageToolStripMenuItem->Text = L"Язык";
			// 
			// LangRUToolStripMenuItem
			// 
			this->LangRUToolStripMenuItem->Name = L"LangRUToolStripMenuItem";
			this->LangRUToolStripMenuItem->Size = System::Drawing::Size(181, 26);
			this->LangRUToolStripMenuItem->Text = L"Русский";
			this->LangRUToolStripMenuItem->Click += gcnew System::EventHandler(this, &LoginForm::LangRUToolStripMenuItem_Click);
			// 
			// LangENToolStripMenuItem
			// 
			this->LangENToolStripMenuItem->Name = L"LangENToolStripMenuItem";
			this->LangENToolStripMenuItem->Size = System::Drawing::Size(181, 26);
			this->LangENToolStripMenuItem->Text = L"Английский";
			this->LangENToolStripMenuItem->Click += gcnew System::EventHandler(this, &LoginForm::LangENToolStripMenuItem_Click);
			// 
			// LangBYToolStripMenuItem
			// 
			this->LangBYToolStripMenuItem->Name = L"LangBYToolStripMenuItem";
			this->LangBYToolStripMenuItem->Size = System::Drawing::Size(181, 26);
			this->LangBYToolStripMenuItem->Text = L"Белорусский";
			this->LangBYToolStripMenuItem->Click += gcnew System::EventHandler(this, &LoginForm::LangBYToolStripMenuItem_Click);
			// 
			// ThemeToolStripMenuItem
			// 
			this->ThemeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->WhiteToolStripMenuItem,
					this->BlueToolStripMenuItem, this->PurpleToolStripMenuItem
			});
			this->ThemeToolStripMenuItem->Name = L"ThemeToolStripMenuItem";
			this->ThemeToolStripMenuItem->Size = System::Drawing::Size(127, 26);
			this->ThemeToolStripMenuItem->Text = L"Тема";
			// 
			// WhiteToolStripMenuItem
			// 
			this->WhiteToolStripMenuItem->Name = L"WhiteToolStripMenuItem";
			this->WhiteToolStripMenuItem->Size = System::Drawing::Size(176, 26);
			this->WhiteToolStripMenuItem->Text = L"Белая";
			this->WhiteToolStripMenuItem->Click += gcnew System::EventHandler(this, &LoginForm::WhiteToolStripMenuItem_Click);
			// 
			// BlueToolStripMenuItem
			// 
			this->BlueToolStripMenuItem->Name = L"BlueToolStripMenuItem";
			this->BlueToolStripMenuItem->Size = System::Drawing::Size(176, 26);
			this->BlueToolStripMenuItem->Text = L"Синяя";
			this->BlueToolStripMenuItem->Click += gcnew System::EventHandler(this, &LoginForm::BlueToolStripMenuItem_Click);
			// 
			// PurpleToolStripMenuItem
			// 
			this->PurpleToolStripMenuItem->Name = L"PurpleToolStripMenuItem";
			this->PurpleToolStripMenuItem->Size = System::Drawing::Size(176, 26);
			this->PurpleToolStripMenuItem->Text = L"Фиолетовая";
			this->PurpleToolStripMenuItem->Click += gcnew System::EventHandler(this, &LoginForm::PurpleToolStripMenuItem_Click);
			// 
			// HelpToolStripMenuItem
			// 
			this->HelpToolStripMenuItem->Name = L"HelpToolStripMenuItem";
			this->HelpToolStripMenuItem->Size = System::Drawing::Size(81, 26);
			this->HelpToolStripMenuItem->Text = L"Справка";
			// 
			// ErrorInfo
			// 
			this->ErrorInfo->AutoSize = true;
			this->ErrorInfo->ForeColor = System::Drawing::Color::Red;
			this->ErrorInfo->Location = System::Drawing::Point(116, 240);
			this->ErrorInfo->Name = L"ErrorInfo";
			this->ErrorInfo->Size = System::Drawing::Size(0, 16);
			this->ErrorInfo->TabIndex = 14;
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(515, 484);
			this->Controls->Add(this->ErrorInfo);
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
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"LoginForm";
			this->Text = L"LoginForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RegistrationBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ResetInputBox();

		if (UsernameInp->Text != GlobalSettings::GetLang("UsernameInp")
			&& PasswordInp->Text != GlobalSettings::GetLang("PasswordInp")
			&& PasswordConfInp->Text != GlobalSettings::GetLang("PasswordConfInp"))
		{
			if (PasswordInp->Text != PasswordConfInp->Text) {
				ErrorInfo->Text = GlobalSettings::GetLang("PassDiffError");
				return;
			}

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
			else {
				ErrorInfo->Text = GlobalSettings::GetLang("ExistingUserError");
			}
		}
		else {
			UsernameInp->ForeColor = (UsernameInp->Text == GlobalSettings::GetLang("UsernameInp") ? Color::Red : UsernameInp->ForeColor);
			PasswordInp->ForeColor = (PasswordInp->Text == GlobalSettings::GetLang("PasswordInp") ? Color::Red : PasswordInp->ForeColor);
			PasswordConfInp->ForeColor = (PasswordConfInp->Text == GlobalSettings::GetLang("PasswordConfInp") ? Color::Red : PasswordConfInp->ForeColor);
			ErrorInfo->Text = GlobalSettings::GetLang("EmptyFieldsError");
		}
	}

	private: System::Void LogInBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (UsernameInp->Text != GlobalSettings::GetLang("UsernameInp") 
			&& PasswordInp->Text != GlobalSettings::GetLang("PasswordInp")) 
		{
			string username = ToStdString(UsernameInp->Text);
			string password = ToStdString(PasswordInp->Text);

			if (LoginUser(username, password, currentUser)) {
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->Close();
			}
			else {
				ErrorInfo->Text = GlobalSettings::GetLang("EmptyFieldsError");
			}
		}
		else {
			UsernameInp->ForeColor = (UsernameInp->Text == GlobalSettings::GetLang("UsernameInp") ? Color::Red : UsernameInp->ForeColor);
			PasswordInp->ForeColor = (PasswordInp->Text == GlobalSettings::GetLang("PasswordInp") ? Color::Red : PasswordInp->ForeColor);
			ErrorInfo->Text = GlobalSettings::GetLang("EmptyFieldsError");
		}
	}


// menuStrip
	// Смена языка
	private: System::Void LangRUToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		GlobalSettings::CurrentLang = Lang::RU;
		ApplySettings();
	}
	private: System::Void LangENToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		GlobalSettings::CurrentLang = Lang::EN;
		ApplySettings();
	}
	private: System::Void LangBYToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		GlobalSettings::CurrentLang = Lang::BY;
		ApplySettings();
	}

	// Смена темы
	private: System::Void WhiteToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		GlobalSettings::CurrentTheme = Theme::White;
		this->BackColor = GlobalSettings::GetTheme();
	}
	private: System::Void BlueToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		GlobalSettings::CurrentTheme = Theme::Blue;
		this->BackColor = GlobalSettings::GetTheme();
	}
	private: System::Void PurpleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		GlobalSettings::CurrentTheme = Theme::Purple;
		this->BackColor = GlobalSettings::GetTheme();
	}


	// Переключение форм
	private: System::Void ToRegisterBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ResetInputBox();

		PasswordConfLabel->Visible = true;
		PasswordConfInp->Visible = true;
		IsAdminBox->Visible = true;
		RegistrationBtn->Visible = true;
		BackToLogBtn->Visible = true;

		LogInBtn->Visible = false;
		ToRegisterBtn->Visible = false;

		ErrorInfo->Location = System::Drawing::Point(ErrorInfo->Location.X, ErrorInfo->Location.Y + 55);
		Header->Text = GlobalSettings::GetLang("RegistrationHeader");
	}

	private: System::Void BackToLogBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ResetInputBox();

		PasswordConfLabel->Visible = false;
		PasswordConfInp->Visible = false;
		IsAdminBox->Visible = false;
		RegistrationBtn->Visible = false;
		BackToLogBtn->Visible = false;

		LogInBtn->Visible = true;
		ToRegisterBtn->Visible = true;

		ErrorInfo->Location = System::Drawing::Point(ErrorInfo->Location.X, ErrorInfo->Location.Y - 55);
		Header->Text = GlobalSettings::GetLang("LogInHeader");
	}


// Настройка полей для ввода
	private: System::Void UsernameInp_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (UsernameInp->Text == GlobalSettings::GetLang("UsernameInp")) {
			UsernameInp->Text = "";
			UsernameInp->ForeColor = Color::Black;
		}
	}
	private: System::Void UsernameInp_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (UsernameInp->Text == "") {
			UsernameInp->Text = GlobalSettings::GetLang("UsernameInp");
			UsernameInp->ForeColor = Color::Gray;
		}
	}
	private: System::Void UsernameInp_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == ' ') {
			e->Handled = true;
		}
	}

	private: System::Void PasswordInp_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (PasswordInp->Text == GlobalSettings::GetLang("PasswordInp")) {
			PasswordInp->Text = "";
			PasswordInp->ForeColor = Color::Black;
		}
	}
	private: System::Void PasswordInp_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (PasswordInp->Text == "") {
			PasswordInp->Text = GlobalSettings::GetLang("PasswordInp");
			PasswordInp->ForeColor = Color::Gray;
		}
	}
	private: System::Void PasswordInp_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == ' ') {
			e->Handled = true;
		}
	}

	private: System::Void PasswordConfInp_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (PasswordConfInp->Text == GlobalSettings::GetLang("PasswordConfInp")) {
			PasswordConfInp->Text = "";
			PasswordConfInp->ForeColor = Color::Black;
		}
	}
	private: System::Void PasswordConfInp_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (PasswordConfInp->Text == "") {
			PasswordConfInp->Text = GlobalSettings::GetLang("PasswordConfInp");
			PasswordConfInp->ForeColor = Color::Gray;
		}
	}
	private: System::Void PasswordConfInp_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == ' ') {
			e->Handled = true;
		}
	}


	// Сброс полей ввода и ошибок
	void ResetInputBox() {
		UsernameInp->ForeColor = (UsernameInp->Text == GlobalSettings::GetLang("UsernameInp") ? Color::Gray : Color::Black);
		PasswordInp->ForeColor = (PasswordInp->Text == GlobalSettings::GetLang("PasswordInp") ? Color::Gray : Color::Black);
		PasswordConfInp->ForeColor = (PasswordConfInp->Text == GlobalSettings::GetLang("PasswordConfInp") ? Color::Gray : Color::Black);
		ErrorInfo->Text = "";
	}

	// Функция локализации LoginForm
	void ApplySettings() {
		//this->BackColor = GlobalSettings::GetTheme();

		// Заголовок
		Header->Text = (PasswordConfInp->Visible ? GlobalSettings::GetLang("RegistrationHeader") : GlobalSettings::GetLang("LogInHeader"));

		// Форма входа/регистрации
		UsernameLabel->Text = GlobalSettings::GetLang("UsernameLabel");
		UsernameInp->Text = (UsernameInp->Text != "" ? GlobalSettings::GetLang("UsernameInp") : "");
		PasswordLabel->Text = GlobalSettings::GetLang("PasswordLabel");
		PasswordInp->Text = (PasswordInp->Text != "" ? GlobalSettings::GetLang("PasswordInp") : "");
		PasswordConfLabel->Text = GlobalSettings::GetLang("PasswordConfLabel");
		PasswordConfInp->Text = (PasswordConfInp->Text != "" ? GlobalSettings::GetLang("PasswordConfInp") : "");
		LogInBtn->Text = GlobalSettings::GetLang("LogInBtn");
		ToRegisterBtn->Text = GlobalSettings::GetLang("ToRegisterBtn");
		IsAdminBox->Text = GlobalSettings::GetLang("IsAdminBox");
		RegistrationBtn->Text = GlobalSettings::GetLang("RegistrationBtn");
		BackToLogBtn->Text = GlobalSettings::GetLang("BackToLogBtn");

		// Меню взаимодействий 
		ViewToolStripMenuItem->Text = GlobalSettings::GetLang("ViewMenuItem");
		LanguageToolStripMenuItem->Text = GlobalSettings::GetLang("LanguageMenuItem");
		LangRUToolStripMenuItem->Text = GlobalSettings::GetLang("LangRUMenuItem");
		LangENToolStripMenuItem->Text = GlobalSettings::GetLang("LangENMenuItem");
		LangBYToolStripMenuItem->Text = GlobalSettings::GetLang("LangBYMenuItem");
		ThemeToolStripMenuItem->Text = GlobalSettings::GetLang("ThemeMenuItem");
		WhiteToolStripMenuItem->Text = GlobalSettings::GetLang("WhiteMenuItem");
		BlueToolStripMenuItem->Text = GlobalSettings::GetLang("BlueMenuItem");
		PurpleToolStripMenuItem->Text = GlobalSettings::GetLang("PurpleMenuItem");
		HelpToolStripMenuItem->Text = GlobalSettings::GetLang("HelpMenuItem");
	}
};
}
