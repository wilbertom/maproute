#ifndef MR_TR_INPUT_WALKER_H
#define MR_TR_INPUT_WALKER_H

#include <vector>

#include <maproute/types.h>

//
// Walk through a vector of data while processing one element at a time.
// The idea is to have a simple interface where users can advance in the input
// without having to keep track of indexes.
//
// The user can advance in the input until ended returns true. From there on
// the user shouldn't call advance anymore unless he backtracks.
//
template <class T> class InputWalker {

private:
    std::vector<T> input;
    typename std::vector<T>::size_type current;
    typename std::vector<T>::size_type size;

public:
    InputWalker(std::vector<T> input);

    //
    // Advance the input and return the new element.
    //
    T advance();

    //
    // Go back one element in the input.
    //
    void backtrack();

    //
    // Returns true when the input is done and you shouldn't call
    // advance anymore.
    //
    bool ended();
};

#endif
