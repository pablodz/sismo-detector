<?php
$con = mysqli_connect('ipCloud','root','123456');
if(!$con)
{
 echo 'No se establecio conexión con el servidor\r';
}
if (!mysqli_select_db ($con,'sismo1'))
{
 echo 'Error al conectar con base de datos\n\r';
}
$SismoID = $_GET["id"];
$acelx = $_GET['x'] ;
$acely = $_GET['y'] ;
$acelz = $_GET['z'] ;
echo $SismoID;
echo $acelx;
echo $acely;
echo $acelz;
/*
   $id=isset($_GET['id'])  ;
    $x=isset($_GET['x']) ;
    $y=isset($_GET['y']) ;
    $z=isset($_GET['z']) ;
*/
//INSERT INTO `sismo1`.`sismo1_historial` (`SismoID`, `acelx`, `acely`, `acelz`) VALUES ('234', '234234', '23423', '423423');
//INSERT INTO sismo1_historial (SismoID ,acelx , acely, acelz) VALUES ($SismoID,$acelx, $acely, $acelz)
$sql = "INSERT INTO `sismo1_historial` (`SismoID`, `acelx`, `acely`, `acelz`) VALUES ($SismoID, $acelx, $acely, $acelz)";
if (!mysqli_query($con,$sql))
{
 echo 'Error al insertar! Quizás sea tabla errónea!';
}
else
{
 echo 'Insertación perfecta +1!';
}
?>
