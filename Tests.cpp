#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Sorts.h"

int TestArraySequence() {
	int* frst{ new int[8] {22,25,4,8,0,19,55,10} };
	ArraySequence<int> mas1(frst, 8);

	int* scnd{ new int[3] {2,32,7} };
	ArraySequence<int> mas2(scnd, 3);

	if (mas1.GetFirst() == 22)
		std::cout << "Test GetFirst: success" << "\n";
	else {
		std::cout << "Test GetFirst: fail" << "\n";
	};

	if (mas1.GetLast() == 10)
		std::cout << "Test GetLast: success" << "\n";
	else {
		std::cout << "Test GetLast: fail" << "\n";
	};

	if (mas1.Get(4) == 8)
		std::cout << "Test Get: success" << "\n";
	else {
		std::cout << "Test Get: fail" << "\n";
	};

	mas1.GetSubsequence(3, 7);
	if (mas1.Get(3) == 4 && mas1.Get(4) == 8 && mas1.Get(5) == 0 && mas1.Get(6) == 19 && mas1.Get(7) == 55)
		std::cout << "Test GetSubSequence: success" << "\n";
	else {
		std::cout << "Test GetSubSequence: fail" << "\n";
	};

	if (mas1.GetLength() == 8)
		std::cout << "Test GetLength: success" << "\n";
	else {
		std::cout << "Test GetLength: fail" << "\n";
	};

	mas1.Append(28);
	if (mas1.GetFirst() == 28)
		std::cout << "Test Append: success" << "\n";
	else {
		std::cout << "Test Append: fail" << "\n";
	};

	mas1.Prepend(17);
	if (mas1.GetLast() == 17)
		std::cout << "Test Prepend: success" << "\n";
	else {
		std::cout << "Test Prepend: fail" << "\n";
	};

	int data = 44;
	mas1.InsertAt(data, 7);
	if (mas1.Get(4) == 11)
		std::cout << "Test InsertAt: success" << "\n";
	else {
		std::cout << "Test InsertAt: fail" << "\n";
	};

	ArraySequence<int>* p2 = mas1.Concat(&mas2);
	if (p2->Get(0) == 28 && p2->Get(1) == 22 && p2->Get(2) == 25 && p2->Get(3) == 4
		&& p2->Get(4) == 8 && p2->Get(5) == 0 && p2->Get(6) == 19 && p2->Get(7) == 55
		&& p2->Get(8) == 10 && p2->Get(9) == 17 && p2->Get(10) == 2 && p2->Get(11) == 32 && p2->Get(12) == 7)
		std::cout << "Test Concat: success" << "\n";
	else {
		std::cout << "Test Concat: fail" << "\n";
	};


	DynamicArray<int> mas3(2);
	if (mas3.Get(0) == -842150451 && mas3.Get(1) == -842150451)
		std::cout << "Test Creation constructor: success" << "\n";
	else {
		std::cout << "Test Creation constructor: fail" << "\n";
	};

	delete[10] frst;
	delete[3] scnd;

	return 0;
}

int TestDynamicArray() {
	int* frst{ new int[8] {22,25,4,8,0,19,55,10} };
	DynamicArray<int> mas1(frst, 8);

	if (mas1.GetLength() == 8)
		std::cout << "Test GetLength: success" << "\n";
	else {
		std::cout << "Test GetLength: fail" << "\n";
	};

	if (mas1.Get(4) == 8)
		std::cout << "Test Get: success" << "\n";
	else {
		std::cout << "Test Get: fail" << "\n";
	};

	mas1.Resize(7);
	if (mas1.GetLength() == 7)
		std::cout << "Test Resize: success" << "\n";
	else {
		std::cout << "Test Resize: fail" << "\n";
	};

	int data = 44;
	mas1.Set(5, data);
	if (mas1.Get(5) == 44)
		std::cout << "Test Set: success" << "\n";
	else {
		std::cout << "Test Set: fail" << "\n";
	};

	DynamicArray<int> mas2(2);
	if (mas2.Get(0) == -842150451 && mas2.Get(1) == -842150451)
		std::cout << "Test Creation constructor: success" << "\n";
	else {
		std::cout << "Test Creation constructor: fail" << "\n";
	};
	//-842150451

	delete[5] frst;

	return 0;
}

