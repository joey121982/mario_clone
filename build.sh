cmake .
make

read -p "Run game? (y/n): " answer

if [[ $answer == "y" ]]; then
    ./build/game
else
    exit
fi