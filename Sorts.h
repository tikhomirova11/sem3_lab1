#pragma once
#include "Sequence.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"

template <typename T>
Sequence <T>* BubbleSort(Sequence <T>* seq)
{
    for (int i = 0; i < seq->GetLength() - 1; i++)
    {
        for (int k = 0; k < seq->GetLength() - i - 1; k++)
        {
            if (seq->Get(k) > seq->Get(k + 1))
            {
                T tmp = seq->Get(k);
                seq->Set(seq->Get(k + 1), k);
                seq->Set(tmp, k + 1);
            }
        }
    }
    return seq;
}

template <typename T>
Sequence<T>* ShellSort(Sequence <T>* seq)
{
    int j;
    int step = (seq->GetLength()) / 2;    // начальное приращение сортировки

    while (step > 0)  // пока существует приращение
    {
        for (int i = 0; i < (seq->GetLength() - step); i++)
        {

            int j = i;
            while ((j >= 0) && (seq->Get(j) > seq->Get(j + step)))
            {
                T tmp = seq->Get(j);
                seq->Set(seq->Get(j + step), j);
                seq->Set(tmp, j + step);
                j = j--;
            }
        }

        step = step / 2;

    }
    return seq;
}

template <typename T>
Sequence <T>* HeapSort(Sequence <T>* seq)
{
    int sh = 0; // Смещение
    bool b;
    do
    {
        b = false;
        for (int i = 0; i < seq->GetLength(); i++)
        {
            if (i * 2 + 2 + sh < seq->GetLength())
            {
                if ((seq->Get(i + sh) > seq->Get(i * 2 + 1 + sh)) || (seq->Get(i + sh) > seq->Get(i * 2 + 2 + sh)))
                {
                    if (seq->Get(i * 2 + 1 + sh) < seq->Get(i * 2 + 2 + sh))
                    {
                        T tmp = seq->Get(i + sh);
                        seq->Set(seq->Get(i * 2 + 1 + sh), i + sh);
                        seq->Set(tmp, i * 2 + 1 + sh);

                        b = true;
                    }
                    else if (seq->Get(i * 2 + 2 + sh) < seq->Get(i * 2 + 1 + sh))
                    {
                        T tmp = seq->Get(i + sh);
                        seq->Set(seq->Get(i * 2 + 2 + sh), i + sh);
                        seq->Set(tmp, i * 2 + 2 + sh);

                        b = true;
                    }
                }
                
                if (seq->Get(i * 2 + 2 + sh) < seq->Get(i * 2 + 1 + sh))
                {
                    T tmp = seq->Get(i * 2 + 1 + sh);
                    seq->Set(seq->Get(i * 2 + 2 + sh), i * 2 + 1 + sh);
                    seq->Set(tmp, i * 2 + 2 + sh);

                    b = true;
                }
            }
            else if (i * 2 + 1 + sh < seq->GetLength())
            {
                if (seq->Get(i + sh) > seq->Get(i * 2 + 1 + sh))
                {
                    T tmp = seq->Get(i + sh);
                    seq->Set(seq->Get(i * 2 + 1 + sh), i + sh);
                    seq->Set(tmp, i * 2 + 1 + sh);

                    b = true;
                }
            }
        }
        if (!b) ++sh; // Смещение увеличивается, когда на текущем этапе сортировать больше нечего
    } while (sh + 2 < seq->GetLength()); // Конец сортировки

    return seq;
}