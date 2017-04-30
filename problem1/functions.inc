<?php

function getNumberOfCases($line) {
	$numbers = getNumbersFromString($line);
	return $numbers[0];
}

function getNumberOfPeople($line) {
	$numbers = getNumbersFromString($line);
	return $numbers[0];
}

function getMinimumOrderPizza($line) {
	$numbers = getNumbersFromString($line);
	$allPizzaSlices = getSumPizzaSlices($numbers);
	$minimumOrderPizza = ceil($allPizzaSlices / SLICES_PER_PIZZA);
	return $minimumOrderPizza;
}

function getSumPizzaSlices($numbers) {
	$sum = 0;
	foreach ($numbers as $number) {
		$sum += intval($number);
	}
	return $sum ;
}

function getNumbersFromString($line) {
	$numbers = array();
	$params = explode(" ", $line);
	foreach ($params as $param) {
		$numbers[] = intval($param);
	}
	return $numbers;
}

function prepareResult($case, $pizza){
	return "Case #".$case.": ".$pizza."\n";
}

function write2file($file, $case, $pizza){
	$text = prepareResult($case, $pizza);
	fwrite($file, $text);
}

function printResult($case, $pizza) {
	printf("Case #%d: %d\n", $case, $pizza);
}

function is_blank_line($file){
	if($file == "\n" || $file == "") return true;
	return false;
}
?>