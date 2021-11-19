/**
* @file GenRandomSequence.h
* @author Карев А.С.
* @version 1.0
* @date 28.02.2021
* @copyright ИБСТ ПГУ
* @brief Заголовочный файл для модуля GenRandomSequence
*/
#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/**
* @brief Программа генерации псевдослучайной последовательности на базе регистра сдвига с линейной обратной связью
* @details В метод передаётся длинна генерируемой последовательности, метод возвращет саму последовательность
*/
class GenRandomSequence
{
private:
	vector<int> reg;
public:
	GenRandomSequence() = delete;
	GenRandomSequence(vector<int> reg);
	vector<int> generate(int N);
};
/**
* @brief Класс обработки ошибок GenRandom_error
*/
class GenRandom_error: public std::invalid_argument
{
public:
	explicit GenRandom_error (const std::string& what_arg):
		std::invalid_argument(what_arg) {}
	explicit GenRandom_error (const char* what_arg):
		std::invalid_argument(what_arg) {}
};
