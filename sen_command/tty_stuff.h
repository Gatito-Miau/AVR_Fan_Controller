#ifndef _TTY_STUFF_H
#define _TTY_STUFF_H

using namespace std;

#include <fcntl.h> // File control definitions
#include <termios.h> // POSIX terminal control definitionss
#include <stdio.h>
#include <stdlib.h>

int open_port (char* path){
	int fd = open(path, O_RDWR | O_NOCTTY | O_SYNC | O_NONBLOCK );
	//int fd = open(path, O_RDWR | O_NOCTTY | O_ASYNC );
	//int fd = open(path, O_RDWR |  O_ASYNC | O_NONBLOCK );
	
	if(fd == -1){
		printf("open_port: Unable to open %s - ", path); exit(1);}
		else{
			//fcntl(fd, F_SETFL, 0);
		}
	
	return fd;
}

int configure_port(int fd){      // configure the port

termios port_settings;
tcgetattr(fd, &port_settings);  

// Arreglo feo  para las demas configuraciones del puerto
port_settings.c_iflag = 0;
port_settings.c_oflag = 0;
port_settings.c_lflag = 35360;
port_settings.c_line = 0;

//cfsetispeed(&port_settings, B9600);    // set for I/O 9600 b/s
//cfsetospeed(&port_settings, B9600);
cfsetispeed(&port_settings, B19200);    // set for I/O 9600 b/s
cfsetospeed(&port_settings, B19200);

port_settings.c_cflag &= ~PARENB;   // Disables parity

port_settings.c_cflag &= ~CSTOPB;   // Unsets "two stop bits"
port_settings.c_cflag &= ~CRTSCTS;  // Disables hardware control
    
port_settings.c_cflag &= ~CSIZE;    // Sets 8 Bits characters
port_settings.c_cflag |= CS8;

tcsetattr(fd, TCSANOW, &port_settings);    // applies the settings to the port NOW

return(fd);
}


#endif
