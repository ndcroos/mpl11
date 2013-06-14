/*!
 * @file
 * This file defines the `boost::mpl11::key` intrinsic.
 */

#ifndef BOOST_MPL11_INTRINSIC_KEY_HPP
#define BOOST_MPL11_INTRINSIC_KEY_HPP

#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace intrinsic {
    struct key : detail::tag_dispatched<key> {

    };
}

template <typename AssociativeSequence, typename ...Args>
struct key
    : apply_raw<intrinsic::key, AssociativeSequence, Args...>
{ };
}}}

#endif // !BOOST_MPL11_INTRINSIC_KEY_HPP
