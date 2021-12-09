#ifndef NODO_PRIMITIVO_H
#define NODO_PRIMITIVO_H

template<typename T>
class Nodo_primitivo{
    private:
        T contenido;
        Nodo_primitivo<T>* siguiente;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Nodo_primitivo.
         */
        Nodo_primitivo(T contenido);

        /*
         * Pre: -.
         * Post: Me va a cambiar el contenido del nodo.
         */
        void cambiar_dato(T contenido);
        
        /*
         * Pre: -.
         * Post: Me va a devolver el contenido del nodo.
         */
        T devolver_dato();

        /*
         * Pre: -.
         * Post: Devuelve el nombre del nodo.
         */
        string obtener_nombre();

        /*
         * Pre: -.
         * Post: Devuelve el nodo siguiente.
         */
        Nodo_primitivo<T>*& direccion_siguiente();

        /*
         * Pre: -.
         * Post: Le asigna como siguiente el nodo recibido.
         */
        void cambiar_siguiente(Nodo_primitivo<T>* nuevo_siguiente);

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Nodo_primitivo.
         */
        ~Nodo_primitivo();
};

template<typename T>
Nodo_primitivo<T>::Nodo_primitivo(T contenido){
    this->contenido = contenido;
    siguiente = nullptr;
}

template<typename T>
void Nodo_primitivo<T>::cambiar_dato(T elemento){
    this->contenido = elemento;

}

template<typename T>
T Nodo_primitivo<T>::devolver_dato(){
    return contenido;
}

template<typename T>
Nodo_primitivo<T>*& Nodo_primitivo<T>::direccion_siguiente(){
    return siguiente;
}

template<typename T>
void Nodo_primitivo<T>::cambiar_siguiente(Nodo_primitivo<T>* nuevo_siguiente){
    siguiente = nuevo_siguiente;
}

template<typename T>
Nodo_primitivo<T>::~Nodo_primitivo(){}


#endif