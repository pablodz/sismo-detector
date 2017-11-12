<?php
// Connecting, selecting database
$link = mysql_connect('XXXXX', 'root', '123456')
    or die('No se puede conectar: ' . mysql_error());
//echo 'Conectado correctamente';
mysql_select_db('credenciales') or die('No se puede conectar Base de Datos Sismo1');

// Performing SQL query
$query = 'SELECT max(estado) FROM usuarios';
$result = mysql_query($query) or die('Fallo envio de Query: ' . mysql_error());

// Printing results in HTML
//echo "<table>\n";
while ($line = mysql_fetch_array($result, MYSQL_ASSOC)) {
    //echo "\t<tr>\n";
    foreach ($line as $col_value) {
        //echo "\t\t<td>$col_value</td>\n";
        echo "$col_value";
    }
    //echo "\t</tr>\n";
}
//echo "</table>\n";

// Free resultset
mysql_free_result($result);

// Closing connection
mysql_close($link);
?>
