#pragma once
template <class T>
class Sequence
{
private:
	int size = 0;

public:
	Sequence() = default;
	virtual ~Sequence() {};

	virtual T GetFirst() const = 0;
	virtual T GetLast() const = 0;
	virtual T Get(int index) const = 0;
	virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const = 0;
	virtual int GetLength() const = 0;



	virtual void Set(T item, int index) const = 0;
	virtual void Append(T item) = 0;
	virtual void Prepend(T item) = 0;
	virtual void Copy(Sequence<T>* mas) = 0;
	virtual void InsertAt(T item, int index) = 0;
	virtual void Print() = 0;
	virtual void Enter() = 0;
	virtual Sequence <T>* Concat(Sequence<T>* list) const = 0;

};