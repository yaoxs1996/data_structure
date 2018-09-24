#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

typedef struct BiTreeNode
{
    char data;
    BiTreeNode *lchild, *rchild;
}Node;

//打印节点
void visit(char ch)
{
    cout << ch << " ";
}

/*先序序列创建二叉树，对于空结点，用“#”代替进行输入*/
//测试用例 ABD##E##C##
/*  A
    /\
   B  C
  /\
  D E*/
Node* create()
{
    Node *p;
    char ch;
    cin >> ch;

    if (ch != '#')
    {
        p = new Node;
        p->data = ch;
        p->lchild = NULL;
        p->rchild = NULL;
        p->lchild = create();
        p->rchild = create();
    }
    else
    {
        p = NULL;
    }

    return p;
}

//由先序和中序遍历序列创建二叉树
//C++只允许指针的引用
void preInOrd(string preord, string inord, Node *&p, int i, int j, int k, int h)
{
    int m = 0;

    p = new Node;
    p->data = preord[i];

    m = k;
    while (inord[m] != preord[i])
        m++;

    //递归调用创建左子树
    if (m == k)
        p->lchild = NULL;
    else
        preInOrd(preord, inord, p->lchild, i + 1, i + m - k, k, m - 1);

    //递归调用创建右子树
    if (m == h)
        p->rchild = NULL;
    else
        preInOrd(preord, inord, p->rchild, i + m - k + 1, j, m + 1, h);
}

Node* createBiTree()
{
    Node *p = new Node;

    string preord ="ABCDEFG";
    string inord = "CBDAEGF";

    //先序序列从i到j
    int i = 0;
    int j = preord.size();
    //中序序列从k到n
    int k = 0;
    int h = inord.size();

    if (preord.size() != inord.size())
    {
        cout << "序列有误，无法建立二叉树" << endl;
        exit(0);
    }
    if (preord.size() <= 0)
    {
        p = NULL;
    }
    else
    {
        preInOrd(preord, inord, p, i, j, k, h);
    }

    return p;
}

//递归实现先序遍历
void preOrder(Node *root)
{
    if (root != NULL)
    {
        visit(root->data);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

//递归实现中序遍历
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->lchild);
        visit(root->data);
        inOrder(root->rchild);
    }
}

//递归实现后序遍历
void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->lchild);
        postOrder(root->rchild);
        visit(root->data);
    }
}

//层次遍历
void levelOrder(Node *root)
{
    Node *temp = new Node;
    queue<Node> q;
    q.push(*root);
    while (!q.empty())
    {
        *temp = q.front();
        visit(temp->data);
        q.pop();

        if (temp->lchild != NULL)
            q.push(*temp->lchild);
        if (temp->lchild != NULL)
            q.push(*temp->rchild);
    }
}

//获得二叉树的深度（高度）
int getDepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->lchild == NULL && root->rchild == NULL)
        return 1;
    int depthL = getDepth(root->lchild);
    int depthR = getDepth(root->rchild);

    return 1 + max(depthL, depthR);
}

//计算二叉树叶子节点的数目
int getNumOfLeaf(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->lchild == NULL && root->rchild == NULL)
        return 1;
    return (getNumOfLeaf(root->lchild) + getNumOfLeaf(root->rchild));
}

int main()
{
    Node *tree = new Node;
    //tree = create();
    tree = createBiTree();

    cout << "先序遍历结果如下：";
    preOrder(tree);
    cout << endl;

    cout << "中序遍历结果如下：";
    inOrder(tree);
    cout << endl;

    cout << "后序遍历结果如下：";
    postOrder(tree);
    cout << endl;

    cout << "层次遍历结果如下：";
    levelOrder(tree);
    cout << endl;

    cout << "该二叉树的高度为：" << getDepth(tree) << endl;
    cout << "该二叉树树叶的数量为：" << getNumOfLeaf(tree) << endl;
    system("pause");
}