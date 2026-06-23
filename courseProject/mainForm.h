#pragma once
#include "Utils.h"
#include "BinaryTree.h"

namespace courseProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ mainForm
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	private:
		BinaryTree* tree = new BinaryTree();
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

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
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




	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
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
			this->ErrorInfo = (gcnew System::Windows::Forms::Label());
			this->PrintCost = (gcnew System::Windows::Forms::TextBox());
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
			this->InpName->Location = System::Drawing::Point(495, 31);
			this->InpName->Name = L"InpName";
			this->InpName->Size = System::Drawing::Size(270, 22);
			this->InpName->TabIndex = 1;
			this->InpName->Text = L"¬ведите название:";
			this->InpName->Enter += gcnew System::EventHandler(this, &mainForm::InpName_Enter);
			this->InpName->Leave += gcnew System::EventHandler(this, &mainForm::InpName_Leave);
			// 
			// InpCost
			// 
			this->InpCost->ForeColor = System::Drawing::Color::Gray;
			this->InpCost->Location = System::Drawing::Point(495, 59);
			this->InpCost->Name = L"InpCost";
			this->InpCost->Size = System::Drawing::Size(270, 22);
			this->InpCost->TabIndex = 2;
			this->InpCost->Text = L"¬ведите стоимость:";
			this->InpCost->Enter += gcnew System::EventHandler(this, &mainForm::InpCost_Enter);
			this->InpCost->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &mainForm::InpCost_KeyPress);
			this->InpCost->Leave += gcnew System::EventHandler(this, &mainForm::InpCost_Leave);
			// 
			// AddNodeBtn
			// 
			this->AddNodeBtn->Location = System::Drawing::Point(495, 87);
			this->AddNodeBtn->Name = L"AddNodeBtn";
			this->AddNodeBtn->Size = System::Drawing::Size(132, 25);
			this->AddNodeBtn->TabIndex = 3;
			this->AddNodeBtn->Text = L"—оздать узел";
			this->AddNodeBtn->UseVisualStyleBackColor = true;
			this->AddNodeBtn->Click += gcnew System::EventHandler(this, &mainForm::AddNodeBtn_Click);
			// 
			// CreateTreeBtn
			// 
			this->CreateTreeBtn->Location = System::Drawing::Point(633, 87);
			this->CreateTreeBtn->Name = L"CreateTreeBtn";
			this->CreateTreeBtn->Size = System::Drawing::Size(132, 25);
			this->CreateTreeBtn->TabIndex = 4;
			this->CreateTreeBtn->Text = L"—оздать дерево";
			this->CreateTreeBtn->UseVisualStyleBackColor = true;
			this->CreateTreeBtn->Click += gcnew System::EventHandler(this, &mainForm::CreateTreeBtn_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->DeleteNodeBtn);
			this->groupBox1->Controls->Add(this->CalcSumBtn);
			this->groupBox1->Location = System::Drawing::Point(496, 178);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(269, 84);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"¬заимодействи€ с филиалом";
			// 
			// DeleteNodeBtn
			// 
			this->DeleteNodeBtn->ForeColor = System::Drawing::Color::Red;
			this->DeleteNodeBtn->Location = System::Drawing::Point(7, 51);
			this->DeleteNodeBtn->Name = L"DeleteNodeBtn";
			this->DeleteNodeBtn->Size = System::Drawing::Size(256, 25);
			this->DeleteNodeBtn->TabIndex = 1;
			this->DeleteNodeBtn->Text = L"”далить узел";
			this->DeleteNodeBtn->UseVisualStyleBackColor = true;
			this->DeleteNodeBtn->Click += gcnew System::EventHandler(this, &mainForm::DeleteNodeBtn_Click);
			// 
			// CalcSumBtn
			// 
			this->CalcSumBtn->Location = System::Drawing::Point(7, 22);
			this->CalcSumBtn->Name = L"CalcSumBtn";
			this->CalcSumBtn->Size = System::Drawing::Size(256, 25);
			this->CalcSumBtn->TabIndex = 0;
			this->CalcSumBtn->Text = L"¬ычислить стоимость";
			this->CalcSumBtn->UseVisualStyleBackColor = true;
			this->CalcSumBtn->Click += gcnew System::EventHandler(this, &mainForm::CalcSumBtn_Click);
			// 
			// RebuildTreeBtn
			// 
			this->RebuildTreeBtn->Location = System::Drawing::Point(503, 269);
			this->RebuildTreeBtn->Name = L"RebuildTreeBtn";
			this->RebuildTreeBtn->Size = System::Drawing::Size(256, 25);
			this->RebuildTreeBtn->TabIndex = 6;
			this->RebuildTreeBtn->Text = L"ѕерестроить дерево";
			this->RebuildTreeBtn->UseVisualStyleBackColor = true;
			this->RebuildTreeBtn->Click += gcnew System::EventHandler(this, &mainForm::RebuildTreeBtn_Click);
			// 
			// DeleteTreeBtn
			// 
			this->DeleteTreeBtn->ForeColor = System::Drawing::Color::Red;
			this->DeleteTreeBtn->Location = System::Drawing::Point(503, 298);
			this->DeleteTreeBtn->Name = L"DeleteTreeBtn";
			this->DeleteTreeBtn->Size = System::Drawing::Size(256, 25);
			this->DeleteTreeBtn->TabIndex = 7;
			this->DeleteTreeBtn->Text = L"”далить дерево";
			this->DeleteTreeBtn->UseVisualStyleBackColor = true;
			this->DeleteTreeBtn->Click += gcnew System::EventHandler(this, &mainForm::DeleteTreeBtn_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->tempToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(796, 28);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// tempToolStripMenuItem
			// 
			this->tempToolStripMenuItem->Name = L"tempToolStripMenuItem";
			this->tempToolStripMenuItem->Size = System::Drawing::Size(60, 24);
			this->tempToolStripMenuItem->Text = L"Temp";
			// 
			// ErrorInfo
			// 
			this->ErrorInfo->AutoSize = true;
			this->ErrorInfo->ForeColor = System::Drawing::Color::Red;
			this->ErrorInfo->Location = System::Drawing::Point(502, 122);
			this->ErrorInfo->Name = L"ErrorInfo";
			this->ErrorInfo->Size = System::Drawing::Size(0, 16);
			this->ErrorInfo->TabIndex = 9;
			// 
			// PrintCost
			// 
			this->PrintCost->ForeColor = System::Drawing::Color::Gray;
			this->PrintCost->Location = System::Drawing::Point(496, 150);
			this->PrintCost->Name = L"PrintCost";
			this->PrintCost->Size = System::Drawing::Size(270, 22);
			this->PrintCost->TabIndex = 10;
			this->PrintCost->Text = L"Cтоимость филиала";
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(796, 426);
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
		private: bool RebuildTree(BinaryTree* tree) {
			treeView1->Nodes->Clear();
			if (!tree->root) {
				return false;
			}

			TreeNode^ rootNode = gcnew TreeNode(ToSysString(tree->root->data_field.bankName));
			rootNode->Tag = tree->root->id;
			treeView1->Nodes->Add(rootNode);

			BuildTree(rootNode, tree->root->left);
			BuildTree(rootNode, tree->root->right);
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


	// ќбработчики
		private: System::Void AddNodeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			TreeNode^ selected = treeView1->SelectedNode;
			if (selected && InpName->Text != "¬ведите название:" && InpCost->Text != "¬ведите стоимость:") {
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
			if (!tree->root && InpName->Text != "¬ведите название:" && InpCost->Text != "¬ведите стоимость:") {
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


		// textBox ¬вода названи€
		private: System::Void InpName_Enter(System::Object^ sender, System::EventArgs^ e) {
			if (InpName->Text == "¬ведите название:") {
				InpName->Text = "";
				InpName->ForeColor = Color::Black;
			}
		}
		private: System::Void InpName_Leave(System::Object^ sender, System::EventArgs^ e) {
			if (InpName->Text == "") {
				InpName->Text = "¬ведите название:";
				InpName->ForeColor = Color::Gray;
			}
		}

		// textBox ¬вода стоимости
		private: System::Void InpCost_Enter(System::Object^ sender, System::EventArgs^ e) {
			if (InpCost->Text == "¬ведите стоимость:") {
				InpCost->Text = "";
				InpCost->ForeColor = Color::Black;
			}
		}
		private: System::Void InpCost_Leave(System::Object^ sender, System::EventArgs^ e) {
			if (InpCost->Text == "") {
				InpCost->Text = "¬ведите стоимость:";
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
