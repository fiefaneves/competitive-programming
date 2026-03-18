#include <bits/stdc++.h>

using namespace std;

// se n for impar -> ex: n = 5 -> ababa -> primeira e ultima sao iguais ('a')
// se n for par -> ex: n = 4 -> abab -> pode pegar 'a' ou 'b'

// string gerada (S)
// como tira letra por letra, o tamanho da string alterna entre impar e par ou par e impar
// caso 1: n é par -> Exemplo 4 do problema (aa?b?b, n=6) -> O primeiro par é aa
    // como as duas letras são iguais, quebra a regra!
    // Resposta: NO. 
// caso 2: n é ímpar -> Como a primeira letra da string original T (que tem tamanho ímpar) sempre será 'a', 
    // e as pontas são iguais, a primeira letra gerada tem que ser obrigatoriamente 'a'. 
    // Depois disso, o restante da string cai na mesma regra dos blocos de 2 letras diferentes.
    // Regra Extra -> O índice 1 tem que ser a (ou ?) -> se for b, a resposta já é NO.
    // Pares a checar: Índices (2, 3), (4, 5), (6, 7)
    // Exemplo 2 do problema (baaba, n=5) -> Começa com b -> Quebra a regra extra imediatamente. Resposta: NO.
    // Exemplo 1 do problema (ababa, n=5) -> Começa com a (Ok) -> O par (2, 3) é ba (Diferentes, Ok) -> O par (4, 5) é ba (Diferentes, Ok) -> Resposta: YES.

// Uma contradição só acontece se n for ímpar e a primeira letra for estritamente um b.
// Em qualquer um dos blocos de 2 letras que você testar, você encontrar um aa ou um bb. 
    // (Se tiver um a?, ?b ou ??, o bloco está válido, pois você sempre poderia substituir o ? pela letra oposta).

void solve() {
    int n; cin >> n;
    string x; cin >> x;

    bool possible = true;
    int index = 0;

    // regra 1 -> impar
    if (n%2 != 0) {
        if (x[0] == 'b') {
            possible = false;
        }
        index = 1;
    }

    // regra 2 -> checar pares de blocos
    for (int i = index; i < n; i+=2) {
        if (x[i] != '?' && x[i+1] != '?' && x[i] == x[i+1]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    for (size_t i = 0; i < t; i++) {
        solve();
    }
    return 0;
}