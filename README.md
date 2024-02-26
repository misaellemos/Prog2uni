# Prog2uni

fds


1)
b) o algoritmo terá o melhor tempo de execução de Ω(nlogn) e em média terá um tempo de execução de θ(nlogn), com o pior caso sendo O(n²) que acontecerá quando o vetor estiver ordenado, de forma crescente ou decrescente, começando a partir do pivô que nesse caso seria a partir do elemento na metade do vetor.

c) com o vetor ordenado a partir do início o programa teria sempre o seu melhor tempo de execução, pois como estamos pegando o elemento do meio com o pivô isso garante que num vetor ordenado o pivô sempre dividirá o vetor atual ao meio em dois subvetores de tamanhos iguais, com isso teremos log_2(n) operações recursivas de divisão do vetor principal. 
( em cada recursão o vetor de n elementos, assim no final multiplicamos esse fator com a quantidade de recursões e temos o tempo de execução do algoritmos. nesse caso: n * logn )

2)
b) deve ser O(nlogn) pois trabalha basicamente com o conceito de árvore binária

3)
a) countingsort tem uma desvantagem que é a necessidade de armazenamento para criar um novo vetor de acesso direto para cada elemento do vetor inicial, dessa forma quanto maior o alcance dos elementos de entrada maior o espaço de armazenamento necessário para fazer a ordenação por esse método e maior será o tempo de execução, sendo dependente não somente de n (número de elementos) como também de m(tamanho do vetor de acesso direto, maior elemento do vetor principal). tendo um agravante que quanto maior o alcance dos elementos(maior elemento) caso o vetor principal não seja consideravelmente preenchido usar esse método será um desperdício de memória, além de que pode ultrapassar o limite de word do seu computador. ex: vet = [1,2,3,4,300] --> vet_dir_acess = [1,2,3,4,5,6...,300], teremos 295 casas desoculpadas no vetor de acesso direto.
countingsort tem um tempo bom de execução para vetores completamente preeenchidos, tendo tempo de O(n + n) = O(2n) = O(n)


