#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "bd.h"




int main(int argc, char * argv [])
{ 
system("pause");
system("cls");

char sql2[90000];
sprintf(sql2,"select * from teste limit 1");

printf("%s", ConsultaUnica(sql2));

//while(atoi(ConsultaUnicaID(sql2)) != 0){
//        system("rastejar.exe");
//}
system("pause");
}
