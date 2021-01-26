#pragma once
#include "Dynamic_Array.h"
#include "Sequence.h"

template <class T>
class ArraySequence : public Sequence<T>
{
protected:
	DynamicArray<T>* mas = 0;
	int size{ 0 };
public:
	ArraySequence() : Sequence<T>()
	{
		mas = new DynamicArray<T>(0);
		this->size = 0;
	}

	ArraySequence(int size) : Sequence<T>()
	{
		mas = new DynamicArray<T>(size);
		this->size = size;
	}

	ArraySequence(T* items, int size) : Sequence<T>()
	{
		mas = new DynamicArray<T>(items, size);
		this->size = size;
	}

	virtual ~ArraySequence() = default;

	virtual int GetLength() const override
	{
		return this->size;
	}

	virtual T GetFirst() const override
	{
		if (this->size == 0) throw std::out_of_range(IndexOutOfRange);

		return mas->Get(0);
	}

	virtual T GetLast() const override
	{

		if (this->size == 0) throw std::out_of_range(IndexOutOfRange);

		return mas->Get(this->size - 1);
	}

	virtual T Get(int index) const override
	{
		if (index < 0 || index >= this->size) throw std::out_of_range(IndexOutOfRange);

		return mas->Get(index);
	}



	virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override
	{
		if (startIndex < 0 || endIndex < 0 || startIndex >= this->size || endIndex >= this->size) throw std::out_of_range(IndexOutOfRange);

		int index(endIndex - startIndex + 1);
		Sequence<T>* getSub = new ArraySequence(0);
		for (int i = 0; i < index; ++i)
			getSub->Prepend(this->mas->Get(i + startIndex));

		return getSub;
	}

	virtual void Set(T item, int index) const override
	{
		this->mas->Set(index, item);
	}


	virtual void Append(T item) override
	{
		this->mas->Resize(this->size + 1);
		T item1 = this->mas->Get(0);
		T item2 = 0;
		for (int i = 0; i < this->size; ++i)
		{
			item2 = item1;
			item1 = mas->Get(i + 1);
			this->mas->Set(i + 1, item2);
		}
		this->mas->Set(0, item);
	}

	virtual void Prepend(T item) override
	{
		mas->Resize(size + 1);
		size = size + 1;
		mas->Set(size - 1, item);
	}

	virtual void InsertAt(T item, int index) override
	{
		if (index < 0 || index == this->size || index > this->size) throw std::out_of_range(IndexOutOfRange);

		ArraySequence<T>* leftMas = new ArraySequence{ 0 };
		for (int i = 0; i < index; ++i)
			leftMas->Prepend(this->mas->Get(i));

		leftMas->Prepend(item);


		ArraySequence<T>* rightMas = new ArraySequence(0);
		for (int i = index; i < this->size; ++i)
			rightMas->Prepend(mas->Get(i));

		ArraySequence<T>* newMas = new ArraySequence(0);
		for (int i = 0; i < leftMas->size; ++i)
			newMas->Prepend(leftMas->Get(i));


		for (int i = 0; i < rightMas->size; ++i)
			newMas->Prepend(rightMas->Get(i));

		++this->size;
		this->mas = newMas->mas;
	}


	virtual ArraySequence <T>* Concat(Sequence<T>* mas1) const override
	{
		int masSize = mas1->GetLength();

		ArraySequence <T>* newMas = new ArraySequence(0);
		for (int i = 0; i < this->size; ++i)
			newMas->Prepend(this->mas->Get(i));

		for (int i = 0; i < masSize; ++i)
			newMas->Prepend(mas1->Get(i));

		return newMas;
	}

	virtual void Print() override
	{
		mas->Print();
	}

	void Copy(Sequence<T>* mas) {
		for (int i = 0; i < mas->GetLength(); i++)
			InsertAt(mas->Get(i), i);
	}

	void Enter() {
		std::cout << "Enter size of the sequence: ";
		int count;
		std::cin >> count;

		for (int i = 0; i < count; i++) {
			T data;
			std::cout << "Element " << i << " : ";
			std::cin >> data;
			Prepend(data);
		}

	}

};