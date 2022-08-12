// Made in August 2022
// remake of the original

#include <iostream>
#include <random>
#include <chrono>

namespace Random
{
	std::default_random_engine eng;

	void Init()
	{
		eng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	}


	int Int()
	{
		std::uniform_int_distribution<int> rand(0, 100);
		return rand(eng);
	}

	int Int(int max)
	{
		std::uniform_int_distribution<int> rand(0, max);
		return rand(eng);
	}

	int Int(int min, int max)
	{
		std::uniform_int_distribution<int> rand(min, max);
		return rand(eng);
	}
}

class Timer
{
public:
	Timer()
	{
		Reset();
	}

	void Reset()
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	float Elapsed()
	{
		return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_Start).count() * 0.001f * 0.001f * 0.001f;
	}

	float ElapsedMs()
	{
		return Elapsed() * 1000.0f;
	}

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
};

enum SortType
{
	None = 0, Ascending, Descending
};

bool IsSorted(int* arr, int size, SortType type = SortType::Ascending)
{
	switch (type)
	{
	case None:
		std::cout << "Invalid sorting type!\n";
		break;
	case Ascending:
		for (int i = 1; i < size; i++)
		{
			if (arr[i - 1] > arr[i])
				return false;
		}
		return true;
	case Descending:
		for (int i = 1; i < size; i++)
		{
			if (arr[i - 1] < arr[i])
				return false;
		}
		return true;
	}
}

void Shuffle(int* arr, int size, int&& randLvl = 1)
{
	for (int i = 0; i < size * randLvl; i++)
		std::swap(arr[Random::Int(size - 1)], arr[Random::Int(size - 1)]);
}

void RandomSort(int* arr, int size)
{
	while (!IsSorted(arr, size))
		Shuffle(arr, size);
}

int main(int argc, char** argv)
{
	Random::Init();
	int arr[]{ 2, 5, 1, 3, 4, 9, 10, 7, 6, 11 };
	int size = sizeof(arr) / sizeof(int);

	Timer timer;
	RandomSort(arr, size);
	std::cout << timer.ElapsedMs() << " ms\n";

	for (int i = 0; i < size; i++)
		std::cout << arr[i] << ' ';

	return 0;
}