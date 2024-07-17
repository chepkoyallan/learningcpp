#include <vector>
using std::vector;
#include <algorithm>

#include <format>
using std::format;

#include "algorithms.h"
#include "iostream"
using std::cout;
using std::string;



void algorithms()
{
    /**
     * Iterators demo
     */
     int i = 10;
     iterators_demo();
}

int iterators_demo()
{
    cout << "Iterators Demo" << "\n";

    vector<int> v{2, 7, 1, 6, 2, -2, 4, 0, 2};

    // begin returns an iterator (it)
    auto it = v.begin();

    // dereference it
    auto element = *it;

    cout << element << '\n';

    it++;

    element = *it;

    cout << element << '\n';

    return 0;
}