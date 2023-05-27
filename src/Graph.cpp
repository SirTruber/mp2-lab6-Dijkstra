#include <Graph.h>
#include <random>
#include <priority_q.h>

struct coo
{
	double x;
	double y;
};

//\brief ��������������� ������� ���������� ������� ����� ����������� �������� �������
//\param g ������ ����
//\param N ���������� ����������� ������
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
	//�������� ��������� ������-�����
	for (size_t i = N - 1; i > 1; --i)
	{
		size_t j = rand() % i;
		swap(open[i], open[j]);
	}
	
	//�������� �����
	while (!open.empty())
	{
		int i = open.back();
		int j = close[rand() % close.size()];
		g.addE(rand() % 100, i, j);
		close.push_back(i);
		open.pop_back();
	}
}

//\brief ��������������� ������� ������������ ������������ ��������� ������ 
//\param g ���� � ����������� �������� �������
//\param f ����������� ������� ���������� 
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

//\brief �������� ��������
//\param g ����, �� ������� �������������� ��������
//\param q ������������ ������� 
//\param v ����� ��������� �������
//\return ������ ������� ��������� �� ������ ������
vector<int> Dijkstra(Graph<coo>& g, priority_q<int>& q, int v)
{
	vector<>
};