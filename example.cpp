// This algorithms is C++ standard set algorithm's UnaryFunction version.
//
//  Copyright Akira Takahashi 2012.
//  Use, modification and distribution is subject to 
//  the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//

#include <iostream>
#include <set>
#include <string>
#include "set_algo.hpp"

template <class T>
void print(const std::string& name, const std::set<T>& s)
{
    std::cout << name << ':';
    std::for_each(s.begin(), s.end(), [](const T& x) {
        std::cout << x << ' ';
    });
    std::cout << std::endl;
}

void union_example()
{
    std::set<int> a = {1, 2, 3};
    std::set<int> b = {4, 5, 6};
    std::set<int> result;

    set_union(a, b, [&](int x) { result.insert(x); });

    print("union", result);
}

void intersection_example()
{
    std::set<int> a = {1, 2, 3, 4};
    std::set<int> b = {4, 5, 6, 1};
    std::set<int> result;

    set_intersection(a, b, [&](int x) { result.insert(x); });

    print("intersection", result);
}

void difference_example()
{
    std::set<int> a = {1, 2, 3, 4, 5};
    std::set<int> b = {2, 3};
    std::set<int> result;

    set_difference(a, b, [&](int x) { result.insert(x); });

    print("difference", result);
}

void symmetric_difference_example()
{
    std::set<int> a = {1, 2, 3, 4, 5, 6};
    std::set<int> b = {2, 3, 4, 7, 8};
    std::set<int> result;

    set_symmetric_difference(a, b, [&](int x) { result.insert(x); });

    print("symmetric_difference", result);
}

int main()
{
    union_example();
    intersection_example();
    difference_example();
    symmetric_difference_example();
}

