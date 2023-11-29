#include <iostream>
#include <vector>
#include <fstream>
#include <variant>
#include "avl.h"

using namespace std;

// Función de ordenamiento por selección
void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(arr[i], arr[min_index]);
        }
    }
}

int main() 
{
  vector<int> valoresEncontrados;
  vector<int> valoresOrdenados;
  int opcion = 0;
  while (opcion != 1 or opcion != 2)
  {
    cout<<"ingrese"<< endl << "1 para utilizar datos previamente registrados"<<endl <<"2 para ingresar nuevos datos."<<endl;
  cin>>opcion;

  if(opcion ==1)
  {
    ifstream archivo("OndasS.txt");
    if (!archivo.is_open())
    {
      cout<<"error al abrir archivo ";
      return 0;
    }
  // Creacion del arbol
    AVL<int> arbolOndas; 
    
    int onda;
    while (archivo >> onda) 
    {
      arbolOndas.add(onda); // Insertar la onda sonora en el árbol AVL
    }
  
    cout << "Ondas sonoras obtenidas:" << endl;
    // muestra los datos onda en orden
    cout << arbolOndas.inorder() << endl; 
  
    archivo.close();

    // Guardar los datos ordenados en un  nuevo archivo
    ofstream nuevoArchivo("OndasOrden.txt");
    if (nuevoArchivo.is_open()) {
      nuevoArchivo << arbolOndas.inorderTo(); 
      cout<< endl;

        nuevoArchivo.close();
        cout << "Nuevos datos guardados en OndasOrden.txt" << endl;
    } else {
        cout << "Error al abrir el archivo para escribir los nuevos datos." << endl;
    }
    
    //busqueda de datos en el arbol.
    int opcion2;
    while(opcion2 != 2)
    {
      cout<<"desea buscar algun valor en especifico de la muestra?"<<endl<<"1 = si"<<endl<<"2 = no"<<endl;
      
      cin>>opcion2;
      if(opcion2 == 1)
      {
        int valorBuscado;
        cout<< "ingrese el valor a buscar:"<< endl;
        cin>>valorBuscado;
  
        bool encontrado = arbolOndas.find(valorBuscado);
        if (encontrado) 
        {
          cout << "El valor " << valorBuscado << " está presente en el árbol." << endl;
  
          // Almacenar el valor encontrado en un vector
          valoresEncontrados.push_back(valorBuscado);
          
        } else {
            cout << "El valor " << valorBuscado << " no se encuentra en el árbol." << endl;
        }
        
      }
      if(opcion2 == 2)
      {
        cout<<"ok, terminando el programa"<<endl;
        cout<<"Los datos buscados fueron los siguientes:"<<endl;
        for(int i = 0; i < valoresEncontrados.size();i++)
        {  
        cout<<" "<<valoresEncontrados[i]<<" ";
        }
        selectionSort(valoresEncontrados);
        cout<<endl<<"permiteme ordenar los datos proporsionados"<<endl;

        for(int i = 0; i < valoresEncontrados.size();i++)
          {  
          cout<<" "<<valoresEncontrados[i]<<" ";
          }
      }
      if(opcion2 <1 or opcion2 >2)
      {
        cout<<"esa opcion no es valida" << endl;
      }
    }
    
    return 0;
  }
  
  // opcion de registro de datos.
  if (opcion ==2)
  {
    AVL<int> arbolOndas;
    int nuevo;
    for (int i = 0; i < 24;i++)
    {
      cout << "dame un valor: ";
      cin>>nuevo;
      cout << endl;
      arbolOndas.add(nuevo);
    }
  
    cout <<"nuevo conjunto de ondas creado "<<endl;
    cout << arbolOndas.inorder() << endl;

    // Guardar los nuevos datos en un archivo
    ofstream nuevoArchivo("NuevasOndas.txt");
    if (nuevoArchivo.is_open()) {
      nuevoArchivo << arbolOndas.inorderTo(); 
      cout<< endl;
      
        nuevoArchivo.close();
        cout << "Nuevos datos guardados en NuevasOndas.txt" << endl;
    } else {
        cout << "Error al abrir el archivo para escribir los nuevos datos." << endl;
    }
    
    //Busqueda de datos en el arbol.
    int opcion2;
    while(opcion2 != 2)
    {
      cout<<"desea buscar algun valor en especifico de la muestra?"<<endl<<"1 = si"<<endl<<"2 = no"<<endl;

      cin>>opcion2;
      if(opcion2 == 1)
      {
        int valorBuscado;
        cout<< "ingrese el valor a buscar:"<< endl;
        cin>>valorBuscado;

        bool encontrado = arbolOndas.find(valorBuscado);
        if (encontrado) 
        {
          cout << "El valor " << valorBuscado << " está presente en el árbol." << endl;

          // Almacenar el valor encontrado en un vector
          valoresEncontrados.push_back(valorBuscado);

        } else {
            cout << "El valor " << valorBuscado << " no se encuentra en el árbol." << endl;
        }

      }
      if(opcion2 == 2)
      {
        cout<<"ok, terminando el programa"<<endl;
        cout<<"Los datos buscados fueron los siguientes:"<<endl;
        for(int i = 0; i < valoresEncontrados.size();i++)
        {  
        cout<<" "<<valoresEncontrados[i]<<" ";
        }
        selectionSort(valoresEncontrados);
        cout<<endl<<"permiteme ordenar los datos proporsionados"<<endl;

        for(int i = 0; i < valoresEncontrados.size();i++)
          {  
          cout<<" "<<valoresEncontrados[i]<<" ";
          }
      }
      else{
        cout<<"esa opcion no es valida" << endl;
      }
    }
    
    return 0;
  }

  else
    {
    cout<<"opcion no valida";
    
    }
  }

}