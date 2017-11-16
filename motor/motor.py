# Autor: Pablo Díaz
# librerias BeautifulSoup y requests
# Motor Sisografo v5.0.0
#======================================================#
from bs4 import BeautifulSoup
#importamos librerias
import requests
import time
import os# Creamos el Bucle infinito
#======================================================#
def enviarAlerta(numero):
    url = "http://localhost:8080/form.php?nom=SismoAlerta&num=+51"+numero+"&msj='Se ha registrado un sismo! Evacué'"
    # Enviamos la data mediante un metodo get
    r = requests.get(url)
    print("SE REGISTRO UN SISMO... SE ENVIÓ MENSAJE!")
    return
while (True):

    # Capturamos el estado de los sismosfos ordenados por codigo y numero de celular
    url = "http://localhost:8080/estadosismos.php"

    # Capturamos el hml de la pagina web y creamos un objeto Response
    r = requests.get(url)
    data = r.text
    # Extraemos el estado y el numero de celular para enviarlo en caso se registre un sismografo
    estado=data[0:1]
    numero=data[1:10]
    print("\n\r "+str(estado))
    print("\n\r " + str(numero))
    #time.sleep(15)
    # tomar decisiones en base a los estados
    if (estado=="1"):

            print("estado es 1")
            print("Enviando mensaje...")
            enviarAlerta(numero)
            print("Esperaré 10 segundos para el siguiente mensaje...")
            time.sleep(20)
    else:
            print("estado es 0")
            print("Seguimos al tanto.....")
