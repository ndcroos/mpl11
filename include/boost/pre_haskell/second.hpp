/*!
 * @file
 * Defines `boost::mpl11::second`.
 */

#ifndef BOOST_MPL11_SECOND_HPP
#define BOOST_MPL11_SECOND_HPP

#include <boost/mpl11/fwd/second.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Pair>
    struct second
        : class_of<Pair>::type::template second_impl<Pair>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SECOND_HPP