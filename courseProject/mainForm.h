#pragma once
#include "Utils.h"
#include "BinaryTree.h"
#include "UserManage.h"

namespace courseProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для mainForm
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	private:
		BinaryTree* tree = new BinaryTree();
		User* currentUser;

	private: System::Windows::Forms::ToolStripMenuItem^ SaveChangesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ RebuildTreeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ DeleteTreeToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ LogOutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ViewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ HelpToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ LanguageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ LangRUToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ LangENToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ LangBYToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ThemeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ WhiteToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ BlueToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ PurpleToolStripMenuItem;

	public:
		mainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			PrintCost->ReadOnly = true;
			PrintCost->BackColor = SystemColors::Window;

			DataField data;
			data.bankName = "T-bank";
			data.cost = 1;
			tree->create_tree(data);
			tree->add_node(0, data);
			tree->add_node(0, data);
			tree->add_node(1, data);
			RebuildTree(tree);
		}

		mainForm(User* user) {
			InitializeComponent();

			currentUser = user;
			GlobalSettings::CurrentLang = user->language;
			GlobalSettings::CurrentTheme = user->theme;
			ApplySettings();

			load_tree_file(user->id, tree);
			RebuildTree(tree);

			if (!user->isAdmin) {
				DeleteTreeBtn->Visible = false;
				DeleteNodeBtn->Visible = false;

				groupBox->Height -= 23;
				this->RebuildTreeBtn->Location = System::Drawing::Point(
					this->RebuildTreeBtn->Location.X, 
					this->RebuildTreeBtn->Location.Y - 25
				);
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~mainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TreeView^ TreeView;
	protected:

	private: System::Windows::Forms::TextBox^ InpName;
	private: System::Windows::Forms::TextBox^ InpCost;
	private: System::Windows::Forms::Button^ AddNodeBtn;
	private: System::Windows::Forms::Button^ CreateTreeBtn;
	private: System::Windows::Forms::GroupBox^ groupBox;



	private: System::Windows::Forms::Button^ DeleteNodeBtn;
	private: System::Windows::Forms::Button^ CalcSumBtn;
	private: System::Windows::Forms::Button^ RebuildTreeBtn;
	private: System::Windows::Forms::Button^ DeleteTreeBtn;



	private: System::Windows::Forms::MenuStrip^ menuStrip1;
private: System::Windows::Forms::ToolStripMenuItem^ MainToolStripMenuItem;

	private: System::Windows::Forms::Label^ ErrorInfo;
	private: System::Windows::Forms::TextBox^ PrintCost;
	private: System::Windows::Forms::Label^ NameLabel;
	private: System::Windows::Forms::Label^ CostLabel;






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
			this->TreeView = (gcnew System::Windows::Forms::TreeView());
			this->InpName = (gcnew System::Windows::Forms::TextBox());
			this->InpCost = (gcnew System::Windows::Forms::TextBox());
			this->AddNodeBtn = (gcnew System::Windows::Forms::Button());
			this->CreateTreeBtn = (gcnew System::Windows::Forms::Button());
			this->groupBox = (gcnew System::Windows::Forms::GroupBox());
			this->DeleteNodeBtn = (gcnew System::Windows::Forms::Button());
			this->CalcSumBtn = (gcnew System::Windows::Forms::Button());
			this->RebuildTreeBtn = (gcnew System::Windows::Forms::Button());
			this->DeleteTreeBtn = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->MainToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SaveChangesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RebuildTreeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DeleteTreeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LogOutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->PrintCost = (gcnew System::Windows::Forms::TextBox());
			this->NameLabel = (gcnew System::Windows::Forms::Label());
			this->CostLabel = (gcnew System::Windows::Forms::Label());
			this->groupBox->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// TreeView
			// 
			this->TreeView->Location = System::Drawing::Point(12, 31);
			this->TreeView->Name = L"TreeView";
			this->TreeView->Size = System::Drawing::Size(477, 376);
			this->TreeView->TabIndex = 0;
			// 
			// InpName
			// 
			this->InpName->BackColor = System::Drawing::SystemColors::Window;
			this->InpName->ForeColor = System::Drawing::Color::Gray;
			this->InpName->Location = System::Drawing::Point(495, 53);
			this->InpName->Name = L"InpName";
			this->InpName->Size = System::Drawing::Size(270, 22);
			this->InpName->TabIndex = 1;
			this->InpName->Text = L"Введите название:";
			this->InpName->Enter += gcnew System::EventHandler(this, &mainForm::InpName_Enter);
			this->InpName->Leave += gcnew System::EventHandler(this, &mainForm::InpName_Leave);
			// 
			// InpCost
			// 
			this->InpCost->ForeColor = System::Drawing::Color::Gray;
			this->InpCost->Location = System::Drawing::Point(495, 97);
			this->InpCost->Name = L"InpCost";
			this->InpCost->Size = System::Drawing::Size(270, 22);
			this->InpCost->TabIndex = 2;
			this->InpCost->Text = L"Введите стоимость:";
			this->InpCost->Enter += gcnew System::EventHandler(this, &mainForm::InpCost_Enter);
			this->InpCost->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &mainForm::InpCost_KeyPress);
			this->InpCost->Leave += gcnew System::EventHandler(this, &mainForm::InpCost_Leave);
			// 
			// AddNodeBtn
			// 
			this->AddNodeBtn->Location = System::Drawing::Point(495, 125);
			this->AddNodeBtn->Name = L"AddNodeBtn";
			this->AddNodeBtn->Size = System::Drawing::Size(132, 25);
			this->AddNodeBtn->TabIndex = 3;
			this->AddNodeBtn->Text = L"Добавить узел";
			this->AddNodeBtn->UseVisualStyleBackColor = true;
			this->AddNodeBtn->Click += gcnew System::EventHandler(this, &mainForm::AddNodeBtn_Click);
			// 
			// CreateTreeBtn
			// 
			this->CreateTreeBtn->Location = System::Drawing::Point(633, 125);
			this->CreateTreeBtn->Name = L"CreateTreeBtn";
			this->CreateTreeBtn->Size = System::Drawing::Size(132, 25);
			this->CreateTreeBtn->TabIndex = 4;
			this->CreateTreeBtn->Text = L"Создать дерево";
			this->CreateTreeBtn->UseVisualStyleBackColor = true;
			this->CreateTreeBtn->Click += gcnew System::EventHandler(this, &mainForm::CreateTreeBtn_Click);
			// 
			// groupBox
			// 
			this->groupBox->Controls->Add(this->DeleteNodeBtn);
			this->groupBox->Controls->Add(this->CalcSumBtn);
			this->groupBox->Location = System::Drawing::Point(496, 217);
			this->groupBox->Name = L"groupBox";
			this->groupBox->Size = System::Drawing::Size(269, 84);
			this->groupBox->TabIndex = 5;
			this->groupBox->TabStop = false;
			this->groupBox->Text = L"Взаимодействия с филиалом";
			// 
			// DeleteNodeBtn
			// 
			this->DeleteNodeBtn->ForeColor = System::Drawing::Color::Red;
			this->DeleteNodeBtn->Location = System::Drawing::Point(7, 51);
			this->DeleteNodeBtn->Name = L"DeleteNodeBtn";
			this->DeleteNodeBtn->Size = System::Drawing::Size(256, 25);
			this->DeleteNodeBtn->TabIndex = 1;
			this->DeleteNodeBtn->Text = L"Удалить узел";
			this->DeleteNodeBtn->UseVisualStyleBackColor = true;
			this->DeleteNodeBtn->Click += gcnew System::EventHandler(this, &mainForm::DeleteNodeBtn_Click);
			// 
			// CalcSumBtn
			// 
			this->CalcSumBtn->Location = System::Drawing::Point(7, 22);
			this->CalcSumBtn->Name = L"CalcSumBtn";
			this->CalcSumBtn->Size = System::Drawing::Size(256, 25);
			this->CalcSumBtn->TabIndex = 0;
			this->CalcSumBtn->Text = L"Вычислить стоимость";
			this->CalcSumBtn->UseVisualStyleBackColor = true;
			this->CalcSumBtn->Click += gcnew System::EventHandler(this, &mainForm::CalcSumBtn_Click);
			// 
			// RebuildTreeBtn
			// 
			this->RebuildTreeBtn->Location = System::Drawing::Point(503, 308);
			this->RebuildTreeBtn->Name = L"RebuildTreeBtn";
			this->RebuildTreeBtn->Size = System::Drawing::Size(256, 25);
			this->RebuildTreeBtn->TabIndex = 6;
			this->RebuildTreeBtn->Text = L"Перестроить дерево";
			this->RebuildTreeBtn->UseVisualStyleBackColor = true;
			this->RebuildTreeBtn->Click += gcnew System::EventHandler(this, &mainForm::RebuildTreeBtn_Click);
			// 
			// DeleteTreeBtn
			// 
			this->DeleteTreeBtn->ForeColor = System::Drawing::Color::Red;
			this->DeleteTreeBtn->Location = System::Drawing::Point(503, 337);
			this->DeleteTreeBtn->Name = L"DeleteTreeBtn";
			this->DeleteTreeBtn->Size = System::Drawing::Size(256, 25);
			this->DeleteTreeBtn->TabIndex = 7;
			this->DeleteTreeBtn->Text = L"Удалить дерево";
			this->DeleteTreeBtn->UseVisualStyleBackColor = true;
			this->DeleteTreeBtn->Click += gcnew System::EventHandler(this, &mainForm::DeleteTreeBtn_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->MainToolStripMenuItem,
					this->ViewToolStripMenuItem, this->HelpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(796, 28);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// MainToolStripMenuItem
			// 
			this->MainToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->SaveChangesToolStripMenuItem,
					this->RebuildTreeToolStripMenuItem, this->DeleteTreeToolStripMenuItem, this->LogOutToolStripMenuItem
			});
			this->MainToolStripMenuItem->Name = L"MainToolStripMenuItem";
			this->MainToolStripMenuItem->Size = System::Drawing::Size(79, 24);
			this->MainToolStripMenuItem->Text = L"Главная";
			// 
			// SaveChangesToolStripMenuItem
			// 
			this->SaveChangesToolStripMenuItem->Name = L"SaveChangesToolStripMenuItem";
			this->SaveChangesToolStripMenuItem->Size = System::Drawing::Size(248, 26);
			this->SaveChangesToolStripMenuItem->Text = L"Сохранить изменения";
			this->SaveChangesToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainForm::SaveChangesToolStripMenuItem_Click);
			// 
			// RebuildTreeToolStripMenuItem
			// 
			this->RebuildTreeToolStripMenuItem->Name = L"RebuildTreeToolStripMenuItem";
			this->RebuildTreeToolStripMenuItem->Size = System::Drawing::Size(248, 26);
			this->RebuildTreeToolStripMenuItem->Text = L"Перестроить дерево";
			this->RebuildTreeToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainForm::RebuildTreeToolStripMenuItem_Click);
			// 
			// DeleteTreeToolStripMenuItem
			// 
			this->DeleteTreeToolStripMenuItem->Name = L"DeleteTreeToolStripMenuItem";
			this->DeleteTreeToolStripMenuItem->Size = System::Drawing::Size(248, 26);
			this->DeleteTreeToolStripMenuItem->Text = L"Удалить дерево";
			this->DeleteTreeToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainForm::DeleteTreeToolStripMenuItem_Click);
			// 
			// LogOutToolStripMenuItem
			// 
			this->LogOutToolStripMenuItem->Name = L"LogOutToolStripMenuItem";
			this->LogOutToolStripMenuItem->Size = System::Drawing::Size(248, 26);
			this->LogOutToolStripMenuItem->Text = L"Выйти из системы";
			this->LogOutToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainForm::LogOutToolStripMenuItem_Click);
			// 
			// ViewToolStripMenuItem
			// 
			this->ViewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->LanguageToolStripMenuItem,
					this->ThemeToolStripMenuItem
			});
			this->ViewToolStripMenuItem->Name = L"ViewToolStripMenuItem";
			this->ViewToolStripMenuItem->Size = System::Drawing::Size(49, 24);
			this->ViewToolStripMenuItem->Text = L"Вид";
			// 
			// LanguageToolStripMenuItem
			// 
			this->LanguageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->LangRUToolStripMenuItem,
					this->LangENToolStripMenuItem, this->LangBYToolStripMenuItem
			});
			this->LanguageToolStripMenuItem->Name = L"LanguageToolStripMenuItem";
			this->LanguageToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->LanguageToolStripMenuItem->Text = L"Язык";
			// 
			// LangRUToolStripMenuItem
			// 
			this->LangRUToolStripMenuItem->Name = L"LangRUToolStripMenuItem";
			this->LangRUToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->LangRUToolStripMenuItem->Text = L"Русский";
			this->LangRUToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainForm::LangRUToolStripMenuItem_Click);
			// 
			// LangENToolStripMenuItem
			// 
			this->LangENToolStripMenuItem->Name = L"LangENToolStripMenuItem";
			this->LangENToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->LangENToolStripMenuItem->Text = L"Английский";
			this->LangENToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainForm::LangENToolStripMenuItem_Click);
			// 
			// LangBYToolStripMenuItem
			// 
			this->LangBYToolStripMenuItem->Name = L"LangBYToolStripMenuItem";
			this->LangBYToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->LangBYToolStripMenuItem->Text = L"Белорусский";
			this->LangBYToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainForm::LangBYToolStripMenuItem_Click);
			// 
			// ThemeToolStripMenuItem
			// 
			this->ThemeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->WhiteToolStripMenuItem,
					this->BlueToolStripMenuItem, this->PurpleToolStripMenuItem
			});
			this->ThemeToolStripMenuItem->Name = L"ThemeToolStripMenuItem";
			this->ThemeToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->ThemeToolStripMenuItem->Text = L"Тема";
			// 
			// WhiteToolStripMenuItem
			// 
			this->WhiteToolStripMenuItem->Name = L"WhiteToolStripMenuItem";
			this->WhiteToolStripMenuItem->Size = System::Drawing::Size(176, 26);
			this->WhiteToolStripMenuItem->Text = L"Белая";
			// 
			// BlueToolStripMenuItem
			// 
			this->BlueToolStripMenuItem->Name = L"BlueToolStripMenuItem";
			this->BlueToolStripMenuItem->Size = System::Drawing::Size(176, 26);
			this->BlueToolStripMenuItem->Text = L"Синяя";
			// 
			// PurpleToolStripMenuItem
			// 
			this->PurpleToolStripMenuItem->Name = L"PurpleToolStripMenuItem";
			this->PurpleToolStripMenuItem->Size = System::Drawing::Size(176, 26);
			this->PurpleToolStripMenuItem->Text = L"Фиолетовая";
			// 
			// HelpToolStripMenuItem
			// 
			this->HelpToolStripMenuItem->Name = L"HelpToolStripMenuItem";
			this->HelpToolStripMenuItem->Size = System::Drawing::Size(81, 24);
			this->HelpToolStripMenuItem->Text = L"Справка";
			// 
			// ErrorInfo
			// 
			this->ErrorInfo->AutoSize = true;
			this->ErrorInfo->ForeColor = System::Drawing::Color::Red;
			this->ErrorInfo->Location = System::Drawing::Point(502, 161);
			this->ErrorInfo->Name = L"ErrorInfo";
			this->ErrorInfo->Size = System::Drawing::Size(0, 16);
			this->ErrorInfo->TabIndex = 9;
			// 
			// PrintCost
			// 
			this->PrintCost->ForeColor = System::Drawing::Color::Gray;
			this->PrintCost->Location = System::Drawing::Point(496, 189);
			this->PrintCost->Name = L"PrintCost";
			this->PrintCost->Size = System::Drawing::Size(270, 22);
			this->PrintCost->TabIndex = 10;
			this->PrintCost->Text = L"Cтоимость филиала";
			// 
			// NameLabel
			// 
			this->NameLabel->AutoSize = true;
			this->NameLabel->Location = System::Drawing::Point(495, 36);
			this->NameLabel->Name = L"NameLabel";
			this->NameLabel->Size = System::Drawing::Size(76, 16);
			this->NameLabel->TabIndex = 11;
			this->NameLabel->Text = L"Название:";
			// 
			// CostLabel
			// 
			this->CostLabel->AutoSize = true;
			this->CostLabel->Location = System::Drawing::Point(495, 81);
			this->CostLabel->Name = L"CostLabel";
			this->CostLabel->Size = System::Drawing::Size(80, 16);
			this->CostLabel->TabIndex = 12;
			this->CostLabel->Text = L"Стоимость:";
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(796, 426);
			this->Controls->Add(this->CostLabel);
			this->Controls->Add(this->NameLabel);
			this->Controls->Add(this->PrintCost);
			this->Controls->Add(this->ErrorInfo);
			this->Controls->Add(this->DeleteTreeBtn);
			this->Controls->Add(this->RebuildTreeBtn);
			this->Controls->Add(this->groupBox);
			this->Controls->Add(this->CreateTreeBtn);
			this->Controls->Add(this->AddNodeBtn);
			this->Controls->Add(this->InpCost);
			this->Controls->Add(this->InpName);
			this->Controls->Add(this->TreeView);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"mainForm";
			this->Text = L"mainForm";
			this->groupBox->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
