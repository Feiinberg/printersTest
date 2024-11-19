#ifndef PRINTERS_PRINTERDATA_H
#define PRINTERS_PRINTERDATA_H


#include <string>
#include <utility>

class PrinterData {
private:
    std::string ProductionFirm;
    std::string SerialNumber;

    std::string PagesPrinted ;

    //could be expanded if needed

public:
    PrinterData();
    PrinterData(PrinterData& other);

    std::string getProductionFirm();
    std::string getSerialNumber();
    std::string getPagesPrinted();

    void setProductionFirm(std::string value);
    void setSerialNumber(std::string value);
    void setPagesPrinted(std::string value);


    void printToConsole();
};


#endif //PRINTERS_PRINTERDATA_H
