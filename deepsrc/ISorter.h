#include "Sequence.h"
#include <functional>
//
// Created by ikmokhirio on 14.09.2019.
//

#ifndef MEPHI_LAB_0_ISORTER_H
#define MEPHI_LAB_0_ISORTER_H

template <typename TElement>
class ISorter {
protected:
public:
    /*
    virtual Sequence<TElement> *sort(Sequence<TElement> *seq,function<int(TElement, TElement)> compare_) = 0;

    bool isSortSuccess(Sequence<TElement> *seq,function<int(TElement, TElement)> compare_) {
        int length = seq->getLength();
        for(int i = 1; i < length; i++) {
            if (compare_(seq->get(i), seq->get(i - 1)) == -1) { //seq->get(i) < seq->get(i-1)
                return false;
            }
        }

        return true;
    }
    */
   // REFACTOR
   /*
   virtual Sequence<TElement> *sort(Sequence<TElement> *seq,ComparisonResult compare_(TElement first, TElement second)) = 0;

    bool isSortSuccess(Sequence<TElement> *seq,Result compare_ = 0) {
        int length = seq->getLength();
        for(int i = 1; i < length; i++) {
            if (compare_(seq->get(i), seq->get(i - 1)) == -1) { //seq->get(i) < seq->get(i-1)
                return false;
            }
        }

        return true;
    }
    */
   // REFACTOR

   virtual Sequence<TElement> *sort(Sequence<TElement> *seq,TElement compare_(TElement first, TElement second));

    bool isSortSuccess(Sequence<TElement> *seq,TElement compare_ = 0) {
        int length = seq->getLength();
        for(int i = 1; i < length; i++) {
            if (compare_(seq->get(i), seq->get(i - 1)) == -1) { //seq->get(i) < seq->get(i-1)
                return false;
            }
        }

        return true;
    }

};


#endif //MEPHI_LAB_0_ISORTER_H