// Построение дерева
	private: bool RebuildTree(BinaryTree* tree) {
		TreeView->Nodes->Clear();
		My_TreeNode* root = tree->get_root();
		if (!root) {
			return false;
		}

		TreeNode^ rootNode = gcnew TreeNode(ToSysString(root->data_field.bankName));
		rootNode->Tag = root->id;
		TreeView->Nodes->Add(rootNode);

		BuildTree(rootNode, root->left);
		BuildTree(rootNode, root->right);
		TreeView->ExpandAll();
		return true;
	}
			
	void BuildTree(TreeNode^ parentNode, My_TreeNode* node) {
		if (node == nullptr) {
			return;
		}

		TreeNode^ current = gcnew TreeNode(ToSysString(node->data_field.bankName));
		current->Tag = node->id;
		parentNode->Nodes->Add(current);

		BuildTree(current, node->left);
		BuildTree(current, node->right);
	}



// Обработчики
	private: System::Void AddNodeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ResetInputBox();

		TreeNode^ selected = TreeView->SelectedNode;
		if (selected 
			&& InpName->Text != GlobalSettings::GetLang("InpName") 
			&& InpCost->Text != GlobalSettings::GetLang("InpCost")) 
		{
			DataField data;
			data.bankName = ToStdString(InpName->Text);
			data.cost = Convert::ToInt32(InpCost->Text);

			tree->add_node((size_t)selected->Tag, data);
			RebuildTree(tree);
		}
		else if (!selected) {
			ErrorInfo->Text = GlobalSettings::GetLang("SelectionError");
		}
		else {
			InpName->ForeColor = (InpName->Text == GlobalSettings::GetLang("InpName") ? Color::Red : InpName->ForeColor);
			InpCost->ForeColor = (InpCost->Text == GlobalSettings::GetLang("InpCost") ? Color::Red : InpCost->ForeColor);
			ErrorInfo->Text = GlobalSettings::GetLang("EmptyFieldsError");
		}
	}

	private: System::Void DeleteNodeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ResetInputBox();

		TreeNode^ selected = TreeView->SelectedNode;
		if (selected) {
			tree->delete_by_id((size_t)selected->Tag);
			RebuildTree(tree);
		}
		else {
			ErrorInfo->Text = GlobalSettings::GetLang("SelectionError");
		}
	}

	private: System::Void CreateTreeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ResetInputBox();

		if (!tree->get_root() 
			&& InpName->Text != GlobalSettings::GetLang("InpName") 
			&& InpCost->Text != GlobalSettings::GetLang("InpCost")) 
		{
			DataField data;
			data.bankName = ToStdString(InpName->Text);
			data.cost = Convert::ToInt32(InpCost->Text);

			tree->create_tree(data);
			RebuildTree(tree);
		}
		else if (tree->get_root()) {
			ErrorInfo->Text = GlobalSettings::GetLang("ExistingTreeError");
		}
		else {
			InpName->ForeColor = (InpName->Text == GlobalSettings::GetLang("InpName") ? Color::Red : InpName->ForeColor);
			InpCost->ForeColor = (InpCost->Text == GlobalSettings::GetLang("InpCost") ? Color::Red : InpCost->ForeColor);
			ErrorInfo->Text = GlobalSettings::GetLang("EmptyFieldsError");
		}
	}

	private: System::Void DeleteTreeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ResetInputBox();
		tree->delete_tree();
		RebuildTree(tree);
	}

	private: System::Void RebuildTreeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ResetInputBox();
		RebuildTree(tree);
	}

	private: System::Void CalcSumBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ResetInputBox();

		TreeNode^ selected = TreeView->SelectedNode;
		if (selected) {
			PrintCost->ForeColor = Color::Black;
			PrintCost->Text = Convert::ToString(tree->calc_sum((size_t)selected->Tag));
		}
		else {
			ErrorInfo->Text = GlobalSettings::GetLang("SelectionError");
		}
	}



