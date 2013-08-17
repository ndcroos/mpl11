/*!
 * @file
 * This file defines the `boost::mpl11::size` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_SIZE_HPP
#define BOOST_MPL11_INTRINSIC_SIZE_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
namespace intrinsic {
    struct size : detail::tag_dispatched<size> {
        template <typename ...Args>
        struct apply
            : integral_c<
                decltype(apply_raw<
                    detail::tag_dispatched<size>, Args...
                >::type::value),
                apply_raw<
                    detail::tag_dispatched<size>, Args...
                >::type::value
            >
        { };
    };
} // end namespace intrinsic

template <typename Sequence, typename ...Args>
struct size
    : apply_raw<intrinsic::size, Sequence, Args...>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_SIZE_HPP
