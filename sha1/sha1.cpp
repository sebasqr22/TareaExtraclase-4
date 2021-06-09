#include "sha1.h"

#define ShiftCircular(bits, palabra) \(((palabra)<<(bits)) | ((palabra) >> (32-(bits))))

void Mensaje(contenido *);
void Procesamiento(contenido *);
int reset(contenido *contexto){
    if(!contexto){
        return nulo;
    }
    contexto->largoBajo =0;
    contexto->largoAlto = 0;
    contexto->indiceBloque = 0;
    contexto->intermedio[0] = 0x67452301;
    contexto->intermedio[1] = 0xEFCDAB89;
    contexto->intermedio[2] = 0x98BADCFE;
    contexto->intermedio[3] = 0x10325476;
    contexto->intermedio[4] = 0xC3D2E1F0;
    contexto->terminado = 0;
    contexto->corrupto = 0;
    return completado;

}
int resultado(contenido * contexto, uint8_t mensaje[hash]){
    int tmp;
    if(!contexto || !mensaje){
        return nulo;
    }
    if(contexto->corrupto){
        return contexto->corrupto;
    }
    if(!contexto->terminado){
        Mensaje(contexto);
        for (int i=0; i<64; i++){
            contexto->bloque[i] = 0;
        }
        contexto->largoBajo = 0;
        contexto->largoAlto = 0;
        contexto->terminado = 1;
    }
    for(int j=0; j<hash; j++){
        mensaje[j] = contexto->intermedio[j>>2] >> 8*(3-(j & 0x03));
    }
    return completado;
}
int entrada(contenido *contexto, const uint8_t *listaMsg, unsigned largo){
    if(!largo){
        return completado;
    }
    if(contexto->corrupto){
        return contexto->corrupto;
    }
    while(largo-- & !contexto->corrupto){
        contexto->bloque[contexto->indiceBloque++] = (*listaMsg & 0xFF);
    }
}