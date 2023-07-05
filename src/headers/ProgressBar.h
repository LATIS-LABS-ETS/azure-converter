#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include<iostream>
#include<string>
#include <chrono>

#include<indicators/progress_bar.hpp>
#include<indicators/block_progress_bar.hpp>

class ProgressBar{
    private:    
        std::chrono::steady_clock::time_point _lastCall;
        unsigned int _total;    
        unsigned int _width = 50;//Total number of characters on the screen
        std::string _symbol = "#";
        std::string _header;
        std::string _footer;

        indicators::BlockProgressBar _bar{
                        indicators::option::BarWidth{50},
                        indicators::option::Start{"["},
                        indicators::option::End{" ]"},
                        indicators::option::ForegroundColor{indicators::Color::green},
                        indicators::option::FontStyles{std::vector<indicators::FontStyle>{indicators::FontStyle::bold}},
                        indicators::option::ShowElapsedTime{true},
                        indicators::option::ShowPercentage{true},
                        indicators::option::ShowRemainingTime{true}
                    };

    public:
        ProgressBar();
        ProgressBar(unsigned int total);
        ProgressBar(unsigned int total, unsigned int width);
        ProgressBar(unsigned int total, std::string symbol);
        ProgressBar(unsigned int total, unsigned int width, std::string symbol);
        
        void setHeader(std::string header);
        void setFooter(std::string footer);
        void update(unsigned int current);
        void finish();
};

#endif