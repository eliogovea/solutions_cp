/***
	SPOJ - NSUBSTR - Substrings
	El problema nos pide decir para cada numero l decir la mayor frecuencia de
	una palabra de largo l en la cadena s
	Para resolverlo construimos es Suffix Automaton de s porque:
	1:
		podemos calcular para cada estado los largos de las cadenas que ese estado acepta,
		qu estas estan en el intervalo [length[suffixlink[s]] + 1, length[s]]
	2:
		podemos calcular para cada estado del automata la cantidad de cadenas contando repeticiones
		que aparecen el la cadena s utilizando los suffixLink, para esto contamos 1 en cada uno de los
		estados que aceptan cada uno de los prefijos de s, ordenamos los estados por length y sumamos a cada
		estado el cnt de los estados que lo tienen a el como suffixLink
	El problema se reduce entonces a que tengo un conjunto de intervalos con un valor determinado
	(para cada estado s el intervalo es desde length[suffixLink[s]] + 1, hasta length[s], y el valor
	es la cantidad de repeticiones de ese estado en s), y un conjunto de queries que son para un numero x
	decir cual es el mayor calor de los intervalos a los que x pertenece
	Con toda esta informacion podemos hacerlo offline
	creamos eventos para cada largo que seran las 'query', entonces para cada estado ponemos
	dos eventos uno que adiciona las repeticiones de ese estado en largo length[s] y otro que quita ese
	numero para largo length[suffixLink[s]], manteniendo en un multiset (para poder insertar, eliminar y preguntar el maxino)
	los valores de cnt activos
	cuando llegamos a un evento que sea una pregunta tenemos en el multiset todos los valores de los intervalos que
	todavia estan abiertos y nos quedamos con el mayor, cuando es un evento de adicionar es que un intervalo comienza
	y insertamos el valor del intervalo en el multiset, si es un evento de quita es que en ese largo + 1 termina un intervalo
	y debemos quitarlo en el multiset
 
**/
 
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
 
using namespace std;
 
const int MAXN = 250000;
const int MAXS = 2 * MAXN;
 
int length[MAXS + 1];
map <char, int> next[MAXS + 1];
int suffixLink[MAXS + 1];
 
int size;
int last;
 
int getNew(int _length) {
	int now = size++;
	length[now] = _length;
	next[now] = map <char, int> ();
	suffixLink[now] = -1;
	return now;
}
 
int getClone(int from, int _length) {
	int now = size++;
	length[now] = _length;
	next[now] = next[from];
	suffixLink[now] = suffixLink[from];
	return now;
}
 
void init() {
	size = 0;
	last = getNew(0);
}
 
void add(int c) {
	int p = last;
	int cur = getNew(length[p] + 1);
	while (p != -1 && next[p].find(c) == next[p].end()) {
		next[p][c] = cur;
		p = suffixLink[p];
	}
	if (p == -1) {
		suffixLink[cur] = 0;
	} else {
		int q = next[p][c];
		if (length[p] + 1 == length[q]) {
			suffixLink[cur] = q;
		} else {
			int clone = getClone(q, length[p] + 1);
			suffixLink[q] = clone;
			suffixLink[cur] = clone;
			while (p != -1 && next[p][c] == q) {
				next[p][c] = clone;
				p = suffixLink[p];
			}
		}
	}
	last = cur;
}
 
int freq[MAXS];
int order[MAXS];
 
int cnt[MAXS];
 
int n;
char s[MAXN];
 
multiset <int> active;
 
vector <int> Eadd[MAXN];
vector <int> Eremove[MAXN];
 
int main() {
 
	gets(s);
	n = strlen(s);
 
	/// build the automaton
	init();
	for (int i = 0; i < n; i++) {
		add(s[i]);
		cnt[last]++;
	}
 
	/// counting sort
	for (int i = 0; i < size; i++) {
		freq[length[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		freq[i] += freq[i - 1];
	}
	for (int i = 0; i < size; i++) {
		order[--freq[length[i]]] = i;
	}
 
	for (int i = size - 1; i > 0; i--) {
		int s = order[i];
		cnt[suffixLink[s]] += cnt[s];
	}
 
	/// add or remove events
	for (int s = 1; s < size; s++) {
		Eadd[length[suffixLink[s]] + 1].push_back(cnt[s]);
		Eremove[length[s]].push_back(cnt[s]);
	}
 
	for (int l = 1; l <= n; l++) {
		for (int i = 0; i < Eremove[l - 1].size(); i++) {
			active.erase(active.find(Eremove[l - 1][i]));
		}
		for (int i = 0; i < Eadd[l].size(); i++) {
			active.insert(Eadd[l][i]);
		}
 
		printf("%d\n", *active.rbegin());
	}
}
