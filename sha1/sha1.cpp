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

}