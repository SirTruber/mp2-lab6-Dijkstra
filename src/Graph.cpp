#include <Graph.h>
#include <random>
#include <priority_q.h>

struct coo
{
	double x;
	double y;
};

//\brief Вспомогательная функция заполнения пустого графа минимальным остовным деревом
//\param g Пустой граф
//\param N Количество необходимых вершин
void minimalTree(Graph<coo>& g,size_t N)
{
	if (N < 1) return;
	for (size_t i = 0; i < N; ++i)
	{
		coo target{ rand()%800,rand()%600 };
		g.addV(target);
	}
	vector<int> open;
	vector<int> close;
	close.push_back(0);

	for(size_t i = 1;i < N;++i)
	{
		open.push_back(i);
	}
	//Алгоритм тасования Фишера-Йетса
	for (size_t i = N - 1; i > 1; --i)
	{
		size_t j = rand() % i;
		swap(open[i], open[j]);
	}
	
	//Алгоритм Прима
	while (!open.empty())
	{
		int i = open.back();
		int j = close[rand() % close.size()];
		g.addE(rand() % 100, i, j);
		close.push_back(i);
		open.pop_back();
	}
}

//\brief Вспомогательная функция дозаполнения минимального остовного дерева 
//\param g Граф с минимальным остовным деревом
//\param f Необходимый процент заполнения 
void fill(Graph<coo>& g, double f)
{
	if (f > 1) return;
	while (g.fill() < f)
	{
		int i = rand() % g._V.size();
		int j = rand() % g._V.size();
		if (i != j)
			g.addE(rand() % 100, i, j);
	}
}

//\brief Алгоритм Дейкстры
//\param g Граф, на котором осуществляется алгоритм
//\param q Приоритетная очередь 
//\param v Номер начальной вершины
//\return Массив списков переходов до нужных вершин
vector<int> Dijkstra(Graph<coo>& g, priority_q<int>& q, int v)
{
	vector<>
};