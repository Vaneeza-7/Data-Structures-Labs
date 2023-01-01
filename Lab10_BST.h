#pragma once
/////////////////////lab12 Vaneeza
#include<iostream>
#include<queue>
using namespace std;

class TreeNode
{
private:
	int value;
public:
	TreeNode* left;
	TreeNode* right;
	TreeNode()
	{
		left = NULL;
		right = NULL;
	}
	TreeNode(int id)
	{
		this->value = id;
		left = NULL;
		right = NULL;
	}

	void setValue(int val) {
		value = val;
	}

	int getValue()
	{
		return value;
	}

};


class BST {
public:

	TreeNode* root;
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
		TreeNode* nptr = root;
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
			     nptr=nptr->right;
		}
		return found;
	}

	void insert(int val)
	{
		TreeNode* n = new TreeNode(val);      //node to be inserted
		TreeNode* temp = new TreeNode();      //to traverse the tree
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
	void PreOrderTraversal(TreeNode* n)
	{
		if(n != NULL)
		{ 
			cout << n->getValue() << " ";
			PreOrderTraversal(n->left);
			PreOrderTraversal(n->right);

		}
	}

	void PostOrderTraversal(TreeNode* n)
	{
		//n = root;
		if (n != NULL)
		{
			PostOrderTraversal(n->left);
			PostOrderTraversal(n->right);
			cout << n->getValue() << " ";

		}
	}

	void InOrderTraversal(TreeNode* n)
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

	void LevelOrder(TreeNode* n)
	{
		queue<TreeNode*> trees;
		TreeNode* temp = n;
		trees.push(temp);
		while (!trees.empty())
		{
			if (trees.front()->left == NULL && trees.front()->right == NULL)
			{
				cout << trees.front()->getValue() << " ";
				trees.pop();
				continue;
			}
			else if(trees.front()->left == NULL && trees.front()->right != NULL)
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

	TreeNode* getMin(TreeNode* ptr)
	{
		while (ptr->left)
		{
			ptr = ptr->left;
		}
		return ptr;
	}
	void makeDeletion(TreeNode*& ptr)
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

	void deleteNode(int val, TreeNode*& nodeptr)
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
	void mirror(TreeNode*& node)
	{
		if (node == NULL)
			return;
		else {
			struct TreeNode* temp;

			/* do the subtrees */
			mirror(node->left);
			mirror(node->right);

			/* swap the pointers in this node */
			temp = node->left;
			node->left = node->right;
			node->right = temp;
			LevelOrder(node);
		}
	}

	//void Reflection(TreeNode*& nodeptr)
	//{
	//	TreeNode* currNode;
	//	TreeNode* temp=new TreeNode();
	//	queue<TreeNode*> Q;
	//	Q.push(nodeptr);
	//	while (!Q.empty())
	//	{
	//		//currNode =Q.front();
	//	    temp = Q.front()->left;
	//		Q.front()->left = Q.front()->right;
	//		Q.front()->right = temp;
	//		Q.push(Q.front()->left);
	//		Q.push(Q.front()->right);
	//		Q.pop();
	//	}
	//	BreadthFirst();
	//}

	//int count = 0;
	//TreeNode* getElement(TreeNode* root, int& k)
	//{
	//	
	//	if (root == NULL)
	//	{
	//		return NULL;
	//	}
	//	TreeNode* left = getElement(root->left, k);
	//	if (left != NULL)
	//		return left;
	//	count++;
	//	if (count == k)
	//		return left;
	//	TreeNode* right = getElement(root->right, k);

	//}

	//int getLeafCount(TreeNode* root)
	//{
	//	if (root != NULL)
	//	{
	//		if (root->left == NULL && root->right == NULL)
	//			return 1;

	//		getLeafCount(root->left) + 1;
	//		getLeafCount(root->right) + 1;
	//	}
	//}
};