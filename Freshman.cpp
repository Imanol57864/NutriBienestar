#include "Freshman.h"
#include <iostream>
#include <iomanip>

Freshman::Freshman(int _id, int _weigth_sep, int _weigth_dec, double _bmi_sep, double _bmi_dec)
{
   id = _id;
   weigth_sep = _weigth_sep;
   weigth_dec = _weigth_dec;
   bmi_sep = _bmi_sep;
   bmi_dec = _bmi_dec;
}

// Getters
int Freshman::getid() {return id;}
int Freshman::get_w_sep() {return weigth_sep;}
int Freshman::get_w_dec() {return weigth_dec;}
double Freshman::get_bmi_sep() {return bmi_sep;}
double Freshman::get_bmi_dec() {return bmi_dec;}

// Print
void Freshman::print()
{
   std::cout << "\n  ||  " << id << "  ";
   if (id > 9){std::cout << "||      " << weigth_sep;} else { std::cout << " ||      " << weigth_sep; }
   std::cout << "      ";
   std::cout << "||      " << weigth_dec << "      ";
   std::cout << "||   " << std::setprecision(2) << std::fixed << bmi_sep << "   ";
   std::cout << "||   "  << bmi_dec << "   ||";
}
