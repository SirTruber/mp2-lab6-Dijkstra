#pragma once
#include <vector>

using namespace std;

template <typename T>
class Graph
{
private:
	struct COO
	{
		struct node
		{
			int   _value; //< ��� �����
			int   _start; //< ������� ������
			int   _end;   //< ������� �����
			node* _next = nullptr; //< ��������� �� ��������� �������
		};
		node  _nil; //< ��������� �������
		node* _root;//< ��������� ������ ������
		size_t _size;//< ���������� �����

		//\brief ����������� �� ���������
		COO() :
			_nil{ 0,0,0,&_nil },
			_root(&_nil),
			_size(0)
		{};

		//\brief ����������
		~COO()
		{
			for (node* tmp = _root; _root != &_nil; _root = tmp)
			{
				tmp = _root->_next;
				delete _root;
			}
			_nil._next = nullptr;
		}

		//\brief ���������� ��� ��������� �����
		//\param value ���
		//\param start ������� ������
		//\param end ������� �����
		void add(const int value,const int start,const int end)
		{
			if (start == end) return;
			if (_root == &nil)
			{
				root = new node{ value,start,end,&nil };
				_nil._next = root;
				++_size;
				return;
			}

			node* tmp = root;
			for (; tmp != &nil; tmp = tmp->_next)
			{
				if (tmp->_start < start) continue;
				if (tmp->_start == start && tmp->_end < end) continue;
				if (tmp->_start == start && tmp->_end == end)
				{
					tmp->_value = value;
					return;
				}
				node* ins = new node{ value,start,end,tmp->_next };
				tmp->_next = ins;
				++_size;
				return;
			}
		};

		//\brief �������� �����
		//\param start ������� ������
		//\param end ������� �����
		void del(const int start,const int end)
		{
			if (start == end) return;
			if (_root == &nil)
			{
				return;
			}

			node* tmp = root;
			for (; tmp != &nil; tmp = tmp->_next)
			{
				if (tmp->_start < start) continue;
				if (tmp->_start == start && tmp->_end < end) continue;
				if (tmp->_start == start && tmp->_end == end)
				{
					node* cur = &nil;
					while (cur->_next != tmp) cur = cur->_next;
					cur->_next = tmp->_next;
					_root = _nil->_next;
					delete tmp;
					--_size;
					return;
				}
				return;
			}
		};

		//\brief �������� ���� ���� �� ������ ������� � ����� ���� ������ ����� ���
		//\param start �������, �� ������� ������� ����
		void del(const int start)
		{
			if (_root == &nil)
			{
				return;
			}

			node* tmp = root;
			for (;tmp != &nil; tmp = tmp->_next)
			{
				if (tmp->_start < start && tmp->_end < start) continue;
				if (tmp->_end == start) { del(tmp->_start, start); continue }
				if (tmp->_start == start)
				{
					node* cur = &nil;
					while (cur->_next != tmp) cur = cur->_next;
					while (tmp->_start == start && tmp != &nil)
					{
						cur->_next = tmp->_next;
						delete tmp; --_size;
						tmp = cur->_next
					}
					_root = _nil->_next;
					continue;
				}
				if (tmp->_start > start) --tmp->_start;
				if (tmp->_end > start) --tmp->_end;
			}
		}
	};
	
public:
	vector<T> _V; //< ������ ������
	COO       _E; //< ��������� ����

	//\brief �������� ������� � ����
	//\param target ������� ��� ����������
	void addV(const T& target)
	{
		_V.push_back(T);
	}

	//\brief ���������� ��� ��������� �����
	//\param value ���
	//\param start ������� ������
	//\param end ������� �����
	void addE(const int value, const int start, const int end)
	{
		_E.add(value, start, end);
	}

	//\brief �������� �������
	//\param target ����� �������
	void delV(const int target)
	{
		_V.erase(_V.begin() + target);
		_E.del(target);
	};

	//\brief �������� �����
	//\param start ������� ������
	//\param end ������� �����
	void delE(const int start, const int end)
	{
		_E.del(start, end);
	}

	//\brief ���������� ������� ������������� �����
	//\return ����� �� ������ �� �������
	double fill()
	{
		return static_cast<double>(_E._size) / static_cast<double>(_V.size() * (_V.size() - 1));
	};
};