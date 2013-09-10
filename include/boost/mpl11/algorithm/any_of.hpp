/*!
 * @file
 * Defines `boost::mpl11::algorithm::any_of`.
 */

#ifndef BOOST_MPL11_ALGORITHM_ANY_OF_HPP
#define BOOST_MPL11_ALGORITHM_ANY_OF_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Overloaded algorithm for querying a sequence about the truth value of
     * its elements.
     */
    template <typename Sequence, typename Predicate = detail::optional>
    struct any_of;

    /*!
     * @ingroup algorithm
     *
     * Returns whether any of the elements of a sequence satisfies
     * a given `Predicate`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `not_<none_of<Sequence, Predicate>>`.
     */
    template <typename Sequence, typename Predicate>
    struct any_of BOOST_MPL11_DOXYGEN_ONLY(<Sequence, Predicate>)
        : dispatch<tag::any_of, Sequence, Predicate>
    { };

    /*!
     * @ingroup algorithm
     *
     * Returns whether any of the elements of a sequence is a `true`-valued
     * boolean @ref IntegralConstant.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `any_of<Sequence, _1>`.
     */
    template <typename Sequence>
    struct any_of<Sequence>
        : dispatch<tag::any_of, Sequence>
    { };
}}} // end namespace boost::mpl11::algorithm

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/any_of.hpp>
#endif

#endif // !BOOST_MPL11_ALGORITHM_ANY_OF_HPP
