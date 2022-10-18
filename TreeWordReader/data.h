#define ESC 		27
#define ENTER 		13
#define SALVA		-115
#define CARICA		39
#define STAMPATUTTO	'J'

struct NODO{
	char 	Numero;		//Carattere della sequenza
	char 	Lettera;	//Carattere corrispondente alla sequenza (Destinata al nodo terminale)
	LISTA 	*Figli;		//Puntatore all'oggetto che gestisce tutti i figli del nodo attuale
	NODO 	*Next;		//Puntatore al prossimo "fratello" 
};
