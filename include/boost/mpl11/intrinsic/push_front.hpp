/*!
 * @file
 * This file defines the `boost::mpl11::push_front` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_PUSH_FRONT_HPP
#define BOOST_MPL11_INTRINSIC_PUSH_FRONT_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>


namespace boost { namespace mpl11 {
    namespace intrinsic {
        struct push_front : detail::tag_dispatched<push_front> {
            struct mpl11 {
                struct is_inplace_transformation;
            };
        };
    }

    template <typename Sequence, typename ...Args>
    struct push_front
        : apply_raw<intrinsic::push_front, Sequence, Args...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_PUSH_FRONT_HPP
