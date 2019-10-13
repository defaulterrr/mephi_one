#include "ISorter.h"

template <typename Comparable>
class InsertSort: public ISorter<Comparable> {
public:
        Sequence<Comparable> *sort(Sequence<Comparable> *seq, Comparable compare_(Comparable first, Comparable second)){
                /*Comparable i, key, j;
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
                return seq;*/

                // int counter=0;
                //     for(int i=1;i<seq->getLength();i++){
                //         for(int j=i; j>0 && compare_(seq->get(j-1),seq->get(j));j--){
                //             counter++;
                //             // int tmp=seq[j-1];
                //             // seq[j-1]=seq[j];
                //             // seq[j]=tmp;
                //             seq->swap(j,j-1);
                //         }
                //     }

                int temp,item; 
                    for (int counter = 1; counter < seq->getLength(); counter++)
                    {
                        temp = seq->get(counter);
                        item = counter-1; 
                        while(item >= 0 && compare_(seq->get(item),temp)) 
                        {
                            seq->setElement(item + 1,seq->get(item));
                            seq->setElement(item,temp);
                            item--;
                        }
                    }


                 return seq;
        }
};