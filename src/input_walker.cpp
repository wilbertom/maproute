#ifndef MR_TR_INPUT_WALKER_C
#define MR_TR_INPUT_WALKER_C

#include <maproute/input_walker.hpp>

template <class T> InputWalker<T>::InputWalker(std::vector<T> input) {
    this->input = input;
    this->current = 0;
    this->size = this->input.size();
}

template <class T> T InputWalker<T>::advance() {
    T el = this->input[this->current];
    this->current += 1;
    return el;
}

template <class T> void InputWalker<T>::backtrack() {
    this->current -= 1;
}

template <class T> bool InputWalker<T>::ended() {
    return this->current >= this->size;
}

#endif
