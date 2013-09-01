/*!
 * @file
 * Defines `boost::mpl11::intrinsic::clear`.
 */

#ifndef BOOST_MPL11_INTRINSIC_CLEAR_HPP
#define BOOST_MPL11_INTRINSIC_CLEAR_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/erase.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Returns an empty sequence concept-identical to `Sequence`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
       @code
            erase<
                Sequence,
                begin<Sequence>::type,
                end<Sequence>::type
            >
       @endcode
     */
    template <typename Sequence>
    struct clear
        : detail::tag_dispatched<tag::clear, Sequence>::template
          with_default<
            lazy_always<
                erase<
                    Sequence,
                    typename begin<Sequence>::type,
                    typename end<Sequence>::type
                >
            >
          >
    { };
}}} // end namespace boost::mpl11::intrinsic

#endif // !BOOST_MPL11_INTRINSIC_CLEAR_HPP