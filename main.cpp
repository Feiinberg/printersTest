#include <iostream>



#include "snmp++-3.5.2\libsnmp.h"
#include "snmp++-3.5.2\include\snmp_pp\snmp_pp.h"

#include "SnmpGetPrinterdata.h"

int main() {



    Snmp_pp::Snmp::socket_startup(); // Инициализация SNMP


    const Snmp_pp::UdpAddress address("127.0.0.1/161"); // Пример адреса
    if (!address.valid()) {
        std::cout << "Invalid destination: " << address << std::endl;
        return(1);
    }


    PrinterData printerData(SnmpGetPrinterdata::getPrinterData(address));

    printerData.printToConsole();

    Snmp_pp::Snmp::socket_cleanup(); // Очистка
    return 0;
}