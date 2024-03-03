#include<iostream>
#include<queue>
using namespace std;

class Tree{
	
	public: 
		int val;
		Tree *left;
		Tree *right;

		Tree(int val)
		{
			this->val = val;
			left = nullptr;
			right = nullptr;
		}
};

class Demo {

	Tree *root = nullptr;

	public: 

		void accept()
		{
			if(root == nullptr)
			{
				root = new Tree(20);
			}

			insert(root, 15);
			insert(root, 25);
			insert(root, 12);
			insert(root, 17);
			insert(root, 22);
			insert(root, 18);

			inorder(root);

			level();
		}

		void insert(Tree *node, int val)
		{
			if(node->val > val)
			{
				if(!node->left)
				{
					node->left = new Tree(val);
				}
				else 
				{
					insert(node->left, val);
				}
			}
			else 
			{
				if(!node->right)
				{
					node->right = new Tree(val);
				}
				else 
				{
					insert(node->right, val);
				}
			}
		}

		void inorder(Tree *node)
		{
			if(node)
			{
				inorder(node->left);
				cout<<node->val<<" ";
				inorder(node->right);
			}
		}

		void level()
		{
			queue<Tree*> q;
			cout<<"\n";
			q.push(root);

			while(!q.empty())
			{
				int n = q.size();


				for(int i = 0; i < n; ++i)
				{
					Tree *t = q.front();
					q.pop();

					cout<<t->val<<" ";

					if(t->left)
						q.push(t->left);
					if(t->right)
						q.push(t->right);
				}
				cout<<"\n";
			}

		}
};

int main(void){
	Demo ob;

	ob.accept();
}