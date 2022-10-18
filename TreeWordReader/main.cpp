#include<cstdlib>
#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>

using namespace std;

struct NODO;
class  TREE;
class  LISTA;

#include "data.h"
#include "liste.cpp"
#include "tree.cpp"

/*=============================================================

Obiettivo del programma:
	Il seguente programma serve a memorizzare delle sequenze
	di numeri. A ogni sequenza di numeri corrisponde un carattere
	scelto dall'utente. E' impossibile ripetere una sequenza di numeri
	precedentemente inserita per la memorizzazione di un nuovo carattere.

Strutture dati utilizzate:
	E' stato scelto un albero come struttura dati per memorizzare le sequenze.
	Ogni nodo può avere un numero indeterminato di figli.
	I figli per ogni nodo vengono gestiti da un oggetto di classe LISTA.

Metodologia di funzionamento:
	L'utente dovrà inserire carattere per carattere i numeri dei nodi
	rappresentati una sequenza già esistente. Se durante l'inserimento
	della sequenza, si giunga a un numero inesistente, questo viene creato.
	L'utente potrà quindi visualizzare,
	livello per livello, tutti i figli di ciascun nodo, dipendentemente
	da dove si trovi in quel momento. Se, durante la scelta dei nodi,
	si giunga a un nodo terminale (che corrisponde al termine di una 
	sequenza legato a un carattere,), il carattere in questione viene
	stampato su schermo e l'utente potrà ricominciare a creare/scegliere
	le sequenze di numeri dal nodo padre.

	Luca Gargiulo
-------------------------------------------------------------*/

main()
{
	TREE Albero;			//Oggetto per la memorizzazione delle sequenze
	char CarattereBattuto;	//Memorizza valore ascii del carattere battuto
	
	do
	{
		cout<<"________________________________________________________"<<endl;
		cout<<"Batti il carattere \"ì\" per salvare e \"'\" per caricare una struttura albero . . ."<<endl;
		cout<<"________________________________________________________"<<endl;
		cout<<"Lista figli del nodo corrente ..."<<endl;
		Albero.StampaFigli();	//Stampa dei figli dipendentemente dal nodo corrente
		
		cout<<"________________________________________________________"<<endl;
		cout<<"Inserisci un numero da inserire nell'albero : ";
		CarattereBattuto = getch();
		cout<<CarattereBattuto<<endl;
		
		if(CarattereBattuto >= '0' && CarattereBattuto <= '9')			//Se il carattere battuto è un numero
		{
			/*
				La variabile FeedBack può assumere i valori:
					0) Se il nodo selezionato non è un nodo terminale
				  !=0) Se il nodo selezionato è terminale
			*/
			char FeedBack = Albero.InserisciNumero(CarattereBattuto);	//Spostati verso il figlio di valore "CarattereBattuto" (Il nodo viene creato se inesistente)
			
			if(FeedBack != 0)	//se alla sequenza di numeri corrisponde già un carattere
			{
				Albero.ResetPointer();		//Torna al primo nodo dell'albero
				cout<<"________________________________________________________"<<endl;
				cout<<"Errore, sembra che questa sequenza esista gia'!"<<endl;
				cout<<"Corrisponde al carattere : "<<FeedBack<<endl;
			}
		}
		else if(CarattereBattuto == ENTER)	//Se si vuole confermare una sequenza
		{
			cout<<"________________________________________________________"<<endl;
			cout<<"Inserire carattere da confermare nella sequenza : ";
			char CarattereConfermaSequenza = getch();
			cout<<CarattereConfermaSequenza<<endl;
			
			if(Albero.ConfermaSequenza(CarattereConfermaSequenza))
				cout<<"Carattere aggiunto con successo!"<<endl;
			else
				cout<<"\nSembra tu non abbia inserito alcuna sequenza o che hai provato a far diventare un nodo con figli terminale!\nSpostamento al nodo iniziale . . ."<<endl;
			
			Albero.ResetPointer(); //Torna al primo nodo dell'albero
		}
		else if(CarattereBattuto == SALVA)	//se si vuole salvare la struttura albero su un file
		{
			cout<<"________________________________________________________"<<endl;
			cout<<"Inserire nome del file in cui salvare l'albero : ";
			string NomeFile;
			getline(cin,NomeFile);
			
			Albero.SalvaAlberoFile(NomeFile);
			cout<<"Salvataggio albero effettuato nel file : "<<NomeFile<<endl;
		}
		else if(CarattereBattuto == CARICA)	//se si vuole caricare la struttura albero da un file
		{
			cout<<"________________________________________________________"<<endl;
			cout<<"Inserire nome del file da cui l'albero : ";
			string NomeFile;
			getline(cin,NomeFile);
			
			Albero.CancellaAlbero();			//cancella la struttura dell'albero attuale
			Albero.CaricaAlberoFile(NomeFile);	//carica l'albero
		}
		else if(CarattereBattuto == STAMPATUTTO)
		{
			cout<<"________________________________________________________"<<endl;
			cout<<"Stampo tutte le combinazioni : "<<endl;
			Albero.InizializzaStampaCombinazioni();
			cout<<endl;
		}
	}
	while(CarattereBattuto != ESC);
}
