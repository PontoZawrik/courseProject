#pragma once
#include <iostream>
#include <string>
using std::string;


struct DataField {
	string bankName = "NoName";
	long int cost = -1;
};

struct My_TreeNode {
	DataField data_field;
	size_t id = 0;
	My_TreeNode* left = nullptr;
	My_TreeNode* right = nullptr;
};

class BinaryTree {
private:
	size_t global_id = 0;

	My_TreeNode* find_el(My_TreeNode*, size_t);
	My_TreeNode* find_parent(My_TreeNode*, size_t);
	void delete_node(My_TreeNode*);
	long int calc_sum(My_TreeNode*);


public:
	My_TreeNode* root = nullptr;

	BinaryTree();
	BinaryTree(DataField);

	My_TreeNode* find_el(size_t);
	My_TreeNode* find_parent(size_t);
	bool create_tree(DataField);
	bool add_node(size_t, DataField);
	void delete_by_id(size_t);
	void delete_tree();
	long int calc_sum(size_t);
};




//
//void delete_branches(BinaryTree* tree) {
//	delete_tree(tree->left);
//	delete_tree(tree->right);
//	tree->left = nullptr;
//	tree->right = nullptr;
//}
//
//BinaryTree* find_the_knot_tree(string name_delete, BinaryTree* tree) {
//	if (tree != nullptr) {
//		if (tree->data_field.name == name_delete) {
//			return tree;
//		}
//		else {
//			if (name_delete < (tree->data_field).name) {
//				return find_the_knot_tree(name_delete, tree->left);
//			}
//			else {
//				return find_the_knot_tree(name_delete, tree->right);
//			}
//		}
//	}
//	return nullptr;
//}
//
//BinaryTree* copy_tree(BinaryTree* tree, BinaryTree* find_element_copy) {
//	if (find_element_copy != nullptr) {
//		tree = add_node(find_element_copy->data_field, tree);
//		tree = copy_tree(tree, find_element_copy->left);
//		tree = copy_tree(tree, find_element_copy->right);
//	}
//	return tree;
//}
//
//BinaryTree* subfunction_delete_element_tree(string name_delete, BinaryTree* new_tree, BinaryTree* old_tree) {
//	if (old_tree != nullptr) {
//		if (old_tree->data_field.name != name_delete) {
//			new_tree = add_node(old_tree->data_field, new_tree);
//		}
//		new_tree = subfunction_delete_element_tree(name_delete, new_tree, old_tree->left);
//		new_tree = subfunction_delete_element_tree(name_delete, new_tree, old_tree->right);
//	}
//	return new_tree;
//}
//
//BinaryTree* delete_elem_tree(string name_delete, BinaryTree* tree) {
//	BinaryTree* tmp_tree = nullptr;
//	tree = subfunction_delete_element_tree(name_delete, tmp_tree, tree);
//	delete_tree(tmp_tree);
//	delete tmp_tree;
//	return tree;
//}
//
//BinaryTree* find_parent_tree(BinaryTree* element_tree, BinaryTree* tree) {
//	if (tree != nullptr && tree != element_tree) {
//		if (tree->left == element_tree || tree->right == element_tree) {
//			return tree;
//		}
//		else {
//			if ((element_tree->data_field).name < (tree->data_field).name)
//				return find_parent_tree(element_tree, tree->left);
//			else
//				return find_parent_tree(element_tree, tree->right);
//		}
//	}
//	return tree;
//}
//
//// Сомнительно...
//BinaryTree* delete_element_tree2(string name_delete, BinaryTree* tree) {
//	BinaryTree* find_element_tree = find_the_knot_tree(name_delete, tree);
//	BinaryTree* parent_element = find_parent_tree(find_element_tree, tree);
//	BinaryTree* tmp_tree = nullptr;
//
//	tmp_tree = copy_tree(tmp_tree, find_element_tree->left);
//	tmp_tree = copy_tree(tmp_tree, find_element_tree->right);
//
//	if (tree == find_element_tree) {
//		delete_branches(find_element_tree);
//		tree = nullptr;
//	}
//	else {
//		if (parent_element->left == find_element_tree) {
//			delete_branches(find_element_tree);
//			parent_element->left = nullptr;
//		}
//		else {
//			if (parent_element->right == find_element_tree) {
//				delete_branches(find_element_tree);
//				parent_element->right = nullptr;
//			}
//		}
//	}
//	tree = copy_tree(tree, tmp_tree);
//	return tree;
//}
//
//int main() {
//	system("chcp 65001");
//
//	BinaryTree* tree = nullptr;
//	DataField data_field;
//	string name_find;
//	int menu = 0;
//	bool exit_menu = true;
//
//	while (exit_menu) {
//		cout << "\n1-To add in tree element\n2-To add in tree element random value\n"
//			<< "3-To show all tree\n4-To find the knot tree by the name\n"
//			<< "5-To delete the knot tree by thr name\n0-to exit\nEnter number: ";
//		cin >> menu;
//
//		switch (menu) {
//		case 1: {
//			cout << "Enter element tree: ";
//			data_field.inpute();
//			tree = add_node(data_field, tree);
//			break;
//		}
//		case 2: {
//			cout << "Random element tree: - OK.\n";
//			data_field.set_random();
//			tree = add_node(data_field, tree);
//			break;
//		}
//		case 3: {
//			cout << "Show all tree:\n";
//			treeprint(tree);
//			break;
//		}
//		case 4: {
//			cout << "Enter Name: ";
//			cin >> name_find;
//			treeprint_byname(name_find, find_the_knot_tree(name_find, tree));
//			break;
//		}
//		case 5: {
//			cout << "Enter Name: ";
//			cin >> name_find;
//			tree = delete_element_tree2(name_find, tree);
//			break;
//		}
//		case 0: {
//			exit_menu = false;
//			break;
//		}
//		default: break;
//		}
//	}
//	delete_tree(tree);
//	system("pause");
//}