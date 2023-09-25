#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>

using namespace std;

int main(int argc, char* argv[]) {
    string in_file, out_file;

    if (argc == 3) {
        in_file = argv[1];
        out_file = argv[2];
        cout << "Программа выполнена, проверьте ответ" << endl;
    }
    else if (argc == 2) {
        cout << "Введите файл для записи" << endl;
    }
    else if (argc == 1) {
        cout << "Введите файлы для чтения и записи" << endl;
    }


    ifstream input_file;
    input_file.open(in_file);


    map <string, int> word_frequency;
    string word, cleeanedWord;
    int counterOfAllWord = 0;

    while (!input_file.eof()) {
        getline(input_file, word);
        for (int i = 0; i <= word.size(); ++i){
            if (isalnum(word[i]) != 0) {
                cleeanedWord += word[i];
            }
            else {
                word_frequency[cleeanedWord]++;
                counterOfAllWord++;
                cleeanedWord.clear();
            }
        }
    }

    list <pair<string, int> > sortMap;
    for (auto item : word_frequency) {
        sortMap.push_front(item);
    }
    sortMap.sort();

    input_file.close();


    ofstream output_file;
    output_file.open(out_file);
    output_file << "Слово,Частота,Частота (%)" << endl;

    for (auto element : sortMap) {
        double frequencyInPercentage = ((double)element.second / counterOfAllWord) * 100.0;
        output_file << element.first << "," << element.second << "," << (int)frequencyInPercentage<< "%" << endl;
    }

    return 0;
}