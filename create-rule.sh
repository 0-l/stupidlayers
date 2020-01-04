sudo tee /usr/lib/udev/rules.d/30-stupidlayers.rules << "EOF"
ACTION=="add", \
KERNEL=="event[0-9]*", \
ATTRS{name}=="SONiX USB DEVICE", \
RUN+="/bin/sh -c 'echo /usr/bin/stupidlayers /dev/input/%k | at now'"
EOF

sudo yay -S at
sudo ln -s /etc/sv/at /var/service
sudo sv start at
sudo udevadm control --reload
sudo udevadm control --reload-rules
