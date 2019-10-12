#include "ISorter.h"

template <typename Comparable>
class MergeSort: public ISorter<Comparable> {
public:
        Sequence<Comparable> *sort(Sequence<Comparable> *seq, Comparable compare_(Comparable first, Comparable second)){
                Comparable i, key, j;
                for (i = 1;i< seq->getLength(); i++){
                    key = seq->get(i);
                    j = i - 1;

                    while (j>= 0 && compare_(seq->get(j),key))
                    {
                        seq->setElement(j+1,seq->get(j));
                        j = j - 1;
                    }

                    seq->setElement(j+1,key);
                    
                }
                return seq;
        }
};