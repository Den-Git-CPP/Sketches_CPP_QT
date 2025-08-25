$pathfolder = Get-Location
Set-Location $pathfolder
mkdir build
Set-Location build
cmake .. -G "MinGW Makefiles"
mingw32-make

Set-Location $pathfolder


