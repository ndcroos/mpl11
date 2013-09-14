/*!
 * @file
 * Defines `boost::mpl11::view::empty`.
 */

#ifndef BOOST_MPL11_VIEW_EMPTY_HPP
#define BOOST_MPL11_VIEW_EMPTY_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 { namespace view {
    /*!
     * @ingroup views
     *
     * Random access sequence containing no elements.
     */
    struct empty BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::view


#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace empty_detail { struct begin_end; }

template <>
struct dispatch<tag::begin, view::empty>
    : identity<empty_detail::begin_end>
{ };

template <>
struct dispatch<tag::end, view::empty>
    : identity<empty_detail::begin_end>
{ };

template <>
struct dispatch<tag::category_of, view::empty>
    : identity<category::random_access_sequence>
{ };

template <>
struct dispatch<tag::category_of, empty_detail::begin_end>
    : identity<category::random_access_iterator>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_EMPTY_HPP
