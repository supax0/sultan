# Exit immediately if any command exits with a non-zero status
set -e

if [ "$1" == "build" ]; then
    cd compiler || exit
    gcc driver.c sultanc.tab.c lex.yy.c -o sultanc -ll
    echo "Build complete."

elif [ "$1" == "run" ]; then
    # Check if the second argument is provided and ends with .sn
    if [[ -z "$2" ]]; then
        echo "Error: No .sn file provided."
        exit 1
    elif [[ "$2" != *.sn ]]; then
        echo "Error: File must have a .sn extension."
        exit 1
    fi
    
    cd compiler || exit
    ./sultanc "$2"
    echo "Run complete."

elif [ "$1" == "clean" ]; then
    cd compiler || exit
    rm -r sultanc lex.yy.c sultanc.tab.c sultanc.tab.h target
    echo "Clean complete."

else
    echo "Usage: $0 {build|run <file.sn>|clean}"
    exit 1
fi
