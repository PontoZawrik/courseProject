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

	private: System::Windows::Forms::ToolStripMenuItem^ SaveChangesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ RebuildTreeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ DeleteTreeToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ LogOutToolStripMenuItem;




	private: System::Windows::Forms::ToolStripMenuItem^ видToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ справкаToolStripMenuItem;
		   User* currentUser;
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
			this->Text = "Добро пожаловать " + ToSysString(user->username);

			load_tree_file(user->id, tree);
			RebuildTree(tree);

			if (!user->isAdmin) {
				this->Text += " (Гостевой режим)";
				DeleteTreeBtn->Visible = false;
				DeleteNodeBtn->Visible = false;

				groupBox1->Height -= 23;
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
	private: System::Windows::Forms::TreeView^ treeView1;
	private: System::Windows::Forms::TextBox^ InpName;
	private: System::Windows::Forms::TextBox^ InpCost;
	private: System::Windows::Forms::Button^ AddNodeBtn;
	private: System::Windows::Forms::Button^ CreateTreeBtn;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ DeleteNodeBtn;
	private: System::Windows::Forms::Button^ CalcSumBtn;
	private: System::Windows::Forms::Button^ RebuildTreeBtn;
	private: System::Windows::Forms::Button^ DeleteTreeBtn;





	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ tempToolStripMenuItem;
	private: System::Windows::Forms::Label^ ErrorInfo;
	private: System::Windows::Forms::TextBox^ PrintCost;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;




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
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->InpName = (gcnew System::Windows::Forms::TextBox());
			this->InpCost = (gcnew System::Windows::Forms::TextBox());
			this->AddNodeBtn = (gcnew System::Windows::Forms::Button());
			this->CreateTreeBtn = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->DeleteNodeBtn = (gcnew System::Windows::Forms::Button());
			this->CalcSumBtn = (gcnew System::Windows::Forms::Button());
			this->RebuildTreeBtn = (gcnew System::Windows::Forms::Button());
			this->DeleteTreeBtn = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->tempToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SaveChangesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RebuildTreeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DeleteTreeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LogOutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->видToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ErrorInfo = (gcnew System::Windows::Forms::Label());
			this->PrintCost = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// treeView1
			// 
			this->treeView1->Location = System::Drawing::Point(12, 31);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(477, 376);
			this->treeView1->TabIndex = 0;
			// 
			// InpName
			// 
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
			this->AddNodeBtn->Text = L"Создать узел";
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
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->DeleteNodeBtn);
			this->groupBox1->Controls->Add(this->CalcSumBtn);
			this->groupBox1->Location = System::Drawing::Point(496, 217);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(269, 84);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Взаимодействия с филиалом";
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
				this->tempToolStripMenuItem,
					this->видToolStripMenuItem, this->справкаToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(796, 28);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// tempToolStripMenuItem
			// 
			this->tempToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->SaveChangesToolStripMenuItem,
					this->RebuildTreeToolStripMenuItem, this->DeleteTreeToolStripMenuItem, this->LogOutToolStripMenuItem
			});
			this->tempToolStripMenuItem->Name = L"tempToolStripMenuItem";
			this->tempToolStripMenuItem->Size = System::Drawing::Size(79, 24);
			this->tempToolStripMenuItem->Text = L"Главная";
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
			// видToolStripMenuItem
			// 
			this->видToolStripMenuItem->Name = L"видToolStripMenuItem";
			this->видToolStripMenuItem->Size = System::Drawing::Size(49, 24);
			this->видToolStripMenuItem->Text = L"Вид";
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(81, 24);
			this->справкаToolStripMenuItem->Text = L"Справка";
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
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(495, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 16);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Название:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(495, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 16);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Стоимость:";
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(796, 426);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->PrintCost);
			this->Controls->Add(this->ErrorInfo);
			this->Controls->Add(this->DeleteTreeBtn);
			this->Controls->Add(this->RebuildTreeBtn);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->CreateTreeBtn);
			this->Controls->Add(this->AddNodeBtn);
			this->Controls->Add(this->InpCost);
			this->Controls->Add(this->InpName);
			this->Controls->Add(this->treeView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"mainForm";
			this->Text = L"mainForm";
			this->groupBox1->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
// Построение дерева
	private: bool RebuildTree(BinaryTree* tree) {
		treeView1->Nodes->Clear();
		My_TreeNode* root = tree->get_root();
		if (!root) {
			return false;
		}

		TreeNode^ rootNode = gcnew TreeNode(ToSysString(root->data_field.bankName));
		rootNode->Tag = root->id;
		treeView1->Nodes->Add(rootNode);

		BuildTree(rootNode, root->left);
		BuildTree(rootNode, root->right);
		treeView1->ExpandAll();
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
		TreeNode^ selected = treeView1->SelectedNode;
		if (selected && InpName->Text != "Введите название:" && InpCost->Text != "Введите стоимость:") {
			DataField data;
			data.bankName = ToStdString(InpName->Text);
			data.cost = Convert::ToInt32(InpCost->Text);

			tree->add_node((size_t)selected->Tag, data);
			RebuildTree(tree);
		}
	}

	private: System::Void DeleteNodeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		TreeNode^ selected = treeView1->SelectedNode;
		if (selected) {
			tree->delete_by_id((size_t)selected->Tag);
			RebuildTree(tree);
		}
	}

	private: System::Void CreateTreeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!tree->get_root() && InpName->Text != "Введите название:" && InpCost->Text != "Введите стоимость:") {
			DataField data;
			data.bankName = ToStdString(InpName->Text);
			data.cost = Convert::ToInt32(InpCost->Text);

			tree->create_tree(data);
			RebuildTree(tree);
		}
	}

	private: System::Void DeleteTreeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		tree->delete_tree();
		RebuildTree(tree);
	}

	private: System::Void RebuildTreeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		RebuildTree(tree);
	}

	private: System::Void CalcSumBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		TreeNode^ selected = treeView1->SelectedNode;
		if (selected) {
			PrintCost->ForeColor = Color::Black;
			PrintCost->Text = Convert::ToString(tree->calc_sum((size_t)selected->Tag));
		}
	}



	// MenuStrip
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
		this->DialogResult = System::Windows::Forms::DialogResult::Retry;
		this->Close();
	}



	// textBox Ввода названия
	private: System::Void InpName_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (InpName->Text == "Введите название:") {
			InpName->Text = "";
			InpName->ForeColor = Color::Black;
		}
	}
	private: System::Void InpName_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (InpName->Text == "") {
			InpName->Text = "Введите название:";
			InpName->ForeColor = Color::Gray;
		}
	}

	// textBox Ввода стоимости
	private: System::Void InpCost_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (InpCost->Text == "Введите стоимость:") {
			InpCost->Text = "";
			InpCost->ForeColor = Color::Black;
		}
	}
	private: System::Void InpCost_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (InpCost->Text == "") {
			InpCost->Text = "Введите стоимость:";
			InpCost->ForeColor = Color::Gray;
		}
	}
	private: System::Void InpCost_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && !Char::IsControl(e->KeyChar) && e->KeyChar != '-') {
			e->Handled = true;
		}
	}

};
}
