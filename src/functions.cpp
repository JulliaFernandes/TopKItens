#include"functions.hpp"

using namespace std;

int Partition(vector<WordInfo*>& heap, int start, int end){
	
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(heap[i]->occurrences > heap[pivot]->occurrences){
			swap(heap[i],heap[j]);
			++j;
		}
	}
	swap(heap[j],heap[pivot]);
	return j;
	
}

void Quicksort(vector<WordInfo*>& heap, int start, int end ){

	if(start<end){
		int p = Partition(heap,start,end);
		Quicksort(heap,start,p-1);
		Quicksort(heap,p+1,end);
	}
	
}

void fillHeap(vector<WordInfo*>& heap, const unordered_map<string, WordInfo>& glossary, int k) {
    int num = min(k, static_cast<int>(glossary.size()));
    heap.reserve(num);

    auto it = glossary.begin();
    for (int i = 0; i < num; ++i) {
        heap.push_back(const_cast<WordInfo*>(&it->second));
        ++it;
    }

    while(it!=glossary.end()) {
        WordInfo* current = const_cast<WordInfo*>(&it->second);
        if (current->occurrences > heap[0]->occurrences) {
            heap[0] = current;

            // Reorganizar o heap usando o afundamento (sink) HEAPIFY
            int index = 0;
            int n = num; // Tamanho atual do heap
            while (true) {
                int leftChild = 2 * index + 1;
                int rightChild = 2 * index + 2;
                int smallest = index;

                if (leftChild < n && heap[leftChild]->occurrences < heap[smallest]->occurrences)
                    smallest = leftChild;

                if (rightChild < n && heap[rightChild]->occurrences < heap[smallest]->occurrences)
                    smallest = rightChild;

                if (smallest != index) {
                    std::swap(heap[index], heap[smallest]);
                    index = smallest;
                } else {
                    break;
                }
            }
        }
        ++it;
    }

    Quicksort(heap, 0, heap.size()-1);

    int width = 20;
    cout << "+" << setfill('-') << setw(width - 2) << "+" << endl;
    int j=1;
    for (int i = (int)heap.size()-1; i >=0 ; --i) {
        //cout << j << ") " << "\033[31m" << heap[i]->word << "\033[0m" << ": " << heap[i]->occurrences << endl;
        cout << j << ") " << heap[i]->word << ": " << heap[i]->occurrences << endl;
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

void readText(string fileName, ifstream &file, unordered_map<string, WordInfo> &glossary, unordered_map<string, WordInfo> &glossaryStopWords)
{
  file.open(fileName);
    if (!file.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
        return;
    }
    regex exceptions("[a-zA-Z0-9'À-ÿ\\-“”]+");

    string line;
    bool aux=false;

    while (getline(file, line))
    {
        sregex_iterator it(line.begin(), line.end(),exceptions); //criado um objeto que vai percorrer a frase salva em line e vai utlizar a expressao regular exceptions
        sregex_iterator end; //objeto criado para representar o fim da frase salva em line
        
        while (it != end) //percorre todas as correspondências encontradas pela expressão regular na linha.
        { 
            string word = it->str(); //aqui é pq cheguei a alguma coisa que nao é minha expressao regular, por exemplo, um espaco ou ponto, enfim ai passo ela para uma variavel de string
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            
            if(glossaryStopWords.find(word) == glossaryStopWords.end()) //se nao achar no de StopWords posso adicionar ao meu glossary
            {
                aux = treatments(word);
                if(!aux){
                    WordInfo newWord;
                    newWord.occurrences = 1;
                    newWord.word = word;
                    if(glossary.find(word) != glossary.end()) glossary[word].occurrences++;
                    else glossary[word] = newWord;
                } 
            }
            ++it;
            aux=false;
        }
    }
    glossary.erase("-");
    glossary.erase("—");

    file.close();
}

void fillGlossaryStopWords(unordered_map<string, WordInfo> &glossaryStopWords)
{
    ifstream fileStopWords;

    fileStopWords.open("data/stopwords.txt");
    if (!fileStopWords.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
        return;
    }

    string line;
    while(getline(fileStopWords, line)){
        if(!fileStopWords.eof()){
            line.pop_back();
        }
        WordInfo newWord;
        newWord.occurrences = 1;
        newWord.word = line;

        glossaryStopWords[line] = newWord;
    }

    fileStopWords.close();

}

void printGlossary(unordered_map<string,WordInfo> glossary)
{
  for (const auto& entry : glossary) {
    cout << "Chave no map: " << entry.first << ": " << entry.second.occurrences << endl;
  }
}

bool treatments(string &word)
{   
    if ( word.length() >= 2 && (word[0] == '-' && word[1] == '-') ){
        word.erase(0,2);
        if(word.length()==0) return true;
        else return false;
    } 
    
    if(word[0] == '-'){
        word.erase(0,1);
        if(word.length()==0) return true;
        else return false;
    }

    if(word[word.size()-1] == '-'){
        word.pop_back();
        if(word.length()==0) return true;
        else return false;
    }
    
    if( (word.length() >= 3 && (word.substr(word.size()-3, word.size()-1) == "”" )) ){
        word.erase(word.size()-3, word.size()-1);
        if(word.length()==0) return true;
        else return false;
    }
    
    if(word.length() >= 3 && word.substr(0,3) == "“"){
        word.erase(0,3);
        if(word.length()==0) return true;
        else return false;
    }

    return false;
}