#pragma once
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

template<class T>
class TreeNode
{
private:
	T value;
public:
	TreeNode* left;
	TreeNode* right;
	TreeNode()
	{
		left = NULL;
		right = NULL;
	}
	TreeNode(T id)
	{
		this->value = id;
		left = NULL;
		right = NULL;
	}

	void setValue(T val) {
		value = val;
	}

	T getValue()
	{
		return value;
	}

};

template<class T>
class BST {
public:

	TreeNode<T>* root;
	BST()
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

	bool retrieve(int val)
	{
		bool found = false;
		TreeNode<T>* nptr = root;
		while (nptr != NULL)
		{
			if (nptr->getValue() == val)
			{
				found = true;
				break;
			}
			else if (nptr->getValue() > val)
			{
				nptr = nptr->left;
			}
			else
				nptr = nptr->right;
		}
		return found;
	}

	void insert(T val)
	{
		TreeNode<T>* n = new TreeNode<T>(val);      //node to be inserted
		TreeNode<T>* temp = new TreeNode<T>();      //to traverse the tree
		temp = root;

		if (isempty())
		{
			root = n;
		}
		else
		{
			if (retrieve(val) == false)
			{
				while (temp != NULL)
				{
					if (val > temp->getValue())
					{
						if (temp->right == NULL)
						{
							temp->right = n;
							break;
						}
						else
							temp = temp->right;
					}

					else if (val < temp->getValue())
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
		}
	}
	void PreOrderTraversal(TreeNode<T>* n)
	{
		if (n != NULL)
		{
			cout << n->getValue() << " ";
			PreOrderTraversal(n->left);
			PreOrderTraversal(n->right);

		}
	}

	void PostOrderTraversal(TreeNode<T>* n)
	{
		//n = root;
		if (n != NULL)
		{
			PostOrderTraversal(n->left);
			PostOrderTraversal(n->right);
			cout << n->getValue() << " ";

		}
	}

	void InOrderTraversal(TreeNode<T>* n)
	{
		//n = root;
		if (n != NULL)
		{
			InOrderTraversal(n->left);
			cout << n->getValue() << " ";
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

	void LevelOrder(TreeNode<T>* n)
	{
		queue<TreeNode<T>*> trees;
		TreeNode<T>* temp = n;
		trees.push(temp);
		while (!trees.empty())
		{
			if (trees.front()->left == NULL && trees.front()->right == NULL)
			{
				cout << trees.front()->getValue() << " ";
				trees.pop();
				continue;
			}
			else if (trees.front()->left == NULL && trees.front()->right != NULL)
			{
				trees.push(trees.front()->right);
				cout << trees.front()->getValue() << " ";
				trees.pop();
				continue;
			}
			else if (trees.front()->left != NULL && trees.front()->right == NULL)
			{
				trees.push(trees.front()->left);
				cout << trees.front()->getValue() << " ";
				trees.pop();
				continue;
			}
			else
				trees.push(trees.front()->left);
			trees.push(trees.front()->right);
			cout << trees.front()->getValue() << " ";
			trees.pop();
			continue;
		}
	}

	void BreadthFirst()
	{
		cout << "Breadth First/Level Order Traversal is: " << endl;
		LevelOrder(root);
		cout << endl;
	}

	TreeNode<T>* getMin(TreeNode<T>* ptr)
	{
		while (ptr->left)
		{
			ptr = ptr->left;
		}
		return ptr;
	}
	void makeDeletion(TreeNode<T>*& ptr)
	{
		TreeNode* temp = new TreeNode();
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

	void deleteNode(int val, TreeNode<T>*& nodeptr)
	{
		if (nodeptr == NULL)
			cout << "Not found in tree";

		else if (nodeptr->getValue() > val)
		{
			deleteNode(val, nodeptr->left);
		}
		else if (nodeptr->getValue() < val)
		{
			deleteNode(val, nodeptr->right);
		}
		else makeDeletion(nodeptr);
	}

	void Reflection(TreeNode<T>** nodeptr)
	{
		TreeNode<T>* currNode;
		TreeNode<T>* temp=new TreeNode<T>();
		queue<TreeNode<T>*> Q;
		Q.push(*nodeptr);
		while (!Q.empty())
		{
			currNode = Q.front();
			Q.pop();
			temp = currNode->left;
			currNode->left = currNode->right;
			currNode->right = temp;
			if (currNode->left) {
				Q.push(currNode->left);
			}
			if (currNode->right) {
				Q.push(currNode->right);
			}
		
		}
		
	}

	TreeNode<T>* makeExpressionTree(string postfix)
	{
		stack<TreeNode<T>*> opstk;
		char symb, topsymb;
		int length = postfix.length();
		for (int i = 0; i < length; i++)
		{
			while ((postfix[i] == 32))
			{
				i++;
			}
			symb = postfix[i];
			if (symb >= 'A' && symb <= 'Z')
			{
				TreeNode<T>* operand = new TreeNode<T>(symb);
				opstk.push(operand);
			}
			else if (symb >= 'a' && symb <= 'z')
			{
				TreeNode<T>* operand = new TreeNode<T>(symb);
				opstk.push(operand);
			}
			else
			{
				TreeNode<T>* operat = new TreeNode<T>(symb);
				operat->right = opstk.top();
				opstk.pop();
				operat->left = opstk.top();
				opstk.pop();
				opstk.push(operat);

			}
		}

		return opstk.top();
		opstk.pop();
	}

};




