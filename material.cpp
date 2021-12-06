#include <iostream>
#include "emojis.h"
#include "material.h"

Material::Material(string nombre, string emoji, int cantidad){
    this->nombre = nombre;
    this->emoji = emoji;
    this->cantidad = cantidad;
}

Material::Material(){
    this->nombre = "NULL";
    this->emoji = "NULL";
    this->cantidad = 0;
}

void Material::mostrar(){
    cout << devolver_nombre() << "( " << devolver_emoji() << " ) " << devolver_cantidad() <<   endl;
}

string Material::devolver_nombre(){
    return this->nombre;
}

string Material::devolver_emoji(){
    return this->emoji;
}

int Material::devolver_cantidad() {
    return this->cantidad;
}

void Material::modificar_cantidad(int cantidad) {
    this->cantidad = cantidad;
}

void Material::aumentar_cantidad(int cantidad) {
    this->cantidad +=cantidad;
}

void Material::reducir_cantidad(int cantidad) {
    this->cantidad -=cantidad;
}


void Material::imprimir_resumen(){
    cout <<"\tSoy un material de nombre " << nombre << " ( " << emoji << " ) y me encuentro en el casillero consultado."<< endl;
}

Material::~Material(){}
