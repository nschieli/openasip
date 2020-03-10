/*
    Copyright (c) 2002-2016 Tampere University of Technology.

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
 * @file InputFUBroker.hh
 *
 * Declaration of InputFUBroker class.
 *
 * @author Heikki Kultala 2016-2020 (heikki.kultala-no.spam-tuni.fi)
 * @note rating: red
 */

#ifndef TTA_FU_BROKER_HH
#define TTA_FU_BROKER_HH

#include "ResourceBroker.hh"
#include "DataDependenceGraph.hh"

namespace TTAMachine {
    class FunctionUnit;
}

class MoveNode;
class ProgramOperation;

/**
 * Input function unit broker.
 */
class FUBroker : public ResourceBroker {
public:
    FUBroker(std::string name, unsigned int initiationInterval = 0) :
        ResourceBroker(name, initiationInterval) {}
    virtual ~FUBroker() {}
protected:
    std::pair<bool, const TTAMachine::FunctionUnit*> findDstFUOfMove(
        const MoveNode& node,
        const TTAMachine::FunctionUnit* resFU,
        DataDependenceGraph::NodeSet& processedInputNodes) const;

    std::pair<bool, const TTAMachine::FunctionUnit*> findFUOfPO(
        ProgramOperation& po, const TTAMachine::FunctionUnit* resFU) const;
};

#endif
