# See https://github.com/bxparks/UnixHostDuino for documentation about this
# Makefile to compile and run Arduino programs natively on Linux or MacOS.

GENERATED := validation_data.cpp validation_data.h validation_tests.cpp
OBJS = validation_data.o validation_tests.o
APP_NAME := BasicValidationUsingPythonTest
ARDUINO_LIBS := AUnit AceTime
include ../../../../UnixHostDuino/UnixHostDuino.mk

runtests:
	./$(APP_NAME).out

.PHONY: $(GENERATED)

validation_data.cpp:
	../../../tools/tzcompiler.sh --tag 2019a --action unittest --language arduino --scope basic --start_year 2000 --until_year 2038
