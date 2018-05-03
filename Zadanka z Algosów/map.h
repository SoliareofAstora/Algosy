#pragma once
#include "avl.h"
template  <typename key, typename value>
class map
{
	
};





/*Hej!

Opiszê Ci, co straci³eœ : generalnie na pocz¹tku opowiada³ o s³owniku
(po ang.map).Wiadomo, elementy s¹ przechowywane jako pary klucza i wartoœci, 
a szuka siê po kluczach, które musz¹ byæ unikatowe.

Na zad.dom.które liczy siê do kolokwium mamy na max.za 
2 tyg.zaimplementowaæ tak¹ mapê na naszym drzewie BST, 
które robiliœmy do zbioru.Mo¿na skorzystaæ z 
std::pair do tworzenia elementów.Najlepiej ¿eby to by³o to samo drzewo 
z iteratorami i chodzi o to by jak najmniej zmieniaæ funkcje z tego drzewa.
Jako przyk³ad zastanawialiœmy siê, jak zrobiæ Find'a bez zmiany funkcji z BST: 
Trzeba upakowaæ parê w klasê i przeci¹¿yæ operator porównania :
	class TreeData {
	std::pair<K, V> p;
	bool operator==(const TreeData & td) {
		return p.first == td.first;
	}
};

Jakby coœ by³o niejasne to pisz : )
Pozdrawiam,
Kasia*/