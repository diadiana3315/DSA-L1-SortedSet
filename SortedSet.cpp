#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <iostream>

/**
 * Constructor
 * Worst case: θ(1)
 * Best case: θ(1)
 * Average case: θ(1)
 * Total: θ(1)
 * */
SortedSet::SortedSet(Relation r) {
    cap = 5;
    nrElems = 0;
    array = new TComp[5]{0};
    this->r = r;
}


/**
 * Add elem to SortedSet
 * Worst case: θ(n)
 * Best case: θ(1)
 * Average case: θ(n)
 * Total: O(n)
 * */
bool SortedSet::add(TComp elem) {
    if (search(elem))
        return false;

    resize();

    if (nrElems == 0) {
        array[0] = elem;
    }
    else {
        int i;
        for (i = nrElems - 1; i >= 0; i--)
            if (r(elem, array[i])) {
                array[i + 1] = array[i];
            }
            else break;
        array[i + 1] = elem;
    }
    nrElems++;

    return true;
}

/**
 * Resize SortedSet
 * Worst case: θ(n)
 * Best case: θ(1)
 * Average case: O(n)
 * Total: O(n)
 * */
void SortedSet::resize() {
    if (nrElems == cap)
        cap *= 2;
    else if (nrElems < cap / 4)
        cap /= 2;
    else return;

    auto *newvec = new TComp[cap];
    for(int i = 0; i<nrElems; i++){
        newvec[i] = array[i];
    }
    delete[]array;
    array = newvec;
}

/**
 * Remove elem from SortedSet if elem exists
 * Worst case: θ(n)
 * Best case: θ(n)
 * Average case: θ(n)
 * Total: θ(n)
 * */
bool SortedSet::remove(TComp elem) {
    int pos = -1;
    for(int i = 0; i < nrElems; i++){
        if(array[i] == elem){
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        for (int i = pos; i < nrElems; i++)
            array[i] = array[i + 1];
        nrElems--;
        resize();
        return true;
    }
    return false;
}


/**
 * Binary search
 * Worst case: θ(log n)
 * Best case: θ(1)
 * Average case: θ(log n)
 * Total: O(log n)
 * */
bool SortedSet::search(TComp elem) const {
    int low = 0, high = nrElems - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (elem == array[mid]) {
            return true;
        } else if (!r(elem, array[mid]))
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}


/**
 * Return length of SortedSet
 * Worst case: θ(1)
 * Best case: θ(1)
 * Average case: θ(1)
 * Total: θ(1)
 * */
int SortedSet::size() const {
    return nrElems;
}



/**
 * Return true if SortedSet is empty, false otherwise
 * Worst case: θ(1)
 * Best case: θ(1)
 * Average case: θ(1)
 * Total: θ(1)
 * */
bool SortedSet::isEmpty() const {
    return nrElems == 0;
}


/**
 * Return an iterator for this SortedSet
 * Worst case: θ(1)
 * Best case: θ(1)
 * Average case: θ(1)
 * Total: θ(1)
 * */
SortedSetIterator SortedSet::iterator() const {
    return SortedSetIterator(*this);
}


/**
 * Destructor
 * Worst case: θ(n)
 * Best case: θ(n)
 * Average case: θ(n)
 * Total: θ(n)
 * */
SortedSet::~SortedSet() {
    delete[] array;
}

/**
 * Check if two SortedSets are equal
 * Worst case: θ(n)
 * Best case: θ(1)
 * Average case: O(n)
 * Total: O(n)
 *
 */
bool SortedSet::checkEqual(const SortedSet& other ) const {
    if (nrElems != other.nrElems) {
        return false;
    }
    int i = 0;
    while(i < nrElems){
            if (array[i] != other.array[i]) {
                return false;
            }
            i++;
    }
    return true;
}

/**
 * function checkEqual(const SortedSet& other)
 * if nrElems != other.nrElems
 *      return false
 * end-if
 * i<-0
 * while i < nrElems execute
 *          if array[i] != other.array[j] then
 *              return false
 *          end-if
 *          i<-i+1
 * end-while
 * return true
 * end-function
 *
 *
 *
 * pre: array[i], other.array[i] ∈ TComp
 * post: true, if sortedSet = other.sortedSet
 *       false, otherwise
 **/






