#!/bin/sh

ROOT_UID="0"

#Check if run as root
if [ `whoami` != root ]; then
  echo Please run this script as root or using sudo
  exit
fi
does_folder_exist() {
  if [ -d $HOME/$1 ]
  then
    echo "**************************"
    echo "You already have a ~/$1 folder."
    echo "If you want to use this script, please backup your $1 folder first."
    echo "**************************"
    exit 1
  fi
}

does_folder_exist "termcolor"

START_DIR=pwd

echo "*** Cloning repository into ~/termcolor ..."
git clone git://github.com/cyounes/termcolor.git ~/termcolor;
cd ~/termcolor;
echo "installing \033[1mtermcolor.h\033[0m... "
sudo cp termcolor.h /usr/include/termcolor.h
sleep 1
# Go back to the user ran this script from
cd $START_DIR

# Remove the cloned folder
echo "removing cloned folder..."
rm -rf ~/termcolor
sleep 1
# Print out some happy success messages
echo ""
echo ""
echo "***********************************************"
echo "*** \033[5mDone!\033[0m                                   ***"
echo "*** \033[4mSummary:\033[0m                                ***"
echo "*** \033[32mcloned\033[0m git reppository to ~/termcolor   ***"
echo "*** \033[32minstalled\033[0m library on /usr/include/      ***"
echo "*** \033[31mRemoved\033[0m cloned folder                   ***"
echo "*** \033[42m\033[30mHave a great day!\033[0m                       ***"
echo "***********************************************"
echo ""
echo ""
