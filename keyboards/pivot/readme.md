

For 24


    make qfly/config24:k24
    or 
    ./24.sh
    
For 75
    make qfly/q75:75keymap
    or
    ./75.sh

vkeymap=75keymap
vconfig=q75
make qfly/${vconfig}:$vkeymap
cp /c/msys64/home/xx/qmk_firmware3/.build/qfly_${vconfig}_$vkeymap.uf2 E:/flash.uf2



docker upgrade to v2
