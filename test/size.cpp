/**
 * This file defines unit tests for the size metafunction.
 */

#include <mpl11/size.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                size<>::type,
                std::integral_constant<std::size_t, 0>
              >::value, "");

static_assert(std::is_same<
                size<int>::type,
                std::integral_constant<std::size_t, 1>
              >::value, "");

static_assert(std::is_same<
                size<float, char, void>::type,
                std::integral_constant<std::size_t, 3>
              >::value, "");
