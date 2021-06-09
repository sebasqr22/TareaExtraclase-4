#ifndef _SHA1_H_
#define _SHA1_H_

#include <stdint.h> 

#ifndef _SHA_tipos_
#define _SHA_tipos_
enum{
    completado = 0,
    nulo, 
    entradaLarga,
    error
};
#endif

//-------------------
#define hash 20
typedef struct contenido{
    uint32_t intermedio[hash/4];
    uint32_t largoBajo;
    uint32_t largoAlto;
    int_least16_t indiceBloque;
    uint8_t bloque[64];
    int terminado;
    int corrupto;
    
} contenido;

int reset(contenido *);
int entrada(
    contenido *,
    const uint8_t *,
    unsigned int);
int resultado(contenido *,
uint8_t mensaje[hash]);
#endif
