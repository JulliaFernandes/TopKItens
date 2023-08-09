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
    //priority_queue<NodeTree*, vector<NodeTree*>, Compare> fifo;
    vector<WordInfo*> heap;

    for(int i=1; i<=ARQ; i++){
        cout << "i" << i << endl;
        string fileName = "data/input" + to_string(i) + ".txt";
        readText(fileName, file, glossary);
    }

    cout << "==========================================================================" << endl;
    cout << "\t*** Palavras mais frequentes ***" << endl;
    cout << setw(6) << "WORD" << " | " << setw(8) << "FREQUENCY" << endl;
    fillHeap(heap, glossary, k);

    cout << "--------------------------------------------------------------------------" << endl;

    cout << "Julliaaaaaaaaaa" << endl;
    endTime = clock();
    clock_t elapsedTime = endTime - startTime;
    double elapsedTimeMs = ((double)elapsedTime/CLOCKS_PER_SEC)*1000;
    cout << "TEMPO DE EXECUÇÃO: " << elapsedTimeMs << " ms " << endl;
    return 0;
}