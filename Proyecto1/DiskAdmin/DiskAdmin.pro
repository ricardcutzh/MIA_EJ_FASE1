TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    consola.c \
    listatoken.c \
    analizadorlexico.c \
    analizadorsintactico.c

HEADERS += \
    consola.h \
    listatoken.h \
    general.h \
    analizadorlexico.h \
    analizadorsintactico.h
