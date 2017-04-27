<?php

function isBlankLine($line) {
	if($line == "\n" OR $line == "") return true;
	return false;
}

function getNumberOfCases($line) {
	$numbers = getNumbersFromLine($line);
	return $numbers[0];
}

function getNumberOfRolls($line) {
	$numbers = getNumbersFromLine($line);
	return $numbers[0];
}

function getAllRolls($line) {
	$numbers = getNumbersFromLine($line);
	return $numbers;
}

function getScores($numbersOfRolls, $rolls) {
	$totalScore = 0;
	$last_score = 0;
	$currentRoll = 0;
	$scores = array();
	for ($roll_index = 0; $roll_index < $numbersOfRolls - 2; $roll_index++) { 
		$score = $rolls[$roll_index];
		$totalScore += $score;
		$currentRoll++;
		if(!isLastFrame($currentRoll)) {
			if(isStrike($score, $currentRoll)) {
				$totalScore += $rolls[$roll_index + 1] + $rolls[$roll_index + 2];
				$currentRoll++;
			} else if (isSpare($score, $last_score, $currentRoll)) {	
				$totalScore += $rolls[$roll_index + 1];
			}
			$last_score = $score;

			if(isEndFrame($currentRoll)) {
				$last_score = 0;
				$scores[] = $totalScore;
			}
		}
	}
	
	$totalScore += $rolls[$numbersOfRolls - 2] + $rolls[$numbersOfRolls - 1];
	$scores[] = $totalScore;
	
	return $scores;
}

function isStrike($score, $currentRoll ) {
	return $score == 10 && !isEndFrame($currentRoll) ;
}

function isSpare($score, $last_score, $currentRoll) {
	return ($score + $last_score) == 10 && isEndFrame($currentRoll);
}

function isEndFrame($currentRoll) {
	return ($currentRoll % 2 == 0);
}
function isLastFrame($currentRoll) {
	return $currentRoll > 18 ;
}

function getNumbersFromLine($line) {
	$numbers = array();
	$params = explode(" ", $line);
	foreach ($params as $value) {
		$numbers[] = intval($value);
	}
	return $numbers;

}


?>