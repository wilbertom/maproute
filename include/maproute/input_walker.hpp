#ifndef MR_TR_INPUT_WALKER_H
#define MR_TR_INPUT_WALKER_H

#include <vector>

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
    // Returns the current element in the input.
    //
    T get_current() const;

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

template <class T> InputWalker<T>::InputWalker(std::vector<T> input) {
    this->input = input;
    this->current = 0;
    this->size = this->input.size();
}

template <class T> T InputWalker<T>::get_current() const {
    return this->input[this->current - 1];
}

template <class T> T InputWalker<T>::advance() {
    this->current += 1;
    return this->get_current();
}

template <class T> void InputWalker<T>::backtrack() {
    this->current -= 1;
}

template <class T> bool InputWalker<T>::ended() {
    return this->current >= this->size;
}

#endif
