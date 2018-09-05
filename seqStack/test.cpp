#include"seqStack.h"
using namespace std;

int main()
{
	seqStack<int> stack(10);
	for(int i=0; i<10; i++)
	{
		stack.push(i);
	}
	stack.print();

	stack.push(88);
	cout << stack.pop() << endl;
	cout << stack.getTop() << endl;
	stack.print();

	stack.clear();
	stack.print();

	return 0;
}