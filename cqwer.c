#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int main() {
    short int choice;
    char buffer[32];

    SetConsoleTitle("cqwer-18072023");
    system("mode con: cols=120 lines=30"); // For Windows XP - 7

    // MENU
    menu:
    choice = -1;
    system("cls");
    system("echo PC: \%computername\%");
    printf("ID (LiteManager Pro Server):\n");
    system("reg query \"HKEY_LOCAL_MACHINE\\SYSTEM\\LiteManager\\v3.4\\Server\\Parameters\" /v \"ID (read only)\"");
    printf(
    "\n"
    " 1. Принудительно завершить работу LibreOffice (taskkill)\n"
    " 2. Принудительно завершить работу LibreOffice (pskill)\n"
    "==================== Требуюутся права Aдминистратора ====================\n"
    " 3. Перезапустить службу \"Windows Search\"\n"
    " 4. Перезапустить службы \"Сервер\" и \"Рабочая станция\"\n"
    " 5. Перезапустить службу \"Диспетчер печати\" и удалить все очереди печати\n"
    " 6. (4+5) Перезапустить службы \"Сервер\", \"Рабочая станция\", \"Диспетчер печати\" и удалить все очереди печати\n"
    " 7. Перезапустить службу \"Служба загрузки изображений Windows (WIA)\"\n"
    " 8. Перезапустить службу \"Autodesk Licensing Service\"\n"
    " 9. Включение поддержки SMBv1 в Windows 10-11 (DISM)\n"
    "10. sfc /scannow - НЕ РАБОТАЕТ\n"
    "11. Проверка и восстановление системы Windows 10-11 (DISM)\n"
    "12. chkdsk C: /f /r\n"
    "=========================================================================\n"
    "13. Перезапустить LiteManager Pro Server\n"
    "14. Удалить пустые папки в AppData (текущий пользователь) и ProgramData\n"
    "??. Очистка кэша аддонов Garry's Mod\n"
    "??. GOST 31688-2012 (7-Zip)\n"
    "\n"
    " 0. Выход (или CTRL+C)\n"
    "\n"
    );

    printf("TYPE (short int): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%hd", &choice);

    switch (choice) {
        case 1:
            goto soffice1;
        case 2:
            goto soffice2;
        case 3:
            goto wsearch;
        case 4:
            goto lanman;
        case 5:
            goto spooler;
        case 6:
            goto lanman_spooler;
        case 7:
            goto stisvc;
        case 8:
            goto acad;
        case 9:
            goto smb;
        case 10:
            goto sfc;
        case 11:
            goto dism;
        case 12:
            goto chkdsk;
        case 13:
            goto romserver;
        case 14:
            goto clear;
        case 111:
            goto gmod;
        case 222:
            goto backup;
        case 0:
            goto end;
        default:
            printf("%hd, IS INVALID.\n", choice);
            goto restart;
    }

    // 1. LibreOffice #1
    soffice1:
    system("cls");
    printf("WORKING...\n\n");
    system("taskkill /f /im soffice.bin");
    system("taskkill /f /im soffice.exe");
    goto restart;

    // 2. LibreOffice #2
    soffice2:
    system("cls");
    printf("WORKING...\n"); // 1x \n
    system("pskill soffice.bin");
    system("pskill soffice.exe");
    goto restart;

    // 3. Windows Search
    wsearch:
    system("cls");
    printf("WORKING...\n\n");
    system("net stop WSearch");
    system("net start WSearch");
    goto restart;

    // 4. LanmanServer && LanmanWorkstation
    lanman:
    system("cls");
    printf("WORKING...\n\n");
    system("net stop LanmanServer");
    system("net stop LanmanWorkstation");
    system("net start LanmanServer");
    system("net start LanmanWorkstation");
    goto restart;

    // 5. Spooler
    spooler:
    system("cls");
    printf("WORKING...\n\n");
    system("net stop Spooler");
    system("del \%SystemRoot\%\\system32\\spool\\PRINTERS\\*.* /q /s");
    system("net start Spooler");
    goto restart;

    // 6. 4 + 5
    lanman_spooler:
    system("cls");
    printf("WORKING...\n\n");
    system("net stop LanmanServer");
    system("net stop LanmanWorkstation");
    system("net start LanmanServer");
    system("net start LanmanWorkstation");
    system("net stop Spooler");
    system("del \%SystemRoot\%\\system32\\spool\\PRINTERS\\*.* /q /s");
    system("net start Spooler");
    goto restart;

    // 7. Windows Image Acquisition (WIA)
    stisvc:
    system("cls");
    printf("WORKING...\n\n");
    system("net stop stisvc");
    system("net start stisvc");
    goto restart;

    // 8. Autodesk Licensing Service
    acad:
    system("cls");
    printf("WORKING...\n\n");
    system("net stop AdskLicensingService");
    system("net start AdskLicensingService");
    goto restart;

    // 9. SMBv1
    smb:
    system("cls");
    printf("WORKING...\n\n");
    system("Dism /online /Get-Features /format:table | find \"SMB1Protocol\"");
    system("pause");
    system("Dism /online /Enable-Feature /FeatureName:\"SMB1Protocol-Client\"");
    system("Dism /online /Enable-Feature /all /FeatureName:\"SMB1Protocol-Client\"");
    goto restart;

    // 10. sfc /scannow
    sfc:
    system("cls");
    printf("WORKING...\n"); // 1x \n
    system("start sfc /scannow");
    goto restart;

    // 11. DISM
    dism:
    system("cls");
    printf("WORKING...\n"); // 1x \n
    system("Dism /Online /Cleanup-Image /CheckHealth");
    system("Dism /Online /Cleanup-Image /RestoreHealth");
    goto restart;

    // 12. chkdsk C: /f /r
    chkdsk:
    system("cls");
    printf("WORKING...\n\n");
    system("chkdsk C: /f /r");
    goto restart;

    // 13. LiteManager Pro Server
    romserver:
    system("cls");
    printf("WORKING...\n\n");
    system("\"C:\\Program Files (x86)\\LiteManager Pro - Server\\ROMServer.exe\" /restart");
    goto restart;

    // 14. AppData && ProgramData
    clear:
    system("cls");
    printf("WORKING...\n\n");
    system("echo ROBOCOPY...");
    system("robocopy \"\%USERPROFILE\%\\AppData\" \"\%USERPROFILE\%\\AppData\" /S /MOVE /NFL /NDL >nul 2>&1");
    system("robocopy \"\%PROGRAMDATA\%\" \"\%PROGRAMDATA\%\" /S /MOVE /NFL /NDL >nul 2>&1");
    goto restart;

    // 111. Garry's Mod
    gmod:
    system("cls");
    printf("WORKING...\n\n");
    system("del \"C:\\Program Files (x86)\\Steam\\steamapps\\common\\GarrysMod\\garrysmod\\cache\\*.*\" /s /q /f");
    system("rmdir \"C:\\Program Files (x86)\\Steam\\steamapps\\common\\GarrysMod\\garrysmod\\cache\\lua\" /s /q");
    system("rmdir \"C:\\Program Files (x86)\\Steam\\steamapps\\common\\GarrysMod\\garrysmod\\cache\\workshop\" /s /q");
    system("del \"C:\\Program Files (x86)\\Steam\\steamapps\\common\\GarrysMod\\garrysmod\\data\\*.*\" /s /q /f");
    system("rmdir \"C:\\Program Files (x86)\\Steam\\steamapps\\common\\GarrysMod\\garrysmod\\data\" /s /q");
    system("del \"C:\\Program Files (x86)\\Steam\\steamapps\\common\\GarrysMod\\garrysmod\\demos\\*.*\" /s /q /f");
    system("del \"C:\\Program Files (x86)\\Steam\\steamapps\\common\\GarrysMod\\garrysmod\\dupes\\*.*\" /s /q /f");
    system("del \"C:\\Program Files (x86)\\Steam\\steamapps\\common\\GarrysMod\\garrysmod\\screenshots\\*.*\" /s /q /f");
    system("del \"C:\\Program Files (x86)\\Steam\\steamapps\\common\\GarrysMod\\garrysmod\\videos\\*.*\" /s /q /f");
    system("echo ROBOCOPY...");
    system("robocopy \"C:\\Program Files (x86)\\Steam\\steamapps\\workshop\" \"C:\\Program Files (x86)\\Steam\\steamapps\\workshop\" /S /MOVE >nul 2>&1");
    goto restart;

    // 222. GOST 31688-2012
    backup:
    system("cls");
    printf("WORKING...\n"); // 1x \n
    system("del \"D:\\TRANSFER\\GOST 31688-2012.7z\"");
    system("C:\\PROGRA~1\\7-Zip\\7z.exe a -t7z \"D:\\TRANSFER\\GOST 31688-2012.7z\" \"D:\\SYNC\\Obsidian\\GOST 31688-2012\" -pP622056714");
    goto restart;

    // RESTART
    restart:
    system("::echo.");
    system("pause");
    system("cls");
    goto menu;

    // END
    end:
    return 0;
}
