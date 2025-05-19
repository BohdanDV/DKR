#include <iostream>
#include <fstream>
 enum LogLevel { DEBUG, INFO, WARNING, ERROR, CRITICAL };


class Logger{

private:
    static Logger& getInstance(const std::string& filename = "logfile.txt");
    std::ofstream logFile;
    Logger (const Logger&){}
    Logger& operator=(Logger&)= delete;


public:
    Logger(const std::string& filename);
    ~Logger();
    void log(LogLevel level, const std::string& message);
    std::string convertLevel (LogLevel level);
   
    





};
