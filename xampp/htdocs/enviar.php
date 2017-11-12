<?php
$con = mysqli_connect('XXXXXXXX','root','123456');


if(!$con)
{
 echo 'No se establecio conexión con el servidor';
}
if (!mysqli_select_db ($con,'peru1'))
{
 echo 'Error al conectar con peru1';
}

 $SismoID= $_GET["id"];
$acelx = $_GET['x'] ;
$acely = $_GET['y'] ;
$acelz = $_GET['z'] ;
$e = $_GET['e'] ;
echo ("\n\r");
echo '-------INFORMACION ENVIADA AL SERVIDOR-------------';
echo ("\n\r");
echo 'ID=';
echo $SismoID;
echo ';';
echo 'acelX=';
echo $acelx;
echo ';';
echo 'acelY=';
echo $acely;
echo ';';
echo 'acelZ=';
echo $acelz;
echo ';';
echo 'e=';
echo $e;

$sql = "UPDATE `lima01` SET `acelx`='$acelx', `acely`='$acely', `acelz`='$acelz'  WHERE `id`=$SismoID;";
echo ("\n\r");
echo $sql;

if (!mysqli_query($con,$sql))
{
echo ("\n\r");
 echo 'Error al insertar! Quizás sea tabla errónea!';
}

else
{
    echo ("\n\r");
 echo '-------  INSERTACION PERFECTA ACELERACIONES  ----------';
 echo ("\n\r");
}
//====================================================================
//====================================================================
//====================================================================
$con2 = mysqli_connect('XXXXX','root','123456');
if (!mysqli_select_db ($con2,'credenciales'))
{
 echo 'Error al conectar con credenciales';
}
else{
    echo 'Si se conecto a tabla credenciales';
}
$sql2 = "UPDATE usuarios SET estado=$e WHERE `idusuarios`=$SismoID;";
echo ("\n\r");
echo $sql2;
if (!mysqli_query($con2,$sql2))
{
echo ("\n\r");
 echo 'Error al insertar! Quizás sea tabla errónea!';
}
else
{
    echo ("\n\r");
 echo '-------  INSERTACION PERFECTA ESTADO  ----------';
 echo ("\n\r");
}

?>
