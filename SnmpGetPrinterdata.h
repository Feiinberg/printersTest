#ifndef PRINTERS_SNMPGETPRINTERDATA_H
#define PRINTERS_SNMPGETPRINTERDATA_H

#include "snmp++-3.5.2\libsnmp.h"
#include "snmp++-3.5.2\include\snmp_pp\snmp_pp.h"

#include <string>
#include <iostream>

#include "PrinterData.h"

class SnmpGetPrinterdata {
public:
    static std::string getValueByOid(Snmp_pp::Snmp &snmp, const std::string &oid, const Snmp_pp::UdpAddress &address);

    static PrinterData getPrinterData( const Snmp_pp::UdpAddress &address);
};


#endif //PRINTERS_SNMPGETPRINTERDATA_H