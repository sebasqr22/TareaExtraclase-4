#include "sha1.cpp"
#include <iostream>
#include <string.h>

#define t1 "sad"
#define t2 "hola"
#define t3 "2345243"
#define t4 "fdshjhtrtf"

using namespace std;

long int repeticion[4] = {1,1,1000000,10};

char *prueba[4]{
    t1,
    t2,
    t3,
    t4
};

int main(){
    contenido sha1;
    int i, j, error;
    uint8_t mensaje[20];
    for(j=0; j<4; j++){
        cout << j+1 << repeticion[j] << prueba[j];
        error = reset(&sha1);
        if(error){
            fprintf(stderr, "Error de reset: ", error);
            break;
        }
        for(i=0; i<repeticion[j]; i++){
            error = entrada(&sha1, (const unsigned char *) prueba[j], strlen(prueba[j]));
            if(error){
                fprintf(stderr, "Error de reset: ", error);
                break;
            }
        }
        error = resultado(&sha1, mensaje);
        if(error){
            fprintf(stderr, "Se puede computar...", error);
        }
        else{
            for(i=0; i<20; i++){
                cout << mensaje[i] << "\n";
            }
        }
    }
    error = entrada(&sha1, (const unsigned char *) prueba[1], 1);
    cout << "Error: " << error;
    error = reset(0);
    return 0;
}