from sys import argv
from os  import system

system(f"sudo -H -u nexi pactl set-sink-volume 0 {argv[2]}{argv[1]}%")
