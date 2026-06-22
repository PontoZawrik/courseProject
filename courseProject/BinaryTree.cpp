#include "BinaryTree.h"

BinaryTree::BinaryTree() {}
BinaryTree::BinaryTree(DataField data) {
	create_tree(data);
}

My_TreeNode* BinaryTree::find_el(My_TreeNode* node, size_t id) {
	if (!node) {
		return nullptr;
	}
	if (node->id == id) {
		return node;
	}

	My_TreeNode* left = find_el(node->left, id);
	if (left) {
		return left;
	}
	return find_el(node->right, id);

}

My_TreeNode* BinaryTree::find_el(size_t id) {
	if (!root) {
		return nullptr;
	}
	if (root->id == id) {
		return root;
	}

	My_TreeNode* left = find_el(root->left, id);
	if (left) {
		return left;
	}
	return find_el(root->right, id);
}

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
	My_TreeNode* select = find_el(id);
	delete_node(select);
}

void BinaryTree::delete_tree() {
	if (root != nullptr) {
		delete_node(root->left);
		delete_node(root->right);
		delete root;
	}
}