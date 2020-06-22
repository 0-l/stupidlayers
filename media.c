#include <stdlib.h>
#include <stdio.h>

void adjust_volume(int percentage) {
  char modifier = percentage > 0 ? '+' : '-';
  char command[50];

  // pulseaudio's subprocess is run as the logged user, not as root
  sprintf(command, "python amixer.py %d %c", abs(percentage), modifier);

  int ret = system(command);

  if (ret > 0)
    printf("install alsa-utils: \"sudo pacman -S alsa-utils\"\n");
}

void adjust_backlight(int percentage) {
  char modifier = percentage > 0 ? 'A' : 'U';
  char command[50];

  sprintf(command, "sudo light -%c %d", modifier, abs(percentage));

  int ret = system(command);

  if (ret > 0)
    printf("install light: \"sudo pacman -S light\"\n");
}
