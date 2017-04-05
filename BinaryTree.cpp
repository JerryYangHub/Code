struct SBinaryTreeNode
{
	int val;
	SBinaryTreeNode *left;
	SBinaryTreeNode *right;
	SBinaryTreeNode(int v) {val = v;left = NULL;right = NULL;};
};
class CBinaryTree
{
public:
	int GetNodeNum(SBinaryTreeNode *pRoot);
	int GetLeafNum(SBinaryTreeNode *pRoot);
	int GetDepth(SBinaryTreeNode *pRoot);
	
	void PreOrder(SBinaryTreeNode *pRoot);
	void PreOrderNon(SBinaryTreeNode *pRoot);

	void InOrder(SBinaryTreeNode *pRoot);
	void InOrderNon(SBinaryTreeNode *pRoot);

	void PostOrder(SBinaryTreeNode *pRoot);
	void PostOrderNon(SBinaryTreeNode *pRoot);
	void LevelOrder(SBinaryTreeNode *pRoot);
};

//节点数
int CBinaryTree::GetNodeNum(SBinaryTreeNode *pRoot)
{
	if (pRoot == NULL) return 0;
	else
		return GetNodeNum(pRoot->left) + GetNodeNum(pRoot->right) + 1;
}

//叶子数
int CBinaryTree::GetLeafNum(SBinaryTreeNode *pRoot)
{
	if (pRoot == NULL) return 0;
	if (pRoot->left == NULL && pRoot->right == NULL) return 1;
	else return GetLeafNum(pRoot->left) + GetLeafNum(pRoot->right);
}

//深度(max(左子树深度，右子树深度) + 1)
int CBinaryTree::GetDepth(SBinaryTreeNode *pRoot)
{
	if (pRoot == NULL) return 0;
	int leftDepth = GetDepth(pRoot->left);
	int rightDepth = GetDepth(pRoot->right);
	return leftDepth > rightDepth ? (leftDepth + 1) : (rightDepth + 1);
}

//先序遍历 递归
void CBinaryTree::PreOrder(SBinaryTreeNode *pRoot)
{
	if (pRoot) 
	{
		cout<<pRoot->val<<" ";
		PreOrder(pRoot->left);
		PreOrder(pRoot->right);
	}
}

//先序遍历 非递归（用stack）
void CBinaryTree::PreOrderNon(SBinaryTreeNode *pRoot)
{
	stack<pair<SBinaryTreeNode *, bool>> s;
	s.push(make_pair(pRoot, false));
	bool visited;
	SBinaryTreeNode *p;
	while(!s.empty())
	{
		p = s.top().first;
		visited = s.top().second;
		s.pop();
		if(p == NULL)
			continue;
		if(visited)
		{
			cout<<p->val<<" ";
		}
		else
		{
			s.push(make_pair(p->right, false));
			s.push(make_pair(p->left, false));
			s.push(make_pair(p, true));
		}
	}
}

//中序遍历 递归
void CBinaryTree::InOrder(SBinaryTreeNode *pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->left);
		cout<<pRoot->val<<" ";
		InOrder(pRoot->right);
	}
}

//中序遍历 非递归
void CBinaryTree::InOrderNon(SBinaryTreeNode *pRoot)
{
	stack<pair<SBinaryTreeNode *, bool>> s;
	s.push(make_pair(pRoot, false));
	bool visited;
	SBinaryTreeNode *p;
	while(!s.empty())
	{
		p = s.top().first;
		visited = s.top().second;
		s.pop();
		if(p == NULL)
			continue;
		if(visited)
		{
			cout<<p->val<<" ";
		}
		else
		{
			s.push(make_pair(p->right, false));
			s.push(make_pair(p, true));
			s.push(make_pair(p->left, false));
		}
	}
}

//后序遍历 递归
void CBinaryTree::PostOrder(SBinaryTreeNode *pRoot)
{
	if (pRoot)
	{
		PostOrder(pRoot->left);
		PostOrder(pRoot->right);
		cout<<pRoot->val<<" ";
	}
}

void CBinaryTree::PostOrderNon(SBinaryTreeNode *pRoot)
{
	stack<pair<SBinaryTreeNode *, bool>> s;
	s.push(make_pair(pRoot, false));
	bool visited;
	SBinaryTreeNode *p;
	while(!s.empty())
	{
		p = s.top().first;
		visited = s.top().second;
		s.pop();
		if(p == NULL)
			continue;
		if(visited)
		{
			cout<<p->val<<" ";
		}
		else
		{
			s.push(make_pair(p, true));
			s.push(make_pair(p->right, false));
			s.push(make_pair(p->left, false));
		}
	}
}

//层次遍历
void CBinaryTree::LevelOrder(SBinaryTreeNode *pRoot)
{
	if (pRoot)
	{

		SBinaryTreeNode * p = pRoot;
		queue<SBinaryTreeNode*> Q;
		Q.push(p);
		while (!Q.empty())
		{
			p = Q.front();
			cout << p->val<< " ";
			Q.pop();
			if (p->left)
				Q.push(p->left);
			if (p->right)
				Q.push(p->right);
		}
	}
}