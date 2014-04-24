<?php 
error_reporting(E_ALL);
ini_set('display_errors','1');
include 'PhpSerial.php';

header('Content-type: text/plain');

echo "1";

$serial = new PhpSerial;
echo "serial created";
$serial->deviceSet("/dev/ttyACM1");
$serial->confBaudRate(9600);
$serial->deviceOpen();
echo "Opened";

$serial->sendMessage("O");

echo $serial->readPort();

$serial->deviceClose();
?>
