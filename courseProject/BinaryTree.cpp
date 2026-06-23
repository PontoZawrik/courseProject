#include "BinaryTree.h"

// Конструкторы
BinaryTree::BinaryTree() {}
BinaryTree::BinaryTree(DataField data) {
	create_tree(data);
}


// Поиск
My_TreeNode* BinaryTree::find_el(My_TreeNode* node, size_t id) {
	if (node) {
		if (node->id == id) {
			return node;
		}
		else {
			My_TreeNode* left = find_el(node->left, id);
			if (left) {
				return left;
			}
			return find_el(node->right, id);
		}
	}
	return node;
}

My_TreeNode* BinaryTree::find_el(size_t id) {
	if (root) {
		if (root->id == id) {
			return root;
		}
		else {
			My_TreeNode* left = find_el(root->left, id);
			if (left) {
				return left;
			}
			return find_el(root->right, id);
		}
	}
	return root;
}

My_TreeNode* BinaryTree::find_parent(size_t id) {
	if (root != nullptr && root->id != id) {
		if ((root->left && root->left->id == id) || (root->right && root->right->id == id)) {
			return root;
		}
		else {
			My_TreeNode* left = find_parent(root->left, id);
			if (left) {
				return left;
			}
			return find_parent(root->right, id);
		}
	}
	return nullptr;
}

My_TreeNode* BinaryTree::find_parent(My_TreeNode* node, size_t id) {
	if (node != nullptr && node->id != id) {
		if ((node->left && node->left->id == id) || (node->right && node->right->id == id)) {
			return node;
		}
		else {
			My_TreeNode* left = find_parent(node->left, id);
			if (left) {
				return left;
			}
			return find_parent(node->right, id);
		}
	}
	return node;
}


// Основные методы
bool BinaryTree::create_tree(DataField data) {
	if (root) {
		return false;
	}
	root = new My_TreeNode;
	root->data_field = data;
	root->id = global_id++;
	root->left = nullptr;
	root->right = nullptr;
	return true;
}

bool BinaryTree::add_node(size_t id, DataField data) {
	My_TreeNode* parent = find_el(id);

	if (!parent || (parent->left && parent->right)) {
		return false;
	}

	My_TreeNode* new_node = new My_TreeNode;
	new_node->data_field = data;
	new_node->id = global_id++;
	new_node->left = nullptr;
	new_node->right = nullptr;

	if (!parent->left) {
		parent->left = new_node;
	}
	else {
		parent->right = new_node;
	}

	return true;
}


void BinaryTree::delete_node(My_TreeNode* node) {
	if (node != nullptr) {
		delete_node(node->left);
		delete_node(node->right);
		delete node;
	}
}

void BinaryTree::delete_by_id(size_t id) {
	My_TreeNode* parent = find_parent(id);
	if (parent->left && parent->left->id == id) {
		delete_node(parent->left);
		parent->left = nullptr;
	}
	else {
		delete_node(parent->right);
		parent->right = nullptr;
	}
}

void BinaryTree::delete_tree() {
	if (root != nullptr) {
		delete_node(root->left);
		delete_node(root->right);
		delete root;
		root = nullptr;
	}
}

long int BinaryTree::calc_sum(My_TreeNode* node) {
	if (node) {
		return node->data_field.cost + calc_sum(node->left) + calc_sum(node->right);
	}
	return 0;
}

long int BinaryTree::calc_sum(size_t id) {
	return calc_sum(find_el(id));
}