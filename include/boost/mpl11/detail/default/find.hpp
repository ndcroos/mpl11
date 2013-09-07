/*!
 * @file
 * Defines the default implementation of `boost::mpl11::algorithm::find`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_FIND_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_FIND_HPP

#include <boost/mpl11/algorithm/find_if.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
template <typename Sequence, typename Element>
struct dispatch<detail::default_<tag::find>, Sequence, Element>
    : algorithm::find_if<Sequence, intrinsic::equal_to<Element, _1>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_FIND_HPP
