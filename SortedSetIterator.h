#ifndef L1_SORTEDSETITERATOR_H
#define L1_SORTEDSETITERATOR_H

#endif //L1_SORTEDSETITERATOR_H

#pragma once

#include "SortedSet.h"

//DO NOT CHANGE THIS PART
class SortedSetIterator {
    friend class SortedSet;

private:
    const SortedSet &multime;
    int index;

    SortedSetIterator(const SortedSet &m);

public:
    void first();
    void next();
    TElem getCurrent();
    bool valid() const;
};