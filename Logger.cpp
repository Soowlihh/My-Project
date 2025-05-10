#include "Logger.h"
#include <iostream>
#include <cmath>

Logger::Logger() : attemptCount(0){}

//records passwords attempt
void Logger::logAttempt(const string& password){
    logEntries.push_back({++attemptCount, password});
}
//prints last 10 attempts
void Logger::printLog(int count, int limit) const {
  int start = (count == -1 || limit > logEntries.size()) ? 0 : logEntries.size() - limit;
    for(size_t i  = start; i <logEntries.size(); ++i){
        cout <<"Attempt" << logEntries[i].attemptNumber << ": " << logEntries[i].password << endl;
    }
}
//shows attempts before cracking password
int Logger::getAttemptCount() const {
    return attemptCount;
}
