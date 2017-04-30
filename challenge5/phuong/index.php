<?php

$host = 'http://52.49.91.111';
$ports = range(4017,8120);
foreach ($ports as $port)
{
	echo $port."\n";
    $ch = curl_init();
	curl_setopt($ch, CURLOPT_URL,$host.":".$port);

	$server_output = curl_exec ($ch);
	var_dump($server_output);
	curl_close ($ch);
	fclose($output);

}

?>