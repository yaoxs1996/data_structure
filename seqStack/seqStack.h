#include<iostream>

template<typename T>
class seqStack
{
private:
	int m_top;
	T *m_elements;
	int m_maxsize;

public:
	seqStack(int sz):m_top(-1), m_maxsize(sz)
	{
		m_elements = new T[sz];
		if(m_elements == NULL)
		{
			std::cout << "Application error!" << std::endl;
			exit(1);
		}
	}
	~seqStack()
	{
		delete[] m_elements;
	}

	void push(const T item);
	T pop();
	T getTop() const;
	void print();
	void clear()
	{
		m_top = -1;
	}
	bool isEmpty() const
	{
		return m_top == -1;
	}
	bool isFull() const
	{
		return m_top == m_maxsize-1;
	}
};

template<typename T>
void seqStack<T>::push(const T item)
{
	if(isFull())
	{
		std::cout << "Stack is full!" << std::endl;
		return;
	}
	m_elements[++m_top] = item;
}

template<typename T>
T seqStack<T>::pop()
{
	if(isEmpty())
	{
		std::cout << "Stack is empty!" << std::endl;
		exit(1);
	}
	return m_elements[m_top--];
}

template<typename T>
T seqStack<T>::getTop() const
{
	if(isEmpty())
	{
		std::cout << "stack is empty!" << std::endl;
		exit(1);
	}
	return m_elements[m_top];
}

template<typename T>
void seqStack<T>::print()
{
	std::cout << "bottom";
	for(int i=0; i<=m_top; i++)
	{
		std::cout << " ---> " << m_elements[i];
	}
	std::cout << " ---> top" << std::endl;
}