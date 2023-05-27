#pragma once
template <typename T>
struct node 
{
	T _data;
	node *next;
	const T& operator *() { return _data; }
};

template<typename T>
class list 
{
private:
	node* root;
public:
	list() : 
		root(nullptr) 
	{};

	void push(T)
	{

	}

		void pop();

	node* first() { return root; };
	
	node* last() 
	{
		node<T>* tmp = root;
		while (tmp->next != nullptr)
			tmp = tmp->next;
		return tmp;
	}
	
	node* next(node<T> n) { return n.next; }
};