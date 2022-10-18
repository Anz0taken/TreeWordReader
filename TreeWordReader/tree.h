/*=============================================================
La classe TREE serve a gestire la memorizzazione di tutti 
i nodi necessari per la strutturazione delle sequenze di numeri 
corrispondenti ai caratteri.

La testa è un puntatore a un nodo statico per facilitare la strutturazione delle funzioni.

La classe TREE è integrata di un puntatore privato, "LastInsert", che contiene
l'indirizzo dell'ultimo nodo scelto/creato. Se è stata confermata
una sequenza, LastInsert punterà alla testa dell'albero

	Luca Gargiulo
-------------------------------------------------------------*/
class TREE{
	private:
		NODO *Head;				//Testa della lista
		NODO *LastInsert;		//Ultimo nodo inserito
	
		void CaricaFigliNodo(NODO* Nodo, int NumeroFigli, fstream &Canale);
		void StampaCombinazioniEffettive(NODO* Nodo, string Sequenza);
	public:
		TREE();		//Inizializzazione della variabile Head e puntatore LastInsert
		~TREE();	//Eliminazione di tutta la memoria dalla memory heap
		char InserisciNumero(int Numero);		//Inserimento figlio al nodo LastInsert
		bool ConfermaSequenza(int Carattere);	//Conferma della sequenza appena inserita associandola a un carattere
		void StampaFigli();						//Stampo di tutti i figli di LastInsert
		void ResetPointer();					//Resetta LastInsert facendolo ripuntare alla testa
		void SalvaAlberoFile(string NomeFile);	//Dato un nome, viene salvata la struttura dell'albero corrente su un file con il nome scelto
		void CaricaAlberoFile(string NomeFile);	//Dato un nome, viene caricata la struttura dell'albero corrente da un file con il nome scelto
		void CancellaAlbero();					//Cancella la struttura dell'albero attuale
		void InizializzaStampaCombinazioni();			//Stampa tutte le combinazioni presenti nel sistema
		
};
