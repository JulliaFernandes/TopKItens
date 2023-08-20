#include"functions.hpp"
//#include"header.hpp"

using namespace std;

#define k 20
#define ARQ 2

int main()
{
    clock_t startTime, endTime;
    startTime = clock();

    ifstream file;
    unordered_map<string, WordInfo> glossary;
    unordered_map<string, WordInfo> glossaryStopWords;

    //priority_queue<NodeTree*, vector<NodeTree*>, Compare> fifo;
    vector<WordInfo*> heap;

    fillGlossaryStopWords(glossaryStopWords);
    //printGlossary(glossaryStopWords);

    for(int i=1; i<=ARQ; i++){
        string fileName = "data/input" + to_string(i) + ".txt";
        readText(fileName, file, glossary, glossaryStopWords);
    }

    cout << "==========================================================================" << endl;
    cout << "\t*** Palavras mais frequentes ***" << endl;
    cout << setw(6) << "WORD" << " | " << setw(8) << "FREQUENCY" << endl;
    fillHeap(heap, glossary, k);

    cout << "--------------------------------------------------------------------------" << endl;

    endTime = clock();
    clock_t elapsedTime = endTime - startTime;
    double elapsedTimeMs = ((double)elapsedTime/CLOCKS_PER_SEC)*1000;
    cout << "TEMPO DE EXECUÇÃO: " << elapsedTimeMs << " ms " << endl;
    return 0;
}