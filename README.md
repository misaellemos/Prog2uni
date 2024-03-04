--------------------------------------------- Respostas ----------------------------------------------------------

1-
a) 

b)
	Quicksort é um algoritmo de ordenação comparativo, ou seja, seu critério para a ordenação está na comparação de valores dos elementos do vetor, o programa seleciona um determinado valor que será chamado de pivô e através dele fará comparações para que ao fim de um processo recursivo o programa se encontre ordenado, e que utiliza o método chamado de "divisão e conquista",  que são algoritmos que desmembram o problema  em vários subproblemas semelhantes ao problema original, mas de tamanho menor, resolvem os subproblemas recursivamente e depois combinam essas soluções com o objetivo de criar uma solução para o problema original. 
	O processo de divisão consiste em particionar o vetor em dois subvetores, que podem ser vazios, reorganizando-os, para isso se utiliza de uma variável chamada pivô que será utilizada como ferramenta para reorganizar e dividindo virtualmente o vetor em dois subvetores, a esquerda um subvetor contendo os elementos com valores menores que o pivô e a direita um subvetor contendo os elementos maiores que o pivô.(inicialmente teremos um vetor A[p ... r] contendo elementos cujos valores vão de p até r, e então particionado a partir de um pivô p em: A[p ... q] (lado menor) e A[q + 1 ... r] (lado maior), tal que q <= p < q + 1).  Seguindo, ocorre processo de conquista ordenando cada um dos subvetores resultantes do particionamento (A[p...q],  A[q+1...p]) a partir de chamadas recursivas da função quicksort. Ao final combinando os dois subvetores sem a necessidade de trabalho extra, pois cada um deles já estará ordenado. 
	A ideia central desse algoritmo está na função particiona que utiliza o pivô para dividir virtualmente o vetor em dois subvetores a partir de comparações entre o ele e cada elemento do vetor, um subvetor irá conter os elementos menores que o pivô e outro os elementos maiores que o pivô, retornando o índice do ponto de divisão entre os dois lados da partição que será usado como parâmetro para repetir de forma recursiva a função quicksort, repetindo o processo até que o vetor inicial se encontre totalmente ordenado.
	Para analisar o tempo de execução do quicksort, o primeiro passo é encontrar a relação  de recorrência. O algoritmo possui uma chamada ao método particiona e duas chamadas recursivas, essas chamadas podem não dividir o vetor ao meio sempre, isso depende de como o pivô irá separar virtualmente o vetor. Então, vamos descrever a relação de recorrência como sendo os custos para particionar e fazer as chamadas recursivas para os subvetores da esquerda e da direita:
 		T(n) = T(|esquerda|) + T(|direita|) + Θ(particiona)
	Como a função particiona possui apenas  algumas operações primitivas e uma iteração sobre todo o vetor, e como o vetor possui um tamanho n sabemos que a complexidade do seu tempo de execução será Θ(n). Dessa forma, temos:
		T(n) = T(|esquerda|) + T(|direita|) + Θ(n)
	Agora falta analisar os termos T(|esquerda|) e T(|direita|). Temos conhecimento da relação dos tamanhos dos subvetores e o vetor, que por sua vez dependem do pivô escolhido para o particionamento. No qual:
		esquerda + direita = n
Lembrando que: 
		esquerda <= pivo
Portanto:
		n <= pivo + direita
	Dessa forma, podemos afirmar que o tempo de execução do quicksort depende de como balanceado está cada particionamento, que por sua vez dependem de quais elementos serão usados como pivôs. 
	Caso os dois lados da partição tenham aproximadamente o mesmo tamanho(se n for o número de elementos do vetor, cada partição irá conter aproximadamente n/2 elementos), ela estará balanceada e então sua recorrência será uma árvore de recursão que se assemelha a uma árvore binária balanceada na qual conforme vai descendo o nível da árvore a complexidade de cada nó diminui numa proporção de 1/2 e essa árvore possuirá uma altura de log(n), tendo assim melhor tempo de execução. 
