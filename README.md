# Il-grande-cifrario
--> PROGRAMMAZIONE PROCEDURALE CON LABORATORIO <--

-->DESCRIZIONE<--
--
L'algoritmo è composto da 3 cifrari fatti in linguaggio C.
1 - Cifrario di Cesare
2 - Cifrario a Sostituzione
3 - Cifrario a Staccionata

Di seguito le descrizioni fornite dal professore dell'università:
1) In crittografia il cifrario di Cesare è uno dei più antichi algoritmi crittografici di cui si abbia traccia storica.
È un cifrario a sostituzione monoalfabetica in cui ogni lettera del testo in chiaro è sostituita nel testo cifrato
dalla lettera che si trova un certo numero di posizioni dopo nell’alfabeto.
Questi tipi di cifrari sono detti anche cifrari a sostituzione o cifrari a scorrimento a causa del loro modo di operare:
la sostituzione avviene lettera per lettera, scorrendo il testo dall’inizio alla fine.
Come è noto, Giulio Cesare usava, nel corso delle varie guerre, comunicare attraverso dispacci cifrati.
Il codice usato da Cesare era un semplice cifrario di sostituzione dove le lettere alfabetiche
differivano di una costante (chiave k) dalle lettere codificate in chiaro.
https://it.wikipedia.org/wiki/Cifrario_di_Cesare.

2) La sostituzione operante su singole lettere, detta sostituzione semplice,
si applica utilizzando un altro alfabeto scritto con le lettere disposte in un certo ordine detto alfabeto per la sostituzione.
Questo può essere preparato ruotando od invertendo l’alfabeto (creando così, rispettivamente, il cifrario di Cesare in Sezione 1, ed il cifrario Atbash)
oppure mescolando le lettere secondo un ordine prestabilito: in quest’ultimo caso si parla di alfabeto mescolato o alfabeto squilibrato.
https://it.wikipedia.org/wiki/Cifrario_a_sostituzione.

3) Il cifrario a staccionata (noto anche come cifrario a zigzag) è un tipo di cifrario a trasposizione che deve il suo nome al modo in cui
il testo in chiaro viene cifrato: esso viene trascritto lettera per lettera su righe ideali,
diagonalmente verso il basso e poi risalendo una volta arrivati alla riga più bassa e viceversa arrivati alla riga più in alto, disegnando
ipotetiche traverse di un’immaginaria staccionata oppure di uno zigzag.
Il messaggio cifrato si ottiene, alla fine, leggendo le lettere così posizionate riga per riga.
https://it.wikipedia.org/wiki/Cifrario_a_staccionata

-->COME VIENE SVOLTO L'ESERCIZIO<--
--
Scrivere un programma su un file singolo di nome soluzione.c (non modificare il nome del file) 
che per prima cosa prende in input da tastiera una stringa con caratteri senza vincoli, contenente quindi anche numeri,
simboli di punteggiatura, etc (è in gergo il nostro plaintext); 
fare riferimento alla Figura 3 per la dimensione massima della stringa e come leggerla: fgets è una funzione della libreria stdio.h.
Come prima cosa, si elimini dalla stringa ricevuta tutti i caratteri che non fanno parte dell’alfabeto, cioè a-z, A-Z. 
Supporre di utilizzare l’alfabeto inglese (26 lettere).
Inoltre, le lettere maiuscole diventano minuscole. 
Per esempio, la stringa “Ciao, come stai?” deve essere trasformata in “ciaocomestai”.
A questo punto, l’utente sceglie con quale dei tre metodi sopra descritti vuole cifrare
la stringa:
1. Il cifrario di Cesare;
2. Il cifrario a sostituzione (alfabeto mescolato).
3. Il cifrario a staccionata.

Esempio per definire la stringa da leggere e leggere la stringa da tastiera con fgets
      char s t r i n g a [ 5 6 ] ;
      f g e t s ( s t r i n g a , s i z e o f ( s t r i n g a ) , s t d i n ) ;

