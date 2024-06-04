all: sensordata

sensordata: main.c temp_api.c sensordata.c
	gcc -I . -o sensordata main.c temp_api.c sensordata.c

clean:
	rm -rf *.o sensordata
