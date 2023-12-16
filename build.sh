cmake .

make

read -p "Run game? (y/n): " answer
if [[ $(uname) == "Linux" ]]; then
    if [[ $answer == "y" ]]; then
        ./build/game
    else
        exit
    fi
elif [[ $(uname) == "Windows" ]]; then
    if [[ $answer == "y" ]]; then
        ./build/game.exe
    else
        exit
    fi
fi
