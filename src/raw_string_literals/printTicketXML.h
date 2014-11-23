const CString PrintTicketXml::Prefix(
    "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
    "<psf:PrintTicket version=\"1\" "
    "xmlns:psf=\"http://schemas.microsoft.com/windows/2003/08/printing/printschemaframework\" "
    "xmlns:psk=\"http://schemas.microsoft.com/windows/2003/08/printing/printschemakeywords\" "
    "xmlns:ns0000=\"http://schemas.datacard.com/2009/09/printing/XPS_Card_Printer\"> ");

const CString PrintTicketXml::DisablePrintingAll(
    "<psf:Feature name=\"ns0000:DocumentEncodeOnly\">"
    "<psf:Option name=\"ns0000:All\" />"
    "</psf:Feature>");
