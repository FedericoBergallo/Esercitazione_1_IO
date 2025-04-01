#include<iostream>
#include<fstream>
#include <vector>
#include <iomanip>
using namespace std;


long double trasformato ( long double x)
{
	long double xnew= 0.75 * x -1.75;
	return xnew;
}


int main()
{
	//leggo il file
	std::ifstream fstr("data.txt");
		//controllo che il file sia letto nel modo giusto
		if (fstr.fail())
	{
		std::cerr <<"errore nell'apertura del file" <<std::endl;  //oggetto standard per stampa di errori
		return 1;  
	}
	std::vector<long double> vettore_numeri;
	long double numero;
	while (fstr >> numero)     //associo i contenuti del file a numero
	{
		vettore_numeri.push_back(numero);
	}
	fstr.close();
	std::ofstream ofs("result.txt"); //creo il file di output
	ofs << "# N Mean"<< endl;
	int cond= vettore_numeri.size();
	//cout << cond << endl;
	
	std::vector <long double> vettore_numeri_trasformati;  
	for (int i=0; i <= cond-1; i++)
	{
		long double numero_trasformato= trasformato(vettore_numeri[i]);
		vettore_numeri_trasformati.push_back(numero_trasformato);
	
		long double somma=0.0;
		for (int j=0; j <=i; j++)
		{
			somma += vettore_numeri_trasformati[j];
		}
		long double media = somma / (i+1);
		ofs << i+1 <<" "<< fixed << setprecision(20)<< scientific << media << endl;
	}
	ofs.close();
	return 0;
}
