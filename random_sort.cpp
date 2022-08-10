// Made in December 2022

#include <iostream>
#include <random>

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

bool IsSorted(int v[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (v[i - 1] > v[i])
			return false;
	}
	return true;
}

int main()
{
	int n, v[100]{};
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> v[i];

	std::default_random_engine engine;
	std::uniform_int_distribution<int> random(0, n - 1);
	
	while (!IsSorted(v, n))
	{
		int from = random(engine);
		int to = random(engine);

		while (from == to) // don't copy from v[x] to v[x]
			to = random(engine);
		
		Swap(v[from], v[to]);
	}

	for (int i = 0; i < n; i++)
		std::cout << v[i] << ' ';
	
	return 0;
}