#ifndef RECETA_H
#define RECETA_H

class Receta {
    private:
        int piedra;
        int madera;
        int metal;
    public:
        Receta();
        Receta(int piedra, int madera, int metal);

        void modificar_piedra(int cantidad);
        void modificar_madera(int cantidad);
        void modificar_metal(int cantidad);

        int devoler_piedra();
        int devoler_madera();
        int devoler_metal();
};


#endif //RECETA_H
