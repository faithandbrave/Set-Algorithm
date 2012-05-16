#ifndef SET_ALGORITHM_INCLUDE
#define SET_ALGORITHM_INCLUDE

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

#include <algorithm>
#include <boost/range.hpp>
#include <boost/function_output_iterator.hpp>
#include <boost/move/move.hpp>

template <class InputIterator1, class InputIterator2,
          class UnaryFunction, class Compare>
void make_union(InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2, InputIterator2 last2,
                UnaryFunction&& f, Compare&& comp)
{
    std::set_union(
            first1, last1, first2, last2,
            boost::make_function_output_iterator(boost::move(f)),
            boost::move(comp));
}

template <class InputIterator1, class InputIterator2, class UnaryFunction>
void make_union(InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2, InputIterator2 last2,
                UnaryFunction&& f)
{
    std::set_union(
            first1, last1, first2, last2,
            boost::make_function_output_iterator(boost::move(f)));
}

template <class InputRange1, class InputRange2,
          class UnaryFunction, class Compare>
void make_union(const InputRange1& r1, const InputRange2& r2,
                UnaryFunction&& f, Compare&& comp)
{
    make_union(boost::begin(r1), boost::end(r1),
               boost::begin(r2), boost::end(r2),
               boost::move(f), boost::move(comp));
}

template <class InputRange1, class InputRange2, class UnaryFunction>
void make_union(const InputRange1& r1, const InputRange2& r2, UnaryFunction&& f)
{
    make_union(boost::begin(r1), boost::end(r1),
               boost::begin(r2), boost::end(r2),
               boost::move(f));
}

template <class InputIterator1, class InputIterator2,
          class UnaryFunction, class Compare>
void make_intersection(InputIterator1 first1, InputIterator1 last1,
                       InputIterator2 first2, InputIterator2 last2,
                       UnaryFunction&& f, Compare&& comp)
{
    std::set_intersection(
            first1, last1, first2, last2,
            boost::make_function_output_iterator(boost::move(f)),
            boost::move(comp));
}

template <class InputIterator1, class InputIterator2, class UnaryFunction>
void make_intersection(InputIterator1 first1, InputIterator1 last1,
                       InputIterator2 first2, InputIterator2 last2,
                       UnaryFunction&& f)
{
    std::set_intersection(
            first1, last1, first2, last2,
            boost::make_function_output_iterator(boost::move(f)));
}

template <class InputRange1, class InputRange2,
          class UnaryFunction, class Compare>
void make_intersection(const InputRange1& r1, const InputRange2& r2,
                       UnaryFunction&& f, Compare&& comp)
{
    make_intersection(
            boost::begin(r1), boost::end(r1),
            boost::begin(r2), boost::end(r2),
            boost::move(f),
            boost::move(comp));

}

template <class InputRange1, class InputRange2, class UnaryFunction>
void make_intersection(const InputRange1& r1, const InputRange2& r2,
                       UnaryFunction&& f)
{
    make_intersection(
            boost::begin(r1), boost::end(r1),
            boost::begin(r2), boost::end(r2),
            boost::move(f));
}

template <class InputIterator1, class InputIterator2,
          class UnaryFunction, class Compare>
void make_difference(InputIterator1 first1, InputIterator1 last1,
                     InputIterator2 first2, InputIterator2 last2,
                     UnaryFunction&& f, Compare&& comp)
{
    std::set_difference(
            first1, last1, first2, last2,
            boost::make_function_output_iterator(boost::move(f)),
            boost::move(comp));
}

template <class InputIterator1, class InputIterator2, class UnaryFunction>
void make_difference(InputIterator1 first1, InputIterator1 last1,
                     InputIterator2 first2, InputIterator2 last2,
                     UnaryFunction&& f)
{
    std::set_difference(
            first1, last1, first2, last2,
            boost::make_function_output_iterator(boost::move(f)));
}

template <class InputRange1, class InputRange2,
          class UnaryFunction, class Compare>
void make_difference(const InputRange1& r1, const InputRange2& r2,
                     UnaryFunction&& f, Compare&& comp)
{
    make_difference(
            boost::begin(r1), boost::end(r1),
            boost::begin(r2), boost::end(r2),
            boost::move(f),
            boost::move(comp));
}

template <class InputRange1, class InputRange2, class UnaryFunction>
void make_difference(const InputRange1& r1, const InputRange2& r2, UnaryFunction&& f)
{
    make_difference(
            boost::begin(r1), boost::end(r1),
            boost::begin(r2), boost::end(r2),
            boost::move(f));
}

template <class InputIterator1, class InputIterator2,
          class UnaryFunction, class Compare>
void make_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
                               InputIterator2 first2, InputIterator2 last2,
                               UnaryFunction&& f,
                               Compare&& comp)
{
    std::set_symmetric_difference(
            first1, last1,
            first2, last2,
            boost::make_function_output_iterator(boost::move(f)),
            boost::move(comp));
}

template <class InputIterator1, class InputIterator2, class UnaryFunction>
void make_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
                               InputIterator2 first2, InputIterator2 last2,
                               UnaryFunction&& f)
{
    std::set_symmetric_difference(
            first1, last1,
            first2, last2,
            boost::make_function_output_iterator(boost::move(f)));
}

template <class InputRange1, class InputRange2,
          class UnaryFunction, class Compare>
void make_symmetric_difference(const InputRange1& r1, const InputRange2& r2,
                               UnaryFunction&& f, Compare&& comp)
{
    make_symmetric_difference(
            boost::begin(r1), boost::end(r1),
            boost::begin(r2), boost::end(r2),
            boost::move(f),
            boost::move(comp));
}

template <class InputRange1, class InputRange2, class UnaryFunction>
void make_symmetric_difference(const InputRange1& r1, const InputRange2& r2,
                               UnaryFunction&& f)
{
    make_symmetric_difference(
            boost::begin(r1), boost::end(r1),
            boost::begin(r2), boost::end(r2),
            boost::move(f));
}

#endif

