#include "liste.h"

/*
	La funzione inserisce un nodo corrispondente a un numero nella lista.
	La funzione returna l'indirizzo del nodo appena creato.
*/
NODO* LISTA::Inserisci(int Numero)
{
	NODO 	*Pt,	//Puntatore al nodo da creare
			*Scr1,	//Puntatore di scorrimento 1
			*Scr2;	//Puntatore di scorrimento 2
			
	//Creazione nodo . . .
	Pt = new NODO;
	Pt->Numero = Numero;
	Pt->Lettera = 0;
	Pt->Figli = new LISTA;
	
	//Scorrimento della lista fino a che il nodo[n+1]->Numero sia maggiore del numero che vogliamo.
	//Ergo l'indirizzo nodo[n] � ci� che ci interessa per procedere (Src1)
	for(Scr1 = Head, Scr2 = Head->Next; Scr2 && Numero > Scr2->Numero; Scr1 = Scr1->Next, Scr2 = Scr1->Next);
	
	Scr1->Next = Pt;
	Pt->Next = Scr2;

	TotaleNumeri++;		//Incrementa il numero dei figli presenti nella lista
	
	return Pt;			//Restituisci l'indirizzo del nodo appena creato
}

//Questa funzione stampa tutti i valori "numero" di tutti i nodi della lista
void LISTA::Stampa()
{
	NODO *Pt;
	Pt = Head->Next;				//Punta al primo nodo
	
	while(Pt!=0)					//Fino all'ultimo elemento della lista
	{
		cout<<Pt->Numero<<" ";
		Pt = Pt->Next;				//passa al prossimo
	}
	cout<<endl;
}

void LISTA::StampaSequenza(string Sequenza)
{
	NODO *Pt;
	Pt = Head->Next;				//Punta al primo nodo
	
	while(Pt!=0)					//Fino all'ultimo elemento della lista
	{
		Sequenza = Sequenza+(Pt->Numero);
		
		if(!Pt->Figli->GetNumFigl()) //Se questo figlio non ha nodi
			cout<<"Stampo una sequenza : "<<Sequenza<<endl;
		else
		{
			Pt->Figli->StampaSequenza(Sequenza);
		}
		
		Pt = Pt->Next;				//passa al prossimo
	}
	cout<<endl;
}

//Passato il valore "Numero" alla funzione, restituisce l'indirizzo del nodo di valore richiesto, altrimenti null.
NODO* LISTA::IsThereNum(int Numero)
{
	NODO *Pt;
	bool Found;
	
	for(Pt = Head->Next, Found = false; Pt && !Found;)	//Fino a che non si � arrivati alla fine e non � stato trovato alcun match
		if(Numero == Pt->Numero)
			Found = true;
		else
			Pt = Pt->Next;

	return Pt;
}

//Cancellazione di tutti i figli, figli dei figli ecc. della lista.
//Cancellazione di tutti i nodi presenti della lista.
void LISTA::CancellaRami()
{	
	TotaleNumeri = 0;
	
	for(NODO* Pt = Head->Next, *App;Pt;)	//Per ogni nodo della lista
	{
		Pt->Figli->CancellaRami();			//Cancella tutti i suoi figli
		App = Pt->Next;						//Memorizza l'indirizzo del prossimo nodo
		delete Pt;							//Cancella il nodo attuale
		Pt = App;							//Passa al prossimo
	}
	
	Head->Next = NULL;
}

int LISTA::GetNumFigl()
{
	return TotaleNumeri;
}

void LISTA::SalvaNodiFile(fstream &Canale)
{
	for(NODO* Pt = Head->Next, *App;Pt;Pt = Pt->Next)	//Per ogni nodo della lista
	{
		int NFigli = Pt->Figli->GetNumFigl();
		
		Canale.write(&Pt->Numero, sizeof(char));
		Canale.write(&Pt->Lettera, sizeof(char));
		Canale.write(reinterpret_cast<const char *>(&NFigli), sizeof(int));
		
		if(NFigli)
			Pt->Figli->SalvaNodiFile(Canale);
	}
}

NODO* LISTA::GetHeadLista()
{
	return Head;
}
