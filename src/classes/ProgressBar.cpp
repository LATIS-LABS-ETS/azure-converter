#include<stdlib.h>
#include<cmath>
#include <indicators/cursor_control.hpp>

#include<ProgressBar.h>


ProgressBar::ProgressBar(){    
    indicators::show_console_cursor(false);
}
ProgressBar::ProgressBar(unsigned int total): _total(total), _width(100), _symbol("#"){
    ProgressBar();
    this->_bar.set_option(indicators::option::BarWidth{this->_width});
}
ProgressBar::ProgressBar(unsigned int total, unsigned int width): _total(total), _width(width), _symbol("#"){
    ProgressBar();
    this->_bar.set_option(indicators::option::BarWidth{this->_width});
}
ProgressBar::ProgressBar(unsigned int total, std::string symbol): _total(total), _width(100), _symbol(symbol){
    ProgressBar();
    this->_bar.set_option(indicators::option::BarWidth{this->_width});
}
ProgressBar::ProgressBar(unsigned int total, unsigned int width, std::string symbol): _total(total), _width(width), _symbol(symbol){
    ProgressBar();
    this->_bar.set_option(indicators::option::BarWidth{this->_width});
}


void ProgressBar::update(unsigned int current){
    float ratio = fmin(((float) current) / ((float) this->_total), 1.0);
    this->_bar.set_option(indicators::option::PrefixText{this->_header});
    this->_bar.set_option(indicators::option::PostfixText{this->_footer});
    this->_bar.set_progress(ratio*100);
}

void ProgressBar::setHeader(std::string header){
    this->_header = header;
}

void ProgressBar::setFooter(std::string footer){
    this->_footer = footer;
}

void ProgressBar::finish(){
    indicators::show_console_cursor(true);
    this->_bar.mark_as_completed();
}