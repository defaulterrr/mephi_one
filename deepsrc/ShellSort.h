#include "ISorter.h"
//
// Created by ikmokhirio on 14.09.2019.
//

#ifndef MEPHI_LAB_0_SHELLSORT_H
#define MEPHI_LAB_0_SHELLSORT_H

template<typename TElement>
class ShellSort : public ISorter<TElement> {
public:
    /*
    Sequence<TElement> *sort(Sequence<TElement> *seq, function<int(TElement, TElement)> compare_) {
        int step, i, j;
        int length = seq->getLength();
        for (step = length / 2; step > 0; step /= 2) {
            for (i = step; i < length; i++) {
                for (j = i - step; j >= 0 && compare_(seq->get(j), seq->get(j + step)) ==
                                             1; j -= step) { //seq->get(j) > seq->get(j + step)
                    seq->swap(j, j + step);
                }
            }
        }
        return seq;
    }
    */


   // REFACTORED 
   /*
   Sequence<TElement> *sort(Sequence<TElement> *seq,ComparisonResult compare_(TElement first, TElement second)) {
        int step, i, j;
        int length = seq->getLength();
        for (step = length / 2; step > 0; step /= 2) {
            for (i = step; i < length; i++) {
                for (j = i - step; j >= 0 && compare_(seq->get(j), seq->get(j + step)) ==
                                             1; j -= step) { //seq->get(j) > seq->get(j + step)
                    seq->swap(j, j + step);
                }
            }
        }
        return seq;
    }
    */
    // REFACTORED 



    Sequence<TElement> *sort(Sequence<TElement> *seq,TElement compare_(TElement first, TElement second)) {
        int step, i, j;
        int length = seq->getLength();
        for (step = length / 2; step > 0; step /= 2) {
            for (i = step; i < length; i++) {
                for (j = i - step; j >= 0 && compare_(seq->get(j), seq->get(j + step)) ==
                                             1; j -= step) { //seq->get(j) > seq->get(j + step)
                    seq->swap(j, j + step);
                }
            }
        }
        return seq;
    }
};

#endif //MEPHI_LAB_0_SHELLSORT_H
