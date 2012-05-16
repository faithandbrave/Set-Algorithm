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
#include <utility>
#include <type_traits>
#include <boost/utility/enable_if.hpp>
#include <boost/range.hpp>
#include <boost/function_output_iterator.hpp>
#include <boost/move/move.hpp>

template <class F, class V>
struct is_unary_callable_base {
private:
	template <class F2, class V2>
    static auto check(F2&& f, V2 v) -> decltype((f(v)), std::true_type());

    static auto check(...) -> std::false_type;
public:
	typedef
		decltype(check(std::declval<F>(), std::declval<V>()))
	type;
};

template <class F, class V>
struct is_unary_callable : is_unary_callable_base<F, V>::type {};

template <class InputIterator1, class InputIterator2,
          class UnaryFunction, class Compare>
auto set_union(InputIterator1 first1, InputIterator1 last1,
               InputIterator2 first2, InputIterator2 last2,
               UnaryFunction&& f, Compare&& comp) ->
	typename boost::enable_if<is_unary_callable<
				UnaryFunction,
				decltype(*first1)
	>>::type
{
    std::set_union(
            first1, last1, first2, last2,
            boost::make_function_output_iterator(boost::move(f)),
            boost::move(comp));
}

template <class InputIterator1, class InputIterator2, class UnaryFunction>
auto set_union(InputIterator1 first1, InputIterator1 last1,
               InputIterator2 first2, InputIterator2 last2,
               UnaryFunction&& f) ->
	typename boost::enable_if<is_unary_callable<
				UnaryFunction,
				decltype(*first1)
	>>::type
{
    std::set_union(
            first1, last1, first2, last2,
            boost::make_function_output_iterator(boost::move(f)));
}

template <class InputRange1, class InputRange2,
          class UnaryFunction, class Compare>
auto set_union(const InputRange1& r1, const InputRange2& r2,
               UnaryFunction&& f, Compare&& comp) ->
	typename boost::enable_if<is_unary_callable<
				UnaryFunction,
				typename boost::range_value<InputRange1>::type
	>>::type
{
    ::set_union(boost::begin(r1), boost::end(r1),
              boost::begin(r2), boost::end(r2),
              boost::move(f), boost::move(comp));
}

template <class InputRange1, class InputRange2, class UnaryFunction>
auto set_union(const InputRange1& r1, const InputRange2& r2, UnaryFunction&& f)
	-> 	typename boost::enable_if<is_unary_callable<
				UnaryFunction,
				typename boost::range_value<InputRange1>::type
		>>::type
{
    ::set_union(boost::begin(r1), boost::end(r1),
              boost::begin(r2), boost::end(r2),
              boost::move(f));
}

template <class InputIterator1, class InputIterator2,
          class UnaryFunction, class Compare>
auto set_intersection(InputIterator1 first1, InputIterator1 last1,
                      InputIterator2 first2, InputIterator2 last2,
                      UnaryFunction&& f, Compare&& comp) ->
	typename boost::enable_if<is_unary_callable<
				UnaryFunction,
				decltype(*first1)
	>>::type
{
    std::set_intersection(
            first1, last1, first2, last2,
            boost::make_function_output_iterator(boost::move(f)),
            boost::move(comp));
}

template <class InputIterator1, class InputIterator2, class UnaryFunction>
auto set_intersection(InputIterator1 first1, InputIterator1 last1,
                      InputIterator2 first2, InputIterator2 last2,
                      UnaryFunction&& f) ->
	typename boost::enable_if<is_unary_callable<
				UnaryFunction,
				decltype(*first1)
	>>::type
{
    std::set_intersection(
            first1, last1, first2, last2,
            boost::make_function_output_iterator(boost::move(f)));
}

template <class InputRange1, class InputRange2,
          class UnaryFunction, class Compare>
auto set_intersection(const InputRange1& r1, const InputRange2& r2,
                       UnaryFunction&& f, Compare&& comp) ->
	typename boost::enable_if<is_unary_callable<
				UnaryFunction,
				typename boost::range_value<InputRange1>::type
	>>::type
{
    ::set_intersection(
            boost::begin(r1), boost::end(r1),
            boost::begin(r2), boost::end(r2),
            boost::move(f),
            boost::move(comp));

}