Melhor caso:
		T(n) = T(n/2) + T(n/2) + Θ(n)
, ou seja,
		T(n) = 2T(n/2) + Θ(n)
	A partir da análise dos nós folha da árvore de recursão, percebemos que em cada nível teremos um custo n (nível 0: Θ(n); nível 1: 2* T(n/2) = Θ(n), nível 2: 4*T(n/4) = Θ(n), ..., último nível: log(n)*T(1) = Θ(n)). Assim, como teremos log(n) níveis nessa árvore seu custo será n por cada nível vezes a altura da árvore mais custo do nó( T(n) = Θ(n)*log(n) + Θ(n)). Assim chegamos na resposta:
		T(n) = Ω(n*log(n))
	Ao contrário, caso a partição ocorra sempre de forma desbalanceada, de forma que sempre um dos subvetores resultantes do particionamento seja vazio, ela cai no seu pior caso, e então a sua árvore de recorrência possuirá apenas um dos filhos com valores e o outro lado vazio, se assemelhando a uma estrutura linear em que o valor de n vai decrementando de um em um.
Pior caso:
		T(n) = T(n − 1) + T(0) + Θ(n)
, ou seja,
		T(n) = T(n − 1) + Θ(n)
Intuitivamente, se somarmos os custos em cada nível de recursão obteremos uma série aritmética(P.A.) de razão igual a -1, resultando assim num somatório da função particiona n vezes, indo do valor n até o valor 1, a soma dessa P.A. será S(n) =  (n + 1)n/2 = (n² + n)/2. Desse modo temos:
		T(n) = O(n²)
	Agora tendo conhecimento dos melhor e pior caso do algoritmo, basta analisar as razões que o levam a esses estados. O pior caso ocorre quando ele executa recorrentemente péssimas partições através do pivô de forma a sempre resultar subvetores desbalanceados, contendo um subvetor vazio ou quase vazio. É evidente que esse caso ocorre quando o pivô escolhido é ou o maior ou o menor elemento do arranjo, não contendo assim elementos a sua direita ou a sua esquerda, respectivamente, isso o fará que desencadeie no exemplo mostrado de pior caso. E seu melhor caso ocorrerá quando executa recorrentemente ótimas partições resultando sempre em subvetores balanceados com tamanho aproximadamente iguais. Evidentemente, esse caso irá acontecer quando o pivô sempre for escolhido de forma a ser o elemento mediano do arranjo, permitindo uma separação igualitária e desencadeando no exemplo mostrado de melhor caso. Apesar de seu melhor caso ser raro, na média a complexidade do algoritmo tende a ter a mesma complexidade que ele, O(n*log(n)). A teoria nos diz que mesmo alternando péssimos particionamentos e bons particionamentos o algoritmo ainda seria O(n*log(n)).
	Escolhendo o pivô como elemento do meio do vetor:
Recebendo os valores de entrada de forma aleatória o algoritmo executará no seu tempo médio, como explicado acima. No entanto, seu pior caso ocorreria quando recebesse um vetor ordenado a partir do meio do vetor, de forma crescente ou decrescente, pois dessa forma o valor selecionado para ser o pivô seria sempre ou o menor elemento ou o maior.
	Escolhendo o pivô de forma aleatória:
Caso escolhamos o pivô de forma aleatória a probabilidade dele ser o menor ou o maior elemento do vetor é de p = 2/n, para cair no pior caso seria necessário que sempre fosse escolhido o pior pivô, tendo assim uma probabilidade muito pequena disso acontecer de p = 2/n*2/(n-1)...1/1. Então, escolher aleatoriamente um pivô é uma boa estratégia para diminuir significativamente a ocorrência do pior caso. No programa usado neste trabalho, a forma de gerar aleatoriedade foi através de uma aproximação do valor da mediana do vetor, somando os valores do primeiro elemento, do elemento do meio e do último elemento e dividindo o resultado por três, na tentativa de se aproximar mais do melhor caso.


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

