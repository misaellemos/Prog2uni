--------------------------------------------- Respostas ----------------------------------------------------------
1-
a) 

b)
	Quicksort é um algoritmo de ordenação comparativo, ou seja, seu critério para a ordenação está na comparação de valores dos elementos do vetor, o programa seleciona um determinado valor que será chamado de pivô e através dele fará comparações para que ao fim de um processo recursivo o programa se encontre ordenado. A ideia central desse algoritmo é em utilizar o pivô para dividir virtualmente o vetor a ser ordenado em dois subvetores a partir de comparações entre o ele e cada elemento do vetor, um subvetor irá conter os elementos menores que o pivô e outro os elementos maiores que o pivô, e repetindo de forma recursiva esse processo de seleção de um pivô e corte virtual em cada um dos subvetores encontrados até que se chegue num subvetor unitário, dessa forma ao fim do programa o vetor inicial se encontrará totalmente ordenado.
	
O programa é dependente do pivô para fazer os processos de comparação e assim separar o vetor a fim de ordená-lo, portanto a complexidade do tempo de execução do algoritmo está diretamente ligada a quão apropriada foi a seleção do pivô para determinado momento. Quanto melhor o dividir o vetor mais rápido será a execução, de forma que caso o programa consiga separar sempre o vetor em duas partes iguais sua repartição se assemelhará a uma árvore binária, contendo log_2(n) de tamanho ... tendo complexidade de O(nlogn) . É trivial imaginar que os piores casos para ordenação seria quando o pivô não dividisse o vetor em dois e dessa forma seu processo teria tamanho linear n, isso acontecerá quando o pivô for sempre o maior ou menor elemento do vetor ... tendo complexidade de O(n²). ... na média terá um tempo de execução de θ(nlogn).

 o algoritmo terá o melhor tempo de execução de Ω(nlogn) e em média terá um tempo de execução de θ(nlogn), com o pior caso sendo O(n²) que acontecerá quando o vetor estiver ordenado, de forma crescente ou decrescente, começando a partir do pivô que nesse caso seria a partir do elemento na metade do vetor.

c) com o vetor ordenado a partir do início o programa teria sempre o seu melhor tempo de execução, pois como estamos pegando o elemento do meio com o pivô isso garante que num vetor ordenado o pivô sempre dividirá o vetor atual ao meio em dois subvetores de tamanhos iguais, com isso teremos log_2(n) operações recursivas de divisão do vetor principal. ( em cada recursão o vetor de n elementos, assim no final multiplicamos esse fator com a quantidade de recursões e temos o tempo de execução do algoritmos. nesse caso: n * logn )

d)

2-
a)

b) deve ser O(nlogn) pois trabalha basicamente com o conceito de árvore binária

c)

d)  o heapsort tá sendo o pior dos 4 disparádo, a constante dele deve ser uma merda, vejo melhor dps

3-
a) countingsort tem uma desvantagem que é a necessidade de armazenamento para criar um novo vetor de acesso direto para cada elemento do vetor inicial, dessa forma quanto maior o alcance dos elementos de entrada maior o espaço de armazenamento necessário para fazer a ordenação por esse método e maior será o tempo de execução, sendo dependente não somente de n (número de elementos) como também de m(tamanho do vetor de acesso direto, maior elemento do vetor principal). tendo um agravante que quanto maior o alcance dos elementos(maior elemento) caso o vetor principal não seja consideravelmente preenchido usar esse método será um desperdício de memória, além de que pode ultrapassar o limite de word do seu computador. ex: vet = [1,2,3,4,300] --> vet_dir_acess = [1,2,3,4,5,6...,300], teremos 295 casas desoculpadas no vetor de acesso direto.
countingsort tem um tempo bom de execução para vetores completamente preeenchidos, tendo tempo de O(n + n) = O(2n) = O(n)

b) quanto maior o vetor e mais preenchido ele é em relação ao alcance dos elementos, melhor será o tempo do countingsort em comparação com os outros

c)

