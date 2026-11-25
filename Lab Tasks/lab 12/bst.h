#pragma once
#include <iostream>

template<typename T>
class bst {
private:
	template <typename U>
	struct node {
		U val;
		node<U>* left, * right, * parent;

	};
	node<T>* head;
	int n;
public:
	bst() {
		head = new node<T>;
		head->parent = head->left = head->right = head;
		n = 0;
	}
	void insert(const T& v) {
		node<T>* temp;
		temp = new node<T>;
		temp->val = v;
		temp->left = temp->right = head;
		if (head->parent == head) {
			head->parent = temp;
			temp->parent = head;
			head->right = head->left = temp;
			++n;
		}
		else {
			node<T>* ptr;
			ptr = head->parent;
			while (true) {
				if (temp->val > ptr->val) {
					if (ptr->right == head) {
						ptr->right = temp;
						temp->parent = ptr;
						if (temp->val > head->right->val)
							head->right = temp;
						++n;
						break;
					}
					else {
						ptr = ptr->right;
					}
				}
				else {
					if (ptr->left == head) {
						ptr->left = temp;
						temp->parent = ptr;
						if (temp->val > head->left->val)
							head->left = temp;
						++n;
						break;
					}
					else {
						ptr = ptr->left;
					}
				}
			}
		}

	}
	bool contains(const T& val) {
		node<T>* ptr;
		ptr = head->parent;
		while (ptr != head) {
			if (val == ptr->val)
				return true;
			else if (val > ptr->val)
				ptr = ptr->right;
			else
				ptr = ptr->left;
		}
		return false;
	}
	bool empty()const {
		return (head->parent == head);
			
	}
	int size()const
	{
		return n;
	}
};