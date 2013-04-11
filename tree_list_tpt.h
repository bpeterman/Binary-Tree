#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class tree {
public:
  // tree node structure
	struct tree_node {
		T data;
		tree_node *left, *right;	// left and right child pointers	
		tree_node(T d, tree_node *l, tree_node *r):data(d),left(l),right(r){}
	};
	
	tree_node *root; // root "head" pointer for entire tree
	
	// helper method used by tree print method
	void print_spaces(int n) { 
		for(int i=0; i<n; ++i)
			cout << " ";
	}	
public:
	// default constructor
	tree():root(nullptr){}
	
	// constructor which creates a root node
	tree(const T& d) {
		root=new tree_node(d, nullptr, nullptr);
	}

	
	// returns the smallest value in tree
	// throw domain error exception if tree is empty
	T smallest(){
		if(root==nullptr)
			throw domain_error("empty list");
		return smallest(root);
	} 
	T smallest(tree_node* r){
		if(r->left == nullptr)
			return r->data;
		else
			return smallest(r->left);
	} 
	
	// returns the largest value in tree
	// throw domain error exception if tree is empty
	T largest(){
		if(root==nullptr)
			throw domain_error("empty list");
		return largest(root);
	} 
	T largest(tree_node* r){
		if(r->right == nullptr)
			return r->data;
		else
			return largest(r->right);
	} 
	// returns sum of all elements in the tree
	// use IN-ORDER traversal
	// return template generic value T() if empty
	T in_sum(){
		return T(); // replace with proper code
	}
	
	// returns sum of all elements in the tree
	// use POST-ORDER traversal
	// return template generic value T() if empty
	T post_sum() {
		return T(); // replace with proper code
	}

	// destructor, call delete on all nodes
	~tree(){

		
	}  
	
	// copy constructor
	tree(const tree&other){} 
	
	// assignment operator
	tree& operator=(const tree&other){
		if (this == &other)
			return *this;
			
		return *this; // replace with proper code
	} 

	
	// recursive tree print method using pre-order traversal
	void pre_print(tree_node*r,int level) {
		if(r == nullptr) // base case
			return;
			
		// print node data
		print_spaces(level*3);
		cout << r->data << endl;
		
		// handle left sub-tree
		if(r->right && ! r->left) {
			print_spaces(level*3+3);
			cout << "no left"<< endl;
		}
		pre_print(r->left, level+1);
		
		// handle right sub-tree
		if(!r->right && r->left) {
			print_spaces(level*3+3);
			cout << "no right" << endl;			
		}
		pre_print(r->right, level+1);
	}
	
	// wrapper method for recursive tree print method
	void pre_print(void) {
		pre_print(root, 0);
	}

	// recursive contains method
	bool contains(tree_node* r, const T& val) const {
		if(r == nullptr)
			return false;
		if(r->data == val)
			return true;
		if(r->data > val)
			return contains(r->left, val);
		else
			return contains(r->right, val);
	}
	
	// wrapper method for recursive contains method
	bool contains(const T& value) const { return contains(root,value);}
	
	// recursive insert method for inserting new value into tree
	// only inserts new values at leaves, never in middle of tree
	// does NOT insert duplicate values into tree
	void insert(tree_node* r, const T&val) {
		if(r->data == val)
			return;
			
		if(r->data > val) {
			if(r->left == nullptr) 
				r->left = new tree_node(val, nullptr, nullptr);
			else
				insert(r->left, val);
		}
		else {
			if(r->right == nullptr) 
				r->right = new tree_node(val, nullptr, nullptr);
			else
				insert(r->right, val);
		}
	}

	// wrapper method for recursive tree insert method
	void insert(const T&val) {
		if(root == nullptr)
			root = new tree_node(val, nullptr, nullptr);
		else
			insert(root,val);
	}

};
