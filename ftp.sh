#!/bin/bash
read -p "Enter Username: " ftpuser
read -p "Enter Username Password: " T3@m$h@r3
echo
ftp_server="10.10.37.219"
ftp_username="$Username"
ftp_password="$Password"
mkdir /home/username/linux/source_folder
source_folder="/home/username/source_folder/"
cp -avr config* $source_folder
dest_folder="/home/username/linux/dest_folder/"
ftp -in $ftp_server <<END_SCRIPT
quote USER $ftp_username
quote PASS $ftp_password
cd $source_folder
!cd $dest_folder
mget -R *
quit
