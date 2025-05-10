#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>
using namespace std;

struct LogEntry{
    int attemptNumber;
    string password;
};
//Function to record password attempts
class Logger {
    private: 
    vector<LogEntry> logEntries;
    int attemptCount;

    public:
    Logger();
    void logAttempt(const string& password);
    void printLog(int count, int limit) const;
    int getAttemptCount() const;
};

#endif
