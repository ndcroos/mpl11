/*!
 * @file
 * Forward declares `boost::mpl11::shift_right`.
 */

#ifndef BOOST_MPL11_FWD_SHIFT_RIGHT_HPP
#define BOOST_MPL11_FWD_SHIFT_RIGHT_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup bitwise_operators
     *
     * Returns `T1 >> T2 >> ...Tn`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct shift_right;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_SHIFT_RIGHT_HPP