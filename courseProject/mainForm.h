#pragma once
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
			DataField data;
			data.bankName = "T-bank";
			data.cost = 1000000;
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
			this->SuspendLayout();
			// 
			// treeView1
			// 
			this->treeView1->Location = System::Drawing::Point(156, 63);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(383, 286);
			this->treeView1->TabIndex = 0;
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(963, 511);
			this->Controls->Add(this->treeView1);
			this->Name = L"mainForm";
			this->Text = L"mainForm";
			this->ResumeLayout(false);

		}
#pragma endregion
		private: bool RebuildTree(BinaryTree* tree) {
			if (!tree->root) {
				return false;
			}

			treeView1->Nodes->Clear();

			TreeNode^ rootNode = gcnew TreeNode(gcnew String(tree->root->data_field.bankName.c_str()));
			rootNode->Tag = tree->root->id;
			treeView1->Nodes->Add(rootNode);

			BuildTree(rootNode, tree->root);
			treeView1->ExpandAll();
			return true;
		}
			
		void BuildTree(TreeNode^ parentNode, My_TreeNode* node) {
			if (node == nullptr) {
				return;
			}

			TreeNode^ current = gcnew TreeNode(gcnew String(node->data_field.bankName.c_str()));
			current->Tag = node->id;
			parentNode->Nodes->Add(current);

			BuildTree(current, node->left);
			BuildTree(current, node->right);
		}


	};
}
