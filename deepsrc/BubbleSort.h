#include "ISorter.h"
//
// Created by ikmokhirio on 14.09.2019.
//

#ifndef MEPHI_LAB_0_BUBBLESORT_H
#define MEPHI_LAB_0_BUBBLESORT_H

template <typename TElement>
class BubbleSort: public ISorter<TElement> {
public:

    Sequence<TElement> *sort(Sequence<TElement> *seq,TElement compare_(TElement first, TElement second)) {
        int length = seq->getLength();
        for (int i = 0; i < (length - 1); i++) {
            for (int j = (length - 1); j > i; j--) {
                if (compare_(seq->get(j - 1), seq->get(j)) == 1) //seq->get(j - 1) > seq->get(j)
                {
                    seq->swap(j-1,j);
                }
            }
        }
        return seq;
    }
};


#endif //MEPHI_LAB_0_BUBBLESORT_H
