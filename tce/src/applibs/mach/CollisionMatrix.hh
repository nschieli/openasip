/*
    Copyright (c) 2002-2009 Tampere University.

    This file is part of TTA-Based Codesign Environment (TCE).

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
 */
/**
 * @file CollisionMatrix.hh
 *
 * Declaration of CollisionMatrix class.
 *
 * @author Pekka J��skel�inen 2006 (pekka.jaaskelainen-no.spam-tut.fi)
 * @note rating: red
 */

#ifndef TTA_COLLISION_MATRIX_HH
#define TTA_COLLISION_MATRIX_HH

#include <vector>
#include <deque>

#include "BitMatrix.hh"

namespace TTAMachine{
    class ResourceVectorSet;
}
class FUReservationTableIndex;

/**
 * Represents a collision matrix.
 */
class CollisionMatrix : public BitMatrix {
public:

    CollisionMatrix(
        FUReservationTableIndex& reservationTables, std::size_t index);

    CollisionMatrix(std::size_t width, std::size_t height, bool value);

    virtual ~CollisionMatrix();

    virtual bool isCollision(std::size_t row, std::size_t column) const;
};

#endif
