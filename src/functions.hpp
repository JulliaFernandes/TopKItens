#ifndef FUNCTIONS_HPP_
#define FUNCTIONS_HPP_

#include"header.hpp"
using namespace std;

typedef struct WordInfo{
  std::string word;
  int occurrences;
  //std::vector<int> references;

  WordInfo() : word("\0"), occurrences(0) {}

  WordInfo(string word, int occurrences){
    word = word;
    occurrences = occurrences;
  }

} WordInfo;

void heapify(vector<WordInfo*>& arr, int n, int i);

void heapSort(vector<WordInfo*>& arr);

void fillHeap(vector<WordInfo*>& heap, const unordered_map<string, WordInfo>& glossary, int k);

bool emptyLine(const string linha);

void readText(string fileName, ifstream &file, unordered_map<string, WordInfo> &glossary);

#endif