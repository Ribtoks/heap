#pragma once
/*
	Прототипы функций работы с арифметическим кодированием
*/


/*
	Функция сжатия файла методом 
	арифметического кодирования
	
	
	Входные параметры:
	
	inputFile - путь к входному файлу для сжатия
	encodedFile - путь к запису сжатого файла
*/
void EncodeFile (char* inputFilePath, char* encodedFilePath);



/*
	Функция разархивирования сжатого файла
	методом арифметического кодирования
	
	
	Входные параметры:
		
	encodedFile - путь к входному файлу, предначально заархивированному
		с помощью предыдущей функции
	decodedFile - путь к разархивированный файл
*/
void DecodeFile (char* encodedFilePath, char* decodedFilePath);