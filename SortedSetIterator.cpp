#include "SortedSetIterator.h"
#include <stdexcept>

using namespace std;

/**
 * Constructor
 * Worst case: θ(1)
 * Best case: θ(1)
 * Average case: θ(1)
 * Total: θ(1)
 * */
SortedSetIterator::SortedSetIterator(const SortedSet &m) : multime(m) {
    index = 0;
}


/**
 * Set iterator to first position
 * Worst case: θ(1)
 * Best case: θ(1)
 * Average case: θ(1)
 * Total: θ(1)
 * */
void SortedSetIterator::first() {
    if (multime.isEmpty())
        throw std::out_of_range("first(): Index out of range for " + to_string(index));
    index = 0;
}


/**
 * Increment current position
 * Worst case: θ(1)
 * Best case: θ(1)
 * Average case: θ(1)
 * Total: θ(1)
 * */
void SortedSetIterator::next() {
    if (!valid()) {
        throw std::out_of_range("next(): Index out of range for " + to_string(index));
    }
    index++;
}


/**
 * Return element on current position
 * Worst case: θ(1)
 * Best case: θ(1)
 * Average case: θ(1)
 * Total: θ(1)
 * */
TElem SortedSetIterator::getCurrent() {
    if (valid())
        return multime.array[index];
    else
        throw std::out_of_range("getCurrent(): Index out of range for " + to_string(index));
}


/**
 * Check if current index is valid
 * Worst case: θ(1)
 * Best case: θ(1)
 * Average case: θ(1)
 * Total: θ(1)
 * */
bool SortedSetIterator::valid() const {
    if (multime.isEmpty())
        return false;
    if (index < 0 || index >= multime.nrElems) {
        return false;
    }
    return true;
}
