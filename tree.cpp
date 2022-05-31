#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
	int data;
	Node* right;
	Node* left;

	Node(int data) {
		this->data = data;
		this->right = nullptr;
		this->left = nullptr;

	}
};

class BST {
private:
	Node* root = nullptr;

public:

	BST() {
		this->root = nullptr;
	}
	
	// Add iterative method
	void add_iterative(int data) {
		Node* new_node = new Node(data);

		if (root == nullptr) {
			root = new_node;
			return;
		}

		Node* temp = root;
		Node* parent = nullptr;

		while (temp != nullptr) {
			parent = temp;
			if (new_node->data <= temp->data) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		
		if (new_node->data < parent->data) {
			parent->left = new_node;
		}
		else {
			parent->right = new_node;
		}

	}
	// Add recursive method
	void add_recursive_helper(Node* temp, int data) {
		if (data < temp->data) {
			if (temp->left == nullptr) {
				Node* new_node = new Node(data);
				temp->left = new_node;
			}
			else {
				add_recursive_helper(temp->left, data);
			}
		}
		else {
			if (temp->right == nullptr) {
				Node* new_node = new Node(data);
				temp->right = new_node;
			}
			else {
				add_recursive_helper(temp->right, data);
			}
		}
	}
	void add_recursive(int data) {
	
		if (root == nullptr) {
			Node* new_node = new Node(data);
			root = new_node;
			return;
		}
		else {
			add_recursive_helper(root, data);
		}


	}
	
	// Max element iterative method
	int get_max_iterative() {
		Node* current_node = root;
		while (current_node->right != nullptr) {
			current_node = current_node->right;
		}
		return current_node->data;
	}
	// Max element recursive method
	int get_max_recursive_helper(Node* temp) {
		if (temp->right == nullptr) {
			return temp->data;
		}
		else {
			return get_max_recursive_helper(temp->right);
		}

	}
	int get_max_recursive() {
		return get_max_recursive_helper(root);
	}

	// Min element iterative method
	int get_min_iterative() {
		Node* current_node = root;
		while (current_node->left != nullptr) {
			current_node = current_node->left;
		}
		return current_node->data;
	}
	// Min element recursive method
	int get_min_recursive_helper(Node* temp) {
		if (temp->left == nullptr) {
			return temp->data;
		}
		else {
			  get_min_recursive_helper(temp->left);
		}

	}
	int get_min_recursive() {
		return get_min_recursive_helper(root);
	}

	// Height of a BT - Maximum depth of BT
	int get_height_helper(Node* temp) {
		if (temp == nullptr) {
			return -1;
		}
		int left = get_height_helper(temp->left); // if we pass the base case we will return in this var -1 
		int right = get_height_helper(temp->right);

		return max(left + 1, right + 1);

	}
	int get_height() {
		return get_height_helper(root);
	}

	// BFS 
	void bfs() {

		if (root == nullptr) {
			return;
		}

		queue<Node*> q;
		q.push(root);
		
		while (!q.empty()) {

			Node* cureent_node = q.front();
			q.pop();

			cout << cureent_node->data << " " ;

			if (cureent_node->left != nullptr) {
				q.push(cureent_node->left);
			}

			if (cureent_node->right != nullptr) {
				q.push(cureent_node->right);
			}
			
		}
		
		cout << endl; 
	}

	// DFS 
	// 1 - Pre-order  ROOT-L-R
	void dfs_preorder_helper(Node* temp) {
		if (temp == nullptr) {
			return;
		}
		cout << temp->data << " ";
		dfs_preorder_helper(temp->left);
		dfs_preorder_helper(temp->right);

	}
	void dfs_preorder() {
		dfs_preorder_helper(root);
	}
	// 2 - In-order L-ROOT-R
	void dfs_inorder_helper(Node* temp) {
		if (temp == nullptr) {
			return;
		}

		dfs_inorder_helper(temp->left);
		cout << temp->data << " ";
		dfs_inorder_helper(temp->right);

	}
	void dfs_inorder() {
		dfs_inorder_helper(root);
	}
	// 3 - Post-order L-R-ROOT
	void dfs_postorder_helper(Node* temp) {
		if (temp == nullptr) {
			return;
		}

		dfs_postorder_helper(temp->left);
		dfs_postorder_helper(temp->right);
		cout << temp->data << " ";

	}
	void dfs_postorder() {
		dfs_postorder_helper(root);
	}
};




int main()
{

	BST t;
	t.add_recursive(10);
	t.add_recursive(7);
	t.add_recursive(15);
	t.add_recursive(3);
	t.add_recursive(9);
	t.add_recursive(12);

	t.dfs_postorder();




	

	return 0;
}

 
