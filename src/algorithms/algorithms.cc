#include <vector>
using std::vector;
#include <algorithm>


#include <format>
using std::format;

#include "algorithms.h"

#include "iostream"
using std::cout;
using std::string;
using std::count;



void algorithms()
{
    /**
     * Iterators demo
     */
     //iterators_demo();

     /**
      * counting entries
      */
      count_target_value();

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

int count_target_value()
{
    cout << "Count how many entries have the target value (2)" << "\n";

    vector<int> v{2, 7, 1, 6, 2, -2, 4, 0, 2};

    /**
     * Approach 1 (Raw loops approach)
     */

    {
        int twos = 0;
        int const target = 2;
        for (size_t i = 0; i < v.size(); i++)
        {
            if (v[i] == target)
            {
                twos++;
                cout << "Approach 1: " << twos << "\n";
            }
        }
    }

    /**
     * Approach 2
     */
    {
        int const target = 2;
        //int twos = count(v.begin(), v.end(), target);
        //int twos = count(begin(v), end(v), target);

        int twos = std::ranges::count(v, target);
        cout << "Approach 2: " << twos << "\n";
    }


    return 0;
}