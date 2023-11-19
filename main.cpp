// https://ejuarez.bitbucket.io/tc1031/proyecto_3.html

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <random>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

// Alfonso Imanol Macias Marañon

// Setup
#include "Freshman.h"
list<Freshman *> DB{};
int option;
void menu();
void print_all();
bool compareFreshmen(Freshman *a, Freshman *b);
void binarySearchByID();
void readDB();
void writeDBToFile(const string resDB_freshman);

// main Setup
int main() {
  readDB();
  menu();
  return 0;
}

// menu setup
void menu() {
  while (true) {
    cout << "\n\n  BASE DE DATOS | PESO & BMI | NUTRIBIENESTAR";
    cout << "\n  Menu Principal. Elige la opcion que deseas visualizar.";
    cout << "\n  (1) Base de datos original.";
    cout << "\n  (2) Ordenar por bmi en Septiembre menor a mayor. (Introsort)";
    cout << "\n  (3) Ordenar por bmi en Diciembre menor a mayor. (Introsort)";
    cout << "\n  (4) Ordenar por peso en Septiembre menor a mayor. (Introsort)";
    cout << "\n  (5) Ordenar por peso en Diciembre menor a mayor. (Introsort)";
    cout << "\n  (6) Busqueda por ID. (Binary Search)";
    cout << "\n  (7) Guardar base de datos actual en formato archivo '.csv'. ";
    cout << "\n  (8) Cerrar.";
    cout << "\n  Ingrese un solo caracter: ";
    if (cin >> option) {
      if (option >= 1 && option <= 8)
        break;
    }
    cout << "\n  |!| Error al ingresar valores. \n  |!| Presione una tecla "
            "para volver a iniciar.";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  // Switch case para llamar a las funciones y ejecutar el menu
  switch (option) {
  case 6:
    binarySearchByID();
    break;
  case 7:
    writeDBToFile("resDB_freshman.csv");
    break;
  case 8:
    for (auto &freshman : DB)
      delete freshman;
    DB.clear();
    cout << "\n  |!| Programa cerrado exitosamente!\n";
    exit(0);
  default:
    DB.sort(compareFreshmen);
    print_all();
  }
  menu();
}

// Prototipo #1 - print setup
void print_all() {
  cout << "\n  ||  id  ||  weigth_sep  ||  weigth_dec  ||  bmi_sep  ||  "
          "bmi_dec  ||";
  for (auto &freshman : DB) {
    freshman->print();
  }
}

// Prototipo #2 - bool comparison for list::sort
bool compareFreshmen(Freshman *a, Freshman *b) {
  switch (option) {
  case 2:
    return a->get_w_sep() < b->get_w_dec();
  case 3:
    return a->get_w_dec() < b->get_w_dec();
  case 4:
    return a->get_bmi_sep() < b->get_bmi_sep();
  case 5:
    return a->get_bmi_dec() < b->get_bmi_dec();
  }
  return a->getid() < b->getid();
};

// Prototipo #3 - binary search by ID
void binarySearchByID() {
  DB.sort(compareFreshmen);
  int el_id;
  cout << "\n  Por favor, introduce el ID que deseas buscar: ";
  cin >> el_id;

  if (el_id < DB.front()->getid() || el_id > DB.back()->getid()) {
    cout << "\n  |!| La ID no se encuentra en la base de datos.";
    cout << "\n  |!| Por favor vuelve a intentar.";
    return;
  }

  auto low = DB.begin();
  auto high = DB.end();
  auto mid = low;
  Freshman *cursor = nullptr;

  int contador_low = 0;
  int contador_high = DB.size();
  int contador_mid = (contador_high - contador_low) / 2;

  while (contador_low <= contador_high) {
    contador_mid = (contador_high + contador_low) / 2;
    mid = DB.begin();
    advance(mid, contador_mid);
    cursor = *mid;

    if (cursor->getid() == el_id) {
      cout << "\n  "
              "||--------------------------------------------------------------"
              "--||";
      cout << "\n  ||  id  ||  weigth_sep  ||  weigth_dec  ||  bmi_sep  ||  "
              "bmi_dec  ||";
      cout << "\n  "
              "||--------------------------------------------------------------"
              "--||";
      cursor->print();
      cout << "\n  "
              "||--------------------------------------------------------------"
              "--||";
      break;
    } else if (cursor->getid() < el_id) {
      low = mid;
      advance(low, 1);                 // low = mid + 1; punteros
      contador_low = contador_mid + 1; // low += mid+1; int
    } else {
      high = mid;
      advance(low, -1);                 // high = mid + 1; punteros
      contador_high = contador_mid - 1; // low += mid+1; int
    }
  }
}

// Prototipo #4 - read database
void readDB() {
  ifstream file("freshman_kgs.csv");
  if (!file.is_open()) {
    cerr << "|!| Error al abrir el archivo." << endl;
    exit(1);
  }

  string line;
  getline(file, line); // Skip 1st
  while (getline(file, line)) {
    stringstream lineStream(line);
    string cell;
    getline(lineStream, cell, ','); // id
    int id = stoi(cell);

    getline(lineStream, cell, ','); // weigth_sep
    int weigth_sep_val = stoi(cell);

    getline(lineStream, cell, ','); // weigth_dec
    int weigth_dec_val = stoi(cell);

    getline(lineStream, cell, ','); // bmi_sep
    double bmi_sep_val = stod(cell);

    getline(lineStream, cell, ','); // bmi_dec
    double bmi_dec_val = stod(cell);

    // Agregar valores a las listas directamente
    DB.push_back(new Freshman(id, weigth_sep_val, weigth_dec_val, bmi_sep_val,
                              bmi_dec_val));
  }
  file.close();
}

// Prototipo #5 - write database to file
void writeDBToFile(const string resDB_freshman) {
  ofstream outFile(resDB_freshman);
  if (!outFile.is_open()) {
    std::cerr << "Error al abrir el archivo de salida." << std::endl;
    return;
  }

  outFile << "id,weigth_sep,weigth_dec,bmi_sep,bmi_dec\n";
  for (const auto &freshman : DB) {
    outFile << freshman->getid() << "," << freshman->get_w_sep() << ","
            << freshman->get_w_dec() << "," << freshman->get_bmi_sep() << ","
            << freshman->get_bmi_dec() << "\n";
  }
  outFile.close();
  std::cout << "\n  |!| Base de datos escrita en el archivo: " << resDB_freshman << "!";
}
