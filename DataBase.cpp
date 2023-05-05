#include <string>
#include <stdio.h>
#include <conio.h>
#include <string.h>

HWND MENSSAGERIA;
using namespace std;
FILE *document;
void SaveDataBase(LPSTR DataText);

void SaveDataBase(LPSTR DataText){
    document = fopen("Saves/Save.txt","a+");
    if(document==NULL){
        MessageBox(MENSSAGERIA,"There are no files txt in the Saves folder, named -Save-","State",1);
    }
    fprintf(document,"%s \n",DataText);
    MessageBox(MENSSAGERIA,"Guardado Correctamente","Estado",1);
}
