#include "Logger.h"
using namespace std;
#include <ctime>

Logger::~Logger(){
    logFile.close();

}

void Logger::log(LogLevel level, const std::string& message){

    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp),
                "%Y-%m-%d %H:%M:%S", timeinfo);

    cout << "[" << timestamp << "] "<< convertLevel(level) << ": " << message<< endl;

     if (logFile.is_open()) {
            logFile << "[" << timestamp << "] " << convertLevel(level) << ": " << message << endl;
            logFile.flush(); 
        }
}





Logger& Logger::getInstance(const std::string& filename) {
    static Logger instance(filename);
    return instance;
}

 Logger::Logger(const std::string& filename){

    logFile.open(filename, ios::out);
     if (!logFile.is_open()) {
            cerr << "Error opening log file." << endl;
    }
    
 }

 string Logger::convertLevel(LogLevel level) {
    switch (level) {
            case DEBUG:
                return "DEBUG";
            case INFO:
                return "INFO";
            case WARNING:
                return "WARNING";
            case ERROR:
                return "ERROR";
            case CRITICAL:
                return "CRITICAL";
            default:
                return "UNKNOWN"; 
 }
}