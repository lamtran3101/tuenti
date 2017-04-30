<?php

define("TEST_INPUT_FILE", "testInput.txt");
define("TEST_OUTPUT_FILE", "output");

define("SUBMIT_INPUT_FILE", "submitInput.txt");
define("SUBMIT_FILE", "submitOutput");

include "functions.inc";

$output = fopen(SUBMIT_FILE, "w");

$ch = curl_init();

curl_setopt($ch, CURLOPT_URL,"https://52.9.91.111:8443/ghost");

// in real life you should use something like:
// curl_setopt($ch, CURLOPT_POSTFIELDS, 
//          http_build_query(array('postvar1' => 'value1')));

// receive server response ...
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);

$server_output = curl_exec ($ch);
var_dump($server_output);
curl_close ($ch);

fclose($output);
?>

