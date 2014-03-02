/*!
 * @file
 * Defines the methods of the @ref Foldable typeclass.
 */

#ifndef BOOST_MPL11_FOLDABLE_HPP
#define BOOST_MPL11_FOLDABLE_HPP

#include <boost/mpl11/fwd/foldable.hpp>

#include <boost/mpl11/bool.hpp>       // required by fwd/foldable.hpp
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/functional.hpp> //
#include <boost/mpl11/logical.hpp>    //


namespace boost { namespace mpl11 {
    template <typename f, typename state, typename structure>
    struct foldr :
        Foldable<typename datatype<typename structure::type>::type>::
        template foldr_impl<f, state, structure>
    { };

    template <typename f, typename state, typename structure>
    struct foldl :
        Foldable<typename datatype<typename structure::type>::type>::
        template foldl_impl<f, state, structure>
    { };

    namespace foldable_detail {
        template <typename ...xs>
        struct holder {
            using type = holder;

            template <typename x>
            using append = holder<xs..., x>;

            template <template <typename ...> class f>
            using into = f<xs...>;
        };

        struct fill_holder {
            using type = fill_holder;
            template <typename Holder, typename X>
            using apply = typename Holder::type::template append<X>;
        };
    } // end namespace foldable_detail

    template <typename structure, typename f>
    struct unpack
        : foldl<
            foldable_detail::fill_holder,
            foldable_detail::holder<>,
            structure
        >::type::template into<f::type::template apply>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FOLDABLE_HPP
