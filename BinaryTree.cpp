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
	//求节点数
	int GetNodeNum(SBinaryTreeNode *pRoot);
	//求叶子数
	int GetLeafNum(SBinaryTreeNode *pRoot);
	//求深度
	int GetDepth(SBinaryTreeNode *pRoot);
	//先序
	void PreOrder(SBinaryTreeNode *pRoot);
	void PreOrderNon(SBinaryTreeNode *pRoot);
	//中序
	void InOrder(SBinaryTreeNode *pRoot);
	void InOrderNon(SBinaryTreeNode *pRoot);
	//后序
	void PostOrder(SBinaryTreeNode *pRoot);
	void PostOrderNon(SBinaryTreeNode *pRoot);
	//层序
	void LevelOrder(SBinaryTreeNode *pRoot);

	//求第k层的节点数
	int GetKLevelNum(SBinaryTreeNode *pRoot,int k);
	//判断两个二叉树是否同构
	bool isSameStruct(SBinaryTreeNode *pRoot1,SBinaryTreeNode *pRoot2);
	//镜像二叉树
	void MirrorBinaryTree(SBinaryTreeNode *pRoot);
	//最低公共祖先
	SBinaryTreeNode * LowestCommonAncestor(SBinaryTreeNode *pRoot,
											SBinaryTreeNode *Node1,
											SBinaryTreeNode *Node2);
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

//求第K层节点数
int CBinaryTree::GetKLevelNum(SBinaryTreeNode *pRoot,int k)
{
	if (pRoot == NULL || k < 1) return 0;
	if (k == 1) return 1;
	return GetKLevelNum(pRoot->left,k-1) + GetKLevelNum(pRoot->right,k-1);
}

//同构判断（仅判断结构，每个位置的值可以不同）
bool CBinaryTree::isSameStruct(SBinaryTreeNode *pRoot1,SBinaryTreeNode *pRoot2)
{
	if (pRoot1 == NULL && pRoot2 == NULL) return true;
	if (pRoot1 == NULL || pRoot2 == NULL) return false;

	return isSameStruct(pRoot1->left,pRoot2->left) && isSameStruct(pRoot1->right,pRoot2->right);
}

//镜像
void CBinaryTree::MirrorBinaryTree(SBinaryTreeNode *pRoot)
{
	if (pRoot != NULL)
	{
		swap(pRoot->left,pRoot->right);
		MirrorBinaryTree(pRoot->left);
		MirrorBinaryTree(pRoot->right);
	}
}

//最低公共祖先
SBinaryTreeNode * CBinaryTree::LowestCommonAncestor(SBinaryTreeNode *pRoot, SBinaryTreeNode *Node1, SBinaryTreeNode *Node2)
{
	if (pRoot == NULL)
		return NULL;
	if (pRoot == Node1 || pRoot == Node2)
		return pRoot;
	SBinaryTreeNode * left = LowestCommonAncestor(pRoot->left, Node1, Node2);
	SBinaryTreeNode * right = LowestCommonAncestor(pRoot->right, Node1, Node2);
	if (left && right)
		return pRoot;
	return left ? left : right;
}