/**
 * This file defines the empty metafunction.
 */

#ifndef DUCK_EMPTY_HPP
#define DUCK_EMPTY_HPP

#include <type_traits>


namespace duck {

/**
 * Determine whether a parameter pack is empty.
 */
template <typename ...> struct empty { using type = std::false_type; };
template <> struct empty<> { using type = std::true_type; };

} // end namespace duck

#endif // !DUCK_EMPTY_HPP