int TestLinkedlist() {
	int* frst{ new int[8] {22,25,4,8,0,19,55,10} };
	int* scnd{ new int[5] {5,11,8,9,2} };

	LinkedList<int> list1{ frst,6 };
	LinkedList<int> list2{ scnd,5 };

	if (list1.GetFirst() == 22)
		std::cout << "Test GetFirst: success" << "\n";
	else {
		std::cout << "Test GetFirst: fail" << "\n";
	};

	if (list1.GetLast() == 10)
		std::cout << "Test GetLast: success" << "\n";
	else {
		std::cout << "Test GetLast: fail" << "\n";
	};

	if (list1.GetLength() == 8)
		std::cout << "Test GetLenght: success" << "\n";
	else {
		std::cout << "Test GetLenght: fail" << "\n";
	};

	if (list1.Get(5) == 19)
		std::cout << "Test Get: success" << "\n";
	else {
		std::cout << "Test Get: fail" << "\n";
	};

	list1.Append(11);
	if (list1.Get(0) == 11)
		std::cout << "Test Append: success" << "\n";
	else {
		std::cout << "Test Append: fail" << "\n";
	};

	list2.Prepend(7);
	if (list2.Get(5) == 7)
		std::cout << "Test Prepend: success" << "\n";
	else {
		std::cout << "Test Prepend: fail" << "\n";
	};

	LinkedList<int>* p = list2.GetSubList(1, 4);
	if (p->Get(0) == 11 && p->Get(1) == 8 && p->Get(2) == 9 && p->Get(3) == 2)
		std::cout << "Test GetSubList: success" << "\n";
	else {
		std::cout << "Test GetSubList: fail" << "\n";
	};

	list2.InsertAt(3, 2);
	if (list2.Get(2) == 3)
		std::cout << "Test InsertAt: success" << "\n";
	else {
		std::cout << "Test InsertAt: fail" << "\n";
	};

	LinkedList<int>* p2 = list1.Concat(&list2);
	if (p2->Get(0) == 11 && p2->Get(1) == 22 && p2->Get(2) == 25 && p2->Get(3) == 4
		&& p2->Get(4) == 8 && p2->Get(5) == 0 && p2->Get(6) == 19 && p2->Get(7) == 55 && p2->Get(8) == 10 && p2->Get(9) == 5
		&& p2->Get(10) == 11 && p2->Get(11) == 3 && p2->Get(12) == 8 && p2->Get(13) == 9
		&& p2->Get(14) == 2 && p2->Get(15) == 9)
		std::cout << "Test Concat: success" << "\n";
	else {
		std::cout << "Test Concat: fail" << "\n";
	};

	delete[7] frst;
	delete[6] scnd;

	return 0;
}

int TestListSequence() {
	int* frst{ new int[8] {22,25,4,8,0,19,55,10} };
	int* scnd{ new int[5] {5,11,8,9,2} };
	LinkedListSequence<int> list1{ frst,6 };
	LinkedListSequence<int> list2{ scnd,5 };

	if (list1.GetFirst() == 22)
		std::cout << "Test GetFirst: success" << "\n";
	else {
		std::cout << "Test GetFirst: fail" << "\n";
	};

	if (list1.GetLast() == 10)
		std::cout << "Test GetLast: success" << "\n";
	else {
		std::cout << "Test GetLast: fail" << "\n";
	};

	if (list1.GetLength() == 8)
		std::cout << "Test GetLenght: success" << "\n";
	else {
		std::cout << "Test GetLenght: fail" << "\n";
	};

	if (list1.Get(5) == 19)
		std::cout << "Test Get: success" << "\n";
	else {
		std::cout << "Test Get: fail" << "\n";
	};

	list1.Append(11);
	if (list1.Get(0) == 11)
		std::cout << "Test Append: success" << "\n";
	else {
		std::cout << "Test Append: fail" << "\n";
	};

	list2.Prepend(9);
	if (list2.Get(5) == 9)
		std::cout << "Test Prepend: success" << "\n";
	else {
		std::cout << "Test Prepend: fail" << "\n";
	};

	Sequence<int>* p = list2.GetSubsequence(1, 4);
	if (p->Get(0) == 11 && p->Get(1) == 8 && p->Get(2) == 9 && p->Get(3) == 2)
		std::cout << "Test GetSubList: success" << "\n";
	else {
		std::cout << "Test GetSubList: fail" << "\n";
	};

	list2.InsertAt(3, 2);
	if (list2.Get(2) == 3)
		std::cout << "Test InsertAt: success" << "\n";
	else {
		std::cout << "Test InsertAt: fail" << "\n";
	};

	LinkedListSequence<int>* p2 = list1.Concat(&list2);
	if (p2->Get(0) == 11 && p2->Get(1) == 22 && p2->Get(2) == 25 && p2->Get(3) == 4
		&& p2->Get(4) == 8 && p2->Get(5) == 0 && p2->Get(6) == 19 && p2->Get(7) == 55 && p2->Get(8) == 10 && p2->Get(9) == 5
		&& p2->Get(10) == 11 && p2->Get(11) == 3 && p2->Get(12) == 8 && p2->Get(13) == 9
		&& p2->Get(14) == 2 && p2->Get(15) == 9)
		std::cout << "Test Concat: success" << "\n";
	else {
		std::cout << "Test Concat: fail" << "\n";
	};

	delete[7] frst;
	delete[6] scnd;

	return 0;
}

