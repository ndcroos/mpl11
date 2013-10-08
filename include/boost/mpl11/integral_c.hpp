/*!
 * @file
 * Defines `boost::mpl11::integral_c`.
 */

#ifndef BOOST_MPL11_INTEGRAL_C_HPP
#define BOOST_MPL11_INTEGRAL_C_HPP

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c_fwd.hpp>
#include <boost/mpl11/intrinsic/category_of_fwd.hpp>


namespace boost { namespace mpl11 {
    template <typename I, I N>
    struct integral_c  : identity<integral_c<I, N>> {
        using value_type = I;
        static constexpr value_type value = N;
        constexpr operator value_type() const { return value; }
    };

    template <typename I, I N>
    struct dispatch<tag::category_of, integral_c<I, N>>
        : identity<category::integral_constant>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTEGRAL_C_HPP