-->SUGGERIMENTO<--
--
1) Se l’utente richiede il cifrario di Cesare, si deve richiedere in input da tastiera anche la chiave k,
e poi restituire in output la stringa cifrata. In gergo, il risultato della cifratura è chiamato cyphertext.
2) Seguendo il codice ASCII3, le lettere minuscole vanno da 97 (la “a”) a 122 (la “z”). 
122 + 1 (per esempio se k = 1) deve quindi ritornare 97 (la “z” viene stampata come “a”). Utilizzare l’operatore modulo (per esempio).
3) Se l’utente richiede la cifratura a sostituzione, richiedere l’alfabeto mescolato all’utente, e poi successivamente restituire in output il cyphertext.
la stringa che rappresenta l’alfabeto mescolato, presa anch’esso da tastiera, deve contenere tutte e sole le 26 lettere dell’alfabeto.
Si deve quindi controllare se i) non ci sono lettere ripetute e ii) ci sono solo caratteri che sono lettere “a,b,c, ..., z”.
L’alfabeto mescolato può essere preso in input con una fgets e inserito in un array di 26 caratteri (per esempio, l’array può essere chiamato alfabeto_mescolato).
Anche in questo caso il cyphertext deve essere stampato sullo schermo.
4) Possono essere utilizzate le librerie di sistema come la libreria string.h4 e la libreria di sistema ctype.h5
ed in particolare la funzione islower() e isalpha() per controllare ii).
La funzione isalpha() in ctype.h è in particolare utile per controllare se un carattere è una lettere oppure no.
Per controllare i), per ogni carattere in alfabeto_mescolato, controllare che gli altri 25 caratteri in alfabeto_mescolato siano diversi
da quello (utilizzare due cicli for uno dentro l’altra).
5) Se l’utente richiede la cifratura a staccionata, cifrare la stringa attraverso un cifrario a staccionata6, utilizzando 3 righe
(come nell’esempio di Wikipedia di cui è stato riportato il link).
6) Utilizzare una matrice di 3 righe e 56 colonne. Anche in questo caso il cyphertext deve essere stampato sullo schermo.

-->ATTENZIONE<--
--
Attenzione, in C si possono verificare errori tipici durante la lettura dal
buffer di input. Per esempio un carattere di nuova linea \n può rimanere nel buffer dopo
una prima operazione di lettura, ed una seguente operazione di lettura può leggere
quello invece di attendere input da tastiera da parte dell’utente. Oppure, se ciò che
3 https://www.asciitable.com.
4 https://www.tutorialspoint.com/c_standard_library/string_h.htm.
5 https://www.tutorialspoint.com/c_standard_library/ctype_h.htm.
6 https://it.wikipedia.org/wiki/Cifrario_a_staccionata.
viene letto da tastiera è più lungo del limite utilizzato nella fgets, i caratteri in più
possono rimanere nel buffer di lettura. Utilizzare stackoverflow7, 
8, dove si può trovare tutta l’informazione ed esempi di cui si ha bisogno. 
Riassumendo, il buffer di lettura deve essere pulito tra due letture consecutive.
Attenzione 2 Non utilizzare la funzione fflush()9 perché sullo standard input, associato
alla tastiera, (stdin) il suo comportamento è indefinito C.

-->SUBMIT<--
--
Si accettano solo sottomissioni attraverso GitHub all’indirizzo https://classroom.github.com/a/-_hew_Vr.
È necessario creare un account GitHub prima di cliccare sul link. 
Lo studente deve essere in grado di verificare da solo se il push delle modifiche
effettuate in locale abbia avuto successo o meno (non si risponde a domande come “Può
controllare se ho sottomesso correttamente?”).
. L’utilizzo delle funzionalità minime di
Github fa infatti parte delle conoscenze richiesta dal corso.
Per quanto riguarda l’esercizio si prega di non creare branch secondari, ma di modificare il solamente template nel branch principale: al momento del download per la
correzione, i branch secondari non sono visibili e quindi il repository risulterebbe vuoto. Infine, non è necessario avere i diritti di amministratore da parte dello studente,
che infatti non sono concessi in modo da per esempio non poter rendere il repository
pubblico (in quanto esercizio individuale).
Nel template dell’esercizio è presente un file .gitignore che previene il push di file
eseguibili (.exe o .out) e altri, che non devono far parte dal versionamento offerto da GitHub. L’esercizio valutato deve essere contenuto nel file soluzione.c, che è già presente
nel template della cartella GitHub quando viene clonata in locale.
La scadenza per la sottomissione è Domenica 26 Novembre (ore 23:59).
Nel file
README.md del repository aggiungere, ricordarsi di aggiungere 1) nome, 2) cognome
e 3) matricola


N.B
Compilare aggiungendo i flag -std=c11 -Wall (per esempio gcc crypto.c -std=c11 -Wall
I warning devono essere tutti rimossi
Possono essere utilizzare solamente le librerie standard fornite da C (per esempio stdio.h, string.h, ctype.h, etc.).
