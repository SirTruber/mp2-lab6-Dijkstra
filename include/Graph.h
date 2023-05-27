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
			int   _value; //< Вес ребра
			int   _start; //< Вершина начала
			int   _end;   //< Вершина конца
			node* _next = nullptr; //< Указатель на следующий элемент
		};
		node  _nil; //< Фиктивный элемент
		node* _root;//< Указатель начала списка
		size_t _size;//< Количество узлов

		//\brief Конструктор по умолчанию
		COO() :
			_nil{ 0,0,0,&_nil },
			_root(&_nil),
			_size(0)
		{};

		//\brief Деструктор
		~COO()
		{
			for (node* tmp = _root; _root != &_nil; _root = tmp)
			{
				tmp = _root->_next;
				delete _root;
			}
			_nil._next = nullptr;
		}

		//\brief Добавление или изменение ребра
		//\param value Вес
		//\param start Вершина начала
		//\param end Вершина конца
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

		//\brief Удаление ребра
		//\param start Вершина начала
		//\param end Вершина конца
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

		//\brief Удаление всех рёбер из данной вершины и сдвиг всех вершин после нее
		//\param start Вершина, из которой удаляют рёбра
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
	vector<T> _V; //< Вектор вершин
	COO       _E; //< Структура рёбер

	//\brief Добавить вершину в граф
	//\param target Вершина для добавления
	void addV(const T& target)
	{
		_V.push_back(T);
	}

	//\brief Добавление или изменение ребра
	//\param value Вес
	//\param start Вершина начала
	//\param end Вершина конца
	void addE(const int value, const int start, const int end)
	{
		_E.add(value, start, end);
	}

	//\brief Удаление вершины
	//\param target Номер вершины
	void delV(const int target)
	{
		_V.erase(_V.begin() + target);
		_E.del(target);
	};

	//\brief Удаление ребра
	//\param start Вершина начала
	//\param end Вершина конца
	void delE(const int start, const int end)
	{
		_E.del(start, end);
	}

	//\brief Отображает процент заполненности графа
	//\return Число от одного до единицы
	double fill()
	{
		return static_cast<double>(_E._size) / static_cast<double>(_V.size() * (_V.size() - 1));
	};
};