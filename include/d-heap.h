#pragma once

template <typename T>
class d_heap
{
private:
	using ItemIterator = typename std::vector<T>::iterator;
	size_t    _ary;
	vector<T> _map;

	/*\brief Метод сдвига к минимальному элементу
	* \param pos Итератор вершины, для которой происходит сдвиг
	*/
	void shift_up(ItemIterator& pos) 
	{
		ItemIterator target = parents(pos);
		for (ItemIterator it = pos; target != _map.end() && *target > *it;)
		{
			std::swap(*target, *it);
			it = target;
			target = parents(target);
		}
	};

	/*\brief Метод сдвига от минимального элемента по максимальным потомкам.
	* \param pos Итератор вершины, для которой происходит сдвиг.
	*/
	void shift_down(ItemIterator& pos) 
	{
		ItemIterator target = maxBrother(index);
		for (ItemIterator it = index; target != _map.end() && *target < *it;)
		{
			std::swap(*target, *it);
			it = target;
			target = maxBrother(target);
		}
	};

	/*\brief Метод поиска родителя
	* \param index Итератор вершины, для которой происходит поиск
	* \return Вершина, являющаяся родительской
	*/
	ItemIterator parents(const ItemIterator& index)
	{
		if (_map.begin == index) return _map.end();
		return (_map.begin + (index - _map.begin() - 1) / _ary);
	};

	/*\brief Метод поиска макимального по ключу брата
	* \param index Итератор вершины, для которой происходит поиск
	* \return Вершина, являющаяся братом с макимальным ключом
	*/
	ItemIterator maxBrother(const ItemIterator& index)
	{
		int distance = index - _map.begin();
		if (_map.size() < distance * _ary + _ary + 1) return _map.end();
		T max = _map[distance * _ary + 1];
		int max_i = 1;
		for (int i = 2; i <= _ary; ++i)
		{
			if (_map[distance * _ary + i] > max)
			{
				max = _map[distance * _ary + i];
				max_i = i;
			}
		}
		return _map.begin() + distance * _ary + max_i;
	};

public:
	d_heap(size_t d = 2) :
		_ary(d)
	{};
	void heapify(vector<T> data)
	{
		_map(data);
		for(auto i =_map.begin();)
	};

	void insert(const T& target) {};

	T findMin() {};

	void decreaseKey();


	/*\brief Метод удаления произвольной вершины путём замены с самой удалённой вершиной.
   * \param index Итератор вершины, для которой происходит удаление.
   * \return true при успешном удалении ,false, если элемент не может быть удалён.
   */
	bool del(const ItemIterator& index)
	{
		if (index < _map.end() && index >= _map.begin())
		{
			swap(*index, *(_map.end() - 1));
			_map.pop();
			shiftDown(_map.begin());
			return true;
		}
		return false;
	};
};