#include"functions.hpp"

using namespace std;

// void printGlossary(unordered_map<string,NodeTree> glossary)
// {
//   for (const auto& entry : glossary) {
//     cout << "Chave no map: " << entry.first << ": " << entry.second.word.occurrences << endl;
//   }
// }

// void existentWord(string str, int n, unordered_map<string, NodeTree> &glossary)
// {
//     //as ndk to storage token
//     glossary[str].word.occurrences++;
//     glossary[str].word.references.push_back(n);
//     // glossary[str].occurrences++;
//     // glossary[str].references.push_back(n);
// }

// void returnWord(string &str, unordered_map<string, NodeTree> &glossary)
// {
//   NodeTree newWord;
//   newWord.word.occurrences = 1;
//       // case ' ':
//       //   if(str!=""){
//       //     if(glossary.find(str) != glossary.end()) glossary[str].word.occurrences++;
//       //     else
//       //       glossary[str] = newWord;
//       //     str = "";
//       //   }
        
//       //   break;

// }

// void fillQueue(priority_queue<NodeTree*, vector<NodeTree*>, Compare> &fifo, unordered_map<string, NodeTree> dict, int K)
// {   
//     for (const auto& entry : dict) {
//       if((int)fifo.size() < K){
//         //fifo.push(entry.second); //utilizando cosntutor sem parametro
//         fifo.push(new NodeTree(entry.first, entry.second.word.occurrences, entry.second.word.references));//utlizando o cosntutor com parametro
//       }
//       else{
//         if(entry.second.word.occurrences > fifo.top()->word.occurrences){
//           fifo.pop();
//           fifo.push(new NodeTree(entry.first, entry.second.word.occurrences, entry.second.word.references));
//         }
//       }
//     }
// }


// void print(priority_queue<NodeTree*, vector<NodeTree*>, Compare> fifo){
//   while(!fifo.empty()){
//     cout << fifo.top()->word.word << ": ";
//     cout << fifo.top()->word.occurrences  << " - ";
//     cout << fifo.top()->word.references.size() << endl;

//     fifo.pop();
//   }
// }


void heapify(vector<WordInfo*>& arr, int n, int i) 
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left]->occurrences < arr[smallest]->occurrences)
        smallest = left;

    if (right < n && arr[right]->occurrences < arr[smallest]->occurrences)
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void heapSort(vector<WordInfo*>& arr) 
{
    // int n = arr.size();

    // for (int i = n / 2 - 1; i >= 0; i--)
    //     heapify(arr, n, i);

    // // Apenas uma iteração para garantir que o menor elemento esteja na primeira posição
    // swap(arr[0], arr[n - 1]);

    int n = arr.size();

    // for (int i = n / 2 - 1; i >= 0; i--)
    //     heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void fillHeap(vector<WordInfo*>& heap, const unordered_map<string, WordInfo>& glossary, int k) 
{
    // Obter o número de elementos a serem inseridos (o mínimo entre k e o tamanho do glossary)
    int elementosParaInserir = min(k, static_cast<int>(glossary.size()));

    // Reservar espaço no vetor heap para evitar realocações desnecessárias
    heap.reserve(elementosParaInserir);

    // Iterador para percorrer o mapa glossary
    auto it = glossary.begin();

    // Inserir os primeiros elementosParaInserir elementos no heap
    for (int i = 0; i < elementosParaInserir; ++i) {
        heap.push_back(const_cast<WordInfo*>(&it->second));
        ++it;
    }

    // Criar um heap mínimo com os elementos iniciais
    for (int i = elementosParaInserir / 2 - 1; i >= 0; --i) {
        heapify(heap, elementosParaInserir, i);
    }

    // Percorrer o restante dos elementos da hash e atualizar o heap
    for (; it != glossary.end(); ++it) {
        WordInfo* current = const_cast<WordInfo*>(&it->second);
        if (current->occurrences > heap[0]->occurrences) {
            // Substituir o menor elemento no heap pelo elemento atual
            heap[0] = current;
            // Reorganizar o heap para manter a propriedade do heap mínimo
            heapify(heap, elementosParaInserir, 0);
        }
    }

    // Ordenar o heap mínimo em ordem crescente (os k itens mais frequentes estarão no final do heap)
    heapSort(heap);

    // Imprimir os k itens mais frequentes em ordem crescente
    int startIdx = heap.size() - 1;

    int width = 20;
    cout << "+" << setfill('-') << setw(width - 2) << "+" << endl;
    int j=1;
    for (int i = startIdx; i >=0 ; --i) {
      //cout << "|" << " -> "<< "\033[31m" << heap[i]->word << "\033[0m" << ": " << heap[i]->occurrences  << endl;
      //cout << ">" << i+1 << "-" << "\033[31m" << heap[i]->word << "\033[0m" << ": " << heap[i]->occurrences << endl;
      cout << j << ") " << heap[i]->word << ": " << heap[i]->occurrences << endl;  
        //cout << heap[i]->word << ": " << heap[i]->occurrences << endl;
        j++;
    }
    cout << "+" << setfill('-') << setw(width - 2) << "+" << endl;
}

bool emptyLine(const string linha)
{
    for (char c : linha){
        if (!isspace(c)){ // Se o caractere não for espaço em branco, a linha não está vazia
            return false;
        }
    }
    // Se todos os caracteres forem espaços em branco, a linha está vazia
    return true;
}

void readText(string fileName, ifstream &file, unordered_map<string, WordInfo> &glossary)
{
  file.open(fileName);
        if (!file.is_open()) {
            cout << "Erro ao abrir o arquivo." << endl;
            return;
        }
        regex exceptions("[a-zA-Z0-9'À-ÿ-]+");

        string line;
        bool aux=false;

        while (getline(file, line)){
            sregex_iterator it(line.begin(), line.end(),exceptions); //criado um objeto que vai percorrer a frase salva em line e vai utlizar a expressao regular exceptions
            sregex_iterator end; //objeto criado para representar o fim da frase salva em line
            while (it != end) { //percorre todas as correspondências encontradas pela expressão regular na linha.
                string word = it->str(); //aqui é pq cheguei a alguma coisa que nao é minha expressao regular, por exemplo, um espaco ou ponto, enfim ai passo ela para uma variavel de string
                if(word.length() >= 2 && word[0] == '-' && word[1] == '-'){
                        word.erase(0,2);
                        if(word.length()==0){
                            aux=true;
                        }
                }   
                if(!aux){
                    transform(word.begin(), word.end(), word.begin(), ::tolower);
                    WordInfo newWord;
                    newWord.occurrences = 1;
                    //newWord.references.push_back(n);
                    newWord.word = word;
                    if(glossary.find(word) != glossary.end())
                    {   
                        glossary[word].occurrences++;
                        //int tam = glossary[word].references.size();
                        //if(glossary[word].references[tam-1] != n) glossary[word].references.push_back(n);
                    } 
                    else glossary[word] = newWord;
                }
                    
                ++it;
                aux=false;
            }
            //n++;
        }
        // glossary.erase("--");
        glossary.erase("-");

        file.close();
}