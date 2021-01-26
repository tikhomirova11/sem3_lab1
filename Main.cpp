#pragma once
#include<iostream>
#include <chrono>
#include"ArraySequence.h"
#include"Sequence.h"
#include"LinkedListSequence.h"
#include"Sorts.h"
#include "Test.h"

int CHECK(int choice, int left, int right)
{
	if ((choice < left) || (choice > right))
	{
		while ((choice < left) || (choice > right))
		{
			std::cout << "ERROR! WRONG NUMBER!\n Please, try again." << std::endl;
			std::cin >> choice;
		}
	}

	return choice;
}

template <typename T>
Sequence <T>* SortChoice(Sequence <T>* seq)
{
	int sort_choice;
	std::cout << "\nWhich sort do you want to use:" << std::endl;
	std::cout <<
		"1. Bubble sort" << std::endl <<
		"2. Shell sort" << std::endl <<
		"3. Heap sort" << std::endl;

	std::cin >> sort_choice;

	sort_choice = CHECK(sort_choice, 1, 3);

	std::cout << "\nYour choice: " << sort_choice << std::endl;

	if (sort_choice == 1)
	{
		BubbleSort(seq);
		double time_sort1 = time_sort(seq, 1);

		std::cout << "\nTime for BubbleSort is " << time_sort1 << " mircosecond \n";
	}

	if (sort_choice == 2)
	{
		ShellSort(seq);
		double time_sort2 = time_sort(seq, 2);

		std::cout << "\nTime for ShellSort is " << time_sort2 << " mircosecond \n";
	}

	if (sort_choice == 3)
	{
		HeapSort(seq);
		double time_sort3 = time_sort(seq, 3);

		std::cout << "\nTime for HeapSort is " << time_sort3 << " mircosecond \n";
	}

	std::cout << "Sorting result: ";
	seq->Print();

	return seq;
}


template<typename T>
double time_sort(Sequence<T>* mas, int choice_sort) {

	auto start = std::chrono::high_resolution_clock::now();

	if (choice_sort == 1)  BubbleSort(mas);
	if (choice_sort == 2)  ShellSort(mas);
	if (choice_sort == 3)  HeapSort(mas);

	auto finish = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
	double time_sort = duration.count();
	return time_sort;
}

int main()
{
	std::cout << "Hi! " << std::endl;

	int choice, RandomMasSize, RandomListSize, test_choice = 0;

	do
	{
		std::cout << "\n  Choose the operation:\n"
			"1. Enter array, sort it and knew time of sort \n"
			"2. Enter random array, sort it and knew time of sort\n"
			"3. Enter list, sort it and knew time of sort\n"
			"4. Enter random list, sort it and knew time of sort\n"
			"5. See Tests\n"
			"6. exit\n";

		std::cin >> choice;

		choice = CHECK(choice, 1, 6);

		std::cout << "\nYour choice: " << choice << std::endl;

		switch (choice)
		{
		case 1:

			Sequence<int> * mas1;
			mas1 = new ArraySequence<int>();

			mas1->Enter();
			mas1->Print();

			mas1 = SortChoice(mas1);

			break;

		case 2:

			std::cout << "Size of random array:  ";
			std::cin >> RandomMasSize;

			Sequence<int>* RandomMas1;
			RandomMas1 = new ArraySequence<int>(0);

			for (int i(0); i < RandomMasSize; ++i)
				RandomMas1->Prepend(rand());


			std::cout << "Random array: \n";
			RandomMas1->Print();

			RandomMas1 = SortChoice(RandomMas1);


			break;

		case 3:

			Sequence<int> * list1;
			list1 = new LinkedListSequence<int>();

			list1->Enter();
			list1->Print();

			list1 = SortChoice(list1);

			break;

		case 4:

			std::cout << "Size of random List:  ";
			std::cin >> RandomListSize;

			Sequence<int>* RandomList1;
			RandomList1 = new LinkedListSequence<int>();

			for (int i(0); i < RandomListSize; ++i)
				RandomList1->Prepend(rand());


			std::cout << "Random list: \n";
			RandomList1->Print();

			RandomList1 = SortChoice(RandomList1);

			break;
		case 5:
			std::cout << " Choose the test:\n"
				"1. Test for Bubble sort \n"
				"2. Test for Shell sort\n"
				"3. Test for Heap sort\n"
				"4. Test for all sorts\n";
			std::cin >> test_choice;

			test_choice = CHECK(test_choice, 1, 4);

			std::cout << "\nYour choice: " << test_choice << std::endl;

			if (test_choice == 1) TestBubbleSort();
			if (test_choice == 2) TestShellSort();
			if (test_choice == 3) TestHeapSort();
			break;

		case 6:
			std::cout << "Thank you for using this program! Bye! ";
		}
	} while (choice != 6);

}
