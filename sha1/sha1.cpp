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
        contexto->largoBajo += 8;
        if(contexto->largoBajo == 0){
            contexto->largoAlto++;
            if(contexto->largoAlto == 0){
                contexto->corrupto = 1;
            }
        }
        if(contexto->indiceBloque == 64){
            Procesamiento(contexto);
        }
        listaMsg++;
    }
    return completado;
}
void Procesamiento(contenido *contexto){
    const uint32_t lista[] = {
        0x5A827999,
        0x6ED9EBA1,
        0x8F1BBCDC,
        0xCA62C1D6
    };
    int contador;
    uint32_t tmp;
    uint32_t Palabra[80];
    uint32_t A, B, C, D, E;

    for(contador = 0; contador < 80; contador ++){
        Palabra[contador] = ShiftCircular(1, Palabra[contador-3] ^ Palabra[contador-8] ^ Palabra[contador-14] ^ Palabra[contador-16]);
    }
    A = contexto->intermedio[0];
    B = contexto->intermedio[1]; 
    C = contexto->intermedio[2];
    D = contexto->intermedio[3];
    E = contexto->intermedio[4];

    for(contador = 0; contador < 20; contador ++){
        tmp = ShiftCircular(5, A) + ((B & C) | ((~B) & D)) +_ E + Palabra[contador] + lista[0];
        E = D;
        D = C;
        C = ShiftCircular(30, B);
        B = A;
        A = tmp;
    }
}