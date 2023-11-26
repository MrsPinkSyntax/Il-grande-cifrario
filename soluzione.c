#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define maxLenghPlainText 56
#define alphabetSize 26

//BAMAAROUF CHADIA - Data di consegna 26/11/2023
/*
Algoritmo composto da 3 cifrari:
Cifrario di cesare; cifrario a sostituzione e cifrario a staccionata
Viene implementato un sistema di scelta della cifratura attraverso cui l'utente inserisce 
plaintext che viene convertito in cyphertext.

*/

//Funzione generica per rimozione caratteri non ammessi
void preprocessString(char *strInput) {
    int i, j = 0;
    for (i = 0; strInput[i] != '\0'; i++) {
        if (isalpha(strInput[i])) {
            strInput[j++] = tolower(strInput[i]);
        }
    }
    strInput[j] = '\0';
}

//funzione per il cifrario di cesare
void encryptCaesar(char *plaintext, int key) {
    for(int i = 0; plaintext[i] != '\0'; i++) {
        plaintext[i] = (plaintext[i] - 'a' + key) % alphabetSize + 'a';
    }
}


// Verifica alfabeto in input per il cifrario a sostituzione
int isValidAlphabet(const char *alphabetSub) {
    if (strlen(alphabetSub) != alphabetSize) {
        // Lunghezza non corretta
        printf("ERRORE! Lunghezza alfabeto inserito\n");
        return 0;
    }

    for (int i = 0; i < alphabetSize; i++ ) {
        // Contiene caratteri non validi come maiuscoli o speciali ecc.
        if (!isalpha(alphabetSub[i]) || !islower(alphabetSub[i])) {
            printf("ATTENZIONE! Sono stati inseriti caratteri non ammessi nell'alfabeto\n");
            return 0;
        }

        for (int j = i+1; j < alphabetSize; j++) {
            // Sono presenti dei duplicati
            if (alphabetSub[i] == alphabetSub[j]) {
                printf("ERRORE! Sono stati rilevati dei duplicati\n");
                return 0;
            }
        }
    }

    // Raggiunto questo punto l'array dell'alfabeto è valido
    return 1; 
}

//funzione per cifrare il cyphertext con il cifrario a sostituzione

void encryptSubstitution(char *plaintext, const char *alphabetSub) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            int index = tolower(plaintext[i]) - 'a';
            plaintext[i] = islower(plaintext[i]) ? tolower(alphabetSub[index]) : toupper(alphabetSub[index]);
        }
    }
}

/*
void inizializzaMatrix(char *matrixRailFence, int rows, int cols, char *plaintext) {
    for(int i = 0; i<rows;i++) {
        for(int j = 0; j<strlen(plaintext); j++) {
            matrixRailFence[i][j] = '.';
            printf("%c", matrixRailFence[i][j]);
        }
        printf("\n");
    }
    printf("\n");
} 
*/

void encryptRailFence(char *plaintext, int rows) {
    int posizione = 0, direzione = 1;

    char matrixRailFence[rows][maxLenghPlainText];

    //Inizializzazione della matrice con puntini
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < strlen(plaintext); j++) {
            matrixRailFence[i][j] = '.';
        }
    }

    for (int i = 0; i < strlen(plaintext); i++) {
        matrixRailFence[posizione][i] = plaintext[i];
        if (i > 0) {
            if (posizione == 0 || posizione == rows - 1) {
                direzione = -direzione;
            }
        }
        posizione += direzione;
    }

    //stampa della matrice
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < strlen(plaintext); j++) {
            printf("%c", matrixRailFence[i][j]);
        }
        printf("\n");
    }

    char cyphertext[maxLenghPlainText];
    int index = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < strlen(plaintext); j++) {
            if (matrixRailFence[i][j] != '.') {
                cyphertext[index++] = matrixRailFence[i][j];
            }
        }
    }
    cyphertext[index] = '\0';
    printf("\nCyphertext: %s\n", cyphertext);
}


int main () {
    char plaintext[maxLenghPlainText];
    char alphabet_mescolato[alphabetSize + 1];
    int key, choice;
    int flag = 0;
    int rows = 3;
    char matrixRailFence[rows][maxLenghPlainText];

    //Input del plaintext
    printf("Inserisci la stringa che vuoi cifrare: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    //rimuovo il newline inserito da fgets
    plaintext[strcspn(plaintext, "\n")] = '\0';
    //Pprocesso in anticipo la stringa così che entrando nei vari casi dovrò solo processare la cifratura
    preprocessString(plaintext);



    printf("\nScegli il metodo con cui vuoi cifrare\n");
    printf("1 - Il cifrario di Cesare\n2 - Il cifrario a sostituzione\n3 - Il cifrario a staccionata\n");
    printf("Digita il numero: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nHai scelto il cifrario di Cesare!\nIn questo metodo è richiesto l'inserimento di una chiave...\n");
            printf("Inserisci la chiave: ");
            scanf("%d", &key);
            encryptCaesar(plaintext, key);

            printf("\nIl Cyphertext è: %s\n", plaintext);

        break;
        case 2:
            //cifrario a sostituzione
            while(!flag) {
                //input ddell'alfabeto mescolato con gestione degli errori
                
                printf("Inserisci l'alfabeto mescolato (minuscolo, senza ripetizioni): ");
                
                fgets(alphabet_mescolato, sizeof(alphabet_mescolato), stdin);
                /*rimuovo anche qui il new line inserito da fgets*/
                alphabet_mescolato[strcspn(alphabet_mescolato, "\n")] = '\0';
                
                //verifica la validità dell'alfabeto mescolato
                if(!isValidAlphabet(alphabet_mescolato)) {
                    printf("L'alfabeto mescolato non è valido.\nAssicurati che siano presenti solo lettere minuscole e senza ripetizioni.\n");
                    flag = 0;

                } else {
                    //input valido si esce dal ciclo
                    flag = 1;
                }

                
            }
            encryptSubstitution(plaintext, alphabet_mescolato);
            printf("\nIl Cyphertext è: %s\n", plaintext);
            

        break;
        case 3:
            //Codice per il cifrario a staccionata
            int rows = 3;
            encryptRailFence(plaintext, rows);
            break;
        default:
        printf("scelta invalida...ritenta\n");
        return 1;
    }

    return 0;
}
