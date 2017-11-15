# Autor: Pablo Díaz
# Haciendo pruebas con BeautifulSoup y requests
# Importamos las librerias

from bs4 import BeautifulSoup
#importamos librerias
import requests
import time
import os# Creamos el Bucle infinito
#======================================================#

#======================================================#
#!/usr/bin/python
def enviarAlerta(numero):
    url = "http://localhost:8080/form.php?nom=SismoAlerta&num=+51"+numero+"&msj='Se ha registrado un movimiento telúrico en su zona. Evacué'"
    # Capturamos el hml de la pagina web y creamos un objeto Response
    r = requests.get(url)
    print("SE REGISTRO UN SISMO... SE ENVIÓ MENSAJE!")
    return
while (True):

    # Capturamos la url
    url = "http://localhost:8080/estadosismos.php"

    # Capturamos el hml de la pagina web y creamos un objeto Response
    r = requests.get(url)
    data = r.text
       # Creamos el objeto soup y le pasamos lo capturado con request
    #soup = BeautifulSoup(data, 'html.parser')

    # Fecha de juego center date_time
    #fecha = soup.find_all('td', class_="center date_time")

    # Buscamos el div para sacar los grados
    #eventos = soup.find_all('td', class_="event")

    # Buscamos el div para sacar la sensacion termica
    #estadisticas = soup.find_all('td', class_=("center outcome "))
    #i=0
    #j=0
    # Con [0] saco el primer elemento y con [1] el segundo
    #print(str(data))
    estado=data[0:1]
    numero=data[1:10]
    print("\n\r "+str(estado))
    print("\n\r " + str(numero))
    #time.sleep(15)
    if (estado=="1"):

            print("estado es 1")
            print("Enviando mensaje...")
            enviarAlerta(numero)
            print("Esperaré 10 segundos para el siguiente mensaje...")
            time.sleep(20)
    else:
            print("estado es 0")
            print("Seguimos al tanto.....")
    # Boramos los datos viejos, para Windows es "cls"
    os.system('cls')
