#include "TREE.h"

TREE::TREE()
{
	//Inizializzazione testa e LastInsert
	Head 			= new NODO;
	Head->Figli 	= new LISTA;
	Head->Lettera 	= 0;
	Head->Numero 	= 0;
	
	LastInsert = Head;
}

TREE::~TREE()
{
	//Rilascio memoria di tutti i figli di head (E i figli dei figli dei figli ecc.)
	Head->Figli->CancellaRami();
	delete Head;					//Rilascia la memoria Head
}

/*
	Dato un numero "Numero", la funzione ricerca se tra i figli dell'ultimo nodo inserito
	è presente uno che abbia Nodo->Numero uguale al numero inserito dall'utente.
	
	Se è presente LastInsert assume l'indirizzo di tale nodo, altrimenti lo crea.
	
	Se il nodo interessato è già presente ed è un nodo terminale, returna il valore ascii di tale sequenza,
	altrimenti returna il valore 0.
*/
char TREE::InserisciNumero(int Numero)
{
	char LetteraSequenza = 0;
	
	NODO *NodoInteressato;
	
	//Controllo della presenza tra i figli del nodo LastInsert del nuovo nodo d'interesse
	NodoInteressato = LastInsert->Figli->IsThereNum(Numero);
	
	if(NodoInteressato)	//Se il nodo esiste
	{	
		if(NodoInteressato->Lettera == 0)	//Se uil nodo non è terminale
			LastInsert = NodoInteressato;	//LastInsert punta al nuovo nodo
		else
			LetteraSequenza = NodoInteressato->Lettera;	//Memorizza il carattere della sequenza terminata
	}
	else	//Se non esiste
	{
		LastInsert = LastInsert->Figli->Inserisci(Numero);	//Crealo, LastInsert assume tale indirizzo
	}

	return LetteraSequenza;
}

/*
	Dato un carattere alla funzione, 
*/
bool TREE::ConfermaSequenza(int Carattere)
{
	bool Done = false;
	
	if(LastInsert != Head && !LastInsert->Figli->GetNumFigl())
	{
		Done = true;
		LastInsert->Lettera = Carattere;
	}
	
	return Done;
}

void TREE::StampaFigli()
{	
	LastInsert->Figli->Stampa();
}

void TREE::ResetPointer()
{
	LastInsert = Head;
}

/*
	1° byte numero della sequenza,
	2° byte char terminale
	3° int  numero figli
*/
void TREE::SalvaAlberoFile(string NomeFile)
{
	fstream Canale;
	
	Canale.open(NomeFile,ios::out | ios::binary);
	
	if(Canale.is_open())
	{
		ResetPointer();
		
		int NFigli = Head->Figli->GetNumFigl();
		
		Canale.write((char*)(&NFigli), sizeof(int));
		
		Head->Figli->SalvaNodiFile(Canale);
		
		Canale.close();
	}
}

void TREE::CaricaAlberoFile(string NomeFile)
{
	fstream Canale;
	
	Canale.open(NomeFile,ios::in | ios::binary);
	
	if(Canale.is_open())
	{
		int NumeroFigli_1;
		
		Canale.read((char*)&NumeroFigli_1,sizeof(int));
		
		for(int i = 0; i < NumeroFigli_1; i++)
		{
			char Numero;
			char Lettera;
			int  NumeroFigli_2;
			
			Canale.read(&Numero, sizeof(char));
			Canale.read(&Lettera, sizeof(char));
			Canale.read((char*)&NumeroFigli_2,sizeof(int));
			
			Head->Figli->Inserisci((int)Numero);
			
			if(NumeroFigli_2)
				CaricaFigliNodo(Head->Figli->IsThereNum(Numero),NumeroFigli_2, Canale);
			else
			{
				NODO* App = Head->Figli->IsThereNum(Numero);
				App->Lettera = Lettera;
			}
		}
		
		Canale.close();
	}
}

void TREE::CaricaFigliNodo(NODO* Nodo, int NumeroFigli_1, fstream &Canale)
{
	for(int i = 0; i < NumeroFigli_1; i++)
	{
		char Numero;
		char Lettera;
		int  NumeroFigli_2;
		
		Canale.read(&Numero, sizeof(char));
		Canale.read(&Lettera, sizeof(char));
		Canale.read((char*)&NumeroFigli_2,sizeof(int));
		
		Nodo->Figli->Inserisci((int)Numero);
		
		if(NumeroFigli_2)
			CaricaFigliNodo(Nodo->Figli->IsThereNum(Numero),NumeroFigli_2, Canale);
		else
		{
			NODO* App = Nodo->Figli->IsThereNum(Numero);
			App->Lettera = Lettera;
		}
	}
}

void TREE::CancellaAlbero()
{
	Head->Figli->CancellaRami();
	ResetPointer();
}

void TREE::InizializzaStampaCombinazioni()
{
	string Sequenza = "";
	
	Head->Figli->StampaSequenza(Sequenza);
}

void TREE::StampaCombinazioniEffettive(NODO* Nodo, string Sequenza)
{

}