void TestBubbleSort() {
	std::cout << " ---- Test BubbleSort ---- " << "\n";

	int* mas1{ new int[8] { 22,25,4,8,0,19,55,10 } };
	int* mas2{ new int[6] { 32000,200,84,1123,1560, 8000 } };
	int* mas3{ new int[1] { 9 } };
	int* mas4{ new int[3] { 0,0,0 } };
	int* mas5{ new int[8] { -22,-25,-4,-8,0,-19,-55,-10 } };
	int* mas6{ new int[9] { 8,-4,-17,0,34,17,-26,48,0 } };
	int* mas7{ new int[0] { } };
	int* mas8{ new int[5] { 22,21,20,19,18 } };
	int* mas9{ new int[5] { 18,19,20,21,22 } };
	int* mas10{ new int[2] { 8,-1 } };
	double* mas11{ new double[6] { -12.3,13.2,2.111,6.6,0,-2 } };

	std::cout << " ---- Tests for array ---- " << "\n";

	ArraySequence<int> mas1_arr(mas1, 8);
	BubbleSort(&mas1_arr);
	if (mas1_arr.Get(0) == 0 && mas1_arr.Get(1) == 4 && mas1_arr.Get(2) == 8 && mas1_arr.Get(3) == 10 && mas1_arr.Get(4) == 19 && mas1_arr.Get(5) == 22
		&& mas1_arr.Get(6) == 25 && mas1_arr.Get(7) == 55)
		std::cout << "Test 1 for array: success" << "\n";
	else {
		std::cout << "Test 1 for array: fail" << "\n";
	};
	
	ArraySequence<int> mas2_arr(mas2, 6);
	BubbleSort(&mas2_arr);
	if (mas2_arr.Get(0) == 84 && mas2_arr.Get(1) == 200 && mas2_arr.Get(2) == 1123 && mas2_arr.Get(3) == 1560 && mas2_arr.Get(4) == 8000 && mas2_arr.Get(5) == 32000)
		std::cout << "Test 2 for array: success" << "\n";
	else 
	{
		std::cout << "Test 2 for array: fail" << "\n";
	};

	ArraySequence<int> mas3_arr(mas3, 1);
	BubbleSort(&mas3_arr);
	if (mas3_arr.Get(0) == 9)
		std::cout << "Test 3 for array: success" << "\n";
	else 
	{
		std::cout << "Test 3 for array: fail" << "\n";
	};

	ArraySequence<int> mas4_arr(mas4, 3);
	BubbleSort(&mas4_arr);
	if (mas4_arr.Get(0) == 0 && mas4_arr.Get(1) == 0 && mas4_arr.Get(2) == 0 )
		std::cout << "Test 4 for array: success" << "\n";
	else 
	{
		std::cout << "Test 4 for array: fail" << "\n";
	};

	ArraySequence<int> mas5_arr(mas5, 8);
	BubbleSort(&mas5_arr);
	if (mas5_arr.Get(0) == -55 && mas5_arr.Get(1) == -25 && mas5_arr.Get(2) == -22 && mas5_arr.Get(3) == -19 && mas5_arr.Get(4) == -10
		&& mas5_arr.Get(5) == -8 && mas5_arr.Get(6) == -4 && mas5_arr.Get(7) == 0)
		std::cout << "Test 5 for array: success" << "\n";
	else {
		std::cout << "Test 5 for array: fail" << "\n";
	};

	ArraySequence<int> mas6_arr(mas6, 9);
	BubbleSort(&mas6_arr);
	if (mas6_arr.Get(0) == -26 && mas6_arr.Get(1) == -17 && mas6_arr.Get(2) == -4 && mas6_arr.Get(3) == 0 && mas6_arr.Get(4) == 0 && mas6_arr.Get(5) == 8
		&& mas6_arr.Get(6) == 17 && mas6_arr.Get(7) == 34 && mas6_arr.Get(8) == 48)
		std::cout << "Test 6 for array: success" << "\n";
	else {
		std::cout << "Test 6 for array: fail" << "\n";
	};

	ArraySequence<int> mas7_arr(mas7, 0);
	BubbleSort(&mas7_arr);
	if (mas7_arr.GetLength() == 0)
		std::cout << "Test 7 for array: success" << "\n";
	else {
		std::cout << "Test 7 for array: fail" << "\n";
	};

	ArraySequence<int> mas8_arr(mas8, 5);
	BubbleSort(&mas8_arr);
	if (mas8_arr.Get(0) == 18 && mas8_arr.Get(1) == 19 && mas8_arr.Get(2) == 20 && mas8_arr.Get(3) == 21 && mas8_arr.Get(4) == 22)
		std::cout << "Test 8 for array: success" << "\n";
	else {
		std::cout << "Test 8 for array: fail" << "\n";
	};

	ArraySequence<int> mas9_arr(mas9, 5);
	BubbleSort(&mas9_arr);
	if (mas9_arr.Get(0) == 18 && mas9_arr.Get(1) == 19 && mas9_arr.Get(2) == 20 && mas9_arr.Get(3) == 21 && mas9_arr.Get(4) == 22)
		std::cout << "Test 9 for array: success" << "\n";
	else {
		std::cout << "Test 9 for array: fail" << "\n";
	};

	ArraySequence<int> mas10_arr(mas10, 2);
	BubbleSort(&mas10_arr);
	if (mas10_arr.Get(0) == -1 && mas10_arr.Get(1) == 8)
		std::cout << "Test 10 for array: success" << "\n";
	else {
		std::cout << "Test 10 for array: fail" << "\n";
	};

	ArraySequence<double> mas11_arr(mas11, 6);
	BubbleSort(&mas11_arr);
	if (mas11_arr.Get(0) == -12.3 && mas11_arr.Get(1) == -2 && mas11_arr.Get(2) == 0 && mas11_arr.Get(3) == 2.111 && mas11_arr.Get(4) == 6.6 && mas11_arr.Get(5) == 13.2)
		std::cout << "Test 11 for array: success" << "\n";
	else {
		std::cout << "Test 11 for array: fail" << "\n";
	};


	std::cout << " ---- Tests for list ---- " << "\n";

	LinkedListSequence<int> mas1_list(mas1, 8);

	BubbleSort(&mas1_list);
	if (mas1_list.Get(0) == 0 && mas1_list.Get(1) == 4 && mas1_list.Get(2) == 8 && mas1_list.Get(3) == 10 && mas1_list.Get(4) == 19 && mas1_list.Get(5) == 22
		&& mas1_list.Get(6) == 25 && mas1_list.Get(7) == 55)
		std::cout << "Test 1 for list: success" << "\n";
	else 
	{
		std::cout << "Test 1 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas2_list(mas2, 6);
	BubbleSort(&mas2_list);
	if (mas2_list.Get(0) == 84 && mas2_list.Get(1) == 200 && mas2_list.Get(2) == 1123 && mas2_list.Get(3) == 1560 && mas2_list.Get(4) == 8000 && mas2_list.Get(5) == 32000)
		std::cout << "Test 2 for list: success" << "\n";
	else 
	{
		std::cout << "Test 2 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas3_list(mas3, 1);
	BubbleSort(&mas3_list);
	if (mas3_list.Get(0) == 9 )
		std::cout << "Test 3 for list: success" << "\n";
	else 
	{
		std::cout << "Test 3 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas4_list(mas4, 3);
	BubbleSort(&mas4_list);
	if (mas4_list.Get(0) == 0 && mas4_list.Get(1) == 0 && mas4_list.Get(2) == 0)
		std::cout << "Test 4 for list: success" << "\n";
	else 
	{
		std::cout << "Test 4 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas5_list(mas5, 8);
	BubbleSort(&mas5_list);
	if (mas5_list.Get(0) == -55 && mas5_list.Get(1) == -25 && mas5_list.Get(2) == -22 && mas5_list.Get(3) == -19 && mas5_list.Get(4) == -10
		&& mas5_list.Get(5) == -8 && mas5_list.Get(6) == -4 && mas5_list.Get(7) == 0)
		std::cout << "Test 5 for list: success" << "\n";
	else {
		std::cout << "Test 5 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas6_list(mas6, 9);
	BubbleSort(&mas6_list);
	if (mas6_list.Get(0) == -26 && mas6_list.Get(1) == -17 && mas6_list.Get(2) == -4 && mas6_list.Get(3) == 0 && mas6_list.Get(4) == 0 && mas6_list.Get(5) == 8
		&& mas6_list.Get(6) == 17 && mas6_list.Get(7) == 34 && mas6_list.Get(8) == 48)
		std::cout << "Test 6 for list: success" << "\n";
	else {
		std::cout << "Test 6 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas7_list(mas7, 0);
	BubbleSort(&mas7_list);
	if (mas7_arr.GetLength() == 0)
		std::cout << "Test 7 for list: success" << "\n";
	else {
		std::cout << "Test 7 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas8_list(mas8, 5);
	BubbleSort(&mas8_list);
	if (mas8_list.Get(0) == 18 && mas8_list.Get(1) == 19 && mas8_list.Get(2) == 20 && mas8_list.Get(3) == 21 && mas8_list.Get(4) == 22)
		std::cout << "Test 8 for list: success" << "\n";
	else {
		std::cout << "Test 8 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas9_list(mas9, 5);
	BubbleSort(&mas9_list);
	if (mas9_list.Get(0) == 18 && mas9_list.Get(1) == 19 && mas9_list.Get(2) == 20 && mas9_list.Get(3) == 21 && mas9_list.Get(4) == 22)
		std::cout << "Test 9 for list: success" << "\n";
	else {
		std::cout << "Test 9 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas10_list(mas10, 2);
	BubbleSort(&mas10_list);
	if (mas10_list.Get(0) == -1 && mas10_list.Get(1) == 8)
		std::cout << "Test 10 for list: success" << "\n";
	else {
		std::cout << "Test 10 for list: fail" << "\n";
	};

	LinkedListSequence<double> mas11_list(mas11, 6);
	BubbleSort(&mas11_list);
	if (mas11_list.Get(0) == -12.3 && mas11_list.Get(1) == -2 && mas11_list.Get(2) == 0 && mas11_list.Get(3) == 2.111 && mas11_list.Get(4) == 6.6 && mas11_list.Get(5) == 13.2)
		std::cout << "Test 11 for list: success" << "\n";
	else {
		std::cout << "Test 11 for list: fail" << "\n";
	};

	delete[] mas1;
	delete[] mas2;
	delete[] mas3;
	delete[] mas4;
	delete[] mas5;
	delete[] mas6;
	delete[] mas7;
	delete[] mas8;
	delete[] mas9;
	delete[] mas10;
	delete[] mas11;
}

void TestShellSort() {
	std::cout << " ---- Test ShellSort ---- " << "\n";

	int* mas1{ new int[8] { 22,25,4,8,0,19,55,10 } };
	int* mas2{ new int[6] { 32000,200,84,1123,1560, 8000 } };
	int* mas3{ new int[1] { 9 } };
	int* mas4{ new int[3] { 0,0,0 } };
	int* mas5{ new int[8] { -22,-25,-4,-8,0,-19,-55,-10 } };
	int* mas6{ new int[9] { 8,-4,-17,0,34,17,-26,48,0 } };
	int* mas7{ new int[0] { } };
	int* mas8{ new int[5] { 22,21,20,19,18 } };
	int* mas9{ new int[5] { 18,19,20,21,22 } };
	int* mas10{ new int[2] { 8,-1 } };
	double* mas11{ new double[6] { -12.3,13.2,2.111,6.6,0,-2 } };

	std::cout << " ---- Tests for array ---- " << "\n";

	ArraySequence<int> mas1_arr(mas1, 8);
	ShellSort(&mas1_arr);
	if (mas1_arr.Get(0) == 0 && mas1_arr.Get(1) == 4 && mas1_arr.Get(2) == 8 && mas1_arr.Get(3) == 10 && mas1_arr.Get(4) == 19 && mas1_arr.Get(5) == 22
		&& mas1_arr.Get(6) == 25 && mas1_arr.Get(7) == 55)
		std::cout << "Test 1 for array: success" << "\n";
	else {
		std::cout << "Test 1 for array: fail" << "\n";
	};

	ArraySequence<int> mas2_arr(mas2, 6);
	ShellSort(&mas2_arr);
	if (mas2_arr.Get(0) == 84 && mas2_arr.Get(1) == 200 && mas2_arr.Get(2) == 1123 && mas2_arr.Get(3) == 1560 && mas2_arr.Get(4) == 8000 && mas2_arr.Get(5) == 32000)
		std::cout << "Test 2 for array: success" << "\n";
	else
	{
		std::cout << "Test 2 for array: fail" << "\n";
	};

	ArraySequence<int> mas3_arr(mas3, 1);
	ShellSort(&mas3_arr);
	if (mas3_arr.Get(0) == 9)
		std::cout << "Test 3 for array: success" << "\n";
	else
	{
		std::cout << "Test 3 for array: fail" << "\n";
	};

	ArraySequence<int> mas4_arr(mas4, 3);
	ShellSort(&mas4_arr);
	if (mas4_arr.Get(0) == 0 && mas4_arr.Get(1) == 0 && mas4_arr.Get(2) == 0)
		std::cout << "Test 4 for array: success" << "\n";
	else
	{
		std::cout << "Test 4 for array: fail" << "\n";
	};

	ArraySequence<int> mas5_arr(mas5, 8);
	ShellSort(&mas5_arr);
	if (mas5_arr.Get(0) == -55 && mas5_arr.Get(1) == -25 && mas5_arr.Get(2) == -22 && mas5_arr.Get(3) == -19 && mas5_arr.Get(4) == -10
		&& mas5_arr.Get(5) == -8 && mas5_arr.Get(6) == -4 && mas5_arr.Get(7) == 0)
		std::cout << "Test 5 for array: success" << "\n";
	else {
		std::cout << "Test 5 for array: fail" << "\n";
	};

	ArraySequence<int> mas6_arr(mas6, 9);
	ShellSort(&mas6_arr);
	if (mas6_arr.Get(0) == -26 && mas6_arr.Get(1) == -17 && mas6_arr.Get(2) == -4 && mas6_arr.Get(3) == 0 && mas6_arr.Get(4) == 0 && mas6_arr.Get(5) == 8
		&& mas6_arr.Get(6) == 17 && mas6_arr.Get(7) == 34 && mas6_arr.Get(8) == 48)
		std::cout << "Test 6 for array: success" << "\n";
	else {
		std::cout << "Test 6 for array: fail" << "\n";
	};

	ArraySequence<int> mas7_arr(mas7, 0);
	ShellSort(&mas7_arr);
	if (mas7_arr.GetLength() == 0)
		std::cout << "Test 7 for array: success" << "\n";
	else {
		std::cout << "Test 7 for array: fail" << "\n";
	};

	ArraySequence<int> mas8_arr(mas8, 5);
	ShellSort(&mas8_arr);
	if (mas8_arr.Get(0) == 18 && mas8_arr.Get(1) == 19 && mas8_arr.Get(2) == 20 && mas8_arr.Get(3) == 21 && mas8_arr.Get(4) == 22)
		std::cout << "Test 8 for array: success" << "\n";
	else {
		std::cout << "Test 8 for array: fail" << "\n";
	};

	ArraySequence<int> mas9_arr(mas9, 5);
	ShellSort(&mas9_arr);
	if (mas9_arr.Get(0) == 18 && mas9_arr.Get(1) == 19 && mas9_arr.Get(2) == 20 && mas9_arr.Get(3) == 21 && mas9_arr.Get(4) == 22)
		std::cout << "Test 9 for array: success" << "\n";
	else {
		std::cout << "Test 9 for array: fail" << "\n";
	};

	ArraySequence<int> mas10_arr(mas10, 2);
	ShellSort(&mas10_arr);
	if (mas10_arr.Get(0) == -1 && mas10_arr.Get(1) == 8)
		std::cout << "Test 10 for array: success" << "\n";
	else {
		std::cout << "Test 10 for array: fail" << "\n";
	};

	ArraySequence<double> mas11_arr(mas11, 6);
	ShellSort(&mas11_arr);
	if (mas11_arr.Get(0) == -12.3 && mas11_arr.Get(1) == -2 && mas11_arr.Get(2) == 0 && mas11_arr.Get(3) == 2.111 && mas11_arr.Get(4) == 6.6 && mas11_arr.Get(5) == 13.2)
		std::cout << "Test 11 for array: success" << "\n";
	else {
		std::cout << "Test 11 for array: fail" << "\n";
	};


	std::cout << " ---- Tests for list ---- " << "\n";

	LinkedListSequence<int> mas1_list(mas1, 8);

	ShellSort(&mas1_list);
	if (mas1_list.Get(0) == 0 && mas1_list.Get(1) == 4 && mas1_list.Get(2) == 8 && mas1_list.Get(3) == 10 && mas1_list.Get(4) == 19 && mas1_list.Get(5) == 22
		&& mas1_list.Get(6) == 25 && mas1_list.Get(7) == 55)
		std::cout << "Test 1 for list: success" << "\n";
	else
	{
		std::cout << "Test 1 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas2_list(mas2, 6);
	ShellSort(&mas2_list);
	if (mas2_list.Get(0) == 84 && mas2_list.Get(1) == 200 && mas2_list.Get(2) == 1123 && mas2_list.Get(3) == 1560 && mas2_list.Get(4) == 8000 && mas2_list.Get(5) == 32000)
		std::cout << "Test 2 for list: success" << "\n";
	else
	{
		std::cout << "Test 2 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas3_list(mas3, 1);
	ShellSort(&mas3_list);
	if (mas3_list.Get(0) == 9)
		std::cout << "Test 3 for list: success" << "\n";
	else
	{
		std::cout << "Test 3 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas4_list(mas4, 3);
	ShellSort(&mas4_list);
	if (mas4_list.Get(0) == 0 && mas4_list.Get(1) == 0 && mas4_list.Get(2) == 0)
		std::cout << "Test 4 for list: success" << "\n";
	else
	{
		std::cout << "Test 4 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas5_list(mas5, 8);
	ShellSort(&mas5_list);
	if (mas5_list.Get(0) == -55 && mas5_list.Get(1) == -25 && mas5_list.Get(2) == -22 && mas5_list.Get(3) == -19 && mas5_list.Get(4) == -10
		&& mas5_list.Get(5) == -8 && mas5_list.Get(6) == -4 && mas5_list.Get(7) == 0)
		std::cout << "Test 5 for list: success" << "\n";
	else {
		std::cout << "Test 5 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas6_list(mas6, 9);
	ShellSort(&mas6_list);
	if (mas6_list.Get(0) == -26 && mas6_list.Get(1) == -17 && mas6_list.Get(2) == -4 && mas6_list.Get(3) == 0 && mas6_list.Get(4) == 0 && mas6_list.Get(5) == 8
		&& mas6_list.Get(6) == 17 && mas6_list.Get(7) == 34 && mas6_list.Get(8) == 48)
		std::cout << "Test 6 for list: success" << "\n";
	else {
		std::cout << "Test 6 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas7_list(mas7, 0);
	ShellSort(&mas7_list);
	if (mas7_arr.GetLength() == 0)
		std::cout << "Test 7 for list: success" << "\n";
	else {
		std::cout << "Test 7 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas8_list(mas8, 5);
	ShellSort(&mas8_list);
	if (mas8_list.Get(0) == 18 && mas8_list.Get(1) == 19 && mas8_list.Get(2) == 20 && mas8_list.Get(3) == 21 && mas8_list.Get(4) == 22)
		std::cout << "Test 8 for list: success" << "\n";
	else {
		std::cout << "Test 8 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas9_list(mas9, 5);
	ShellSort(&mas9_list);
	if (mas9_list.Get(0) == 18 && mas9_list.Get(1) == 19 && mas9_list.Get(2) == 20 && mas9_list.Get(3) == 21 && mas9_list.Get(4) == 22)
		std::cout << "Test 9 for list: success" << "\n";
	else {
		std::cout << "Test 9 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas10_list(mas10, 2);
	ShellSort(&mas10_list);
	if (mas10_list.Get(0) == -1 && mas10_list.Get(1) == 8)
		std::cout << "Test 10 for list: success" << "\n";
	else {
		std::cout << "Test 10 for list: fail" << "\n";
	};

	LinkedListSequence<double> mas11_list(mas11, 6);
	ShellSort(&mas11_list);
	if (mas11_list.Get(0) == -12.3 && mas11_list.Get(1) == -2 && mas11_list.Get(2) == 0 && mas11_list.Get(3) == 2.111 && mas11_list.Get(4) == 6.6 && mas11_list.Get(5) == 13.2)
		std::cout << "Test 11 for list: success" << "\n";
	else {
		std::cout << "Test 11 for list: fail" << "\n";
	};

	delete[] mas1;
	delete[] mas2;
	delete[] mas3;
	delete[] mas4;
	delete[] mas5;
	delete[] mas6;
	delete[] mas7;
	delete[] mas8;
	delete[] mas9;
	delete[] mas10;
	delete[] mas11;

}

void TestHeapSort() 
{
	std::cout << " ---- Test HeapSort ---- " << "\n";

	int* mas1{ new int[8] { 22,25,4,8,0,19,55,10 } };
	int* mas2{ new int[6] { 32000,200,84,1123,1560, 8000 } };
	int* mas3{ new int[1] { 9 } };
	int* mas4{ new int[3] { 0,0,0 } };
	int* mas5{ new int[8] { -22,-25,-4,-8,0,-19,-55,-10 } };
	int* mas6{ new int[9] { 8,-4,-17,0,34,17,-26,48,0 } };
	int* mas7{ new int[0] { } };
	int* mas8{ new int[5] { 22,21,20,19,18 } };
	int* mas9{ new int[5] { 18,19,20,21,22 } };
	int* mas10{ new int[2] { 8,-1 } };
	double* mas11{ new double[6] { -12.3,13.2,2.111,6.6,0,-2 } };

	std::cout << " ---- Tests for array ---- " << "\n";

	ArraySequence<int> mas1_arr(mas1, 8);
	HeapSort(&mas1_arr);
	if (mas1_arr.Get(0) == 0 && mas1_arr.Get(1) == 4 && mas1_arr.Get(2) == 8 && mas1_arr.Get(3) == 10 && mas1_arr.Get(4) == 19 && mas1_arr.Get(5) == 22
		&& mas1_arr.Get(6) == 25 && mas1_arr.Get(7) == 55)
		std::cout << "Test 1 for array: success" << "\n";
	else {
		std::cout << "Test 1 for array: fail" << "\n";
	};

	ArraySequence<int> mas2_arr(mas2, 6);
	HeapSort(&mas2_arr);
	if (mas2_arr.Get(0) == 84 && mas2_arr.Get(1) == 200 && mas2_arr.Get(2) == 1123 && mas2_arr.Get(3) == 1560 && mas2_arr.Get(4) == 8000 && mas2_arr.Get(5) == 32000)
		std::cout << "Test 2 for array: success" << "\n";
	else
	{
		std::cout << "Test 2 for array: fail" << "\n";
	};

	ArraySequence<int> mas3_arr(mas3, 1);
	HeapSort(&mas3_arr);
	if (mas3_arr.Get(0) == 9)
		std::cout << "Test 3 for array: success" << "\n";
	else
	{
		std::cout << "Test 3 for array: fail" << "\n";
	};

	ArraySequence<int> mas4_arr(mas4, 3);
	HeapSort(&mas4_arr);
	if (mas4_arr.Get(0) == 0 && mas4_arr.Get(1) == 0 && mas4_arr.Get(2) == 0)
		std::cout << "Test 4 for array: success" << "\n";
	else
	{
		std::cout << "Test 4 for array: fail" << "\n";
	};

	ArraySequence<int> mas5_arr(mas5, 8);
	HeapSort(&mas5_arr);
	if (mas5_arr.Get(0) == -55 && mas5_arr.Get(1) == -25 && mas5_arr.Get(2) == -22 && mas5_arr.Get(3) == -19 && mas5_arr.Get(4) == -10
		&& mas5_arr.Get(5) == -8 && mas5_arr.Get(6) == -4 && mas5_arr.Get(7) == 0)
		std::cout << "Test 5 for array: success" << "\n";
	else {
		std::cout << "Test 5 for array: fail" << "\n";
	};

	ArraySequence<int> mas6_arr(mas6, 9);
	HeapSort(&mas6_arr);
	if (mas6_arr.Get(0) == -26 && mas6_arr.Get(1) == -17 && mas6_arr.Get(2) == -4 && mas6_arr.Get(3) == 0 && mas6_arr.Get(4) == 0 && mas6_arr.Get(5) == 8
		&& mas6_arr.Get(6) == 17 && mas6_arr.Get(7) == 34 && mas6_arr.Get(8) == 48)
		std::cout << "Test 6 for array: success" << "\n";
	else {
		std::cout << "Test 6 for array: fail" << "\n";
	};

	ArraySequence<int> mas7_arr(mas7, 0);
	HeapSort(&mas7_arr);
	if (mas7_arr.GetLength() == 0)
		std::cout << "Test 7 for array: success" << "\n";
	else {
		std::cout << "Test 7 for array: fail" << "\n";
	};

	ArraySequence<int> mas8_arr(mas8, 5);
	HeapSort(&mas8_arr);
	if (mas8_arr.Get(0) == 18 && mas8_arr.Get(1) == 19 && mas8_arr.Get(2) == 20 && mas8_arr.Get(3) == 21 && mas8_arr.Get(4) == 22)
		std::cout << "Test 8 for array: success" << "\n";
	else {
		std::cout << "Test 8 for array: fail" << "\n";
	};

	ArraySequence<int> mas9_arr(mas9, 5);
	HeapSort(&mas9_arr);
	if (mas9_arr.Get(0) == 18 && mas9_arr.Get(1) == 19 && mas9_arr.Get(2) == 20 && mas9_arr.Get(3) == 21 && mas9_arr.Get(4) == 22)
		std::cout << "Test 9 for array: success" << "\n";
	else {
		std::cout << "Test 9 for array: fail" << "\n";
	};

	ArraySequence<int> mas10_arr(mas10, 2);
	HeapSort(&mas10_arr);
	if (mas10_arr.Get(0) == -1 && mas10_arr.Get(1) == 8)
		std::cout << "Test 10 for array: success" << "\n";
	else {
		std::cout << "Test 10 for array: fail" << "\n";
	};

	ArraySequence<double> mas11_arr(mas11, 6);
	HeapSort(&mas11_arr);
	if (mas11_arr.Get(0) == -12.3 && mas11_arr.Get(1) == -2 && mas11_arr.Get(2) == 0 && mas11_arr.Get(3) == 2.111 && mas11_arr.Get(4) == 6.6 && mas11_arr.Get(5) == 13.2)
		std::cout << "Test 11 for array: success" << "\n";
	else {
		std::cout << "Test 11 for array: fail" << "\n";
	};


	std::cout << " ---- Tests for list ---- " << "\n";

	LinkedListSequence<int> mas1_list(mas1, 8);

	HeapSort(&mas1_list);
	if (mas1_list.Get(0) == 0 && mas1_list.Get(1) == 4 && mas1_list.Get(2) == 8 && mas1_list.Get(3) == 10 && mas1_list.Get(4) == 19 && mas1_list.Get(5) == 22
		&& mas1_list.Get(6) == 25 && mas1_list.Get(7) == 55)
		std::cout << "Test 1 for list: success" << "\n";
	else
	{
		std::cout << "Test 1 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas2_list(mas2, 6);
	HeapSort(&mas2_list);
	if (mas2_list.Get(0) == 84 && mas2_list.Get(1) == 200 && mas2_list.Get(2) == 1123 && mas2_list.Get(3) == 1560 && mas2_list.Get(4) == 8000 && mas2_list.Get(5) == 32000)
		std::cout << "Test 2 for list: success" << "\n";
	else
	{
		std::cout << "Test 2 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas3_list(mas3, 1);
	HeapSort(&mas3_list);
	if (mas3_list.Get(0) == 9)
		std::cout << "Test 3 for list: success" << "\n";
	else
	{
		std::cout << "Test 3 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas4_list(mas4, 3);
	HeapSort(&mas4_list);
	if (mas4_list.Get(0) == 0 && mas4_list.Get(1) == 0 && mas4_list.Get(2) == 0)
		std::cout << "Test 4 for list: success" << "\n";
	else
	{
		std::cout << "Test 4 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas5_list(mas5, 8);
	HeapSort(&mas5_list);
	if (mas5_list.Get(0) == -55 && mas5_list.Get(1) == -25 && mas5_list.Get(2) == -22 && mas5_list.Get(3) == -19 && mas5_list.Get(4) == -10
		&& mas5_list.Get(5) == -8 && mas5_list.Get(6) == -4 && mas5_list.Get(7) == 0)
		std::cout << "Test 5 for list: success" << "\n";
	else {
		std::cout << "Test 5 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas6_list(mas6, 9);
	HeapSort(&mas6_list);
	if (mas6_list.Get(0) == -26 && mas6_list.Get(1) == -17 && mas6_list.Get(2) == -4 && mas6_list.Get(3) == 0 && mas6_list.Get(4) == 0 && mas6_list.Get(5) == 8
		&& mas6_list.Get(6) == 17 && mas6_list.Get(7) == 34 && mas6_list.Get(8) == 48)
		std::cout << "Test 6 for list: success" << "\n";
	else {
		std::cout << "Test 6 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas7_list(mas7, 0);
	HeapSort(&mas7_list);
	if (mas7_arr.GetLength() == 0)
		std::cout << "Test 7 for list: success" << "\n";
	else {
		std::cout << "Test 7 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas8_list(mas8, 5);
	HeapSort(&mas8_list);
	if (mas8_list.Get(0) == 18 && mas8_list.Get(1) == 19 && mas8_list.Get(2) == 20 && mas8_list.Get(3) == 21 && mas8_list.Get(4) == 22)
		std::cout << "Test 8 for list: success" << "\n";
	else {
		std::cout << "Test 8 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas9_list(mas9, 5);
	HeapSort(&mas9_list);
	if (mas9_list.Get(0) == 18 && mas9_list.Get(1) == 19 && mas9_list.Get(2) == 20 && mas9_list.Get(3) == 21 && mas9_list.Get(4) == 22)
		std::cout << "Test 9 for list: success" << "\n";
	else {
		std::cout << "Test 9 for list: fail" << "\n";
	};

	LinkedListSequence<int> mas10_list(mas10, 2);
	HeapSort(&mas10_list);
	if (mas10_list.Get(0) == -1 && mas10_list.Get(1) == 8)
		std::cout << "Test 10 for list: success" << "\n";
	else {
		std::cout << "Test 10 for list: fail" << "\n";
	};

	LinkedListSequence<double> mas11_list(mas11, 6);
	HeapSort(&mas11_list);
	if (mas11_list.Get(0) == -12.3 && mas11_list.Get(1) == -2 && mas11_list.Get(2) == 0 && mas11_list.Get(3) == 2.111 && mas11_list.Get(4) == 6.6 && mas11_list.Get(5) == 13.2)
		std::cout << "Test 11 for list: success" << "\n";
	else {
		std::cout << "Test 11 for list: fail" << "\n";
	};

	delete[] mas1;
	delete[] mas2;
	delete[] mas3;
	delete[] mas4;
	delete[] mas5;
	delete[] mas6;
	delete[] mas7;
	delete[] mas8;
	delete[] mas9;
	delete[] mas10;
	delete[] mas11;

	
}



