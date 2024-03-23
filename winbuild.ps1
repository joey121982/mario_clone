cmake . -G "MinGW Makefiles"
mingw32-make

$answer = Read-Host "Run game? (y/n)"
if (($answer -eq "y") -or ($answer -eq "Y") -or ($answer -eq "")) {
    Start-Process -FilePath ".\build\game.exe"
} else {
    exit
}