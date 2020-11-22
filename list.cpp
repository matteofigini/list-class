#include <iostream>
using namespace std;

/* CLASSE: NODO <template>
 * Realizza l'implementazione per i nodi appartenenti a una lista
 * ATTRIBUTI:
 * data (Template): contenuto del nodo
 * *next (Nodo): puntatore al nodo successivo
 * METODI:
 * Nodo(T element): costruttore del nodo, che ammette il passaggio di parametri
 */
template <class T>
class Nodo {
	public:
		T data;
		Nodo *next;
		Nodo *prev;

	Nodo () {
		next = NULL;
		prev = NULL;
	}
  
	Nodo (T element){
		data = element;
		next = NULL;
		prev = NULL;
	}
};

/* CLASSE: Lista <template>
 * Realizza l'implementazione per una lista semplice a puntatore.
 */
template <class T>
class Lista {
	private:
		/* Numero di nodi nella lista */
		int count;
		
	public:
		/* Puntatore al primo nodo */
		Nodo<T> *testa;
		/* Puntatore all'ultimo nodo */
		Nodo<T> *coda;
		
		/* COSTRUTTORE: Lista ()
		 * Alloca lo spazio e inizializza i puntatori a NULL.
		 */
		Lista () {
			testa = NULL;
			coda = NULL;
			this->count = 0;
		}
		
		/* METODO: isEmpty()
		 * Ritorna 1 se la lista è vuota, altrimenti ritorna 0.
		 */
		int isEmpty () {
			if(testa == NULL)
				return 1;
			else
				return 0;	
		}
		
		/* METODO: add(Nodo<T> *node)
		 * Aggiunge in coda il nodo passato come parametro.
		 */
		void add (Nodo<T> *node) {
			if(testa == NULL) {
				testa = node;
				node->next = NULL;
			}
			else {
				Nodo<T> *penultimo = getLastNode();
				penultimo->next = node;
			}
			this->count += 1;
		}
		
		/* METODO: addAt(Nodo<T> *node, int index)
		 * Aggiunge alla lista il nodo passato come parametro all'indice "index".
		 * Se l'indice passato come parametro è negativo o oltre il numero di 
		 * elementi nella lista, viene stampato a video un messaggio di errore.
		 * L'indice ha intervallo [0, count()]
		 */
		void addAt (Nodo<T> *node, int index) {
			int i;
			if(index < 0 || index > this->count) {
				cout << "Eccezione generata: metodo \"addAt()\"; ";
				cout << "Indice oltre i limiti consentiti.\n";
			}
			else if(index == 0) {
				node->next = testa;
				testa = node;
				this->count += 1;
			}
			else if(index == this->count) {
				add(node);
			}
			else {
				Nodo<T> *ptr = testa;
				for (i = 1; i < index; i++)
					ptr = ptr->next;
				node->next = ptr->next;
				ptr->next = node;
				this->count += 1;
			}
		}
		
		/* METODO: print()
		 * Stampa a video la lista.
		 */
		void print () {
			if(this->isEmpty() == 1) {
				cout << "NULL." << endl;
			}
			else {
				for(int i = 0; i < this->count - 1; i++)
					cout << "[ " << getNodeAt(i)->data << " ] -> ";
				cout << "[ " << getLastNode()->data << " ]" << endl;
			}
		}
		
		/* METODO: printAddress()
		 * Stampa a video la lista con gli indirizzi dei nodi e i puntatori.
		 */
		void printAddress () {
			for(int i = 0; i < this->count; i++){
				cout << "[" << getNodeAt(i)->prev << "]:[" << getNodeAt(i) << "]:[" << getNodeAt(i)->data << 
				"]:[" << getNodeAt(i)->next << "]" << endl;
			}
			cout << endl;
		}
		
		/* METODO: count()
		 * Restituisce il numero di nodi appartenenti alla lista.
		 */
		int getCount () {
			return this->count;
		}
		
		/* METODO: findFirst(T element)
		 *	Restituisce l'indice della prima occorrenza del nodo passato
		 *	come parametro.
		 */
		int findFirst (T element) {
			int index = 0;
			int found = 0;
			Nodo<T> *ptr = testa;
			while(found == 0) {
				if(index >= this->count) {
					found = true;
					index = -1;
				}
				else if (getNodeAt(index)->data == element) {
					found = true;
				}
				else {
					index++;
				}
			}
			return index;
		}
		
