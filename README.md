# ListaEncadeada

##No inserir utilizamos o seguinte passo a passo:

1 - Verificar se existe algum endereço ja alocado utilizando um if no inicio == NULL
1.1 - Se não existir utilizamos o malloc para alocar endereço de memoria com corrente e passamos inicio e auxiliar para o mesmo.
2 - Se Existir percorremos atravez do inicio com as variaveis corrente e auxiliar ate chegar no NULL chegando no proximo null (corrente->next = NULL),
2.1 Alocamos com o corrente um novo endereço e setamos o auxiliar->next = corrente
2.2 Colocamos o corrente->next no NULL 
2.3 Passamos o auxiliar para o corrente
2.4 Adicionamos o enterdata

##Na função exibir utilizamos o seguinte passo a passo:

1 - Verificamos se existem struct 
2 - Se existir setamos o auxiliar para o inicio
3 - E a partir dele com um while realizamos (auxiliar != NULL);
4 - Printa na tela
5 - E passa o auxiliar = auxiliar->next (indo para o proximo continuando o while)

##Na função de pesquisar utilizamos o seguine passo à passo:

1 - Verifica se à dados visíveis para serem procurados
2 - Scanf pegando o codigo pesquisado
3 - Auxiliar é setado para inicío 
4 - Enquanto auxiliar != de NULL, ele procura dento de um if com o codigo passado na etapa 2.
5 - Se encontrar variavel achou fica = 1 
6 - Se não encontrar auxiliar = auxiliar->next continuando o loop ...
7 - Se foi finalizado o while e não foi encontrado utilizamos o if == 0 para retornar "que não foi encontrado" 

##Na função de Remover utilizamos o seguinte passo à passo:

1 - Verificamos se existem estrutura ou a lista está vazia, se estiver é finalizado.
2 - Se houver estruturas verificamos se possuí apenas 1 , se estiver é finalizado.
3 - Verificamos se o codigo informado pela pessoa está no inicío se estiver
3.1 - Auxiliar vai para inicío, inicio = inicio->next, 
3.2 - Auxiliar é feito o free,
3.3 - É dada mensagem de exclusão da primeira struct
3.4 - Variavel achou fica = 1
4 - Se não está no inicío setamos o corrente para  corrente = auxiliar-next ficando uma posição a frente do auxiliar
4.1 - Enquanto corrente for diferente de NULL ele percorrera em busca do codigo,
4.2 - Se nao encontra passará para outro corrente = corrente->next e o auxiliar auxiliar=auxiliar->next
4.3 - Se for encotrado no meio do while dará uma mensagem e auxiliar->next = corrente->next e logo após free(corrente), variavel achou ficará 1
4.4 - Exibirá print
5.0 - Se achou == 0 e corrente->codigo == ao digitado, então estará no ultimo campo. Remove corrente e deixa auxiliar como ultimo posicionando next ao NULL.
6.0 - Caso não acha if == 0 mensagem de retorno não foi encontrado o codigo

##Função alterar

1 - Verifica se existe lista
2 - informa o codigo
3 - auxiliar vai ao inicio percorrendo com while
4 - se encontrar, scanf passando auxiliar->codigo se não continua (auxiliar = auxiliar->next)
5 - Caso não consiga encontrar retorna mensagem dizendo que não foi possível.