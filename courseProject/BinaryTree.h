#pragma once
#include <iostream>
#include <string>
using std::string;


struct DataField {
	string bankName = "NoName";
	long int cost = -1;
};

struct My_TreeNode {
	size_t id = 0;
	DataField data_field;
	My_TreeNode* left = nullptr;
	My_TreeNode* right = nullptr;
};

class BinaryTree {
private:
	My_TreeNode* root = nullptr;
	size_t global_id = 0;

	My_TreeNode* find_el(My_TreeNode*, size_t);
	My_TreeNode* find_parent(My_TreeNode*, size_t);
	void delete_node(My_TreeNode*);
	long int calc_sum(My_TreeNode*);


public:

	BinaryTree();
	BinaryTree(DataField);

	My_TreeNode* find_el(size_t);
	My_TreeNode* find_parent(size_t);
	bool create_tree(DataField);
	My_TreeNode* create_node(DataField);
	bool add_node(size_t, DataField);
	void delete_by_id(size_t);
	void delete_tree();
	long int calc_sum(size_t);

	My_TreeNode* get_root();
	size_t get_global_id();
};