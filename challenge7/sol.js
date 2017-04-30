var words = document.querySelectorAll('#words [id^=word]');
var table = document.querySelectorAll('#container table')[0];
var rows = document.querySelectorAll('#container table tr').length;
var cols = document.querySelectorAll('#container table tr:first-child td').length;



function run() {
	
	words.forEach(function(div) {
		var word = words[0].innerHTML;
		var found = false;
		for (var row = 1; row <= rows; row++) {
			if(found) break;
			for (var col = 1; col <= cols; col++) {
				var c = findLetter(row, col);
				if(c == word.charAt(0)) {
					end_id = checkmatch(word, row, col, rows, cols);
					if(end_id != false) {
						start_id = findId(row , col);
						generateMessage(start_id, end_id);
						found = true;
						break;
					}
					
				}
			}
		}
	})
}

function checkmatch(word, row, col, rows, cols) {
	if(isPossibleTop(word, row, col, rows, cols)) {
		return findId(row - word.length + 1, col);
	}
	if(isPossibleTopLeft(word, row, col, rows, cols)) {
		return findId(row - word.length + 1, col - word.length + 1);
	}
	if(isPossibleTopRight(word, row, col, rows, cols)) {
		return findId(row - word.length + 1, col + word.length - 1);
	}
	if(isPossibleLeft(word, row, col, rows, cols)) {
		return findId(row , col - word.length + 1);
	}
	if(isPossibleRight(word, row, col, rows, cols)) {
		return findId(row, col + word.length - 1);
	}
	if(isPossibleBottom(word, row, col, rows, cols)) {
		return findId(row + word.length - 1, col);
	}
	if(isPossibleBottomLeft(word, row, col, rows, cols)) {
		return findId(row + word.length - 1, col - word.length + 1);
	}
	if(isPossibleBottomRight(word, row, col, rows, cols)) {
		return findId(row + word.length - 1, col + word.length - 1);
	}
	return false;
}

function isPossibleTopLeft(word, row, col, rows, cols) {
	if (row < word.length) return false;
	if (col < word.length) return false;

	for (var index = 1; index < word.length; index++) {
		var nextLetter = word.charAt(index);
		var letter = findLetter(row - index, col - index);
		if(nextLetter !== letter) return false;
	}
	return true;
}

function isPossibleTopRight(word, row, col, rows, cols) {
	if (row < word.length) return false;
	if (cols - col + 1 < word.length) return false;

	for (var index = 1; index < word.length; index++) {
		var nextLetter = word.charAt(index);
		var letter = findLetter(row - index, col + index);
		if(nextLetter !== letter) return false;
	}
	return true;
}

function isPossibleBottomRight(word, row, col, rows, cols) {
	if (rows - row + 1 < word.length) return false;
	if (cols - col + 1 < word.length) return false;

	for (var index = 1; index < word.length; index++) {
		var nextLetter = word.charAt(index);
		var letter = findLetter(row + index, col + index);
		if(nextLetter !== letter) return false;
	}
	return true;
}

function isPossibleBottomLeft(word, row, col, rows, cols) {
	if (rows - row + 1 < word.length) return false;
	if (col < word.length) return false;

	for (var index = 1; index < word.length; index++) {
		var nextLetter = word.charAt(index);
		var letter = findLetter(row + index, col - index);
		if(nextLetter !== letter) return false;
	}
	return true;
}

function isPossibleBottom(word, row, col, rows, cols) {
	if (rows - row + 1 < word.length) return false;
	for (var index = 1; index < word.length; index++) {
		var nextLetter = word.charAt(index);
		var letter = findLetter(row + index, col);
		if(nextLetter !== letter) return false;
	}
	return true;
}

function isPossibleTop(word, row, col, rows, cols) {
	if (row < word.length) return false;
	for (var index = 1; index < word.length; index++) {
		var nextLetter = word.charAt(index);
		var letter = findLetter(row - index, col);
		if(nextLetter !== letter) return false;
	}
	return true;
}

function isPossibleRight(word, row, col, rows, cols) {
	if (cols - col + 1 < word.length) return false;
	for (var index = 1; index < word.length; index++) {
		var nextLetter = word.charAt(index);
		var letter = findLetter(row, col + index);
		if(nextLetter !== letter) return false;
	}
	return true;
}

function isPossibleLeft(word, row, col, rows, cols) {
	if (col < word.length) return false;
	for (var index = 1; index < word.length; index++) {
		var nextLetter = word.charAt(index);
		var letter = findLetter(row, col - index);
		if(nextLetter !== letter) return false;
	}
	return true;
}

function findLetter(row, col) {
	let div = document.querySelectorAll('#container table tr:nth-child(' + row +') td:nth-child(' + col +')')[0];
	if(div != "undefined") return div.innerHTML;
	return "";
}

function findId(row, col) {
	let div = document.querySelectorAll('#container table tr:nth-child(' + row +') td:nth-child(' + col +')')[0];
	if(div != "undefined") return div.getAttribute("id");
	return "";
}

function generateMessage(f, t) {
	let e = `${f}-${t}`;
	let m = generateM(e);
	let message = btoa(`${e}-${m}`);
	w.send(message);
}

function generateM(t) {
	let n, e, o, s = 0;
    const c = t + "-saltbae";
    if (!c.length) return s;
    for (n = 0, o = c.length; n < o; n++) e = c.charCodeAt(n), s = (s << 5) - s + e, s |= 0;
    return Math.abs(s)
}