#pragma once

template<typename T>
class priority_q
{
	priority_q() = delete;
	virtual const T& findMin();
	virtual void insert(const T& target);
	virtual T extractMin();
	virtual void increaseKey(const T& target)
};