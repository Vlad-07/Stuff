// Made in August 2022


// Depending on the hardware you may get different results

#include <iostream>
#include <random>
#include <chrono>

int Sum(int, int);

int main(int argc, char** argv)
{
    int a = 5, b = 6, iterations = 1000, faults = 0;

    for (int i = 0; i < iterations; i++)
    {
        if (Sum(a, b) != (a + b))
            faults++;
    }

    std::cout << faults << '\n';
    return 1;
}

int Sum(int a, int b) // Stoopid func
{
    std::default_random_engine eng;
    eng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    int* p1 = new int, * p2 = new int;
    std::uniform_int_distribution<int64_t> rng(p1 < p2 ? (int64_t)p1 : (int64_t)p2, p1 > p2 ? (int64_t)p1 : (int64_t)p2);

    int* p3 = (int*)rng(eng);

    int* ap = (int*)rng(eng), * bp = (int*)rng(eng);
    *ap = a, * bp = b;

    0[p3] = (*ap << 1) + (*bp << 1);

    return (*p3 / (0x10 - 0xe));
}