# Qt_FireBird
## Имеем    
Win10 64 bit
Firebird 2.5 (win32)
Qt Creator 5.0.2

Системная переменная PATH содержащая пути:
G:\Firebird_2_5\bin
G:\Qt\6.2.0\mingw81_64\bin
G:\Qt\Tools\mingw810_64\bin

Далее:
QMake
cd G:\Qt\6.2.0\Src\qtbase\src\plugins\sqldrivers\ibase
qmake "INCLUDEPATH+=G:/Firebird/include" "LIBS+=G:/Firebird/lib/fbclient_ms.lib" ibase.pro
mingw32-make.exe
mingw32-make.exe install
