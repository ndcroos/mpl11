/*!
 * @file
 * Defines `boost::mpl11::count_if`.
 */

#ifndef BOOST_MPL11_COUNT_IF_HPP
#define BOOST_MPL11_COUNT_IF_HPP

#include <boost/mpl11/fwd/count_if.hpp>

#include <boost/mpl11/add.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    namespace count_if_detail {
        template <typename Predicate>
        struct count_pred {
            template <typename N, typename Element>
            struct apply
                : if_t<apply_t<Predicate, Element>,
                    add<N, ulong<1>>, N
                >
            { };
        };
    } // end namespace count_if_detail

    template <typename Sequence, typename Predicate>
    struct count_if
        : foldl_t<
            Sequence, ulong<0>, count_if_detail::count_pred<Predicate>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COUNT_IF_HPP
