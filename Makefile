CC = gcc
CXX = g++

DEF_CFLAGS ?= -g -Wall

CFLAGS ?= $(DEF_CFLAGS) 
SLCP_SOURCES = slcp_ack_cmds.c slcp_anim_cmds.c slcp_led_cmds.c slcp_sensor_cmds.c
SOURCES = corl8_app.c com_utils.c crc_utils.c test_stdio.c usb_serial.c
EXECUTABLE = corl8

all: $(EXECUTABLE)

clean:
	rm -f core $(EXECUTABLE) *.o

corl8_app.o: corl8_app.c
	$(CC) $(CFLAGS) -c $< -o $@

com_utils.o: com_utils.c com_utils.h
	$(CC) $(CFLAGS) -c $< -o $@

crc_utils.o: crc_utils.c crc_utils.h
	$(CC) $(CFLAGS) -c $< -o $@

slcp_ack_cmds.o: slcp_ack_cmds.c slcp_ack_cmds.h
	$(CC) $(CFLAGS) -c $< -o $@

slcp_anim_cmds.o: slcp_anim_cmds.c slcp_anim_cmds.h
	$(CC) $(CFLAGS) -c $< -o $@

slcp_led_cmds.o: slcp_led_cmds.c slcp_led_cmds.h
	$(CC) $(CFLAGS) -c $< -o $@

slcp_sensor_cmds.o: slcp_sensor_cmds.c slcp_sensor_cmds.h
	$(CC) $(CFLAGS) -c $< -o $@

test_stdio.o: test_stdio.c test_stdio.h
	$(CC) $(CFLAGS) -c $< -o $@

usb_serial.o: usb_serial.c usb_serial.h
	$(CC) $(CFLAGS) -c $< -o $@

$(EXECUTABLE): $(SOURCES:.c=.o) $(SLCP_SOURCES:.c=.o)
	$(CC) -o $@ $^
