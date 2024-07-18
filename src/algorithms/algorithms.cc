#include <map>
using std::map;

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
using std::count_if;
using std::all_of;



void algorithms()
{
    /**
     * Iterators demo
     */
     //iterators_demo();

     /**
      * counting entries
      */
//      count_target_value();
      counting_and_finding();

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

        auto twos = std::ranges::count(v, target);
        cout << "Approach 2: " << twos << "\n";
    }


    return 0;
}

int counting_and_finding()
{
    /**
     * Finding particular elements within a collection
     * Counting how many times elements in a collection occur
     */
    vector<int> v{2, 7, 1, 6, 2, -2, 4, 0, 2};

    // count how many entries are odd
    int odds = 0;
    for (auto elem: v)
    {
        if(elem % 2!= 0)
        {
            odds++;
            cout << "odds naive approach: " << odds << "\n";

        }
    }

    odds = count_if(begin(v), end(v),
                    [](auto elem)
                    {return  elem % 2 !=0;});

    cout << "odds if approach1 : " << odds << "\n";

    odds = std::ranges::count_if(
        v,
        [](auto elem)
        {return  elem % 2 != 0; }
        );

    cout << "odds if approach2 : " << odds << "\n";

    map<int, int> month_lengths
    {
            {1, 31},
            {2, 28},
            {3, 31},
            {4, 30},
            {5, 31},
            {6, 30},
            {7, 31},
            {8, 31},
            {9, 30},
            {10, 31},
            {11, 30}
    };

    int long_months = count_if(
        begin(month_lengths),
        end(month_lengths),
        [](auto elem)
        {return elem.second == 31;}
        );


    cout << "count if map : " << long_months << "\n";


    // are all, any or more or none of the values odd? (conclude from number of odd entries)

    bool allof, noneof, anyof;

    allof = (odds == v.size());
    noneof = (odds == 0);
    anyof = (odds > 0);

    /**
     * Allof
     */

    allof = all_of(
        begin(v),
        end(v),
        [](auto elem){return elem % 2 != 0;}
        );

    cout << "all_of v1: : " << allof << "\n";


    allof = std::ranges::all_of(
        v, [](auto elem)
        {return elem % 2 !=0;}
        );

    cout << "all_of v2: " << allof << "\n";

    /**
     * None of
     */

    noneof = none_of(
        begin(v),
        end(v),
        [](auto elem)
        {return  elem % 2!= 0;}
        );

    cout << "non_of v1: " << noneof << "\n";

    noneof = std::ranges::none_of(
        v,
        [](auto elem){return  elem %2 !=0;}
        );

    cout << "non_of v2: " << noneof << "\n";

    /**
     * Anyof
     */

    anyof = any_of(
        begin(v),
        end(v),
        [](auto elem){return elem % 2 != 0;}
        );

    cout << "any_of v1: " << anyof << "\n";

    anyof = std::ranges::any_of(
        v,
        [](auto elem){return elem %2 !=0;}
        );

    cout << "any_of v2: " << anyof << "\n";
    return 0;
}