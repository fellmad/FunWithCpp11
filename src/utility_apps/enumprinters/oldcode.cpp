#include <windows.h>
#include <tchar.h>
#include <winspool.h>

/* Returns TRUE if another printer is installed with the same dataFile */
BOOL IsAnotherDriverInstalled(LPTSTR dataFile)
{
    DWORD         dwBytesNeeded = 0, dwPrtRet = 0, i;
    LPPRINTER_INFO_2 pPrtInfo2;
    BOOL          bReturn = FALSE;
    TCHAR         pDataFile[FILE_SIZE];

    DoTraceMessage(WS_TRACE, TEXT("IsDriverInstalled()"));
    //
    // get byte count needed for buffer, alloc buffer, then enum the drivers
    //

    EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_NETWORK | PRINTER_ENUM_CONNECTIONS,
        (LPTSTR) NULL, 2, NULL, 0, &dwBytesNeeded, &dwPrtRet);

    pPrtInfo2 = (LPPRINTER_INFO_2) LocalAlloc(LPTR, dwBytesNeeded);

    if (pPrtInfo2) {
        EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_NETWORK | PRINTER_ENUM_CONNECTIONS,
            (LPTSTR) NULL, 2, (unsigned char *) pPrtInfo2, dwBytesNeeded, &dwBytesNeeded, &dwPrtRet);

        DoTraceMessage(WS_TRACE, TEXT("IsAnotherDriverInstalled: dwPrtRet = %d"), dwPrtRet);

        for (i = 0; i < dwPrtRet; i++) {
            StringCchCopy(pDataFile, sizeof(pDataFile) / sizeof(pDataFile[0]), TEXT(""));
            if (GetDataFile((pPrtInfo2 + i)->pDriverName, pDataFile, sizeof(pDataFile) / sizeof(pDataFile[0]))) {
                if (!lstrcmpi(pDataFile, dataFile)) {
                    bReturn = TRUE;
                    break;
                }
            }
        }

        LocalFree(pPrtInfo2);
    }

    return bReturn;
}