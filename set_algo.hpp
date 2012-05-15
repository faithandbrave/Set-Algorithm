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

#include <iterator>
#include <utility>
#include <algorithm>
#include <boost/range.hpp>

namespace set_algo_detail {
    template <class UnaryFunction>
    class function_call_iterator
            : public std::iterator<std::output_iterator_tag,
                                   void, void, void, void>
    {
        UnaryFunction f_;

    public:
        explicit function_call_iterator(UnaryFunction&& f)
            : f_(std::forward<UnaryFunction>(f)) {}

        template <class T>
        function_call_iterator& operator=(const T& x)
        {
            f_(x);
            return *this;
        }

        template <class T>
        function_call_iterator& operator=(T&& x)
        {
            f_(std::move(x));
            return *this;
        }

        function_call_iterator& operator*()
            { return *this; }

        function_call_iterator& operator++()
            { return *this; }

        function_call_iterator operator++(int)
            { return *this; }
    };
}

template <class InputIterator1, class InputIterator2,
          class UnaryFunction, class Compare>
void make_union(InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2, InputIterator2 last2,
                UnaryFunction&& f, Compare&& comp)
{
    std::set_union(
            first1, last1, first2, last2,
            set_algo_detail::function_call_iterator<UnaryFunction>(std::move(f)),
            std::move(comp));
}

template <class InputIterator1, class InputIterator2, class UnaryFunction>
void make_union(InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2, InputIterator2 last2,
                UnaryFunction&& f)
{
    std::set_union(
            first1, last1, first2, last2,
            set_algo_detail::function_call_iterator<UnaryFunction>(std::move(f)));
}

template <class InputRange1, class InputRange2,
          class UnaryFunction, class Compare>
void make_union(const InputRange1& r1, const InputRange2& r2,
                UnaryFunction&& f, Compare&& comp)
{
    make_union(boost::begin(r1), boost::end(r1),
               boost::begin(r2), boost::end(r2),
               std::move(f), std::move(comp));
}

template <class InputRange1, class InputRange2, class UnaryFunction>
void make_union(const InputRange1& r1, const InputRange2& r2, UnaryFunction&& f)
{
    make_union(boost::begin(r1), boost::end(r1),
               boost::begin(r2), boost::end(r2),
               std::move(f));
}

template <class InputIterator1, class InputIterator2,
          class UnaryFunction, class Compare>
void make_intersection(InputIterator1 first1, InputIterator1 last1,
                       InputIterator2 first2, InputIterator2 last2,
                       UnaryFunction&& f, Compare&& comp)
{
    std::set_intersection(
            first1, last1, first2, last2,
            set_algo_detail::function_call_iterator<UnaryFunction>(std::move(f)),
            std::move(comp));
}

template <class InputIterator1, class InputIterator2, class UnaryFunction>
void make_intersection(InputIterator1 first1, InputIterator1 last1,
                       InputIterator2 first2, InputIterator2 last2,
                       UnaryFunction&& f)
{
    std::set_intersection(
            first1, last1, first2, last2,
            set_algo_detail::function_call_iterator<UnaryFunction>(std::move(f)));
}

template <class InputRange1, class InputRange2,
          class UnaryFunction, class Compare>
void make_intersection(const InputRange1& r1, const InputRange2& r2,
                       UnaryFunction&& f, Compare&& comp)
{
    make_intersection(
            boost::begin(r1), boost::end(r1),
            boost::begin(r2), boost::end(r2),
            std::move(f),
            std::move(comp));

}

template <class InputRange1, class InputRange2, class UnaryFunction>
void make_intersection(const InputRange1& r1, const InputRange2& r2,
                       UnaryFunction&& f)
{
    make_intersection(
            boost::begin(r1), boost::end(r1),
            boost::begin(r2), boost::end(r2),
            std::move(f));

}

template <class InputIterator1, class InputIterator2,
          class UnaryFunction, class Compare>
void make_difference(InputIterator1 first1, InputIterator1 last1,
                     InputIterator2 first2, InputIterator2 last2,
                     UnaryFunction&& f, Compare&& comp)
{
    std::set_difference(
            first1, last1, first2, last2,
            set_algo_detail::function_call_iterator<UnaryFunction>(std::move(f)),
            std::move(comp));
}

template <class InputIterator1, class InputIterator2, class UnaryFunction>
void make_difference(InputIterator1 first1, InputIterator1 last1,
                     InputIterator2 first2, InputIterator2 last2,
                     UnaryFunction&& f)
{
    std::set_difference(
            first1, last1, first2, last2,
            set_algo_detail::function_call_iterator<UnaryFunction>(std::move(f)));
}

template <class InputRange1, class InputRange2,
          class UnaryFunction, class Compare>
void make_difference(const InputRange1& r1, const InputRange2& r2,
                     UnaryFunction&& f, Compare&& comp)
{
    make_difference(
            boost::begin(r1), boost::end(r1),
            boost::begin(r2), boost::end(r2),
            std::move(f),
            std::move(comp));
}

template <class InputRange1, class InputRange2, class UnaryFunction>
void make_difference(const InputRange1& r1, const InputRange2& r2, UnaryFunction&& f)
{
    make_difference(
            boost::begin(r1), boost::end(r1),
            boost::begin(r2), boost::end(r2),
            std::move(f));
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
            set_algo_detail::function_call_iterator<UnaryFunction>(std::move(f)),
            std::move(comp));
}

template <class InputIterator1, class InputIterator2, class UnaryFunction>
void make_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
                               InputIterator2 first2, InputIterator2 last2,
                               UnaryFunction&& f)
{
    std::set_symmetric_difference(
            first1, last1,
            first2, last2,
            set_algo_detail::function_call_iterator<UnaryFunction>(std::move(f)));
}

template <class InputRange1, class InputRange2,
          class UnaryFunction, class Compare>
void make_symmetric_difference(const InputRange1& r1, const InputRange2& r2,
                               UnaryFunction&& f, Compare&& comp)
{
    make_symmetric_difference(
            boost::begin(r1), boost::end(r1),
            boost::begin(r2), boost::end(r2),
            std::move(f),
            std::move(comp));
}

template <class InputRange1, class InputRange2, class UnaryFunction>
void make_symmetric_difference(const InputRange1& r1, const InputRange2& r2,
                               UnaryFunction&& f)
{
    make_symmetric_difference(
            boost::begin(r1), boost::end(r1),
            boost::begin(r2), boost::end(r2),
            std::move(f));
}

#endif

