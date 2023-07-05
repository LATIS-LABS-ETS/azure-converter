#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include<iostream>
#include<string>
#include <chrono>

class ProgressBar{
    private:
        std::chrono::steady_clock::time_point _lastCall;
        unsigned int _total;    
        unsigned int _width;//Total number of characters on the screen
        std::string _symbol;
        std::string _header;
        std::string _footer;
    public:
        ProgressBar(unsigned int total);
        ProgressBar(unsigned int total, unsigned int width);
        ProgressBar(unsigned int total, std::string symbol);
        ProgressBar(unsigned int total, unsigned int width, std::string symbol);
        void setHeaderAndFooter(std::string header, std::string footer);
        void update(unsigned int current);
        void update(unsigned int current, std::string description);
};

#endif