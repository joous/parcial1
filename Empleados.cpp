#include <iostream>
#include <stdio.h>  
#include <string.h> 

using namespace std;

const char *nombe_archivo = "archivo.dat";

struct Empleado{
	int codigo;
	char nombre[50];
	char apellido[50];
	char puesto[50];
	int sueldo;
	int bonificacion;
	int sueldototal;
};
	
void ingresar_empleado();
void listar_empleado();
void modificar_empleado();
void buscar_empleado();



int main(){
	
	int opc;
	
		do{
			
			cout<<"\n\n \t\t 1: Ingresar Empleado " <<endl;
    		cout<<"\t\t 2: Modificar Empleado "<<endl;
    		cout<<"\t\t 3: Lista de Empleados "<<endl;
    		cout<<"\t\t 4: Eliminar Empleado "<<endl;
    		cout<<"\t\t 5: Buscar Enpleado"<<endl;
  			cout<<"\t\t 6: Salir "<<endl; 
			cin>>opc; 
	
					
			switch(opc){
		
				case 1:
						ingresar_empleado();
				break;
				
				case 2:
						modificar_empleado();
						
				break;
						
				case 3:
						listar_empleado();
				break;
				
				case 4:
					
				break;
				
				case 5:
						buscar_empleado();
				break;
				
				case 6:
					exit(1);
				break;
				
				
				default:
					cout<<"Opcion invalida"<<endl;
			}
	
		}while(opc != 6);
    	
	return 0;
}



void ingresar_empleado(){
	system("cls");
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); // ab
	
	
		Empleado empleado;
		string nombre,apellido;
		
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Sueldo Base:";
		cin>>empleado.sueldo;
		cin.ignore();
		
		cout<<"Ingrese la bonificacion:";
		cin>>empleado.bonificacion;
		cin.ignore();
		
		empleado.sueldototal = empleado.sueldo + empleado.bonificacion;

		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	
		system("cls");
}


void modificar_empleado(){
		system("cls");
		listar_empleado();
		cout<<endl;
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido;	
    	Empleado empleado;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Empleado), SEEK_SET );  // esto es lo que permite modificar en la pocision
	
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Sueldo Base:";
		cin>>empleado.sueldo;
		cin.ignore();
		
		
		cout<<"Ingrese la bonificacion:";
		cin>>empleado.bonificacion;
		cin.ignore();
		
		empleado.sueldototal = empleado.sueldo + empleado.bonificacion;

		
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
		fclose(archivo);
		system("PAUSE");


		system("cls");
}


void listar_empleado(){

		system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Empleado empleado;
	int registro=0;
	fread ( &empleado, sizeof(Empleado), 1, archivo );
	cout<<"________________________"<<endl;
	cout << "ID" <<"|"<< "Codigo" <<"|"<< "Nombre"<<"|"<<"Apellido"<<"|"<<"Sueldo Base"<<"|"<<"Bonificacion"<<"|"<<"Sueldo total"<<endl;	
		do{
		cout<<"________________________"<<endl;
		cout << registro <<" |  "<< empleado.codigo <<" | "<< empleado.nombre <<" "<< empleado.apellido <<" "<<empleado.sueldo<<" "<< empleado.bonificacion <<" "<<empleado.sueldototal <<endl;
        
        
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);

	}
	


void buscar_empleado(){
	
	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int indice=0,pos=0,cod=0;
	cout<<"BUSCAR CODIGO: ";
	cin>>cod;
	Empleado empleado;
	
	fread ( &empleado, sizeof(Empleado), 1, archivo );
		
		do{
			
			if (empleado.codigo == cod){
			pos = indice;
			}
	
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
		
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );

    fread ( &empleado, sizeof( Empleado ), 1, archivo );

    	cout << "Codigo: " << empleado.codigo << endl;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Apellido: " << empleado.apellido << endl;
        cout << "Sueldo Base: " << empleado.sueldo << endl;
        cout << "Sueldo Base: " << empleado.bonificacion << endl;
        cout << "Sueldo Total: " << empleado.sueldototal << endl;
        cout << endl;
	
	fclose(archivo);
	system("PAUSE");
	
	
		system("cls");
}




