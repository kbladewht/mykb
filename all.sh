
currentdate=$(date +%Y%m%d-%H)

#qf_path=/d/Users/ht/Documents/GitHub/vial-qmk5
qf_path=/home/w0011/mykb

RED='\e[1;31m'
GREEN='\e[1;32m'
YELLOW='\033[1;33m'
BLUE='\E[1;34m'
PINK='\E[1;35m'  # 粉红
END='\033[0m'  # 清除颜色

# Check for "clean" option in the script arguments
if [[ "$@" == *clean* ]]; then
    echo -e "${GREEN}Cleaning build environment...${END}"

    make clean
fi

# Check for "clean" option in the script arguments
if [[ "$@" == *cleanall* ]]; then
    echo -e "${GREEN}Cleaning .a library files build environment...${END}"
    rm -rf lib/*.a
fi



RED='\e[1;31m'
GREEN='\e[1;32m'
YELLOW='\033[1;33m'
BLUE='\E[1;34m'
PINK='\E[1;35m'  # 粉红
END='\033[0m'  # 清除颜色




 pconfig1=$1
 pconfig2=$2

  echo "...."

  echo "./all.sh 64_d2 f4    or     ./all.sh 6400 f4"


echo "...."




if [ "$#" -lt 2 ]; then
    echo "Error: At least two parameters are required."
    exit 1
fi

  printf "${GREEN} build_64_${pconfig1}/${pconfig2} ...$END\n"
    qfroot=pivot
    qfconfig=${pconfig1}/${pconfig2}
    qfkeymap=${pconfig1%_*}keymap

    echo "make ${qfroot}/${qfconfig}:${qfkeymap}"
    echo "pconfig2===${pconfig2}"
    echo "pconfig1===${pconfig1}"


     make ${qfroot}/${qfconfig}:${qfkeymap}

