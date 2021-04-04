sudo pip3 install -r requirements.txt

alias display='sudo python3 /home/pi/gpio/src/binding.py'
sudo echo "alias display='sudo python3 /home/pi/gpio/src/binding.py'" >> /home/pi/.bashrc

echo 'Successfully set alias "display"'
