#pragma once
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

template<class T>
class AVLNode
{
private:
	T key;
public:
	AVLNode* left;
	AVLNode* right;
	int height;
	AVLNode()
	{
		key = 0;
		height = -1;
		left = NULL;
		right = NULL;
	}
	AVLNode(T id)
	{
		this->key = id;
		left = NULL;
		right = NULL;
		height = -1;
	}

	void setKey(T val) {
		key = val;
	}

	T getKey()
	{
		return key;
	}

};

int Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

template<class T>
class AVLTree {
public:

	AVLNode<T>* root;
	AVLTree()
	{
		root = NULL;
	}

	bool isempty()
	{
		if (root == NULL)
			return true;
		else
			return false;

	}

	int getHeight(AVLNode<T>* n)
	{
		if (n == NULL)
		{
			return -1;
		}
		else

			return n->height;

	}

	AVLNode<T>* LLrotation(AVLNode<T>* n1)
	{
		AVLNode<T>* n2;
		n2 = n1->right;
		n1->right = n2->left;
		n2->left = n1;
		n1->height = Max(getHeight(n1->left), getHeight(n1->right)) + 1;
		n2->height = Max(getHeight(n2->left), getHeight(n2->right)) + 1;
		return n2;  //the new root
	}

	AVLNode<T>* RRrotation(AVLNode<T>* n1)
	{
		AVLNode<T>* n2;
		n2 = n1->left;
		n1->left = n2->right;
		n2->right = n1;
		n1->height = Max(getHeight(n1->left), getHeight(n1->right)) + 1;
		n2->height = Max(getHeight(n2->left), getHeight(n2->right)) + 1;
		return n2;  //the new root
	}

	AVLNode<T>* LRrotation(AVLNode<T>* n1)
	{
		n1->right = RRrotation(n1->right);
		return LLrotation(n1);
	}

	AVLNode<T>* RLrotation(AVLNode<T>* n1)
	{
		n1->left = LLrotation(n1->left);
		return RRrotation(n1);
	}

	bool retrieve(int val)
	{
		bool found = false;
		AVLNode<T>* nptr = root;
		while (nptr != NULL)
		{
			if (nptr->getKey() == val)
			{
				found = true;
				break;
			}
			else if (nptr->getKey() > val)
			{
				nptr = nptr->left;
			}
			else
				nptr = nptr->right;
		}
		return found;
	}

	AVLNode<T>* insert(T val, AVLNode<T>* node)
	{
		AVLNode<T>* n = new AVLNode<T>(val);      //node to be inserted
		AVLNode<T>* temp = new AVLNode<T>();      //to traverse the tree
		temp = root;

		if (isempty())
		{
			node = n;

		}
		else if (val > node->getKey())
		{
			node->right = insert(val, node->right);
			if (getHeight(node->right) - getHeight(node->left) == 2)
			{
				if (val > (node->right)->getKey())
					node = LLrotation(node);
				else
					node = LRrotation(node);
			}
		}
		else if (val < node->getKey())
		{
			node->left = insert(val, node->left);
			if (getHeight(node->right) - getHeight(node->left) == 2)
			{
				if (val < (node->left)->getKey())
					node = RRrotation(node);
				else
					node = RLrotation(node);
			}
		}
		else {
			cout << "Duplicates not allowed.";
		}
		node->height = Max(getHeight(node->left), getHeight(node->right)) + 1;
		return node;
		/*while (temp != NULL)
				{
					if (val > temp->getKey())
					{
						if (temp->right == NULL)
						{
							temp->right = n;
							break;
						}
						else
							temp = temp->right;
					}

					else if (val < temp->getKey())
					{
						if (temp->left == NULL)
						{
							temp->left = n;
							break;
						}
						else
							temp = temp->left;
					}
				}
			}
			else
			{
				cout << "Duplicates not allowed.\n";
			}
		}*/
	}
	void PreOrderTraversal(AVLNode<T>* n)
	{
		if (n != NULL)
		{
			cout << n->getKey() << " ";
			PreOrderTraversal(n->left);
			PreOrderTraversal(n->right);

		}
	}

	void PostOrderTraversal(AVLNode<T>* n)
	{
		//n = root;
		if (n != NULL)
		{
			PostOrderTraversal(n->left);
			PostOrderTraversal(n->right);
			cout << n->getKey() << " ";

		}
	}

	void InOrderTraversal(AVLNode<T>* n)
	{
		//n = root;
		if (n != NULL)
		{
			InOrderTraversal(n->left);
			cout << n->getKey() << " ";
			InOrderTraversal(n->right);
		}
	}


	void ShowinPreOrder() {
		cout << "PreOrder traversal is : " << endl;
		PreOrderTraversal(root);
		cout << endl;
	}

	void ShowinPostOrder() {
		cout << "PostOrder traversal is : " << endl;
		PostOrderTraversal(root);
		cout << endl;
	}

	void ShowinInOrder() {
		cout << "InOrder traversal is : " << endl;
		InOrderTraversal(root);
		cout << endl;
	}

	void LevelOrder(AVLNode<T>* n)
	{
		queue<AVLNode<T>*> trees;
		AVLNode<T>* temp = n;
		trees.push(temp);
		while (!trees.empty())
		{
			/*if (trees.front()->left == NULL && trees.front()->right == NULL)
			{
				cout << trees.front()->getKey() << " ";
				trees.pop();
				continue;
			}
			else if (trees.front()->left == NULL && trees.front()->right != NULL)
			{
				trees.push(trees.front()->right);
				cout << trees.front()->getKey() << " ";
				trees.pop();
				continue;
			}
			else if (trees.front()->left != NULL && trees.front()->right == NULL)
			{
				trees.push(trees.front()->left);
				cout << trees.front()->getKey() << " ";
				trees.pop();
				continue;
			}
			else
				trees.push(trees.front()->left);
			trees.push(trees.front()->right);
			cout << trees.front()->getKey() << " ";
			trees.pop();
			continue;*/
			/*if (trees.front()->left != NULL)
			{
				trees.push(trees.front()->left);
			}
			if (trees.front()->right != NULL)
			{
				trees.push(trees.front()->right);
			}
			else
				cout << trees.front()->getKey() << " ";
				trees.pop();*/
		}
	}

	void BreadthFirst()
	{
		cout << "Breadth First/Level Order Traversal is: " << endl;
		LevelOrder(root);
		cout << endl;
	}

	AVLNode<T>* getMin(AVLNode<T>* ptr)
	{
		while (ptr->left)
		{
			ptr = ptr->left;
		}
		return ptr;
	}
	void makeDeletion(AVLNode<T>*& ptr)
	{
		AVLNode<T>* temp = new AVLNode<T>();
		if (ptr->right == NULL)
		{
			temp = ptr;
			ptr = ptr->left;
			delete temp;
		}
		else if (ptr->left == NULL)
		{
			temp = ptr;
			ptr = ptr->right;
			delete temp;
		}
		else
		{
			temp = ptr->right;
			temp = getMin(temp);
			temp->left = ptr->left;
			temp = ptr;
			ptr = ptr->right;
			delete temp;
		}

	}

	void deleteNode(int val, AVLNode<T>*& nodeptr)
	{
		if (nodeptr == NULL)
			cout << "Not found in tree";

		else if (nodeptr->getKey() > val)
		{
			deleteNode(val, nodeptr->left);
		}
		else if (nodeptr->getKey() < val)
		{
			deleteNode(val, nodeptr->right);
		}
		else makeDeletion(nodeptr);
	}

};