// MenuStrip
	// Главная
	private: System::Void SaveChangesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		update_tree_file(currentUser->id, tree);
	}
	private: System::Void RebuildTreeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		RebuildTree(tree);
	}
	private: System::Void DeleteTreeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		tree->delete_tree();
		RebuildTree(tree);
	}
	private: System::Void LogOutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		update_tree_file(currentUser->id, tree);
		delete currentUser;
		this->DialogResult = System::Windows::Forms::DialogResult::Retry;
		this->Close();
	}

	// Вид - Язык
	private: System::Void LangRUToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		GlobalSettings::CurrentLang = Lang::RU;
		ApplySettings();
		UpdateUserSettings(currentUser->id);
	}
	private: System::Void LangENToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		GlobalSettings::CurrentLang = Lang::EN;
		ApplySettings();
		UpdateUserSettings(currentUser->id);
	}
	private: System::Void LangBYToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		GlobalSettings::CurrentLang = Lang::BY;
		ApplySettings();
		UpdateUserSettings(currentUser->id);
	}



	// textBox Ввода названия
	private: System::Void InpName_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (InpName->Text == GlobalSettings::GetLang("InpName")) {
			InpName->Text = "";
			InpName->ForeColor = Color::Black;
		}
	}
	private: System::Void InpName_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (InpName->Text == "") {
			InpName->Text = GlobalSettings::GetLang("InpName");
			InpName->ForeColor = Color::Gray;
		}
	}

	// textBox Ввода стоимости
	private: System::Void InpCost_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (InpCost->Text == GlobalSettings::GetLang("InpCost")) {
			InpCost->Text = "";
			InpCost->ForeColor = Color::Black;
		}
	}
	private: System::Void InpCost_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (InpCost->Text == "") {
			InpCost->Text = GlobalSettings::GetLang("InpCost");
			InpCost->ForeColor = Color::Gray;
		}
	}
	private: System::Void InpCost_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && !Char::IsControl(e->KeyChar) && e->KeyChar != '-') {
			e->Handled = true;
		}
	}


	// Сброс полей ввода и ошибок
	void ResetInputBox() {
		InpName->ForeColor = (InpName->Text == GlobalSettings::GetLang("InpName") ? Color::Gray : Color::Black);
		InpCost->ForeColor = (InpCost->Text == GlobalSettings::GetLang("InpCost") ? Color::Gray : Color::Black);
		ErrorInfo->Text = "";
	}

	// Функция локализации mainForm
	void ApplySettings() {
		// Создание Узлов
		NameLabel->Text = GlobalSettings::GetLang("NameLabel");
		InpName->Text = (InpName->Text != "" ? GlobalSettings::GetLang("InpName") : "");
		CostLabel->Text = GlobalSettings::GetLang("CostLabel");
		InpCost->Text = (InpCost->Text != "" ? GlobalSettings::GetLang("InpCost") : "");
		AddNodeBtn->Text = GlobalSettings::GetLang("AddNodeBtn");
		CreateTreeBtn->Text = GlobalSettings::GetLang("CreateTreeBtn");

		// Взаимодействия с деревом
		PrintCost->Text = GlobalSettings::GetLang("PrintCost");
		groupBox->Text = GlobalSettings::GetLang("groupBox");
		CalcSumBtn->Text = GlobalSettings::GetLang("CalcSumBtn");
		DeleteNodeBtn->Text = GlobalSettings::GetLang("DeleteNodeBtn");
		RebuildTreeBtn->Text = GlobalSettings::GetLang("RebuildTreeBtn");
		DeleteTreeBtn->Text = GlobalSettings::GetLang("DeleteTreeBtn");

		// Меню взаимодействий 
		MainToolStripMenuItem->Text = GlobalSettings::GetLang("MainMenuItem");
		SaveChangesToolStripMenuItem->Text = GlobalSettings::GetLang("SaveChangesMenuItem");
		RebuildTreeToolStripMenuItem->Text = GlobalSettings::GetLang("RebuildTreeMenuItem");
		DeleteTreeToolStripMenuItem->Text = GlobalSettings::GetLang("DeleteTreeMenuItem");
		LogOutToolStripMenuItem->Text = GlobalSettings::GetLang("LogOutMenuItem");
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

		// Дополнительно
		this->Text = GlobalSettings::GetLang("WelcomeStr") + ToSysString(currentUser->username);
		this->Text += (currentUser->isAdmin ? "" : GlobalSettings::GetLang("SelectedMode"));
	}

};
}
