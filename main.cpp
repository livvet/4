/**
* @file main.cpp
*/
#include "GenRandomSequence.h"
using namespace std;

int main()
{
	try {
		vector<int> num;
		int length;
		int repeat = 1;

		while(repeat == 1) {
			cout << "Введите длинну регистра.\nДлинна регистра должна быть не менее 3х символов." << endl;
			cin	>> length;

			cout << "Введите регистр.\nРегистр должен состоять из символов 0 или 1. Содержать минимум одну единицу.\nСимволы регистра вводятся по одному." << endl;
			for (int i = 0; i < length; i++) {
				int a;
				cin >> a;
				num.push_back(a);
			}
			
			GenRandomSequence object(num);

			cout << "Введите длинну псевдослучайной последовательности.\nДлина последовательности не может быть меньше 1." << endl;
			cin	>> length;
			
			num = object.generate(length);

			for (int i = 0; i < num.size(); i++)
				cout << num[i];
			cout << endl;

			cout << "Введите 1 чтобы сгенирировать другую последовательность, 0 чтобы выйти" << endl;
			cin >> repeat;
		}
	} catch (const GenRandom_error & e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
