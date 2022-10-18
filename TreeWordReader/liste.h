/*=============================================================
La classe lista serve, per ogni nodo dell'albero, a gestirne i figli.
L'inserimento dei nodi avviene in ordine crescente in base
al valore "Numero" dei nodi.

La testa della lista sar� esso stesso un puntatore a struct NODO,
per una maggiore generalizzazione degli algoritmi.

	Luca Gargiulo
-------------------------------------------------------------*/

class LISTA{
	private:
		NODO *Head;			//Testa della lista
		int TotaleNumeri;	//Numero totale dei figli

	public:
		LISTA(){Head = new NODO;Head->Figli = NULL; Head->Next = NULL; Head->Numero = 0; TotaleNumeri=0;}
		~LISTA(){delete Head;}
		void CancellaRami();			//Cancellazione di tutti i membri della lista e i loro rispettivi dal nodo relativo padre
		NODO* Inserisci(int Numero);	//Funzione di inserimento nodo nella lista. Richiesto il numero del nodo
		void Stampa();					//Stampo d tutti i valori "numero" dei nodi
		NODO* IsThereNum(int Numero);	//Funzione di controllo dell'esistenza di un nodo con il numero richiesto
		int   GetNumFigl();
		void SalvaNodiFile(fstream &Canale);
		NODO* GetHeadLista();
		void StampaSequenza(string Sequenza);
};
