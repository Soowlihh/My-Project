/*
 Soowlih Compaore
 Final Project : Password Cracker
 04/30/2025
 */

#include "HashTable.h"
#include "Logger.h"
#include "md5.h"
#include <iostream>
#include <fstream>
#include <cmath>

//function to load dictionnary
std::vector<std::string> loadDictionary(const std::string& filePath) {
std::vector<std::string> words;
std::ifstream file(filePath);
std::string word;

  if(!file.is_open()) {
  std::cerr << "Failed to open dictionary file: " << filePath << std::endl;
      return words;
    }
    while (std::getline(file, word)) {
        if (!word.empty()) {
            words.push_back(word);
        }
    }
    file.close();
    return words;
}

int main() {
std::cout << "Password Cracker Tool\n----------------------\n";
std::cout << "Loading dictionary from 'dictionary.txt'...\n";
std::cout << std::endl;
 
// Load dictionary
 
std::vector<std::string> dictionary = loadDictionary("dictionary.txt");
std::cout << "Loaded " << dictionary.size() << " words.";
std::cout<<std::endl;
 
// Initialize data structures
 
HashTable hashTable;
Logger logger;
 
// Target hash to crack
 
std::string targetHash = "b848b9c75cf622ec40f505f4606b8d85";
std::cout << "Target hash: " << targetHash << "\n";
 
std::cout <<std::endl;
 
int totalWords = 10000;
 
std::cout << "Processing candidates...\n";
 
 for (int i = 1; i <= totalWords; ++i) {
    // process word...

    if (i % 1000 == 0) {
        std::cout << "\r[Progress: " << i << "/" << totalWords << " words processed]" << std::flush;
        // usleep(100000); // optional delay for testing visibility
    }
}
std::cout << std::endl;
 
 for (const auto& word : dictionary) {
    std::string hash = md5Hash(word);
    logger.logAttempt(word);
    hashTable.insert(hash, word);
    if (hash == targetHash) {
        std::cout << "Password cracked: " << word << std::endl;
        break;
    }
}
// Print log summary
// Show last 10 attempts
 
std::cout << "Summary:\n";
std::cout << "Processed " << logger.getAttemptCount() << " candidates before finding a match.\n";
std::cout << "Last 10 attempts: "<<std::endl;
 logger.printLog(10, 10);
return 0;
}
/*
soowlihhousmoulcompaore@Soowlihs-MacBook-Air-116 ~ % ./cracker_exec
Password Cracker Tool
----------------------
Loading dictionary from 'dictionary.txt'...
Loaded 999999 words.
Target hash: b848b9c75cf622ec40f505f4606b8d85

Processing candidates...
[Progress: 10000/10000 words processed]
Password cracked: hello_professor_ryan
Summary:
Processed 793304 candidates before finding a match.
Last 10 attempts: 
Attempt793295: zebrowski
Attempt793296: zebrostyle
Attempt793297: zebroshka
Attempt793298: zebronic
Attempt793299: zebrone
Attempt793300: zebro_kz
Attempt793301: zebroid09041988
Attempt793302: zebro4ka
Attempt793303: zebro1
Attempt793304: hello_professor_ryan
soowlihhousmoulcompaore@Soowlihs-MacBook-Air-116 ~ % 
*/
