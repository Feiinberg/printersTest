//#include "snmp++-3.5.2\libsnmp.h"
#include "snmp++-3.5.2\include\snmp_pp\snmp_pp.h"

#include <string>
#include <iostream>

#include "PrinterData.h"
#include "SnmpGetPrinterdata.h"
#include "PrinterDatasOids.h"

    std::string
    SnmpGetPrinterdata::getValueByOid(Snmp_pp::CTarget &target, Snmp_pp::Snmp &snmp, const std::string &oid) {


        // Create a PDU for the GET request
        Snmp_pp::Pdu pdu;
        Snmp_pp::Vb vb;  // Variable binding
        vb.set_oid(oid.c_str());  // Set the OID we want to query
        pdu += vb;  // Add the variable binding to the PDU

        // Send the GET request
        int status = snmp.get(pdu, target);

        // Check the status of the request
        if (status == SNMP_CLASS_SUCCESS) {
            // Successfully received a response

           return vb.get_printable_value() ;
        } else {
            // Handle error
            std::cerr << "Error in SNMP GET request: " << Snmp_pp::Snmp::error_msg(status) << std::endl;
            return "";
        }
    }


   PrinterData SnmpGetPrinterdata::getPrinterData( Snmp_pp::Snmp &snmp, const Snmp_pp::UdpAddress &address){

       // Create a target for the SNMP agent
       Snmp_pp::CTarget target(address);
       if (! target.valid()) {
           std::cout << "Invalid target" << std::endl;
           PrinterData a;
           return(a);
       }

    PrinterData result;

    result.setPagesPrinted(getValueByOid(target,snmp,printerDataOids::PrinterPagesPrintedOid,address));
    result.setSerialNumber(getValueByOid(target,snmp,printerDataOids::PrinterSerialNumberOid,address));
    result.setProductionFirm(getValueByOid(target,snmp,printerDataOids::PrinterProductionFirmOid,address));

    return result;
};







