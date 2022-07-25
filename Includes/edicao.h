#ifndef EDICAO_H
#define EDICAO_H

#include "contato.h"

void editarNome(contato_t* agenda, int posicaoRegistro);

void editarCidade(contato_t* agenda, int posicaoRegistro);

void editarEstado(contato_t* agenda, int posicaoRegistro);

void editarPreferencia(contato_t* agenda, int posicaoRegistro);

void editarFutebol(contato_t* agenda, int posicaoRegistro);

void editarData(contato_t* agenda, int posicaoRegistro);

void editarBasquete(contato_t* agenda, int posicaoRegistro);

void editarVolei(contato_t* agenda, int posicaoRegistro);

int menuPreferencia();

int menuEdicao();

#endif