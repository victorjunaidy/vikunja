/* Copyright 2021 Victor
 *
 * This file is part of vikunja.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <alpaka/alpaka.hpp>

namespace vikunja
{
    namespace mem
    {
        namespace iterator
        {
            //! An iterator which returns a constant value
            //!
            //! \tparam TRed The return value of the function.
            template<typename TRed>
            class ConstantIterator : public std::iterator<
                                        std::random_access_iterator_tag,    // iterator_category
                                        TRed,                               // value_type
                                        TRed,                               // difference_type
                                        const TRed*,                        // pointer
                                        TRed>                               // reference
            {
            protected:
                TRed mValue;

            public:
                //-----------------------------------------------------------------------------
                //! Constructor.
                //!
                //! \param value Constant iterator's constant value.
                ALPAKA_FN_HOST_ACC ALPAKA_FN_INLINE
                ConstantIterator(TRed value)
                    : mValue(value)
                {
                }

                //-----------------------------------------------------------------------------
                //! Constructor.
                //!
                //! \param other The other iterator object.
                ALPAKA_FN_HOST_ACC ALPAKA_FN_INLINE ConstantIterator(const ConstantIterator& other) = default;

                //! Returns the index + a supplied offset.
                //!
                //! \param n The offset.
                ALPAKA_FN_HOST_ACC ALPAKA_FN_INLINE auto operator+(TRed n) const -> ConstantIterator
                {
                    return mValue;
                }

                //-----------------------------------------------------------------------------
                //! Returns the current element.
                //!
                //! Returns a reference to the current index.
                ALPAKA_FN_HOST_ACC ALPAKA_FN_INLINE auto operator*() -> decltype(mValue)&
                {
                    return mValue;
                }

                //-----------------------------------------------------------------------------
                //! Returns the current element.
                //!
                //! Returns a reference to the current index.
                ALPAKA_FN_HOST_ACC ALPAKA_FN_INLINE auto operator*() const
                {
                    return mValue;
                }
            };
        } // namespace iterator
    } // namespace mem
} // namespace vikunja
