#include<stdlib.h>
#include <cmath>
#include<ProgressBar.h>


ProgressBar::ProgressBar(unsigned int total): _total(total), _width(100), _symbol("#"){}
ProgressBar::ProgressBar(unsigned int total, unsigned int width): _total(total), _width(width), _symbol("#"){}
ProgressBar::ProgressBar(unsigned int total, std::string symbol): _total(total), _width(100), _symbol(symbol){}
ProgressBar::ProgressBar(unsigned int total, unsigned int width, std::string symbol): _total(total), _width(width), _symbol(symbol){}


void ProgressBar::update(unsigned int current){
    std::chrono::steady_clock::time_point timeNow = std::chrono::steady_clock::now();
    float ratio = ((float) current) / ((float) this->_total);
    int numCharacters = (int) (ratio * (float) this->_width)+1;
    float elapsedTimePerLoop = (std::chrono::duration_cast<std::chrono::nanoseconds>(timeNow - this->_lastCall).count()) / 1e+9;
    float loopsPerSecond = std::ceil((1.0 / elapsedTimePerLoop) * 100.0) / 100.0;
    
    
    std::string message = this->_header+"\n";

    message += std::to_string((int) (ratio * 100))+"%: ";
    
    message.append(numCharacters, this->_symbol[0]);
    message.append(this->_width - numCharacters, ' ');
    message.append(1, '|');
    
    message += "["+std::to_string(current)+"it/"+std::to_string(this->_total)+"it("+std::to_string(loopsPerSecond)+"it/s)"+"]\n";
    message += this->_footer+"\n";
    // system("clear");
    std::cout << message << std::endl;
    this->_lastCall = std::chrono::steady_clock::now();
}

void ProgressBar::update(unsigned int current, std::string description){
    this->update(current);
    std::cout << description << std::endl;
}

void ProgressBar::setHeaderAndFooter(std::string header, std::string footer){
    this->_header = header;
    this->_footer = footer;
}