		/* METODO: findLast(T element)
		 * Restituisce l'indice dell'ultima occorrenza del nodo passato
		 * come parametro.
		 */
		int findLast (T element) {
			int i, index, found;
			Nodo<T> *ptr = testa;
			for (i = 0, index = -1, found = 0; i < this->count; i++) {
				if(getNodeAt(i)->data == element) {
					index = i;
				}
			}
			return index;
		}
		
		/* METODO: findHowMany(T element)
		 * Restituisce il numero di occorrenze del nodo passato
		 * come parametro nella lista.
		 */
		int findHowMany (T element) {
			int howMany, i;
			for(i = 0, howMany = 0; i < this->count; i++) {
				if (getNodeAt(i)->data == element) {
					howMany++;
				}
			}
			return howMany;
		}
		
		/* METODO: sort()
		 * Ordina gli elementi della lista dal minore al maggiore,
		 * scambiando i contenuti dei nodi (campo data), non i 
		 * puntatori.
		 * Il metodo funziona su tutti i tipi di dato per cui sono
		 * overloadati gli operatori > e <, quali dati numerici e 
		 * stringhe.
		 */
		void sort () {
			Nodo<T> *l1 = NULL, *l2 = NULL;
			T temp;
			int ripeti = 1;
			while (ripeti == 1) {
				ripeti = 0;
				for (l1 = testa; l1->next != NULL; l1 = l1->next) {
					for (l2 = l1->next; l2 != NULL; l2 = l2->next) {
						if (l1->data > l2->data) {
							temp = l1->data;
							l1->data = l2->data;
							l2->data = temp;
							ripeti = true;
						}
					}
				}
			}
		}
		
		/* METODO: getNodeAt(int index)
		 * Restituisce il puntatore al nodo dell'indice passato come parametro.
		 */
		Nodo<T>* getNodeAt (int index) {
			int i = 0;
			Nodo<T> *ptr = testa;
			if(index < 0 || index >= this->count) {
				cout << "Eccezione generata: metodo \"getNodeAt()\"; ";
				cout << "Indice oltre i limiti consentiti.\n" << endl;
				ptr = NULL;
			}
			else {
				while(i < index) {
					ptr = ptr->next;
					i++;
				}
			}
			return ptr;
		}
		
		/* METODO: getLastNode()
		 * Restituisce il puntatore all'ultimo nodo della lista.
		 */
		Nodo<T>* getLastNode () {
			Nodo<T> *pointer = NULL;
			pointer = getNodeAt(this->count - 1);
			return pointer;
		}
	
		/* METODO: removeFirst(T element)
		 * Rimuove la prima occorrenza del nodo passato come parametro, senza eliminarlo.
		 * Restituisce l'indirizzo del nodo scollegato dalla lista.
		 */
		Nodo<T>* removeFirst (T element) {
			Nodo<T> *ptr = testa, *previous = NULL;
			int found = 0, indexToGo, i;
			if (getNodeAt(0)->data == element) {
				previous = testa;
				testa = testa->next;
			}
			else {
				indexToGo = findFirst(element);
				if (indexToGo > 0) {
					for(i = 0; i < indexToGo - 1; i++)
						ptr = ptr->next;
					previous = ptr->next;
					ptr->next = ptr->next->next;
					previous->next = NULL;
				}
			}
			this->count -= 1;
			return previous;
		}
		
		/* METODO: removeAll(T element)
		 * Rimuove tutte le occorrenze del nodo passato come parametro, eliminandoli.
		 * Restituisce il numero di nodi scollegati dalla lista.
		 */
		int removeAll(T element) {
			Nodo<T> *ptr = NULL;
			int nodesDeleted = 0;
			int nodesToDelete = findHowMany(element);
			while(nodesDeleted < nodesToDelete) {
				ptr = removeFirst(element);
				ptr->next = NULL;
				free(ptr);
				nodesDeleted++;
			}
			return nodesDeleted;
		}
		
