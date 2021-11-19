/**
 * @file GenRandomSequence.cpp
 */
#include "GenRandomSequence.h"
/**
* @brief Конструктор класса GenRandomSequence
* @param vector<int> reg регистр состоящий из натуральных чисел
* @warning Регистр не может состоять только из нулей.
* @throw GenRandom_error, в случае ошибки
*/
GenRandomSequence::GenRandomSequence(vector<int> reg)
{
	this->reg = reg;

	if(reg.size() < 3)
		throw GenRandom_error(std::string("Слишком короткий регистр"));

	for(int i = 0; i < reg.size(); i++)
		if(reg[i] != 1 && reg[i] != 0)
			throw GenRandom_error(std::string("Недопустимый символ!"));

	int sum = 0;
	for(int i = 0; i < reg.size(); i++)
		sum += reg[i];
	if(sum == 0)
		throw GenRandom_error(std::string("Нулевой регистр!"));
}
/**
* @brief Генерация псевдослучайных чисел
* @param N длинна выходной последовательности
* @warning Последовательность не может состоять из 0 символов,
* однако 1 символ быть может
* @throw GenRandom_error, в случае ошибки
* @return Возвращает вектор содержащий сгенерированную последовательность
*/
vector<int> GenRandomSequence::generate(int N)
{
	if(N < 1)
		throw GenRandom_error(std::string("Не верная длина выходной последовательности!"));
	
	vector<int> num;
	int new_num;
	int reg_len = reg.size();

	for(int i = 0; i < N; i++) {
		num.push_back(reg[reg_len - 1]);
		new_num = reg[0] ^ reg[reg_len - 1];

		for(int j = reg_len - 1; j > 0; j--) {
			reg[j] = reg[j - 1];
		}
		reg[0] = new_num;
	}

	return num;
}