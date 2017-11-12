<?php
$con = mysqli_connect('XXXXXXXXX','root','123456');


if(!$con)
{
 echo 'No se establecio conexión con el servidor\r\n';
}
if (!mysqli_select_db ($con,'peru1'))
{
 echo 'Error al conectar con base de datos\n\r';
}

 $SismoID= $_GET["id"];
$acelx = $_GET['x'] ;
$acely = $_GET['y'] ;
$acelz = $_GET['z'] ;
echo $SismoID;
echo $acelx;
echo $acely;
echo $acelz;
$sql = "UPDATE `lima01` SET `acelx`=$acelx, `acely`=$acely, `acelz`=$acelz WHERE `id`=$SismoID";
if (!mysqli_query($con,$sql))
{
 echo 'Error al insertar! Quizás sea tabla errónea!\n\r';
}

else
{
 echo 'Insertación perfecta!\r\n';
}

?>
