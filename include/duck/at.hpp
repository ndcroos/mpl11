/**
 * This file defines the at metafunction.
 */

#ifndef DUCK_AT_HPP
#define DUCK_AT_HPP

#include <duck/size.hpp>

#include <cstddef>
#include <type_traits>


namespace duck {

/**
 * Extract the parameter at index @p i from a parameter pack.
 * Precondition: @p i is smaller than the number of parameters.
 */
namespace detail {
template <typename Counter, typename ...> struct at_impl;

template <typename Distance, typename First, typename ...Rest>
struct at_impl<std::integral_constant<Distance, 0>, First, Rest...> {
    using type = First;
};

template <typename Distance, Distance pos, typename First, typename ...Rest>
struct at_impl<std::integral_constant<Distance, pos>, First, Rest...>
    : at_impl<std::integral_constant<Distance, pos - 1>, Rest...> { };
} // end namespace detail

template <std::size_t pos, typename ...Range>
struct at {
    static_assert(pos < size<Range...>::type::value, "Index out of range.");
    using type = typename detail::at_impl<
                    std::integral_constant<std::size_t, pos>, Range...>::type;
};

} // end namespace duck

#endif // !DUCK_AT_HPP
