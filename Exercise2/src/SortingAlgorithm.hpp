#pragma once

#include <iostream>
#include <vector>


namespace SortLibrary {

template <typename T>
concept Sortable = requires(T& t){
	{t<t} -> std::convertible_to<bool>;
};


template<Sortable T>
void BubbleSort(std::vector<T>& v)
{
	unsigned int n = v.size();
	for(unsigned int i=0;i<n-1;i++){
		for(unsigned int j=i+1;j<n;j++){
			if(v[j]<v[i]){
				T tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
};

template<Sortable T>
void HeapSort(std::vector<T> &v){
	unsigned int n = v.size();
	//enqueue
	for(unsigned int i=1;i<n;i++){
		unsigned int nodo = i;
		while(nodo>0){
			//trovo nodo padre
			unsigned int nodo_padre;
			if(nodo%2==1)
				nodo_padre = (nodo-1)/2;
			else
				nodo_padre = (nodo-2)/2;
			//controllo se valore del nodo è maggiore del nodo padre
			if(v[nodo]>v[nodo_padre]){
				T tmp = v[nodo];
				v[nodo] = v[nodo_padre];
				v[nodo_padre] = tmp;
			}
			else
				break;
			nodo = nodo_padre;
		}
	}
	//dequeue
	for(unsigned int i=0;i<n;i++){
		//metto valore più grande al fondo
		T tmp = v[0];
		v[0]=v[n-1-i];
		v[n-1-i] = tmp;
		//parto da radice(che è valore più piccolo) e scambio per riavere in radice valore più grande
		unsigned int nodo = 0;
		bool scambio = true;
		unsigned int figlio_sx;
		unsigned int figlio_dx;
		unsigned int max_figlio;
		while(scambio && (2*nodo+1) < n-1-i)
		{	
			//trovo maggiore tra nodi figli e scambio
			figlio_sx = 2*nodo+1;
			figlio_dx = 2*nodo+2;
			if(figlio_dx<n-1-i && figlio_sx<n-1-i){
				if(v[figlio_dx]>v[figlio_sx])
					max_figlio = figlio_dx;
				else
					max_figlio = figlio_sx;
				}
			else if(figlio_dx<n-1-i && figlio_sx>=n-1-i)
				max_figlio = figlio_dx;
			else if(figlio_dx>=n-1-i && figlio_sx<n-1-i)
				max_figlio = figlio_sx;
			if(v[nodo]<v[max_figlio]){
				T tmp = v[nodo];
				v[nodo]=v[max_figlio];
				v[max_figlio] = tmp;
				nodo = max_figlio;
			}
			else
				scambio = false;
		}
		
	}
}
}