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

//��ӡ�ڵ�
void visit(char ch)
{
    cout << ch << " ";
}

/*�������д��������������ڿս�㣬�á�#�������������*/
//�������� ABD##E##C##
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

//�����������������д���������
//C++ֻ����ָ�������
void preInOrd(string preord, string inord, Node *&p, int i, int j, int k, int h)
{
    int m = 0;

    p = new Node;
    p->data = preord[i];

    m = k;
    while (inord[m] != preord[i])
        m++;

    //�ݹ���ô���������
    if (m == k)
        p->lchild = NULL;
    else
        preInOrd(preord, inord, p->lchild, i + 1, i + m - k, k, m - 1);

    //�ݹ���ô���������
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

    //�������д�i��j
    int i = 0;
    int j = preord.size();
    //�������д�k��n
    int k = 0;
    int h = inord.size();

    if (preord.size() != inord.size())
    {
        cout << "���������޷�����������" << endl;
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

//�ݹ�ʵ���������
void preOrder(Node *root)
{
    if (root != NULL)
    {
        visit(root->data);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

//�ݹ�ʵ���������
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->lchild);
        visit(root->data);
        inOrder(root->rchild);
    }
}

//�ݹ�ʵ�ֺ������
void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->lchild);
        postOrder(root->rchild);
        visit(root->data);
    }
}

//��α���
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

//��ö���������ȣ��߶ȣ�
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

//���������Ҷ�ӽڵ����Ŀ
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

    cout << "�������������£�";
    preOrder(tree);
    cout << endl;

    cout << "�������������£�";
    inOrder(tree);
    cout << endl;

    cout << "�������������£�";
    postOrder(tree);
    cout << endl;

    cout << "��α���������£�";
    levelOrder(tree);
    cout << endl;

    cout << "�ö������ĸ߶�Ϊ��" << getDepth(tree) << endl;
    cout << "�ö�������Ҷ������Ϊ��" << getNumOfLeaf(tree) << endl;
    system("pause");
}