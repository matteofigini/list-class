#include <iostream>
#include "list.cpp"

#define EMPTY 1
#define ADD 2
#define ADD_INDEX 3
#define PRINT 4
#define PRINT_PTR 5
#define GET_NUM 6
#define FIRST_OCC 7
#define LAST_OCC 8
#define NUM_ELEM 9
#define SORT 10
#define GET_NODE 11
#define GET_LAST 12
#define REM_FIRST 13
#define REM_ALL 14
#define REM_INDEX 15
#define TO_ARR 16
#define FROM_ARR 17
#define CLEAR 18
#define EXIT 19
using namespace std;

void printMenu ();
void emptyList (Lista<int> *list);
void addElement (Lista<int> *list);
void addElementToIndex (Lista<int> *list);
void searchFirstOccurance (Lista<int> *list);
void searchLastOccurance (Lista<int> *list);
void countOccurances (Lista<int> *list);
void getNodeAtIndex (Lista<int> *list);
void getLastNodeOfList (Lista<int> *list);
void removeFirstOccurance (Lista<int> *list);
void removeAllOccurances (Lista<int> *list);
void removeAtIndex (Lista<int> *list);
void createArrayFromList (Lista<int> *list);
void createListFromArray(Lista<int> *list);

int main () {
	Lista<int> *list = new Lista<int>();
	int scelta;
	printMenu();
	do {
		cout << "Choose an option: ";
		cin >> scelta;
		if (scelta == EMPTY) {
			emptyList(list);
		} else if (scelta == ADD) {
			addElement(list);
		} else if (scelta == ADD_INDEX) {
			addElementToIndex(list);
		} else if (scelta == PRINT) {
			list->print();
		} else if (scelta == PRINT_PTR) {
			list->printAddress();
		} else if (scelta == GET_NUM) {
			cout << "Number of elements: " << list->getCount() << endl;
		} else if (scelta == FIRST_OCC) {
			searchFirstOccurance(list);
		} else if (scelta == LAST_OCC) {
			searchLastOccurance(list);
		} else if (scelta == NUM_ELEM) {
			countOccurances(list);
		} else if (scelta == SORT) {
			list->sort();
		} else if (scelta == GET_NODE) {
			getNodeAtIndex(list);
		} else if (scelta == GET_LAST) {
			getLastNodeOfList(list);
		} else if (scelta == REM_FIRST) {
			removeFirstOccurance(list);
		} else if (scelta == REM_ALL) {
			removeAllOccurances(list);
		} else if (scelta == REM_INDEX) {
			removeAtIndex(list);
		} else if (scelta == TO_ARR) {
			createArrayFromList(list);
		} else if (scelta == FROM_ARR) {
			createListFromArray(list);
		} else if (scelta == CLEAR) {
			list->clear();
		}
	} while (scelta != EXIT);
	return 0;
}

void printMenu () {
	cout << "-------------- MENU --------------\n";
	cout << "1) Check if list is empty\n";
	cout << "2) Add node to the list\n";
	cout << "3) Add node to the list at specific index\n";
	cout << "4) Print the list\n";
	cout << "5) Print the list and the pointers.\n";
	cout << "6) Get number of elements\n";
	cout << "7) Find the first occurance of an element\n";
	cout << "8) Find the last occurance of an element\n";
	cout << "9) Find the number of an element\n";
	cout << "10) Sort the list\n";
	cout << "11) Get node at specific index\n";
	cout << "12) Get the last node\n";
	cout << "13) Remove the first occurance of an element\n";
	cout << "14) Remove all occurances of an element\n";
	cout << "15) Remove at specific index\n";
	cout << "16) Transform the list into an array\n";
	cout << "17) Create list from an array\n";
	cout << "18) Clear the entire list\n";
	cout << "20) Exit\n";
}

void emptyList(Lista<int> *list) {
	if (list->isEmpty()) {
		cout << "Empty list.\n";
	}
	else {
		cout << "Not empty list.\n";
	}
}

void addElement(Lista<int> *list) {
	int num;
	cout << "Numero: ";
	cin >> num;
	list->add(new Nodo<int>(num));
}

void addElementToIndex(Lista<int> *list) {
	int num, i;
	cout << "Numero: ";
	cin >> num;
	cout << "Indice: ";
	cin >> i;
	list->addAt(new Nodo<int>(num), i);
}

void searchFirstOccurance (Lista<int> *list) {
	int num, i;
	cout << "Numero: ";
	cin >> num;
	i = list->findFirst(num);
	cout << "Il primo " << num << " è stato trovato in posizione " << i << endl;
}

void searchLastOccurance (Lista<int> *list) {
	int num, i;
	cout << "Numero: ";
	cin >> num;
	i = list->findLast(num);
	cout << "L'ultimo " << num << " è stato trovato in posizione " << i << endl;
}

void countOccurances (Lista<int> *list) {
	int num, count;
	cout << "Numero: ";
	cin >> num;
	count = list->findHowMany(num);
	cout << num << " è presente " << count << " volte.\n";
}

void getNodeAtIndex (Lista<int> *list) {
	Nodo<int> *t;
	int index;
	cout << "Indice: ";
	cin >> index;
	t = list->getNodeAt(index);
	cout << "Dato dell'elemento all'indice " << index << ": " << t->data << endl;
}

void getLastNodeOfList (Lista<int> *list) {
	Nodo<int> *t;
	t = list->getLastNode();
	cout << "Dato dell'ultimo elemento: " << t->data << endl;
}

void removeFirstOccurance (Lista<int> *list) {
	int num;
	Nodo<int> *temp;
	cout << "Prima occorrenza da rimuovere: ";
	cin >> num;
	temp = list->removeFirst(num);
	free(temp);
}

void removeAllOccurances (Lista<int> *list) {
	int num, deleted;
	cout << "Occorrenze da rimuovere: ";
	cin >> num;
	deleted = list->removeAll(num);
	cout << "Eliminate " << deleted << " occorrenze.\n";
}

void removeAtIndex (Lista<int> *list) {
	int i;
	Nodo<int> *deleted;
	cout << "Indice di rimozione: ";
	cin >> i;
	deleted = list->removeAt(i);
	free(deleted);
}

void createArrayFromList (Lista<int> *list) {
	int i, dim, *arr;
	dim = list->getCount();
	arr = (int *) malloc(sizeof(int) * dim);
	list->toArray(arr);
	for (i = 0; i < dim; i++) {
		cout << *(arr + i) << " ";
	}
}

void createListFromArray(Lista<int> *list) {
	int dim, *arr, i;
	cout << "Dimensione array: ";
	cin >> dim;
	arr = (int *) malloc(sizeof(int) * dim);
	for (i = 0; i < dim; i++) {
		cin >> *(arr + i);
	}
	list->fromArray(arr, 0, dim);
}