		/* METODO: removeAt(int index)
		 * Rimuove il nodo all'indice passato come parametro, senza eliminarlo.
		 * Restituisce l'indirizzo del nodo scollegato dalla lista.
		 * Se non è stato eliminato alcun nodo, restituisce il puntatore nullo.
		 */
		Nodo<T>* removeAt(int index) {
			Nodo<T> *ptr = testa, *previous;
			if(index < 0 || index >= this->count) {
				cout << "Eccezione generata: metodo \"removeAt()\"; ";
				cout << "Indice oltre i limiti consentiti.\n";
				ptr = NULL;
				return ptr;
			}
			else {
				if (index == 0) {
					previous = testa;
					testa = testa->next;
				}
				else {
					for(int i = 0; i < index - 1; i++)
						ptr = ptr->next;
					previous = ptr->next;
					ptr->next = ptr->next->next;
				}
				previous->next = NULL;
				this->count -= 1;
				return previous;
			}
		}
		
		/* METODO: toArray(T *arrayList)
		 * Sposta gli elementi della lista in un array di tipo generico.
		 */
		void toArray (T *arrayList) {
			for(int i = 0; i < this->count; i++) {
				arrayList[i] = getNodeAt(i)->data;
			}
		}
		
		/* METODO: fromArray(T *arrayList)
		 * Aggiunge gli elementi di un array di tipo generico nella lista.
		 * Nel programma main è possibile determinare dinamicamente la grandezza del vettore tramite:
		 * sizeof(vettore)/sizeof(*vettore), sapendo che: vettore = *arrayList
		 */
		void fromArray(T *arrayList, int startFrom, int size) {
			for(int i = startFrom; i < size; i++) {
				add(new Nodo<T>(arrayList[i]));
			}
		}

		/* METODO: clear()
		 * Rimuove tutti gli elementi della lista.
		 * Se la pulizia non è andata a buon fine, stampa a 
		 * video il messaggio d'errore.
		 */
		void clear() {
			while(this->count > 0) {
				removeAt(0);
			}
			if(!isEmpty()) {
				cout << "Eccezione generata: metodo \"clear()\"; ";
				cout << "Impossibile svuotare la lista.\n";
			}
		}

		/* METODO: goNextItem(int &indexNow)
		 * Sposta in avanti l'indice passato come parametro di 1 unità.
		 * Se l'indice è uguale a count() - 1, l'indice si riporta a zero.
		 */
		void goNextItem(int &index) {
			if(index < this.count - 1)
				index++;
			else
				index = 0;
		}
		
		/* METODO: goPreviousItem(int &indexNow)
		 *	Sposta indietro l'indice passato come parametro di 1 unità.
		 * Se l'indice è uguale a zero, l'indice si riporta a count() - 1.
		 */
		void goPreviousItem(int &index) {
			if(index > 0)
				index--;
			else
				index = this.count - 1;
		}
		
		/* METODO: toSingle()
		 *	Trasforma la lista in una lista semplice (di default).
		 */
		void toSingle() {
			int i;
			for(i = 0; i < this->count; i++) {
				getNodeAt(i)->prev = NULL;		//Azzeramento dei puntatori "prev"
			}
			this->coda = NULL;							//Azzeramento del puntatore "coda"
			getLastNode()->next = NULL;			//Azzeramento dell'ultimo puntatore "next"
		}
		
		/* METODO: toBidirectional()
		 *	Trasforma la lista in una lista bidirezionale.
		 */
		void toBidirectional() {
			int i;
			this->toSingle();
			for(i = this->count - 1; i > 0; i--) {
				getNodeAt(i)->prev = getNodeAt(i - 1);
			}
			this->coda = getLastNode();
		}
		
		/* METODO: toCircular()
		 *	Trasforma la lista in una lista semplice circolare.
		 */
		void toCircular() {
			this->toSingle();
			getLastNode()->next = this->testa;	//Aggiornamento dell'ultimo puntatore "next"
		}
		
		/* METODO: toCircBidirectional()
		 *	Trasforma la lista in una lista circolare bidirezionale.
		 */
		void toCircBidirectional() {
			this->toSingle();
			this->toCircular();
			this->toBidirectional();
			getNodeAt(0)->prev = getLastNode();
			getLastNode()->next = testa;
		}
};