template <class InputRange1, class InputRange2, class UnaryFunction>
auto set_intersection(const InputRange1& r1, const InputRange2& r2,
                      UnaryFunction&& f) ->
	typename boost::enable_if<is_unary_callable<
				UnaryFunction,
				typename boost::range_value<InputRange1>::type
	>>::type
{
    ::set_intersection(
            boost::begin(r1), boost::end(r1),
            boost::begin(r2), boost::end(r2),
            boost::move(f));
}

template <class InputIterator1, class InputIterator2,
          class UnaryFunction, class Compare>
auto set_difference(InputIterator1 first1, InputIterator1 last1,
                    InputIterator2 first2, InputIterator2 last2,
                    UnaryFunction&& f, Compare&& comp) ->
	typename boost::enable_if<is_unary_callable<
				UnaryFunction,
				decltype(*first1)
	>>::type
{
    std::set_difference(
            first1, last1, first2, last2,
            boost::make_function_output_iterator(boost::move(f)),
            boost::move(comp));
}

template <class InputIterator1, class InputIterator2, class UnaryFunction>
auto set_difference(InputIterator1 first1, InputIterator1 last1,
                    InputIterator2 first2, InputIterator2 last2,
                    UnaryFunction&& f) ->
	typename boost::enable_if<is_unary_callable<
				UnaryFunction,
				decltype(*first1)
	>>::type
{
    std::set_difference(
            first1, last1, first2, last2,
            boost::make_function_output_iterator(boost::move(f)));
}

template <class InputRange1, class InputRange2,
          class UnaryFunction, class Compare>
auto set_difference(const InputRange1& r1, const InputRange2& r2,
                    UnaryFunction&& f, Compare&& comp) ->
	typename boost::enable_if<is_unary_callable<
				UnaryFunction,
				typename boost::range_value<InputRange1>::type
	>>::type
{
    ::set_difference(
            boost::begin(r1), boost::end(r1),
            boost::begin(r2), boost::end(r2),
            boost::move(f),
            boost::move(comp));
}

template <class InputRange1, class InputRange2, class UnaryFunction>
auto set_difference(const InputRange1& r1, const InputRange2& r2, UnaryFunction&& f) ->
	typename boost::enable_if<is_unary_callable<
				UnaryFunction,
				typename boost::range_value<InputRange1>::type
	>>::type
{
    ::set_difference(
            boost::begin(r1), boost::end(r1),
            boost::begin(r2), boost::end(r2),
            boost::move(f));
}

template <class InputIterator1, class InputIterator2,
          class UnaryFunction, class Compare>
auto set_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
                              InputIterator2 first2, InputIterator2 last2,
                              UnaryFunction&& f,
                              Compare&& comp) ->
	typename boost::enable_if<is_unary_callable<
				UnaryFunction,
				decltype(*first1)
	>>::type
{
    std::set_symmetric_difference(
            first1, last1,
            first2, last2,
            boost::make_function_output_iterator(boost::move(f)),
            boost::move(comp));
}

template <class InputIterator1, class InputIterator2, class UnaryFunction>
auto set_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
                              InputIterator2 first2, InputIterator2 last2,
                              UnaryFunction&& f) ->
	typename boost::enable_if<is_unary_callable<
				UnaryFunction,
				decltype(*first1)
	>>::type
{
    std::set_symmetric_difference(
            first1, last1,
            first2, last2,
            boost::make_function_output_iterator(boost::move(f)));
}

template <class InputRange1, class InputRange2,
          class UnaryFunction, class Compare>
auto set_symmetric_difference(const InputRange1& r1, const InputRange2& r2,
                              UnaryFunction&& f, Compare&& comp) ->
	typename boost::enable_if<is_unary_callable<
				UnaryFunction,
				typename boost::range_value<InputRange1>::type
	>>::type
{
    ::set_symmetric_difference(
            boost::begin(r1), boost::end(r1),
            boost::begin(r2), boost::end(r2),
            boost::move(f),
            boost::move(comp));
}

template <class InputRange1, class InputRange2, class UnaryFunction>
auto set_symmetric_difference(const InputRange1& r1, const InputRange2& r2,
                              UnaryFunction&& f) ->
	typename boost::enable_if<is_unary_callable<
				UnaryFunction,
				typename boost::range_value<InputRange1>::type
	>>::type
{
    ::set_symmetric_difference(
            boost::begin(r1), boost::end(r1),
            boost::begin(r2), boost::end(r2),
            boost::move(f));
}

#endif

