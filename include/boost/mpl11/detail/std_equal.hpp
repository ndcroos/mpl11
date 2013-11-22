/*!
 * @file
 * Defines `boost::mpl11::detail::std_equal`.
 */

#ifndef BOOST_MPL11_DETAIL_STD_EQUAL_HPP
#define BOOST_MPL11_DETAIL_STD_EQUAL_HPP

#include <boost/mpl11/fwd/equal.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Returns whether two iterator-delimited ranges are equal by comparing
     * their elements side-by-side.
     */
    template <
        typename F1, typename L1,
        typename F2, typename L2,
        bool = equal<F1, L1>::value,
        bool = equal<F2, L2>::value
    >
    struct std_equal;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/and.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename F1, typename L1, typename F2, typename L2, bool, bool>
    struct std_equal
        : false_
    { };

    template <typename F1, typename L1, typename F2, typename L2>
    struct std_equal<F1, L1, F2, L2, true, true>
        : true_
    { };

    namespace std_equal_detail {
        template <typename F1, typename L1, typename F2, typename L2>
        struct lazy_next_step
            : std_equal<
                next_t<F1>, L1,
                next_t<F2>, L2
            >
        { };
    } // end namespace std_equal_detail

    template <typename F1, typename L1, typename F2, typename L2>
    struct std_equal<F1, L1, F2, L2, false, false>
        : and_<
            equal<deref_t<F1>, deref_t<F2>>,
            std_equal_detail::lazy_next_step<F1, L1, F2, L2>
        >
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_STD_EQUAL_HPP
