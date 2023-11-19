#ifndef FRESHMAN_H
#define FRESHMAN_H

#include <string>

class Freshman {
private:
    int id, weigth_sep, weigth_dec;
    double bmi_sep, bmi_dec;

public:
    // Constructores
    Freshman(int, int, int, double, double); 
    
    // Getters 
    int getid();
    int get_w_sep();
    int get_w_dec();
    double get_bmi_sep();
    double get_bmi_dec();
    
    // Voids
    void print(); // Impresión de pantallasos para visualizar
};

#endif
