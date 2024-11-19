#include "PrinterData.h"

#include <iostream>
#include <string>
#include <utility>

PrinterData::PrinterData() {
    this->ProductionFirm="";
    this->SerialNumber="";
    this->PagesPrinted="";}

PrinterData::PrinterData(PrinterData& other){
this->ProductionFirm=other.ProductionFirm;
this->SerialNumber=other.SerialNumber;
this->PagesPrinted=other.PagesPrinted;}


std::string PrinterData::getProductionFirm(){return this->ProductionFirm;}
std::string PrinterData::getSerialNumber(){return this->SerialNumber;}
std::string PrinterData::getPagesPrinted(){return this->PagesPrinted;}


void PrinterData::setProductionFirm(std::string value){ this->ProductionFirm=std::move(value);}
void PrinterData::setSerialNumber(std::string value){ this->SerialNumber=std::move(value);}
void PrinterData::setPagesPrinted(std::string value){ this->PagesPrinted=std::move(value);}


void PrinterData::printToConsole(){
    std::cout <<"{";
    std::cout <<"ProductionFirm: "<<this->ProductionFirm<< std::endl;
    std::cout <<"SerialNumber: "<<this->SerialNumber<< std::endl;
    std::cout <<"PagesPrinted: "<<this->PagesPrinted<< "}\n";
}